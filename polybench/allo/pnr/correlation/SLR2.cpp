
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

void center_reduce(
  float v27[260][240],
  float v28[260][240],
  float v29[240],
  float v30[240]
) {	// L49
#pragma HLS array_partition variable=v27 complete dim=1
#pragma HLS array_partition variable=v28 complete dim=1
  l_S_y_0_y: for (int y = 0; y < 240; y++) {	// L50
  #pragma HLS pipeline II=1
    l_S_x_0_x2: for (int x2 = 0; x2 < 260; x2++) {	// L51
      float v33 = v27[x2][y];	// L52
      float d;	// L53
      d = v33;	// L54
      float v35 = v29[y];	// L55
      float v36 = d;	// L56
      float v37 = v36 - v35;	// L57
      d = v37;	// L58
      float v38 = v30[y];	// L62
      float v39 = v38 * 16.124516;	// L63
      float v40 = d;	// L64
      float v41 = v40 / v39;	// L65
      d = v41;	// L66
      float v42 = d;	// L67
      v28[x2][y] = v42;	// L68
    }
  }
}

void compute_corr(
  float v43[260][240],
  float v44[240][240]
) {	// L73
#pragma HLS array_partition variable=v43 complete dim=1
  corr_i: for (int i = 0; i < 239; i++) {	// L74
    v44[i][i] = 1.000000;	// L76
    // corr_j: for (int j = 0; j < (239 - i); j++) {	// L77
    // #pragma HLS loop_tripcount min=119 max=119
    corr_j: for (int j = 0; j < 239; j++) {	// L77
      #pragma HLS pipeline II=1
      if (j < (239 - i)) {
        int v47 = ((i + j) + 1);	// L77
        float v44_i_v47 = 0.000000;	// L79
        corr_k: for (int k1 = 0; k1 < 260; k1++) {	// L80
          float v49 = v43[k1][i];	// L81
          float v50 = v43[k1][v47];	// L82
          float v51 = v49 * v50;	// L83
          v44_i_v47 += v51;
        }
        v44[v47][i] = v44_i_v47;	// L86
      }
    }
  }
  v44[239][239] = 1.000000;	// L93
}

void kernel_correlation(
  float mean_passed_on[240],
  float stddev[240],
  float v57[260][240],
  float v58[240][240]
) {	// L96
  float data_centered[260][240];	// L102
  center_reduce(v57, data_centered, mean_passed_on, stddev);	// L103
  compute_corr(data_centered, v58);	// L104
}

