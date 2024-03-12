
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
void S0(
  float v0[200][200],
  float v1[200][240]
) {	// L3
  #pragma HLS array_partition variable=v1 cyclic dim=2 factor=20

  l_update_i1: for (int i1 = 0; i1 < 200; i1++) {	// L4
    float v3[240];	// L5
    #pragma HLS array_partition variable=v3 cyclic dim=1 factor=20
    l_j1_init: for (int j1_init = 0; j1_init < 240; j1_init++) {	// L7
    #pragma HLS pipeline II=1
    #pragma HLS unroll factor=20
      v3[j1_init] = v1[i1][j1_init];	// L8
    }
    l_S_k1_0_k1: for (int k1 = 0; k1 < 200; k1++) {	// L10
      l_j1: for (int j1 = 0; j1 < 240; j1++) {	// L11
      #pragma HLS pipeline II=1
      #pragma HLS unroll factor=20
        bool v7 = k1 > i1;	// L12
        if (v7) {	// L13
          float v8 = v0[k1][i1];	// L14
          float v9 = v3[j1];	// L15
          float v10 = v8 * v9;	// L16
          float v11 = v9 + v10;	// L17
          v3[j1] = v11;	// L18
        }
      }
    }
    l_j1_back: for (int j1_back = 0; j1_back < 240; j1_back++) {	// L22
    #pragma HLS pipeline II=1
    #pragma HLS unroll factor=20
      float v13 = v3[j1_back];	// L23
      v1[i1][j1_back] = v13;	// L24
    }
  }
}

void S1(
  float v14[200][240]
) {	// L29
  #pragma HLS array_partition variable=v14 cyclic dim=2 factor=20

  l_mul_i0: for (int i0 = 0; i0 < 200; i0++) {	// L30
    l_j0: for (int j0 = 0; j0 < 240; j0++) {	// L31
    #pragma HLS pipeline II=1
    #pragma HLS unroll factor=20
      float v17 = v14[i0][j0];	// L32
      float v18 = v17 * 1.500000;	// L34
      v14[i0][j0] = v18;	// L35
    }
  }
}

void kernel_trmm(
  float v19[200][200],
  float v20[200][240]
) {	// L40
  #pragma HLS array_partition variable=v20 cyclic dim=2 factor=20

  S0(v19, v20);	// L41
  S1(v20);	// L42
}

