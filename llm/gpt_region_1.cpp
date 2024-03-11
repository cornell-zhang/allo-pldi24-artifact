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

const int inp_parallel = inp_num;
const int block_size = inp_num;

void PE_8_4_pack(
  hls::stream<int8_t>& A_in, hls::stream<int8_t>& A_out,
  hls::stream<int8_t>& B_in, hls::stream<int8_t>& B_out,
  int48_t& C_out, int k_size
) {
  PE_LOOP:
  for (int k = 0; k < k_size; k++) {
  #pragma HLS PIPELINE II=1
    ap_int<8> a = A_in.read();
    ap_int<8> b = B_in.read();
    ap_int<17> pack_b = (b(7, 4), ap_uint<13>(0)) + ap_int<17>(b(3, 0));
    ap_int<25> pack_c = a * pack_b;
    C_out += int48_t((pack_c(24, 13), ap_uint<24>(0)) + ap_int<36>(pack_c(11, 0)));
    A_out.write(a);
    B_out.write(b);
  }
}

void systolic_array_k_1024_double(
  hls::stream<io_pack_int8>& A_loader, 
  hls::stream<io_pack_int8> B_loader[2], 
  hls::stream<io_pack_int48>& C_drainer
) {
  hls::stream<int8_t> A_fifo[block_size][block_size * 2 + 1];
  hls::stream<int8_t> B_fifo[block_size * 2][block_size + 1];
  #pragma HLS STREAM variable=A_fifo depth=9
  #pragma HLS BIND_STORAGE variable=A_fifo type=fifo impl=srl
  #pragma HLS STREAM variable=B_fifo depth=17
  #pragma HLS BIND_STORAGE variable=B_fifo type=fifo impl=srl

  int48_t C[block_size][block_size * 2] = {0};
  #pragma HLS ARRAY_PARTITION variable = C complete dim = 1
  #pragma HLS ARRAY_PARTITION variable = C complete dim = 2

	#pragma HLS DATAFLOW
	data_load_AB:for (int k = 0; k < inp_len; k++) {
	#pragma HLS PIPELINE II=1
		io_pack_int8 A_temp = A_loader.read();
    io_pack_int8 B_temp_0 = B_loader[0].read();
		io_pack_int8 B_temp_1 = B_loader[1].read();

		for (int m = 0; m < block_size; m++) {
			A_fifo[m][0].write(A_temp.range(m*8 + 7, m*8));
		}
		
		for (int n = 0; n < block_size; n++) {
			B_fifo[n][0].write(B_temp_0.range(n*8 + 7, n*8));
			B_fifo[block_size + n][0].write(B_temp_1.range(n*8 + 7, n*8));
		}
	}

	systolic_array: for (int m = 0; m < block_size; m++) {
	#pragma HLS UNROLL
		for (int n = 0; n < block_size * 2; n++) {
		#pragma HLS UNROLL
			PE_8_4_pack(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], inp_len);
		}
	}

	data_drain_AB:for (int k = 0; k < inp_len; k++) {
	#pragma HLS PIPELINE II=1
		for (int m = 0; m < block_size; m++) {
			A_fifo[m][block_size * 2].read();
		}
		for (int n = 0; n < block_size * 2; n++) {
			B_fifo[n][block_size].read();
		}
	}

	data_drain_C: for (int n = 0; n < block_size * 2; n++) {
	#pragma HLS PIPELINE II=1
		io_pack_int48 C_temp;
		for (int m = 0; m < block_size; m++) {
			C_temp.range(m*48 + 47, m*48) = C[m][n];
		}
		C_drainer.write(C_temp);
	}
}

void Linear_layer_qkv(
  hls::stream<io_pack_int8>& inp,
  hls::stream<io_pack_int8> block_B_loader[2],
  const float s[seq_num],
  hls::stream<double_pkt_int8>& outp
){
  io_pack_int8 A[inp_len];
    
  hls::stream<io_pack_int8> block_A_loader;
  #pragma HLS STREAM variable=block_A_loader depth=4
  #pragma HLS BIND_STORAGE variable=block_A_loader type=fifo impl=srl

  hls::stream<io_pack_int48> block_C_drainer;
  #pragma HLS STREAM variable=block_C_drainer depth=4
  #pragma HLS BIND_STORAGE variable=block_C_drainer type=fifo impl=srl

  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
  #pragma HLS DATAFLOW
    int ps_offset = ps_id * inp_num;

    init_inp_buf: for (int j = 0; j < inp_len; j++) {    // L19
    #pragma HLS pipeline II=1
        A[j] = inp.read();
    }

    block_gemm:
    for(int jj = 0; jj < pack_inp_len_half/2; jj++){
    #pragma HLS DATAFLOW
    
      init_block_AB:
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
          block_A_loader.write(A[k]);
      }

      systolic_array_k_1024_double(block_A_loader, block_B_loader, block_C_drainer);

      io_pack_int8 outp_data_pack_0;
      io_pack_int8 outp_data_pack_1;
      l_bias_scale_j: for (int j = 0; j < block_size*2; j++) {    // L41
      #pragma HLS pipeline II=1
        io_pack_int48 acc_temp = block_C_drainer.read();
        l_bias_scale_i: for (int i = 0; i < block_size; i++) {    // L40
          int48_t outp_temp = acc_temp.range(i*48 + 47, i*48);
          int24_t outp0_dp = outp_temp.range(47, 24);
          int24_t outp1_dp = outp_temp.range(23, 0);
          int8_t outp0 = outp0_dp * s[ps_offset + i];
          int8_t outp1 = outp1_dp * s[ps_offset + i];
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

  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
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
  
  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
    l_load_j: for (int j = 0; j < inp_len; j++) {
    #pragma HLS pipeline II=1
      io_pack_float inp = inp_addr[ps_id * inp_len + j];
      l_load_i: for (int i = 0; i < inp_num; i++) {
        converter_t data_temp;
        data_temp.i = inp.range(i*32 + 31, i*32);
        data_temp.f *= s[ps_id * inp_num + i];
        data_pack.range(i*8 + 7, i*8) = int8_t(data_temp.f);
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

  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
    l_load_j: for (int j = 0; j < inp_len; j++) {
    #pragma HLS pipeline II=1
      io_pack_float inp = inp_addr[ps_id * inp_len + j];
      l_load_i: for (int i = 0; i < inp_num; i++) {
        converter_t data_temp;
        data_temp.i = inp.range(i*32 + 31, i*32);
        data_temp.f *= s[ps_id * inp_num + i];
        data_pack.range(i*8 + 7, i*8) = int8_t(data_temp.f);
      }
      inp_q.write(data_pack);
    }
  }
}

void weight_loader_r1(
  bus_pack_int8 *wk_addr,
  bus_pack_int8 *wv_addr,
  bus_pack_int8 *wq_addr,
  hls::stream<io_pack_int8> wk_loader[2],
  hls::stream<io_pack_int8> wv_loader[2],
  hls::stream<io_pack_int8> wq_loader[2]
){
  #pragma HLS DATAFLOW
  l_pack_seq_wk: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
    block_wk_load: for(int jj = 0; jj < pack_inp_len_half / 2; jj++){
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
        bus_pack_int8 w_temp = wk_addr[jj * inp_len + k];
        wk_loader[0].write(w_temp.range(63, 0));
        wk_loader[1].write(w_temp.range(127, 64));
      }
    }
  }

  l_pack_seq_wv: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
    block_wv_load: for(int jj = 0; jj < pack_inp_len_half / 2; jj++){
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
        bus_pack_int8 w_temp = wv_addr[jj * inp_len + k];
        wv_loader[0].write(w_temp.range(63, 0));
        wv_loader[1].write(w_temp.range(127, 64));
      }
    }
  }

  l_pack_seq_wq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
    block_wq_load: for(int jj = 0; jj < pack_inp_len_half / 2; jj++){
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
        bus_pack_int8 w_temp = wq_addr[jj * inp_len + k];
        wq_loader[0].write(w_temp.range(63, 0));
        wq_loader[1].write(w_temp.range(127, 64));
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
  bus_pack_int8 *wk_addr,
  bus_pack_int8 *wv_addr,
  bus_pack_int8 *wq_addr,
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
  #pragma HLS array_partition variable=buf17 cyclic factor=inp_parallel/2
  #pragma HLS array_partition variable=buf18 cyclic factor=inp_parallel/2
  #pragma HLS array_partition variable=buf19 cyclic factor=inp_parallel/2
  #pragma HLS array_partition variable=buf20 cyclic factor=inp_parallel/2

  hls::stream<io_pack_int8> inp_k;
  #pragma HLS STREAM variable=inp_k depth=4
  #pragma HLS BIND_STORAGE variable=inp_k type=fifo impl=srl
  hls::stream<io_pack_int8> inp_v;
  #pragma HLS STREAM variable=inp_v depth=4
  #pragma HLS BIND_STORAGE variable=inp_v type=fifo impl=srl
  hls::stream<io_pack_int8> inp_q;
  #pragma HLS STREAM variable=inp_q depth=4
  #pragma HLS BIND_STORAGE variable=inp_q type=fifo impl=srl

  hls::stream<io_pack_int8> block_wk_loader[2];
  #pragma HLS STREAM variable=block_wk_loader depth=4
  #pragma HLS BIND_STORAGE variable=block_wk_loader type=fifo impl=srl
  hls::stream<io_pack_int8> block_wv_loader[2];
  #pragma HLS STREAM variable=block_wv_loader depth=4
  #pragma HLS BIND_STORAGE variable=block_wv_loader type=fifo impl=srl
  hls::stream<io_pack_int8> block_wq_loader[2];
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