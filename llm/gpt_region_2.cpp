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

void PE_8_4_pack_r2(
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

void PE_8_8(
    hls::stream<int8_t>& A_in, hls::stream<int8_t>& A_out,
    hls::stream<int8_t>& B_in, hls::stream<int8_t>& B_out,
    int24_t& C_out, int k_size
) {
    PE_LOOP:
    for (int k = 0; k < k_size; k++) {
    #pragma HLS PIPELINE II=1
        ap_int<8> a = A_in.read();
        ap_int<8> b = B_in.read();
        C_out += a * b;
        A_out.write(a);
        B_out.write(b);
    }
}


void systolic_array_k_attn(
    hls::stream<io_pack_int8>& A_loader, 
    hls::stream<io_pack_int8>& B_loader, 
    hls::stream<io_pack_int24>& C_drainer
) {
    hls::stream<int8_t> A_fifo[block_size][block_size + 1];
    hls::stream<int8_t> B_fifo[block_size][block_size + 1];
    #pragma HLS STREAM variable=A_fifo depth=9
    #pragma HLS BIND_STORAGE variable=A_fifo type=fifo impl=srl
    #pragma HLS STREAM variable=B_fifo depth=9
    #pragma HLS BIND_STORAGE variable=B_fifo type=fifo impl=srl

    int24_t C[block_size][block_size] = {0};
    #pragma HLS ARRAY_PARTITION variable = C complete dim = 1
    #pragma HLS ARRAY_PARTITION variable = C complete dim = 2

    #pragma HLS DATAFLOW
    data_load_AB:for (int k = 0; k < head_len; k++) {
    #pragma HLS PIPELINE II=1
        io_pack_int8 A_temp = A_loader.read();
        for (int m = 0; m < block_size; m++) {
            A_fifo[m][0].write(A_temp.range(m*8 + 7, m*8));
        }
        io_pack_int8 B_temp = B_loader.read();
        for (int n = 0; n < block_size; n++) {
            B_fifo[n][0].write(B_temp.range(n*8 + 7, n*8));
        }
    }

    systolic_array: for (int m = 0; m < block_size; m++) {
    #pragma HLS UNROLL
        for (int n = 0; n < block_size; n++) {
        #pragma HLS UNROLL
            PE_8_8(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], head_len);
        }
    }

    data_drain_AB:for (int k = 0; k < head_len; k++) {
    #pragma HLS PIPELINE II=1
        for (int m = 0; m < block_size; m++) {
            A_fifo[m][block_size].read();
        }
        for (int n = 0; n < block_size; n++) {
            B_fifo[n][block_size].read();
        }
    }

    data_drain_C: for (int n = 0; n < block_size; n++) {
    #pragma HLS PIPELINE II=1
        io_pack_int24 C_temp;
        for (int m = 0; m < block_size; m++) {
            C_temp.range(m*24 + 23, m*24) = C[m][n];
        }
        C_drainer.write(C_temp);
    }
}


void systolic_array_k_cont(
    hls::stream<io_pack_int8>& A_loader, 
    hls::stream<io_pack_int8>& B_loader, 
    hls::stream<io_pack_int24>& C_drainer
) {
    hls::stream<int8_t> A_fifo[block_size][block_size + 1];
    hls::stream<int8_t> B_fifo[block_size][block_size + 1];
    #pragma HLS STREAM variable=A_fifo depth=9
    #pragma HLS BIND_STORAGE variable=A_fifo type=fifo impl=srl
    #pragma HLS STREAM variable=B_fifo depth=9
    #pragma HLS BIND_STORAGE variable=B_fifo type=fifo impl=srl

    int24_t C[block_size][block_size] = {0};
    #pragma HLS ARRAY_PARTITION variable = C complete dim = 1
    #pragma HLS ARRAY_PARTITION variable = C complete dim = 2

    #pragma HLS DATAFLOW
    data_load_AB:for (int k = 0; k < seq_num; k++) {
    #pragma HLS PIPELINE II=1
        io_pack_int8 A_temp = A_loader.read();
        for (int m = 0; m < block_size; m++) {
            A_fifo[m][0].write(A_temp.range(m*8 + 7, m*8));
        }
        io_pack_int8 B_temp = B_loader.read();
        for (int n = 0; n < block_size; n++) {
            B_fifo[n][0].write(B_temp.range(n*8 + 7, n*8));
        }
    }

    systolic_array: for (int m = 0; m < block_size; m++) {
    #pragma HLS UNROLL
        for (int n = 0; n < block_size; n++) {
        #pragma HLS UNROLL
            PE_8_8(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], seq_num);
        }
    }

    data_drain_AB:for (int k = 0; k < seq_num; k++) {
    #pragma HLS PIPELINE II=1
        for (int m = 0; m < block_size; m++) {
            A_fifo[m][block_size].read();
        }
        for (int n = 0; n < block_size; n++) {
            B_fifo[n][block_size].read();
        }
    }

    data_drain_C: for (int n = 0; n < block_size; n++) {
    #pragma HLS PIPELINE II=1
        io_pack_int24 C_temp;
        for (int m = 0; m < block_size; m++) {
            C_temp.range(m*24 + 23, m*24) = C[m][n];
        }
        C_drainer.write(C_temp);
    }
}

void systolic_array_k_1024_double_r2(
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
			PE_8_4_pack_r2(A_fifo[m][n], A_fifo[m][n+1], B_fifo[n][m], B_fifo[n][m+1], C[m][n], inp_len);
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

void Attention_layer(
    hls::stream<io_pack_int8>& inp,
    io_pack_int8 B[pack_seq_num][inp_len], 
    const float s[seq_num],
    hls::stream<io_pack_float>& outp
){
    io_pack_int8 A[head_len];
    #pragma HLS array_partition variable=A cyclic factor=2

    hls::stream<io_pack_int8> block_A_loader;
    hls::stream<io_pack_int8> block_B_loader;
    #pragma HLS STREAM variable=block_A_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_A_loader type=fifo impl=srl
    #pragma HLS STREAM variable=block_B_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_B_loader type=fifo impl=srl

    hls::stream<io_pack_int24> block_C_drainer;
    #pragma HLS STREAM variable=block_C_drainer depth=4
    #pragma HLS BIND_STORAGE variable=block_C_drainer type=fifo impl=srl
    
    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
    #pragma HLS DATAFLOW
        int ps_offset = ps_id * inp_num;
        l_multi_head: for (int h = 0; h < head_num; h++){
        #pragma HLS DATAFLOW
            init_inp_buf: for (int j = 0; j < head_len; j++) {    // L19
            #pragma HLS pipeline II=1
                A[j] = inp.read();
            }

            block_gemm:
            for(int jj = 0; jj < pack_seq_num; jj++){
            #pragma HLS DATAFLOW

                init_block_AB:
                for(int k = 0; k < head_len; k++){
                #pragma HLS PIPELINE II=1
                    block_A_loader.write(A[k]);
                    block_B_loader.write(B[jj][h * head_len + k]);
                }

                systolic_array_k_attn(block_A_loader, block_B_loader, block_C_drainer);

                io_pack_float outp_data_pack;
                l_bias_scale_j: for (int j = 0; j < block_size; j++) {    // L41
                #pragma HLS pipeline II=1
                    io_pack_int24 acc_temp = block_C_drainer.read();
                    l_bias_scale_i: for (int i = 0; i < block_size; i++) {    // L40
                        int24_t outp_temp = acc_temp.range(i*24 + 23, i*24);
                        converter_t outp;
                        outp.f = outp_temp / 8.0 * s[ps_offset + i];
                        outp_data_pack.range(i*32 + 31, i*32) = outp.i;
                    }
                    outp.write(outp_data_pack);
                }
            }
        }
    }
}


void Context_layer(
    hls::stream<io_pack_int8>& inp, 
    io_pack_int8 B[seq_num][pack_inp_len], 
    const float s[seq_num],
    hls::stream<io_pack_int8>& outp
){
    io_pack_int8 A[seq_num]; 

    hls::stream<io_pack_int8> block_A_loader;
    hls::stream<io_pack_int8> block_B_loader;
    #pragma HLS STREAM variable=block_A_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_A_loader type=fifo impl=srl
    #pragma HLS STREAM variable=block_B_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_B_loader type=fifo impl=srl

    hls::stream<io_pack_int24> block_C_drainer;
    #pragma HLS STREAM variable=block_C_drainer depth=4
    #pragma HLS BIND_STORAGE variable=block_C_drainer type=fifo impl=srl

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
    #pragma HLS DATAFLOW
        int ps_offset = ps_id * inp_num;
        l_multi_head: for (int h = 0; h < head_num; h++){
        #pragma HLS DATAFLOW
            init_inp_buf: for (int j = 0; j < seq_num; j++) {    // L19
            #pragma HLS pipeline II=1
                A[j] = inp.read();
            }

            block_gemm:
            for(int jj = 0; jj < pack_head_len; jj++){
            #pragma HLS DATAFLOW

                init_block_AB:
                for(int k = 0; k < seq_num; k++){
                #pragma HLS PIPELINE II=1
                    block_A_loader.write(A[k]);
                    block_B_loader.write(B[k][h * pack_head_len + jj]);
                }

                systolic_array_k_cont(block_A_loader, block_B_loader, block_C_drainer);

                io_pack_int8 outp_data_pack;
                l_bias_scale_j: for (int j = 0; j < block_size; j++) {    // L41
                #pragma HLS pipeline II=1
                    io_pack_int24 acc_temp = block_C_drainer.read();
                    l_bias_scale_i: for (int i = 0; i < block_size; i++) {    // L40
                        int24_t outp_temp = acc_temp.range(i*24 + 23, i*24);
                        int8_t outp = outp_temp * s[ps_offset + i];
                        outp_data_pack.range(i*8 + 7, i*8) = outp;
                    }
                    outp.write(outp_data_pack);
                }
            }
        }
    }
}

void Linear_layer_ds0(
    hls::stream<io_pack_int8>& inp,
    hls::stream<io_pack_int8> block_B_loader[2], 
    const float s[seq_num],
    hls::stream<double_io_pack_float>& outp
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

            systolic_array_k_1024_double_r2(block_A_loader, block_B_loader, block_C_drainer);

            io_pack_float outp_data_pack_0;
            io_pack_float outp_data_pack_1;
            double_io_pack_float outp_data_pack;
            l_bias_scale_j: for (int j = 0; j < block_size*2; j++) {    // L41
            #pragma HLS pipeline II=1
                io_pack_int48 acc_temp = block_C_drainer.read();
                l_bias_scale_i: for (int i = 0; i < block_size; i++) {    // L40
                    int48_t outp_temp = acc_temp.range(i*48 + 47, i*48);
                    int24_t outp0_dp = outp_temp.range(47, 24);
                    int24_t outp1_dp = outp_temp.range(23, 0);
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
  bus_pack_int8 *w_ds0_addr,
  hls::stream<io_pack_int8> w_ds0_loader[2]
){
  #pragma HLS DATAFLOW
    l_pack_seq_ds0: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
        block_w_ds0_load: for(int jj = 0; jj < pack_inp_len_half / 2; jj++){
            for(int k = 0; k < inp_len; k++){
            #pragma HLS PIPELINE II=1
            bus_pack_int8 w_temp = w_ds0_addr[jj * inp_len + k];
            w_ds0_loader[0].write(w_temp.range(63, 0));
            w_ds0_loader[1].write(w_temp.range(127, 64));
            }
        }
    }
}

void K_writer(
    hls::stream<double_pkt_int8>& inp,
    io_pack_int8 K[pack_seq_num][inp_len]
){  
    double_io_pack_int8 data_pack;
    io_pack_int8 buf[inp_len];
    #pragma HLS array_partition variable=buf cyclic factor=2

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
        l_buf: for (int j = 0; j < inp_len/2; j++) {
        #pragma HLS pipeline II=1
            data_pack = inp.read().data;
            buf[2 * j] = data_pack.range(63, 0);
            buf[2 * j + 1] = data_pack.range(127, 64);
        }

        l_write_j: for (int j = 0; j < inp_len; j++) {
        #pragma HLS pipeline II=1
            K[ps_id][j] = buf[j];
        }
    }
}

void V_writer(
    hls::stream<double_pkt_int8>& inp,
    io_pack_int8 V[seq_num][pack_inp_len]
){
    double_io_pack_int8 data_pack;
    io_pack_int8 buf[inp_len];
    #pragma HLS array_partition variable=buf cyclic factor=2

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
        l_buf: for (int j = 0; j < inp_len/2; j++) {
        #pragma HLS pipeline II=1
            data_pack = inp.read().data;
            buf[2 * j] = data_pack.range(63, 0);
            buf[2 * j + 1] = data_pack.range(127, 64);
        }

        l_write_j: for (int j = 0; j < inp_len; j++) {
        #pragma HLS pipeline II=4
            l_write_i: for (int i = 0; i < inp_num; i++) {
                V[ps_id * inp_num + i][j / inp_num].range((j % inp_num)*8 + 7, (j % inp_num)*8) = buf[j];
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

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
        l_buf: for (int j = 0; j < inp_len/2; j++) {
        #pragma HLS pipeline II=1
            data_pack = inp.read().data;
            buf[2 * j] = data_pack.range(63, 0);
            buf[2 * j + 1] = data_pack.range(127, 64);
        }

        l_write_j: for (int j = 0; j < inp_len; j++) {
        #pragma HLS pipeline II=1
            outp.write(buf[j]);
        }
    }
}

void Mask_layer(
    hls::stream<io_pack_float>& inp,
    hls::stream<io_pack_float>& outp
){
    io_pack_float inp_data_pack;
    io_pack_float outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
        l_multi_head: for (int h = 0; h < head_num; h++){
            l_j20: for (int j20 = 0; j20 < seq_num; j20++) {       // L323
            #pragma HLS pipeline II=1
                inp_data_pack = inp.read();
                l_i20: for (int i20 = 0; i20 < inp_num; i20++) {   // L322
                converter_t inp_data;
                inp_data.i = inp_data_pack.range(i20*32 + 31, i20*32);      // L324
                if(j20 > ps_id * inp_num + i20){
                    inp_data.f = -1e10; 
                }
                outp_data_pack.range(i20*32 + 31, i20*32) = inp_data.i;
                }
                outp.write(outp_data_pack);
            }
        }
    }
}

void Softmax_layer(
    hls::stream<io_pack_float>& inp,
    const float s[seq_num],
    hls::stream<io_pack_int8>& outp
) {     // L86
    float buf[inp_num][seq_num];
    #pragma HLS array_partition variable=buf complete dim=1

    float inp_sumRow[inp_num] ={0};
    #pragma HLS array_partition variable=inp_sumRow complete dim=1

    io_pack_float inp_data_pack;
    io_pack_int8 outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
        l_multi_head: for (int h = 0; h < head_num; h++){
            l_exp_sum_j6: for (int j6 = 0; j6 < seq_num; j6++) {     // L92
            #pragma HLS pipeline II=1
                inp_data_pack = inp.read();
                l_exp_sum_i6: for (int i6 = 0; i6 < inp_num; i6++) {       // L91
                    converter_t data_temp;
                    data_temp.i = inp_data_pack.range(i6*32 + 31, i6*32);
                    float v70 = exp(data_temp.f);     // L94
                    buf[i6][j6] = v70;        // L95
                    inp_sumRow[i6] += v70;     // L99
                }
            }

            l_j7: for (int j7 = 0; j7 < seq_num; j7++) {     // L103
            #pragma HLS pipeline II=1
                l_update_i7: for (int i7 = 0; i7 < inp_num; i7++) {        // L102
                    float v78 = buf[i7][j7] / inp_sumRow[i7];    // L106
                    int8_t v80 = v78 * s[ps_id * inp_num + i7];    // L108
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

    double_io_pack_float inp_data_pack_direct;
    io_pack_float buf_data_pack_direct;
    io_pack_float inp_data_pack_shortcut;
    io_pack_float outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
        l_buf: for (int j = 0; j < inp_len/2; j++) {
        #pragma HLS pipeline II=1
            inp_data_pack_direct = inp_direct.read();
            buf[2 * j] = inp_data_pack_direct.range(255, 0);
            buf[2 * j + 1] = inp_data_pack_direct.range(511, 256);
        }

        l_j13: for (int j13 = 0; j13 < inp_len; j13++) {        // L215
        #pragma HLS pipeline II=1
            buf_data_pack_direct = buf[j13];
            inp_data_pack_shortcut = inp_shortcut.read().data;
            l_i13: for (int i13 = 0; i13 < inp_num; i13++) {   // L214
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
    float buf[inp_num][inp_len];
    #pragma HLS array_partition variable=buf complete dim=1

    float mean[inp_num] = {0};       // L226
    float var[inp_num] = {0};        // L232

    io_pack_float inp_data_pack;
    io_pack_float outp_data_pack;

    l_pack_seq: for (int ps_id = 0; ps_id < pack_seq_num; ps_id++){
        l_mean_var_j14: for (int j14 = 0; j14 < inp_len; j14++) {        // L234
        #pragma HLS pipeline II=1
            inp_data_pack = inp.read();
            l_mean_var_i14: for (int i14 = 0; i14 < inp_num; i14++) {       // L233
            converter_t data_temp;
            data_temp.i = inp_data_pack.range(i14*32 + 31, i14*32);      // L235
            buf[i14][j14] = data_temp.f;
            mean[i14] += data_temp.f; // L238
            float v179 = data_temp.f * data_temp.f; // L241
            var[i14] += v179;        // L244
            }
        }

        l_mean_var_i15: for (int i15 = 0; i15 < inp_num; i15++) {
        #pragma HLS pipeline II=1
            mean[i15] /= 1024; 
            var[i15] = var[i15] / 1024 - mean[i15] * mean[i15]; 
        }
        
        l_j16: for (int j16 = 0; j16 < inp_len; j16++) {
        #pragma HLS pipeline II=1
            l_mean_var_i16: for (int i16 = 0; i16 < inp_num; i16++) {
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
    bus_pack_int8 *w_ds0_addr,
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

    io_pack_int8 K[pack_seq_num][inp_len];
    #pragma HLS BIND_STORAGE variable=K type=ram_2p impl=uram
    io_pack_int8 V[seq_num][pack_inp_len];
    #pragma HLS BIND_STORAGE variable=V type=ram_2p impl=uram

    #pragma HLS array_partition variable=buf21 cyclic factor=inp_parallel/2
    #pragma HLS array_partition variable=buf22 cyclic factor=inp_parallel/2
    #pragma HLS array_partition variable=buf23 cyclic factor=inp_parallel/2
    #pragma HLS array_partition variable=buf24 cyclic factor=inp_parallel/2

    hls::stream<io_pack_int8> inp_sfa;
    #pragma HLS STREAM variable=inp_sfa depth=4
    #pragma HLS BIND_STORAGE variable=inp_sfa type=fifo impl=srl
    hls::stream<io_pack_float> attn_outp;
    #pragma HLS STREAM variable=attn_outp depth=4
    #pragma HLS BIND_STORAGE variable=attn_outp type=fifo impl=srl
    hls::stream<io_pack_float> mask_outp;
    #pragma HLS STREAM variable=mask_outp depth=4
    #pragma HLS BIND_STORAGE variable=mask_outp type=fifo impl=srl
    hls::stream<io_pack_int8> sfm_outp;
    #pragma HLS STREAM variable=sfm_outp depth=128
    #pragma HLS BIND_STORAGE variable=sfm_outp type=fifo impl=uram
    hls::stream<io_pack_int8> outp_sfa;
    #pragma HLS STREAM variable=outp_sfa depth=4
    #pragma HLS BIND_STORAGE variable=outp_sfa type=fifo impl=srl
    
    hls::stream<double_io_pack_float> outp_ds0;
    #pragma HLS STREAM variable=outp_ds0 depth=4
    #pragma HLS BIND_STORAGE variable=outp_ds0 type=fifo impl=srl
    hls::stream<io_pack_float> outp_res0;
    #pragma HLS STREAM variable=outp_res0 depth=4
    #pragma HLS BIND_STORAGE variable=outp_res0 type=fifo impl=srl

    hls::stream<io_pack_int8> block_w_ds0_loader[2];
    #pragma HLS STREAM variable=block_w_ds0_loader depth=4
    #pragma HLS BIND_STORAGE variable=block_w_ds0_loader type=fifo impl=srl

    #pragma HLS DATAFLOW
    weight_ds0_loader(w_ds0_addr, block_w_ds0_loader);
    K_writer(outp_k, K);
    V_writer(outp_v, V);
    Q_buffer(outp_q, inp_sfa);

    Attention_layer(inp_sfa, K, buf21, attn_outp);
    Mask_layer(attn_outp, mask_outp);
    Softmax_layer(mask_outp, buf22, sfm_outp);
    Context_layer(sfm_outp, V, buf23, outp_sfa);

    Linear_layer_ds0(outp_sfa, block_w_ds0_loader, buf24, outp_ds0);
    Res_layer0(outp_ds0, outp_inp, outp_res0);
    Layer_norm0(outp_res0, buf13, buf14, outp_ln0);
}

} // extern "C"