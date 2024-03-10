
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
  float v0[260][240],
  float v1[240],
  float v2[240],
  float v3[240][240]
) {	// L3
  l_S_x_0_x: for (int x = 0; x < 240; x++) {	// L4
    float total;	// L5
    total = 0.000000;	// L7
    l_S_k_0_k: for (int k = 0; k < 260; k++) {	// L8
    #pragma HLS pipeline II=1
      float v7 = v0[k][x];	// L9
      float v8 = total;	// L10
      float v9 = v8 + v7;	// L11
      total = v9;	// L12
    }
    float v10 = total;	// L16
    float v11 = v10 / 260.000000;	// L17
    v1[x] = v11;	// L18
  }
  l_S_x_2_x1: for (int x1 = 0; x1 < 240; x1++) {	// L20
    float variance;	// L21
    variance = 0.000000;	// L23
    l_S_m_2_m: for (int m = 0; m < 260; m++) {	// L24
        #pragma HLS pipeline II=1

      float v15 = v0[m][x1];	// L25
      float v16 = v1[x1];	// L26
      float v17 = v15 - v16;	// L27
      float v18 = v17 * v17;	// L31
      float v19 = variance;	// L32
      float v20 = v19 + v18;	// L33
      variance = v20;	// L34
    }
    float v21 = variance;	// L36
    float v22 = v21 / 260.000000;	// L38
    float v23 = sqrt(v22);	// L39
    v2[x1] = v23;	// L40
  }
  l_S_x_4_x2: for (int x2 = 0; x2 < 260; x2++) {	// L42
    l_S_y_4_y: for (int y = 0; y < 240; y++) {	// L43
        #pragma HLS pipeline II=1

      float v26 = v1[y];	// L44
      float v27 = v0[x2][y];	// L45
      float v28 = v27 - v26;	// L46
      v0[x2][y] = v28;	// L47
      float v29 = v2[y];	// L51
      float v30 = v29 * 16.124516;	// L52
      float v31 = v0[x2][y];	// L53
      float v32 = v31 / v30;	// L54
      v0[x2][y] = v32;	// L55
    }
  }
  l_S_i_6_i: for (int i = 0; i < 239; i++) {	// L58
    v3[i][i] = 1.000000;	// L60
    l_S_j_6_j: for (int j = 0; j < ((-i) + 239); j++) {	// L61
        #pragma HLS pipeline II=1
      int v35 = ((i + j) + 1);	// L61
      v3[i][v35] = 0.000000;	// L63
      l_S_k_6_k1: for (int k1 = 0; k1 < 260; k1++) {	// L64
        float v37 = v0[k1][i];	// L65
        float v38 = v0[k1][v35];	// L66
        float v39 = v37 * v38;	// L67
        float v40 = v3[i][v35];	// L68
        float v41 = v40 + v39;	// L69
        v3[i][v35] = v41;	// L70
      }
      float v42 = v3[i][v35];	// L72
      v3[v35][i] = v42;	// L73
    }
  }
  v3[239][239] = 1.000000;	// L77
}

