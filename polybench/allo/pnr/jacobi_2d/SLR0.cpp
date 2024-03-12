
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
  #pragma HLS inline off
  // #pragma HLS array_partition variable=v0 complete dim=2
  #pragma HLS array_partition variable=v0 cyclic factor=50 dim=2

  #pragma HLS array_partition variable=v1 complete dim=2

  float A_reuse_0[3][250];	// L6
  #pragma HLS array_partition variable=A_reuse_0 complete dim=1
  // #pragma HLS array_partition variable=A_reuse_0 complete dim=2
  #pragma HLS array_partition variable=A_reuse_0 cyclic factor=50 dim=2

  float A_reuse_1[3][3];	// L7
  #pragma HLS array_partition variable=A_reuse_1 complete dim=1
  #pragma HLS array_partition variable=A_reuse_1 complete dim=2

  l_A_i0: for (int i0 = 0; i0 < 250; i0++) {	// L8
    l_j0: for (int j0 = 0; j0 < 250; j0++) {	// L9
    #pragma HLS pipeline II=1
    #pragma HLS unroll factor=50
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


void kernel_jacobi_2d(
  float v46[250][250],
  float v47[250][250]
) {	// L83
  l_S_m_0_m: for (int m = 0; m < 100; m++) {	// L84
    compute_A(v46, v47);	// L85
  }
}

