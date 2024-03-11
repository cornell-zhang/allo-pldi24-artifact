
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
  float v1[200][240],
  float v2[200][240],
  float v3[200][240]
) {	// L3
  #pragma HLS array_partition variable=v1 complete dim=2

  #pragma HLS array_partition variable=v2 complete dim=2

  #pragma HLS array_partition variable=v3 complete dim=2

  float buffer[200][240];	// L4
  #pragma HLS array_partition variable=buffer complete dim=2

  l_load_i0: for (int i0 = 0; i0 < 200; i0++) {	// L5
  #pragma HLS pipeline II=1
    l_j0: for (int j0 = 0; j0 < 240; j0++) {	// L6
      float v7 = v1[i0][j0];	// L7
      buffer[i0][j0] = v7;	// L8
    }
  }
  l_update_i1: for (int i1 = 0; i1 < 200; i1++) {	// L11
    l_k1: for (int k1 = 0; k1 < 200; k1++) {	// L12
    #pragma HLS pipeline II=1
      l_j1: for (int j1 = 0; j1 < 240; j1++) {	// L13
        bool v11 = k1 <= i1;	// L14
        if (v11) {	// L15
          float v12 = v0[i1][k1];	// L16
          float v13 = v2[i1][j1];	// L17
          float v14 = v12 * v13;	// L18
          float v15 = buffer[k1][j1];	// L19
          float v16 = v15 + v14;	// L20
          buffer[k1][j1] = v16;	// L21
        }
      }
    }
  }
  l_store_i2: for (int i2 = 0; i2 < 200; i2++) {	// L26
  #pragma HLS pipeline II=1
    l_j2: for (int j2 = 0; j2 < 240; j2++) {	// L27
      float v19 = buffer[i2][j2];	// L28
      v3[i2][j2] = v19;	// L29
    }
  }
}

void S1(
  float v20[200][240],
  float v21[200][240]
) {	// L34
  #pragma HLS array_partition variable=v20 complete dim=2

  #pragma HLS array_partition variable=v21 complete dim=2

  l_mul_i01: for (int i01 = 0; i01 < 200; i01++) {	// L35
  #pragma HLS pipeline II=1
    l_j01: for (int j01 = 0; j01 < 240; j01++) {	// L36
      float v24 = v20[i01][j01];	// L37
      float v25 = v24 * 1.500000;	// L39
      v21[i01][j01] = v25;	// L40
    }
  }
}

void kernel_trmm(
  float v26[200][200],
  float v27[200][240],
  float v28[200][240],
  float v29[200][240]
) {	// L45
#pragma HLS dataflow

  #pragma HLS array_partition variable=v27 complete dim=2

  #pragma HLS array_partition variable=v28 complete dim=2

  #pragma HLS array_partition variable=v29 complete dim=2

  float B_buffer[200][240];	// L46
  #pragma HLS array_partition variable=B_buffer complete dim=2

  S0(v26, v27, v28, B_buffer);	// L47
  S1(B_buffer, v29);	// L48
}