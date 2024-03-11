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

void PE_int8_int16_r2(
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

void systolic_array_attn(
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
	data_load_AB:for (int k = 0; k < head_len; k++) {
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
			PE_int8_int16_r2(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], head_len);
		}
	}

	data_drain_AB:for (int k = 0; k < head_len; k++) {
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


void systolic_array_cont(
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
	data_load_AB:for (int k = 0; k < seq_num; k++) {
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
			PE_int8_int16_r2(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], seq_num);
		}
	}

	data_drain_AB:for (int k = 0; k < seq_num; k++) {
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

void systolic_array_ds0(
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
			PE_int8_int16_r2(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], inp_len);
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

void Attention_layer(
    hls::stream<io_pack_int8>& inp,
    io_pack_int16 B[pack_seq_num_w][inp_len], 
    const float s[seq_num],
    hls::stream<double_io_pack_float>& outp
){
    io_pack_int8 A[head_len];

    hls::stream<io_pack_int8> block_A_loader;
    hls::stream<io_pack_int16> block_B_loader;
    #pragma HLS STREAM variable=block_A_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_A_loader type=fifo impl=srl
    #pragma HLS STREAM variable=block_B_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_B_loader type=fifo impl=srl

    hls::stream<io_pack_int64> block_C_drainer;
    #pragma HLS STREAM variable=block_C_drainer depth=4
    #pragma HLS BIND_STORAGE variable=block_C_drainer type=fifo impl=srl
    
    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    #pragma HLS DATAFLOW
        int ps_offset = ps_id * inp_parallel;
        l_multi_head: for (int h = 0; h < head_num; h++){
        #pragma HLS DATAFLOW
            init_inp_buf: for (int j = 0; j < head_len; j++) {    // L19
            #pragma HLS pipeline II=1
                A[j] = inp.read();
            }

            block_gemm:
            for(int jj = 0; jj < pack_seq_num_w; jj++){
            #pragma HLS DATAFLOW

                init_block_AB:
                for(int k = 0; k < head_len; k++){
                #pragma HLS PIPELINE II=1
                    block_A_loader.write(A[k]);
                    block_B_loader.write(B[jj][h * head_len + k]);
                }

                systolic_array_attn(block_A_loader, block_B_loader, block_C_drainer);

                io_pack_float outp_data_pack_0;
                io_pack_float outp_data_pack_1;
                double_io_pack_float outp_data_pack;
                l_bias_scale_j: for (int j = 0; j < block_size_b; j++) {    // L41
                #pragma HLS pipeline II=1
                    io_pack_int64 acc_temp = block_C_drainer.read();
                    l_bias_scale_i: for (int i = 0; i < block_size_a; i++) {    // L40
                        ap_int<64> outp_temp = acc_temp.range(i*64 + 63, i*64);
                        ap_int<32> outp0_dp = outp_temp.range(31, 0);
                        ap_int<32> outp1_dp = outp_temp.range(63, 32);
                        converter_t outp0;
                        converter_t outp1;
                        outp0.f = outp0_dp / 8.0 * s[ps_offset + i];
                        outp1.f = outp1_dp / 8.0 * s[ps_offset + i];
                        outp_data_pack_0.range(i*32 + 31, i*32) = outp0.i;
                        outp_data_pack_1.range(i*32 + 31, i*32) = outp1.i;
                    }
                    outp_data_pack = (outp_data_pack_1, outp_data_pack_0);
                    outp.write(outp_data_pack);
                }
            }
        }
    }
}


void Context_layer(
    hls::stream<io_pack_int8>& inp, 
    io_pack_int16 B[seq_num][pack_inp_len_w], 
    const float s[seq_num],
    hls::stream<double_io_pack_int8>& outp
){
    io_pack_int8 A[seq_num]; 

    hls::stream<io_pack_int8> block_A_loader;
    hls::stream<io_pack_int16> block_B_loader;
    #pragma HLS STREAM variable=block_A_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_A_loader type=fifo impl=srl
    #pragma HLS STREAM variable=block_B_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_B_loader type=fifo impl=srl

    hls::stream<io_pack_int64> block_C_drainer;
    #pragma HLS STREAM variable=block_C_drainer depth=4
    #pragma HLS BIND_STORAGE variable=block_C_drainer type=fifo impl=srl

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
    #pragma HLS DATAFLOW
        int ps_offset = ps_id * inp_parallel;
        l_multi_head: for (int h = 0; h < head_num; h++){
        #pragma HLS DATAFLOW
            init_inp_buf: for (int j = 0; j < seq_num; j++) {    // L19
            #pragma HLS pipeline II=1
                A[j] = inp.read();
            }

            block_gemm:
            for(int jj = 0; jj < pack_head_len_w; jj++){
            #pragma HLS DATAFLOW

                init_block_AB:
                for(int k = 0; k < seq_num; k++){
                #pragma HLS PIPELINE II=1
                    block_A_loader.write(A[k]);
                    block_B_loader.write(B[k][h * pack_head_len_w + jj]);
                }

                systolic_array_cont(block_A_loader, block_B_loader, block_C_drainer);

                io_pack_int8 outp_data_pack_0;
                io_pack_int8 outp_data_pack_1;
                double_io_pack_int8 outp_data_pack;
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
                    outp_data_pack = (outp_data_pack_1, outp_data_pack_0);
                    outp.write(outp_data_pack);
                }
            }
        }
    }
}

void Linear_layer_ds0(
  hls::stream<double_io_pack_int8>& inp,
  hls::stream<io_pack_int16>& block_B_loader,
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

    init_inp_buf: for (int j = 0; j < inp_len/2; j++) {    // L19
    #pragma HLS pipeline II=1
        (A[2*j + 1], A[2*j]) = inp.read();
    }

    block_gemm:
    for(int jj = 0; jj < pack_inp_len_w; jj++){
    #pragma HLS DATAFLOW
    
      init_block_AB:
      for(int k = 0; k < inp_len; k++){
      #pragma HLS PIPELINE II=1
          block_A_loader.write(A[k]);
      }

      systolic_array_ds0(block_A_loader, block_B_loader, block_C_drainer);

      io_pack_float outp_data_pack_0;
      io_pack_float outp_data_pack_1;
      double_io_pack_float outp_data_pack;
      l_bias_scale_j: for (int j = 0; j < block_size_b; j++) {    // L41
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

void weight_ds0_loader(
  io_pack_int16 *w_ds0_addr,
  hls::stream<io_pack_int16>& w_ds0_loader
){
  #pragma HLS DATAFLOW
    l_pack_seq_ds0: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        block_w_ds0_load: for(int jj = 0; jj < pack_inp_len_w; jj++){
            for(int k = 0; k < inp_len; k++){
                #pragma HLS PIPELINE II=1
                w_ds0_loader.write(w_ds0_addr[jj * inp_len + k]);
            }
        }
    }
}

void K_writer(
    hls::stream<double_pkt_int8>& inp,
    io_pack_int16 K[pack_seq_num_w][inp_len]
){  
    double_io_pack_int8 data_pack;
    io_pack_int8 buf[inp_len];
    #pragma HLS array_partition variable=buf cyclic factor=2

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_buf: for (int j = 0; j < inp_len/2; j++) {
        #pragma HLS pipeline II=1
            data_pack = inp.read().data;
            buf[2 * j] = data_pack.range(inp_parallel*8 - 1, 0);
            buf[2 * j + 1] = data_pack.range(inp_parallel*8 * 2 - 1, inp_parallel*8);
        }

        l_write_j: for (int j = 0; j < inp_len; j++) {
        #pragma HLS pipeline II=1
            K[ps_id * inp_parallel / w_parallel][j].range((ps_id % 2) * 64 + 63,  (ps_id % 2) * 64) = buf[j];
        }
    }
}

void V_writer(
    hls::stream<double_pkt_int8>& inp,
    io_pack_int16 V[seq_num][pack_inp_len_w]
){
    double_io_pack_int8 data_pack;
    io_pack_int8 buf[inp_len];
    #pragma HLS array_partition variable=buf cyclic factor=2

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_buf: for (int j = 0; j < inp_len/2; j++) {
        #pragma HLS pipeline II=1
            data_pack = inp.read().data;
            buf[2 * j] = data_pack.range(inp_parallel*8 - 1, 0);
            buf[2 * j + 1] = data_pack.range(inp_parallel*8 * 2 - 1, inp_parallel*8);
        }

        l_write_j: for (int j = 0; j < inp_len; j++) {
        #pragma HLS pipeline II=8
            l_write_i: for (int i = 0; i < inp_parallel; i++) {
                V[ps_id * inp_parallel + i][j / w_parallel].range((j % w_parallel)*8 + 7, (j % w_parallel)*8) = buf[j].range(i*8 + 7, i*8);
            }
        }
    }
}

void Q_buffer(
    hls::stream<double_pkt_int8>& inp,
    hls::stream<io_pack_int8>& outp
){
    double_io_pack_int8 data_pack;
    io_pack_int8 buf[inp_len];
    #pragma HLS array_partition variable=buf cyclic factor=2

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_buf: for (int j = 0; j < inp_len/2; j++) {
        #pragma HLS pipeline II=1
            data_pack = inp.read().data;
            buf[2 * j] = data_pack.range(inp_parallel*8 - 1, 0);
            buf[2 * j + 1] = data_pack.range(inp_parallel*8 * 2 - 1, inp_parallel*8);
        }

        l_write_j: for (int j = 0; j < inp_len; j++) {
        #pragma HLS pipeline II=1
            outp.write(buf[j]);
        }
    }
}


void Softmax_layer(
    hls::stream<double_io_pack_float>& inp,
    const float s[seq_num],
    hls::stream<io_pack_int8>& outp
) {     // L86
    float buf[inp_parallel][seq_num];
    #pragma HLS array_partition variable=buf complete dim=1

    float inp_sumRow[inp_parallel] ={0};
    #pragma HLS array_partition variable=inp_sumRow complete dim=1

    io_pack_float inp_data_pack_0;
    io_pack_float inp_data_pack_1;
    io_pack_int8 outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_multi_head: for (int h = 0; h < head_num; h++){
            l_buf_j: for (int j = 0; j < seq_num/2; j++) { 
            #pragma HLS pipeline II=1
                (inp_data_pack_1, inp_data_pack_0)  = inp.read();
                l_buf_i: for (int i = 0; i < inp_parallel; i++) {
                    converter_t data_temp_0;
                    converter_t data_temp_1;
                    data_temp_0.i = inp_data_pack_0.range(i*32 + 31, i*32);
                    data_temp_1.i = inp_data_pack_1.range(i*32 + 31, i*32);
                    if(j * 2 > ps_id * inp_parallel + i)
                        buf[i][2 * j] = data_temp_0.f;
                    else
                        buf[i][2 * j] = -1e10;
                    if(j * 2 + 1 > ps_id * inp_parallel + i)
                        buf[i][2 * j + 1] = data_temp_1.f;
                    else
                        buf[i][2 * j + 1] = -1e10;
                }
            }

            l_exp_sum_j6: for (int j6 = 0; j6 < seq_num; j6++) {
            #pragma HLS pipeline II=1
                l_exp_sum_i6: for (int i6 = 0; i6 < inp_parallel; i6++) { 
                    float exp_temp = exp(buf[i6][j6]);
                    inp_sumRow[i6] += exp_temp;
                    buf[i6][j6] =  exp_temp;
                }
            }

            l_j7: for (int j7 = 0; j7 < seq_num; j7++) {     // L103
            #pragma HLS pipeline II=1
                l_update_i7: for (int i7 = 0; i7 < inp_parallel; i7++) {        // L102
                    float v78 = buf[i7][j7] / inp_sumRow[i7];    // L106
                    int8_t v80 = v78 * s[ps_id * inp_parallel + i7];    // L108
                    outp_data_pack.range(i7*8 + 7, i7*8) = v80;
                }
                outp.write(outp_data_pack);
            }
        }
    }
}


void Res_layer0(
  hls::stream<double_io_pack_float>& inp_direct,
  hls::stream<pkt_float>& inp_shortcut,
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
            inp_data_pack_shortcut = inp_shortcut.read().data;
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

void Layer_norm0(
    hls::stream<io_pack_float>& inp,
    const float gamma[inp_len],
    const float beta[inp_len],
    hls::stream<pkt_float>& outp
) {     // L224
    float buf[inp_parallel][inp_len];
    #pragma HLS array_partition variable=buf complete dim=1

    float mean[inp_parallel] = {0};    
    float var[inp_parallel] = {0};    

    io_pack_float inp_data_pack;
    io_pack_float outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num_inp; ps_id++){
        l_mean_var_j14: for (int j14 = 0; j14 < inp_len; j14++) {      
        #pragma HLS pipeline II=1
            inp_data_pack = inp.read();
            l_mean_var_i14: for (int i14 = 0; i14 < inp_parallel; i14++) {  
            converter_t data_temp;
            data_temp.i = inp_data_pack.range(i14*32 + 31, i14*32); 
            buf[i14][j14] = data_temp.f;
            mean[i14] += data_temp.f;
            float v179 = data_temp.f * data_temp.f;
            var[i14] += v179;
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
            pkt_float outp_data;
            outp_data.data = outp_data_pack;
            outp.write(outp_data);
        }
    }
}


#include "const/buf13.h"
#include "const/buf14.h"
#include "const/buf21.h"
#include "const/buf22.h"
#include "const/buf23.h"
#include "const/buf24.h"

void GPT_layer_dataflow_region_2(
    io_pack_int16 *w_ds0_addr,
    hls::stream<double_pkt_int8>& outp_k,
    hls::stream<double_pkt_int8>& outp_v,
    hls::stream<double_pkt_int8>& outp_q,
    hls::stream<pkt_float>& outp_inp,
    hls::stream<pkt_float>& outp_ln0 // depth=4
){
    #pragma HLS interface m_axi port=w_ds0_addr offset=slave bundle=gmem0
    #pragma HLS interface axis register both port=outp_k
    #pragma HLS interface axis register both port=outp_v
    #pragma HLS interface axis register both port=outp_q
    #pragma HLS interface axis register both port=outp_inp
    #pragma HLS interface axis register both port=outp_ln0

    io_pack_int16 K[pack_seq_num_w][inp_len];
    #pragma HLS BIND_STORAGE variable=K type=ram_2p impl=uram
    io_pack_int16 V[seq_num][pack_inp_len_w];
    #pragma HLS BIND_STORAGE variable=V type=ram_2p impl=uram

    #pragma HLS array_partition variable=buf21 cyclic factor=8
    #pragma HLS array_partition variable=buf22 cyclic factor=8
    #pragma HLS array_partition variable=buf23 cyclic factor=8
    #pragma HLS array_partition variable=buf24 cyclic factor=8

    hls::stream<io_pack_int8> inp_sfa;
    #pragma HLS STREAM variable=inp_sfa depth=4
    #pragma HLS BIND_STORAGE variable=inp_sfa type=fifo impl=srl
    hls::stream<double_io_pack_float> attn_outp;
    #pragma HLS STREAM variable=attn_outp depth=4
    #pragma HLS BIND_STORAGE variable=attn_outp type=fifo impl=srl
    hls::stream<io_pack_int8> sfm_outp;
    #pragma HLS STREAM variable=sfm_outp depth=512
    #pragma HLS BIND_STORAGE variable=sfm_outp type=fifo impl=uram
    hls::stream<double_io_pack_int8> outp_sfa;
    #pragma HLS STREAM variable=outp_sfa depth=4
    #pragma HLS BIND_STORAGE variable=outp_sfa type=fifo impl=srl
    hls::stream<double_io_pack_float> outp_ds0;
    #pragma HLS STREAM variable=outp_ds0 depth=4
    #pragma HLS BIND_STORAGE variable=outp_ds0 type=fifo impl=srl
    hls::stream<io_pack_float> outp_res0;
    #pragma HLS STREAM variable=outp_res0 depth=4
    #pragma HLS BIND_STORAGE variable=outp_res0 type=fifo impl=srl

    hls::stream<io_pack_int16> block_w_ds0_loader;
    #pragma HLS STREAM variable=block_w_ds0_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_w_ds0_loader type=fifo impl=srl

    #pragma HLS DATAFLOW
    weight_ds0_loader(w_ds0_addr, block_w_ds0_loader);
    K_writer(outp_k, K);
    V_writer(outp_v, V);
    Q_buffer(outp_q, inp_sfa);
    Attention_layer(inp_sfa, K, buf21, attn_outp);
    Softmax_layer(attn_outp, buf22, sfm_outp);
    Context_layer(sfm_outp, V, buf23, outp_sfa);
    Linear_layer_ds0(outp_sfa, block_w_ds0_loader, buf24, outp_ds0);
    Res_layer0(outp_ds0, outp_inp, outp_res0);
    Layer_norm0(outp_res0, buf13, buf14, outp_ln0);
}

} // extern "C"