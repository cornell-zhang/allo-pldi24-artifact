
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
void stageA(
  float v0[400],
  float v1[400],
  float v2[400][400],
  float v3[400]
) {	// L5
  #pragma HLS array_partition variable=v2 complete dim=2

  #pragma HLS array_partition variable=v3 complete dim=1

  l_A_i0: for (int i0 = 0; i0 < 400; i0++) {	// L6
  #pragma HLS pipeline II=1
    float v5 = v0[i0];	// L7
    float x;	// L8
    x = v5;	// L9
    l_S_j0_0_j0: for (int j0 = 0; j0 < 400; j0++) {	// L10
      float v8 = v2[i0][j0];	// L11
      float v9 = v3[j0];	// L12
      float v10 = v8 * v9;	// L13
      float v11 = x;	// L14
      float v12 = v11 + v10;	// L15
      x = v12;	// L16
    }
    float v13 = x;	// L18
    v1[i0] = v13;	// L19
  }
}

void stageB(
  float v14[400],
  float v15[400],
  float v16[400][400],
  float v17[400]
) {	// L23
  #pragma HLS array_partition variable=v16 complete dim=1

  #pragma HLS array_partition variable=v17 complete dim=1

  l_B_i1: for (int i1 = 0; i1 < 400; i1++) {	// L24
  #pragma HLS pipeline II=1
    float v19 = v14[i1];	// L25
    float x1;	// L26
    x1 = v19;	// L27
    l_S_j1_0_j1: for (int j1 = 0; j1 < 400; j1++) {	// L28
      float v22 = v16[j1][i1];	// L29
      float v23 = v17[j1];	// L30
      float v24 = v22 * v23;	// L31
      float v25 = x1;	// L32
      float v26 = v25 + v24;	// L33
      x1 = v26;	// L34
    }
    float v27 = x1;	// L36
    v15[i1] = v27;	// L37
  }
}

void kernel_mvt(
  float v28[400][400],
  float v29[400][400],
  float v30[400],
  float v31[400],
  float v32[400],
  float v33[400],
  float v34[400],
  float v35[400]
) {	// L41
  #pragma HLS array_partition variable=v28 complete dim=2

  #pragma HLS array_partition variable=v29 complete dim=1

  #pragma HLS array_partition variable=v30 complete dim=1

  #pragma HLS array_partition variable=v31 complete dim=1

  #pragma HLS dataflow

  stageA(v32, v34, v28, v30);	// L42
  stageB(v33, v35, v29, v31);	// L43
}

