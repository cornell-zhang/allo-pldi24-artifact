#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
#include "kernel.h"
using namespace std;

extern "C" {

void PE_int8_int16(
  hls::stream<ap_int<8>>& A_in, hls::stream<ap_int<8>>& A_out,
  hls::stream<ap_int<16>>& B_in, hls::stream<ap_int<16>>& B_out,
  ap_int<64>& C_out, int k_size
) {
  ap_int<32> C_out1;
  ap_int<32> C_out0;
  PE_LOOP: for (int k = 0; k < k_size; k++) {
  #pragma HLS PIPELINE II=1
    ap_int<8> a = A_in.read();
    ap_int<16> b = B_in.read();
    ap_int<24> pack_b = ap_int<24>((b(15, 8), ap_uint<16>(0))) + ap_int<24>(b(7, 0));
    ap_int<16> c1;
    ap_int<16> c0;
    (c1, c0) = a * pack_b;
    c1 = c1 + c0[15];
    C_out1 += c1;
    C_out0 += c0;
    A_out.write(a);
    B_out.write(b);
  }
  C_out = (C_out1, C_out0);
}

void systolic_array_qkv(
  hls::stream<io_pack_int8>& A_loader, 
  hls::stream<io_pack_int16>& B_loader, 
  hls::stream<io_pack_int64>& C_drainer
) {
  hls::stream<ap_int<8>> A_fifo[block_size_a][block_size_b + 1];
  hls::stream<ap_int<16>> B_fifo[block_size_b][block_size_a + 1];
  #pragma HLS STREAM variable=A_fifo depth=block_size_a + 1
  #pragma HLS BIND_STORAGE variable=A_fifo type=fifo impl=srl
  #pragma HLS STREAM variable=B_fifo depth=block_size_b + 1
  #pragma HLS BIND_STORAGE variable=B_fifo type=fifo impl=srl

  ap_int<64> C[block_size_a][block_size_b] = {0};
  #pragma HLS ARRAY_PARTITION variable = C complete dim = 1
  #pragma HLS ARRAY_PARTITION variable = C complete dim = 2

	#pragma HLS DATAFLOW
	data_load_AB:for (int k = 0; k < inp_len; k++) {
	#pragma HLS PIPELINE II=1
		io_pack_int8 A_temp = A_loader.read();
    io_pack_int8 B_temp = B_loader.read();

		for (int m = 0; m < block_size_a; m++) {
			A_fifo[m][0].write(A_temp.range(m*8 + 7, m*8));
		}
		
		for (int n = 0; n < block_size_b; n++) {
			B_fifo[n][0].write(B_temp.range(n*16 + 15, n*16));
		}
	}

	systolic_array: for (int m = 0; m < block_size_a; m++) {
	#pragma HLS UNROLL
		for (int n = 0; n < block_size_b; n++) {
		#pragma HLS UNROLL
			PE_int8_int16(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], inp_len);
		}
	}

	data_drain_AB:for (int k = 0; k < inp_len; k++) {
	#pragma HLS PIPELINE II=1
		for (int m = 0; m < block_size_a; m++) {
			A_fifo[m][block_size_b].read();
		}
		for (int n = 0; n < block_size_b; n++) {
			B_fifo[n][block_size_a].read();
		}
	}

	data_drain_C: for (int n = 0; n < block_size_b; n++) {
	#pragma HLS PIPELINE II=1
		io_pack_int64 C_temp;
		for (int m = 0; m < block_size_a; m++) {
			C_temp.range(m*64 + 63, m*64) = C[m][n];
		}
		C_drainer.write(C_temp);
	}
}

void Linear_layer_qkv(
  hls::stream<io_pack_int8>& inp,
  hls::stream<io_pack_int16>& block_B_loader,
  const float s[seq_num],
  hls::stream<double_pkt_int8>& outp
){
  io_pack_int8 A[inp_len];
    
  hls::stream<io_pack_int8> block_A_loader;
  #pragma HLS STREAM variable=block_A_loader depth=4
  #pragma HLS BIND_STORAGE variable=block_A_loader type=fifo impl=srl

  hls::stream<io_pack_int64> block_C_drainer;
  #pragma HLS STREAM variable=block_C_drainer depth=4
  #pragma HLS BIND_STORAGE variable=block_C_drainer type=fifo impl=srl

  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
  #pragma HLS DATAFLOW
    int ps_offset = ps_id * inp_parallel;

    init_inp_buf: for (int j = 0; j < inp_len; j++) {    // L19
    #pragma HLS pipeline II=1
        A[j] = inp.read();
    }

    block_gemm:
    for(int jj = 0; jj < pack_inp_len_w; jj++){
    #pragma HLS DATAFLOW
    
      init_block_AB:
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
          block_A_loader.write(A[k]);
      }

      systolic_array_qkv(block_A_loader, block_B_loader, block_C_drainer);

      io_pack_int8 outp_data_pack_0;
      io_pack_int8 outp_data_pack_1;
      l_bias_scale_j: for (int j = 0; j < block_size_b; j++) {    // L41
      #pragma HLS pipeline II=1
        io_pack_int64 acc_temp = block_C_drainer.read();
        l_bias_scale_i: for (int i = 0; i < block_size_a; i++) {    // L40
          ap_int<64> outp_temp = acc_temp.range(i*64 + 63, i*64);
          ap_int<32> outp0_dp = outp_temp.range(31, 0);
          ap_int<32> outp1_dp = outp_temp.range(63, 32);
          ap_int<8> outp0 = outp0_dp * s[ps_offset + i];
          ap_int<8> outp1 = outp1_dp * s[ps_offset + i];
          outp_data_pack_0.range(i*8 + 7, i*8) = outp0;
          outp_data_pack_1.range(i*8 + 7, i*8) = outp1;
        }
        double_pkt_int8 pkt_temp;
        pkt_temp.data = (outp_data_pack_1, outp_data_pack_0);
        outp.write(pkt_temp);
      }
    }
  }
}

void input_loader(
  io_pack_float *inp_addr,
  hls::stream<pkt_float>& outp_inp
){
  pkt_float pkt_temp;

  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    l_load_j: for (int j = 0; j < inp_len; j++) {
    #pragma HLS pipeline II=1
      io_pack_float inp = inp_addr[ps_id * inp_len + j];
      pkt_temp.data = inp;
      outp_inp.write(pkt_temp);
    }
  }
}

void input_loader_kv(
  io_pack_float *inp_addr,
  const float s[seq_num],
  hls::stream<io_pack_int8>& inp_k,
  hls::stream<io_pack_int8>& inp_v
){
  io_pack_int8 data_pack;
  
  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    l_load_j: for (int j = 0; j < inp_len; j++) {
    #pragma HLS pipeline II=1
      io_pack_float inp = inp_addr[ps_id * inp_len + j];
      l_load_i: for (int i = 0; i < inp_parallel; i++) {
        converter_t data_temp;
        data_temp.i = inp.range(i*32 + 31, i*32);
        data_temp.f *= s[ps_id * inp_parallel + i];
        data_pack.range(i*8 + 7, i*8) = ap_int<8>(data_temp.f);
      }
      inp_k.write(data_pack);
      inp_v.write(data_pack);
    }
  }
}

void input_loader_q(
  io_pack_float *inp_addr,
  const float s[seq_num],
  hls::stream<io_pack_int8>& inp_q
){
  io_pack_int8 data_pack;

  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    l_load_j: for (int j = 0; j < inp_len; j++) {
    #pragma HLS pipeline II=1
      io_pack_float inp = inp_addr[ps_id * inp_len + j];
      l_load_i: for (int i = 0; i < inp_parallel; i++) {
        converter_t data_temp;
        data_temp.i = inp.range(i*32 + 31, i*32);
        data_temp.f *= s[ps_id * inp_parallel + i];
        data_pack.range(i*8 + 7, i*8) = ap_int<8>(data_temp.f);
      }
      inp_q.write(data_pack);
    }
  }
}

void weight_loader_r1(
  io_pack_int16 *wk_addr,
  io_pack_int16 *wv_addr,
  io_pack_int16 *wq_addr,
  hls::stream<io_pack_int16> &wk_loader,
  hls::stream<io_pack_int16> &wv_loader,
  hls::stream<io_pack_int16> &wq_loader
){
  #pragma HLS DATAFLOW
  l_pack_seq_wk: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    block_wk_load: for(int jj = 0; jj < pack_inp_len_w; jj++){
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
        wk_loader.write(wk_addr[jj * inp_len + k]);
      }
    }
  }

  l_pack_seq_wv: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    block_wv_load: for(int jj = 0; jj < pack_inp_len_w; jj++){
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
        wv_loader.write(wv_addr[jj * inp_len + k]);
      }
    }
  }

  l_pack_seq_wq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    block_wq_load: for(int jj = 0; jj < pack_inp_len_w; jj++){
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
        wq_loader.write(wq_addr[jj * inp_len + k]);
      }
    }
  }
}

#include "const/buf17.h"
#include "const/buf18.h"
#include "const/buf19.h"
#include "const/buf20.h"

void GPT_layer_dataflow_region_1(
  io_pack_float *inp_addr_0,
  io_pack_float *inp_addr_1,
  io_pack_float *inp_addr_2,
  io_pack_int16 *wk_addr,
  io_pack_int16 *wv_addr,
  io_pack_int16 *wq_addr,
  hls::stream<double_pkt_int8>& outp_k,
  hls::stream<double_pkt_int8>& outp_v,
  hls::stream<double_pkt_int8>& outp_q,
  hls::stream<pkt_float>& outp_inp
){
  #pragma HLS interface m_axi port=inp_addr_0 offset=slave bundle=gmem0
  #pragma HLS interface m_axi port=inp_addr_1 offset=slave bundle=gmem1
  #pragma HLS interface m_axi port=inp_addr_2 offset=slave bundle=gmem2
  #pragma HLS interface m_axi port=wk_addr offset=slave bundle=gmem3
  #pragma HLS interface m_axi port=wv_addr offset=slave bundle=gmem4
  #pragma HLS interface m_axi port=wq_addr offset=slave bundle=gmem5
  #pragma HLS interface axis register both port=outp_k
  #pragma HLS interface axis register both port=outp_v
  #pragma HLS interface axis register both port=outp_q
  #pragma HLS interface axis register both port=outp_inp
  #pragma HLS array_partition variable=buf17 cyclic factor=8
  #pragma HLS array_partition variable=buf18 cyclic factor=8
  #pragma HLS array_partition variable=buf19 cyclic factor=8
  #pragma HLS array_partition variable=buf20 cyclic factor=8

  hls::stream<io_pack_int8> inp_k;
  #pragma HLS STREAM variable=inp_k depth=4
  #pragma HLS BIND_STORAGE variable=inp_k type=fifo impl=srl
  hls::stream<io_pack_int8> inp_v;
  #pragma HLS STREAM variable=inp_v depth=4
  #pragma HLS BIND_STORAGE variable=inp_v type=fifo impl=srl
  hls::stream<io_pack_int8> inp_q;
  #pragma HLS STREAM variable=inp_q depth=4
  #pragma HLS BIND_STORAGE variable=inp_q type=fifo impl=srl

  hls::stream<io_pack_int16> block_wk_loader;
  #pragma HLS STREAM variable=block_wk_loader depth=4
  #pragma HLS BIND_STORAGE variable=block_wk_loader type=fifo impl=srl
  hls::stream<io_pack_int16> block_wv_loader;
  #pragma HLS STREAM variable=block_wv_loader depth=4
  #pragma HLS BIND_STORAGE variable=block_wv_loader type=fifo impl=srl
  hls::stream<io_pack_int16> block_wq_loader;
  #pragma HLS STREAM variable=block_wq_loader depth=4
  #pragma HLS BIND_STORAGE variable=block_wq_loader type=fifo impl=srl
  
  #pragma HLS DATAFLOW
  input_loader(inp_addr_0, outp_inp);  // L457
  input_loader_kv(inp_addr_1, buf17, inp_k, inp_v);  // L457
  input_loader_q(inp_addr_2, buf17, inp_q);  // L457
  weight_loader_r1(wk_addr, wv_addr, wq_addr, block_wk_loader, block_wv_loader, block_wq_loader);
  Linear_layer_qkv(inp_k, block_wk_loader, buf18, outp_k);  // L458
  Linear_layer_qkv(inp_v, block_wv_loader, buf19, outp_v);  // L459
  Linear_layer_qkv(inp_q, block_wq_loader, buf20, outp_q);  // L460
}

} // end extern C