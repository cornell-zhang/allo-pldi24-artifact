
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//
#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
using namespace std;
void compute_sum(
  float v0[200][200],
  float v1[200][240],
  float v2[200][240]
) {	// L4
  #pragma HLS inline off
  #pragma HLS array_partition variable=v1 cyclic factor=30 dim=2
  #pragma HLS array_partition variable=v2 cyclic factor=30 dim=2

  l_sum_i1: for (int i1 = 0; i1 < 200; i1++) {	// L5
    float v4[240];	// L6
    #pragma HLS array_partition variable=v4 cyclic factor=30 dim=1
    l_j1_init: for (int j1_init = 0; j1_init < 240; j1_init++) {	// L8
    #pragma HLS pipeline II=1
    #pragma HLS unroll factor=30
      v4[j1_init] = 0.000000;	// L9
    }
    l_k1_k1: for (int k1 = 0; k1 < 200; k1++) {	// L11
      l_j1: for (int j1 = 0; j1 < 240; j1++) {	// L12
      #pragma HLS pipeline II=1
      #pragma HLS unroll factor=30
        bool v8 = k1 < i1;	// L13
        if (v8) {	// L14
          float v9 = v1[k1][j1];	// L15
          float v10 = v0[i1][k1];	// L16
          float v11 = v9 * v10;	// L17
          float v12 = v4[j1];	// L18
          float v13 = v12 + v11;	// L19
          v4[j1] = v13;	// L20
        }
      }
    }
    l_j1_back: for (int j1_back = 0; j1_back < 240; j1_back++) {	// L24
    #pragma HLS pipeline II=1
    #pragma HLS unroll factor=30
      float v15 = v4[j1_back];	// L25
      v2[i1][j1_back] = v15;	// L26
    }
  }
}

void update_C(
  float v16[200][200],
  float v17[200][240],
  float v18[200][240],
  float v19[200][240]
) {	// L31
  #pragma HLS array_partition variable=v17 complete dim=2

  #pragma HLS array_partition variable=v18 complete dim=2

  #pragma HLS array_partition variable=v19 complete dim=2

  l_S_i_0_i: for (int i = 0; i < 200; i++) {	// L32
    l_S_k_0_k: for (int k = 0; k < i; k++) {	// L33
    #pragma HLS pipeline II=1
      l_S_j_0_j: for (int j = 0; j < 240; j++) {	// L34
        float v23 = v19[k][j];	// L35
        float v24 = v17[i][j];	// L36
        float v25 = v24 * 1.500000;	// L38
        float v26 = v16[i][k];	// L39
        float v27 = v25 * v26;	// L40
        float v28 = v23 + v27;	// L41
        v19[k][j] = v28;	// L42
      }
    }
    l_S_j1_2_j11: for (int j11 = 0; j11 < 240; j11++) {	// L45
    #pragma HLS pipeline II=1
      float v30 = v19[i][j11];	// L46
      float v31 = v30 * 1.200000;	// L48
      float v32 = v17[i][j11];	// L49
      float v33 = v32 * 1.500000;	// L51
      float v34 = v16[i][i];	// L52
      float v35 = v33 * v34;	// L53
      float v36 = v31 + v35;	// L54
      float v37 = v18[i][j11];	// L55
      float v38 = v37 * 1.500000;	// L56
      float v39 = v36 + v38;	// L57
      v19[i][j11] = v39;	// L58
    }
  }
}

void kernel_symm(
  float v41[200][200],
  float v43[200][240],
  float v44[200][240],
  float summ[200][240]
) {	// L63
  #pragma HLS array_partition variable=v43 complete dim=2
  #pragma HLS array_partition variable=v44 complete dim=2

  update_C(v41, v43, summ, v44);	// L66
}

