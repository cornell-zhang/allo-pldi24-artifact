
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
void compute_A(
  float v0[250][250],
  float v1[250][250]
) {	// L5
  #pragma HLS array_partition variable=v0 complete dim=2

  #pragma HLS array_partition variable=v1 complete dim=2

  float A_reuse_0[3][250];	// L6
  #pragma HLS array_partition variable=A_reuse_0 complete dim=1
  #pragma HLS array_partition variable=A_reuse_0 complete dim=2

  float A_reuse_1[3][3];	// L7
  #pragma HLS array_partition variable=A_reuse_1 complete dim=1
  #pragma HLS array_partition variable=A_reuse_1 complete dim=2

  l_A_i0: for (int i0 = 0; i0 < 250; i0++) {	// L8
  #pragma HLS pipeline II=1
    l_j0: for (int j0 = 0; j0 < 250; j0++) {	// L9
      float v6 = A_reuse_0[1][j0];	// L10
      A_reuse_0[0][j0] = v6;	// L11
      float v7 = A_reuse_0[2][j0];	// L12
      A_reuse_0[1][j0] = v7;	// L13
      float v8 = v0[i0][j0];	// L14
      A_reuse_0[2][j0] = v8;	// L15
      if ((i0 - 2) >= 0) {	// L16
        for (int v9 = 0; v9 < 3; v9++) {	// L17
          float v10 = A_reuse_1[v9][1];	// L18
          A_reuse_1[v9][0] = v10;	// L19
          float v11 = A_reuse_1[v9][2];	// L20
          A_reuse_1[v9][1] = v11;	// L21
          float v12 = A_reuse_0[v9][j0];	// L22
          A_reuse_1[v9][2] = v12;	// L23
        }
        if ((j0 - 2) >= 0) {	// L25
          float v13 = A_reuse_1[1][0];	// L26
          float v14 = A_reuse_1[0][1];	// L27
          float v15 = v13 + v14;	// L28
          float v16 = A_reuse_1[1][1];	// L29
          float v17 = v15 + v16;	// L30
          float v18 = A_reuse_1[2][1];	// L31
          float v19 = v17 + v18;	// L32
          float v20 = A_reuse_1[1][2];	// L33
          float v21 = v19 + v20;	// L34
          float v22 = v21 * 0.200000;	// L36
          v1[(i0 - 2)][(j0 - 2)] = v22;	// L37
        }
      }
    }
  }
}

void compute_B(
  float v23[250][250],
  float v24[250][250]
) {	// L44
  #pragma HLS array_partition variable=v23 complete dim=2

  #pragma HLS array_partition variable=v24 complete dim=2

  float B_reuse_0[3][250];	// L45
  #pragma HLS array_partition variable=B_reuse_0 complete dim=1
  #pragma HLS array_partition variable=B_reuse_0 complete dim=2

  float B_reuse_1[3][3];	// L46
  #pragma HLS array_partition variable=B_reuse_1 complete dim=1
  #pragma HLS array_partition variable=B_reuse_1 complete dim=2

  l_B_i1: for (int i1 = 0; i1 < 250; i1++) {	// L47
  #pragma HLS pipeline II=1
    l_j1: for (int j1 = 0; j1 < 250; j1++) {	// L48
      float v29 = B_reuse_0[1][j1];	// L49
      B_reuse_0[0][j1] = v29;	// L50
      float v30 = B_reuse_0[2][j1];	// L51
      B_reuse_0[1][j1] = v30;	// L52
      float v31 = v23[i1][j1];	// L53
      B_reuse_0[2][j1] = v31;	// L54
      if ((i1 - 2) >= 0) {	// L55
        for (int v32 = 0; v32 < 3; v32++) {	// L56
          float v33 = B_reuse_1[v32][1];	// L57
          B_reuse_1[v32][0] = v33;	// L58
          float v34 = B_reuse_1[v32][2];	// L59
          B_reuse_1[v32][1] = v34;	// L60
          float v35 = B_reuse_0[v32][j1];	// L61
          B_reuse_1[v32][2] = v35;	// L62
        }
        if ((j1 - 2) >= 0) {	// L64
          float v36 = B_reuse_1[1][0];	// L65
          float v37 = B_reuse_1[0][1];	// L66
          float v38 = v36 + v37;	// L67
          float v39 = B_reuse_1[1][1];	// L68
          float v40 = v38 + v39;	// L69
          float v41 = B_reuse_1[2][1];	// L70
          float v42 = v40 + v41;	// L71
          float v43 = B_reuse_1[1][2];	// L72
          float v44 = v42 + v43;	// L73
          float v45 = v44 * 0.200000;	// L75
          v24[(i1 - 1)][(j1 - 1)] = v45;	// L76
        }
      }
    }
  }
}

void kernel_jacobi_2d(
  float v46[250][250],
  float v47[250][250]
) {	// L83
  #pragma HLS array_partition variable=v46 complete dim=2

  #pragma HLS array_partition variable=v47 complete dim=2

  l_S_m_0_m: for (int m = 0; m < 100; m++) {	// L84
    compute_A(v46, v47);	// L85
    compute_B(v47, v46);	// L86
  }
}

