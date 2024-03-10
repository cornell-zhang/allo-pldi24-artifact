
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
void kernel(
  float v0[400][400],
  float v1[400],
  float v2[400],
  float v3[400],
  float v4[400]
) {	// L2
#pragma HLS array_partition variable=v0 complete dim=2
#pragma HLS array_partition variable=v1 complete dim=1
#pragma HLS array_partition variable=v4 complete dim=1
  l_S_i_j_0_i: for (int i = 0; i < 400; i++) {	// L3
  #pragma HLS pipeline II=1
    l_j: for (int j = 0; j < 400; j++) {	// L4
      float v7 = v0[i][j];	// L5
      float v8 = v1[j];	// L6
      float v9 = v7 * v8;	// L7
      float v10 = v3[i];	// L8
      float v11 = v10 + v9;	// L9
      v3[i] = v11;	// L10
    }
  }
 l_j1: for (int j1 = 0; j1 < 400; j1++) {	// L14 // reordered
 #pragma HLS pipeline II=1
  l_S_i_j_1_i1: for (int i1 = 0; i1 < 400; i1++) {	// L13
      float v14 = v0[j1][i1];	// L15
      float v15 = v2[j1];	// L16
      float v16 = v14 * v15;	// L17
      float v17 = v4[i1];	// L18
      float v18 = v17 + v16;	// L19
      v4[i1] = v18;	// L20
    }
  }
}

