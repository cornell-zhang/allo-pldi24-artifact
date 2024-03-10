
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
void stageS(
  float v0[410][390],
  float v1[410],
  float v2[390]
) {	// L5
  #pragma HLS array_partition variable=v0 complete dim=2
  #pragma HLS array_partition variable=v2 complete dim=1

  l_S_i0_0_i0: for (int i0 = 0; i0 < 410; i0++) {	// L6
    float v4 = v1[i0];	// L7
    float r;	// L8
    r = v4;	// L9
    l_S_j0_0_j0: for (int j0 = 0; j0 < 390; j0++) {	// L10
    #pragma HLS pipeline II=1
    #pragma HLS unroll factor=390
      float v7 = v0[i0][j0];	// L11
      float v8 = r;	// L12
      float v9 = v8 * v7;	// L13
      float v10 = v2[j0];	// L14
      float v11 = v10 + v9;	// L15
      v2[j0] = v11;	// L16
    }
  }
}

void stageQ(
  float v12[410][390],
  float v13[390],
  float v14[410]
) {	// L21
  #pragma HLS array_partition variable=v12 complete dim=1
  #pragma HLS array_partition variable=v14 complete dim=1

  l_S_i1_0_j1: for (int j1 = 0; j1 < 390; j1++) {	// L22
    l_i1: for (int i1 = 0; i1 < 410; i1++) {	// L23
    #pragma HLS pipeline II=1
    #pragma HLS unroll factor=410
      float v17 = v12[i1][j1];	// L24
      float v18 = v13[j1];	// L25
      float v19 = v17 * v18;	// L26
      float v20 = v14[i1];	// L27
      float v21 = v20 + v19;	// L28
      v14[i1] = v21;	// L29
    }
  }
}

void kernel(
  float v22[410][390],
  float v23[410][390],
  float v24[390],
  float v25[410],
  float v26[410],
  float v27[390]
) {	// L34

  stageS(v22, v25, v27);	// L35
  stageQ(v23, v24, v26);	// L36
}

