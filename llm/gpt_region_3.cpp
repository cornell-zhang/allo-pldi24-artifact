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

void PE_int8_int16_r3(
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

void systolic_array_ds1(
  hls::stream<io_pack_int8>& A_loader, 
  hls::stream<io_pack_int16> B_loader[2], 
  hls::stream<io_pack_int64>& C_drainer
) {
  hls::stream<ap_int<8>> A_fifo[block_size_a][block_size_b * 2 + 1];
  hls::stream<ap_int<16>> B_fifo[block_size_b * 2][block_size_a + 1];
  #pragma HLS STREAM variable=A_fifo depth=block_size_a + 1
  #pragma HLS BIND_STORAGE variable=A_fifo type=fifo impl=srl
  #pragma HLS STREAM variable=B_fifo depth=block_size_b * 2 + 1
  #pragma HLS BIND_STORAGE variable=B_fifo type=fifo impl=srl

  ap_int<64> C[block_size_a][block_size_b * 2] = {0};
  #pragma HLS ARRAY_PARTITION variable = C complete dim = 1
  #pragma HLS ARRAY_PARTITION variable = C complete dim = 2

	#pragma HLS DATAFLOW
	data_load_AB:for (int k = 0; k < inp_len; k++) {
	#pragma HLS PIPELINE II=1
		io_pack_int8 A_temp = A_loader.read();
        io_pack_int16 B_temp_0 = B_loader[0].read();
        io_pack_int16 B_temp_1 = B_loader[1].read();

		for (int m = 0; m < block_size_a; m++) {
			A_fifo[m][0].write(A_temp.range(m*8 + 7, m*8));
		}
		
		for (int n = 0; n < block_size_b; n++) {
			B_fifo[n][0].write(B_temp_0.range(n*16 + 15, n*16));
            B_fifo[block_size_b + n][0].write(B_temp_1.range(n*16 + 15, n*16));
		}
	}

	systolic_array: for (int m = 0; m < block_size_a; m++) {
	#pragma HLS UNROLL
		for (int n = 0; n < block_size_b * 2; n++) {
		#pragma HLS UNROLL
			PE_int8_int16_r3(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], inp_len);
		}
	}

	data_drain_AB:for (int k = 0; k < inp_len; k++) {
	#pragma HLS PIPELINE II=1
		for (int m = 0; m < block_size_a; m++) {
			A_fifo[m][block_size_b * 2].read();
		}
		for (int n = 0; n < block_size_b * 2; n++) {
			B_fifo[n][block_size_a].read();
		}
	}

	data_drain_C: for (int n = 0; n < block_size_b * 2; n++) {
	#pragma HLS PIPELINE II=1
		io_pack_int64 C_temp;
		for (int m = 0; m < block_size_a; m++) {
			C_temp.range(m*64 + 63, m*64) = C[m][n];
		}
		C_drainer.write(C_temp);
	}
}

void systolic_array_ds2(
  hls::stream<io_pack_int8>& A_loader, 
  hls::stream<io_pack_int16> B_loader[2], 
  hls::stream<io_pack_int64>& C_drainer
) {
  hls::stream<ap_int<8>> A_fifo[block_size_a][block_size_b * 2 + 1];
  hls::stream<ap_int<16>> B_fifo[block_size_b * 2][block_size_a + 1];
  #pragma HLS STREAM variable=A_fifo depth=block_size_a + 1
  #pragma HLS BIND_STORAGE variable=A_fifo type=fifo impl=srl
  #pragma HLS STREAM variable=B_fifo depth=block_size_b * 2 + 1
  #pragma HLS BIND_STORAGE variable=B_fifo type=fifo impl=srl

  ap_int<64> C[block_size_a][block_size_b * 2] = {0};
  #pragma HLS ARRAY_PARTITION variable = C complete dim = 1
  #pragma HLS ARRAY_PARTITION variable = C complete dim = 2

	#pragma HLS DATAFLOW
	data_load_AB:for (int k = 0; k < gelu_len; k++) {
	#pragma HLS PIPELINE II=1
		io_pack_int8 A_temp = A_loader.read();
        io_pack_int16 B_temp_0 = B_loader[0].read();
        io_pack_int16 B_temp_1 = B_loader[1].read();

		for (int m = 0; m < block_size_a; m++) {
			A_fifo[m][0].write(A_temp.range(m*8 + 7, m*8));
		}
		
		for (int n = 0; n < block_size_b; n++) {
			B_fifo[n][0].write(B_temp_0.range(n*16 + 15, n*16));
            B_fifo[block_size_b + n][0].write(B_temp_1.range(n*16 + 15, n*16));
		}
	}

	systolic_array: for (int m = 0; m < block_size_a; m++) {
	#pragma HLS UNROLL
		for (int n = 0; n < block_size_b * 2; n++) {
		#pragma HLS UNROLL
			PE_int8_int16_r3(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], gelu_len);
		}
	}

	data_drain_AB:for (int k = 0; k < gelu_len; k++) {
	#pragma HLS PIPELINE II=1
		for (int m = 0; m < block_size_a; m++) {
			A_fifo[m][block_size_b * 2].read();
		}
		for (int n = 0; n < block_size_b * 2; n++) {
			B_fifo[n][block_size_a].read();
		}
	}

	data_drain_C: for (int n = 0; n < block_size_b * 2; n++) {
	#pragma HLS PIPELINE II=1
		io_pack_int64 C_temp;
		for (int m = 0; m < block_size_a; m++) {
			C_temp.range(m*64 + 63, m*64) = C[m][n];
		}
		C_drainer.write(C_temp);
	}
}

void Linear_layer_ds1(
  hls::stream<io_pack_int8>& inp,
  hls::stream<io_pack_int16> block_B_loader[2],
  const float s[seq_num],
  hls::stream<double_io_pack_float>& outp
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
    for(int jj = 0; jj < pack_gelu_len_w / 2; jj++){
    #pragma HLS DATAFLOW
    
      init_block_AB:
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
          block_A_loader.write(A[k]);
      }

      systolic_array_ds1(block_A_loader, block_B_loader, block_C_drainer);

      io_pack_float outp_data_pack_0;
      io_pack_float outp_data_pack_1;
      double_io_pack_float outp_data_pack;
      l_bias_scale_j: for (int j = 0; j < block_size_b * 2; j++) {    // L41
      #pragma HLS pipeline II=1
        io_pack_int64 acc_temp = block_C_drainer.read();
        l_bias_scale_i: for (int i = 0; i < block_size_a; i++) {    // L40
          ap_int<64> outp_temp = acc_temp.range(i*64 + 63, i*64);
          ap_int<32> outp0_dp = outp_temp.range(31, 0);
          ap_int<32> outp1_dp = outp_temp.range(63, 32);
          converter_t outp0;
          converter_t outp1;
          outp0.f = outp0_dp * s[ps_offset + i];
          outp1.f = outp1_dp * s[ps_offset + i];
          outp_data_pack_0.range(i*32 + 31, i*32) = outp0.i;
          outp_data_pack_1.range(i*32 + 31, i*32) = outp1.i;
        }
        outp_data_pack = (outp_data_pack_1, outp_data_pack_0);
        outp.write(outp_data_pack);
      }
    }
  }
}

void Linear_layer_ds2(
  hls::stream<io_pack_int8>& inp,
  hls::stream<io_pack_int16> block_B_loader[2],
  const float s[seq_num],
  hls::stream<double_io_pack_float>& outp
){
  io_pack_int8 A[gelu_len];
    
  hls::stream<io_pack_int8> block_A_loader;
  #pragma HLS STREAM variable=block_A_loader depth=4
  #pragma HLS BIND_STORAGE variable=block_A_loader type=fifo impl=srl

  hls::stream<io_pack_int64> block_C_drainer;
  #pragma HLS STREAM variable=block_C_drainer depth=4
  #pragma HLS BIND_STORAGE variable=block_C_drainer type=fifo impl=srl

  l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
  #pragma HLS DATAFLOW
    int ps_offset = ps_id * inp_parallel;

    init_inp_buf: for (int j = 0; j < gelu_len; j++) {    // L19
    #pragma HLS pipeline II=1
        A[j] = inp.read();
    }

    block_gemm:
    for(int jj = 0; jj < pack_inp_len_w / 2; jj++){
    #pragma HLS DATAFLOW
    
      init_block_AB:
      for(int k = 0; k < gelu_len; k++){
      #pragma HLS PIPELINE II=1
          block_A_loader.write(A[k]);
      }

      systolic_array_ds2(block_A_loader, block_B_loader, block_C_drainer);

      io_pack_float outp_data_pack_0;
      io_pack_float outp_data_pack_1;
      double_io_pack_float outp_data_pack;
      l_bias_scale_j: for (int j = 0; j < block_size_b * 2; j++) {    // L41
      #pragma HLS pipeline II=1
        io_pack_int64 acc_temp = block_C_drainer.read();
        l_bias_scale_i: for (int i = 0; i < block_size_a; i++) {    // L40
          ap_int<64> outp_temp = acc_temp.range(i*64 + 63, i*64);
          ap_int<32> outp0_dp = outp_temp.range(31, 0);
          ap_int<32> outp1_dp = outp_temp.range(63, 32);
          converter_t outp0;
          converter_t outp1;
          outp0.f = outp0_dp * s[ps_offset + i];
          outp1.f = outp1_dp * s[ps_offset + i];
          outp_data_pack_0.range(i*32 + 31, i*32) = outp0.i;
          outp_data_pack_1.range(i*32 + 31, i*32) = outp1.i;
        }
        outp_data_pack = (outp_data_pack_1, outp_data_pack_0);
        outp.write(outp_data_pack);
      }
    }
  }
}

void input_loader_ds1_res1(
    hls::stream<pkt_float>& inp,
    const float s[seq_num],
    hls::stream<io_pack_float>& inp_res,
    hls::stream<io_pack_int8>& inp_ds
) {     // L2
    io_pack_float inp_data_pack;
    io_pack_int8 inp_data_pack_ds;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_loader_j: for (int j = 0; j < inp_len; j++) {        // L5
        #pragma HLS pipeline II=1
            inp_data_pack = inp.read().data;
            inp_res.write(inp_data_pack);
            l_loader_i: for (int i = 0; i < inp_parallel; i++) {        // L4
                converter_t data_temp;
                data_temp.i = inp_data_pack.range(i*32 + 31, i*32);
                data_temp.f *=  s[ps_id * inp_parallel + i];   // L9
                inp_data_pack_ds.range(i*8 + 7, i*8) = ap_int<8>(data_temp.f);
            }
            inp_ds.write(inp_data_pack_ds);
        }
    }
}

void weight_loader_r3(
  double_io_pack_int16 *w_ds1_addr,
  double_io_pack_int16 *w_ds2_addr,
  hls::stream<io_pack_int16> w_ds1_loader[2],
  hls::stream<io_pack_int16> w_ds2_loader[2]
){
    #pragma HLS DATAFLOW
    l_pack_seq_ds1: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        block_w_ds1_load: for(int jj = 0; jj < pack_gelu_len_w / 2; jj++){
            for(int k = 0; k < inp_len; k++){
            #pragma HLS PIPELINE II=1
                io_pack_int16 w_pack_0;
                io_pack_int16 w_pack_1;
                (w_pack_1, w_pack_0) = w_ds1_addr[jj * inp_len + k];
                w_ds1_loader[0].write(w_pack_0);
                w_ds1_loader[1].write(w_pack_1);
            }
        }
    }

    l_pack_seq_ds2: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        block_w_ds2_load: for(int jj = 0; jj < pack_inp_len_w / 2; jj++){
            for(int k = 0; k < gelu_len; k++){
            #pragma HLS PIPELINE II=1
                io_pack_int16 w_pack_0;
                io_pack_int16 w_pack_1;
                (w_pack_1, w_pack_0) = w_ds2_addr[jj * gelu_len + k];
                w_ds2_loader[0].write(w_pack_0);
                w_ds2_loader[1].write(w_pack_1);
            }
        }
    }
}

void Gelu_layer(
    hls::stream<double_io_pack_float>& inp,
    const float s[seq_num],
    hls::stream<io_pack_int8>& outp
) {     // L320
    io_pack_float buf[gelu_len];
    #pragma HLS array_partition variable=buf cyclic factor=2

    io_pack_float inp_data_pack_1;
    io_pack_float inp_data_pack_0;
    io_pack_int8 outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    #pragma HLS DATAFLOW
        int ps_offset = ps_id * inp_parallel;

        l_buf: for (int j = 0; j < gelu_len/2; j++) {
        #pragma HLS pipeline II=1
            (inp_data_pack_1, inp_data_pack_0) = inp.read();
            buf[2 * j] = inp_data_pack_0;
            buf[2 * j + 1] = inp_data_pack_1;
        }

        l_j20: for (int j20 = 0; j20 < gelu_len; j20++) {       // L323
        #pragma HLS pipeline II=1
            io_pack_float buf_data_pack = buf[j20];
            l_i20: for (int i20 = 0; i20 < inp_parallel; i20++) {   // L322
                converter_t inp_data;
                float outp_data;
                inp_data.i = buf_data_pack.range(i20*32 + 31, i20*32);      // L324
                if (inp_data.f < 3)
                    outp_data = 0;
                else if(inp_data.f < -1)
                    outp_data = -0.0773 * (inp_data.f + 3) - 0.004;
                else if(inp_data.f < 0)
                    outp_data = 0.1587 * inp_data.f;
                else if(inp_data.f < 1)
                    outp_data = 0.8413 * inp_data.f;
                else if(inp_data.f < 3)
                    outp_data = 1.0773 * (inp_data.f - 1) + 0.8413;
                else
                    outp_data = inp_data.f;
                outp_data_pack.range(i20*8 + 7, i20*8) = ap_int<8>(outp_data * s[ps_offset + i20]);
            }
            outp.write(outp_data_pack);
        }
    }
}


void Res_layer1(
    hls::stream<double_io_pack_float>& inp_direct,
    hls::stream<io_pack_float>& inp_shortcut,
    hls::stream<io_pack_float>& outp
) {     // L212
    io_pack_float buf[inp_len];
    #pragma HLS array_partition variable=buf cyclic factor=2

    io_pack_float inp_data_pack_direct_0;
    io_pack_float inp_data_pack_direct_1;
    io_pack_float buf_data_pack_direct;
    io_pack_float inp_data_pack_shortcut;
    io_pack_float outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_buf: for (int j = 0; j < inp_len/2; j++) {
        #pragma HLS pipeline II=1
            (inp_data_pack_direct_1, inp_data_pack_direct_0) = inp_direct.read();
            buf[2 * j] = inp_data_pack_direct_0;
            buf[2 * j + 1] = inp_data_pack_direct_1;
        }

        l_j13: for (int j13 = 0; j13 < inp_len; j13++) {        // L215
        #pragma HLS pipeline II=1
            buf_data_pack_direct = buf[j13];
            inp_data_pack_shortcut = inp_shortcut.read();
            l_i13: for (int i13 = 0; i13 < inp_parallel; i13++) {   // L214
                converter_t converter_dr;
                converter_t converter_sc;
                converter_t converter_outp;
                converter_dr.i = buf_data_pack_direct.range(i13*32 + 31, i13 * 32);
                converter_sc.i = inp_data_pack_shortcut.range(i13*32 + 31, i13 * 32);
                converter_outp.f = converter_dr.f + converter_sc.f;
                outp_data_pack.range(i13*32 + 31, i13 * 32) = converter_outp.i;
            }
            outp.write(outp_data_pack);
        }
    }
}

void Layer_norm1(
    hls::stream<io_pack_float>& inp,
    const float gamma[inp_len],
    const float beta[inp_len],
    hls::stream<io_pack_float>& outp
) {     // L224
    float buf[inp_parallel][inp_len];
    #pragma HLS array_partition variable=buf complete dim=1

    float mean[inp_parallel] = {0};       // L226
    float var[inp_parallel] = {0};        // L232

    io_pack_float inp_data_pack;
    io_pack_float outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_mean_var_j14: for (int j14 = 0; j14 < inp_len; j14++) {        // L234
        #pragma HLS pipeline II=1
            inp_data_pack = inp.read();
            l_mean_var_i14: for (int i14 = 0; i14 < inp_parallel; i14++) {       // L233
                converter_t data_temp;
                data_temp.i = inp_data_pack.range(i14*32 + 31, i14*32);      // L235
                buf[i14][j14] = data_temp.f;
                mean[i14] += data_temp.f; // L238
                float v179 = data_temp.f * data_temp.f; // L241
                var[i14] += v179;        // L244
            }
        }

        l_mean_var_i15: for (int i15 = 0; i15 < inp_parallel; i15++) {
        #pragma HLS pipeline II=1
            mean[i15] /= inp_len; 
            var[i15] = var[i15] / inp_len - mean[i15] * mean[i15]; 
        }

        l_j16: for (int j16 = 0; j16 < inp_len; j16++) {
        #pragma HLS pipeline II=1
            l_mean_var_i16: for (int i16 = 0; i16 < inp_parallel; i16++) {
            converter_t data_temp;
            data_temp.f = (buf[i16][j16] - mean[i16]) / sqrt(var[i16] + 0.000010);
            data_temp.f = data_temp.f * gamma[j16] + beta[j16];
            outp_data_pack.range(i16*32 + 31, i16*32) = data_temp.i;
            }
            outp.write(outp_data_pack);
        }
    }
}

void output_writer(
    hls::stream<io_pack_float>& inp,
    io_pack_float *outp_addr
){
    io_pack_float outp_data_pack;
    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_j: for (int j = 0; j < inp_len; j++) {
        #pragma HLS pipeline II=1
            outp_addr[ps_id * inp_len + j] = inp.read();
        }
    }
}

#include "const/buf15.h"
#include "const/buf16.h"
#include "const/buf25.h"
#include "const/buf26.h"
#include "const/buf27.h"
#include "const/buf28.h"

void GPT_layer_dataflow_region_3(
    double_io_pack_int16 *w_ds1_addr,
    double_io_pack_int16 *w_ds2_addr,
    hls::stream<pkt_float>& outp_ln0,
    io_pack_float *outp_addr
){
    #pragma HLS interface axis register both port=outp_ln0
    #pragma HLS interface m_axi port=w_ds1_addr offset=slave bundle=gmem0
    #pragma HLS interface m_axi port=w_ds2_addr offset=slave bundle=gmem1
    #pragma HLS interface m_axi port=outp_addr offset=slave bundle=gmem2

    #pragma HLS array_partition variable=buf25 cyclic factor=8
    #pragma HLS array_partition variable=buf26 cyclic factor=8
    #pragma HLS array_partition variable=buf27 cyclic factor=8
    #pragma HLS array_partition variable=buf28 cyclic factor=8
    hls::stream<io_pack_float> inp_res1; // only this one need to have large depth
    #pragma HLS STREAM variable=inp_res1 depth=32*1024
    #pragma HLS BIND_STORAGE variable=inp_res1 type=fifo impl=uram
    hls::stream<io_pack_int8> inp_ds1;
    #pragma HLS STREAM variable=inp_ds1 depth=4
    #pragma HLS BIND_STORAGE variable=inp_ds1 type=fifo impl=srl
    hls::stream<double_io_pack_float> outp_ds1;
    #pragma HLS STREAM variable=outp_ds1 depth=4
    #pragma HLS BIND_STORAGE variable=outp_ds1 type=fifo impl=srl
    hls::stream<io_pack_int8> outp_gelu;
    #pragma HLS STREAM variable=outp_gelu depth=4096
    #pragma HLS BIND_STORAGE variable=outp_gelu type=fifo impl=uram
    hls::stream<double_io_pack_float> outp_ds2;
    #pragma HLS STREAM variable=outp_ds2 depth=4
    #pragma HLS BIND_STORAGE variable=outp_ds2 type=fifo impl=srl
    hls::stream<io_pack_float> outp_res1;
    #pragma HLS STREAM variable=outp_res1 depth=4
    #pragma HLS BIND_STORAGE variable=outp_res1 type=fifo impl=srl
    hls::stream<io_pack_float> outp_ln1;
    #pragma HLS STREAM variable=outp_ln1 depth=4
    #pragma HLS BIND_STORAGE variable=outp_ln1 type=fifo impl=srl

    hls::stream<io_pack_int16> block_w_ds1_loader[2];
    #pragma HLS STREAM variable=block_w_ds1_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_w_ds1_loader type=fifo impl=srl
    hls::stream<io_pack_int16> block_w_ds2_loader[2];
    #pragma HLS STREAM variable=block_w_ds2_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_w_ds2_loader type=fifo impl=srl
    
    #pragma HLS DATAFLOW
    input_loader_ds1_res1(outp_ln0, buf25, inp_res1, inp_ds1);
    weight_loader_r3(w_ds1_addr, w_ds2_addr, block_w_ds1_loader, block_w_ds2_loader);
    Linear_layer_ds1(inp_ds1, block_w_ds1_loader, buf26, outp_ds1);
    Gelu_layer(outp_ds1, buf27, outp_gelu); 
    Linear_layer_ds2(outp_gelu, block_w_ds2_loader, buf28, outp_ds2); 
    Res_layer1(outp_ds2, inp_res1, outp_res1); 
    Layer_norm1(outp_res1, buf15, buf16, outp_ln1); 
    output_writer(outp_ln1, outp_addr);
}

} // extern "C"