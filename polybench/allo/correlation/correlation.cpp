
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
void compute_mean(
  float v0[260][240],
  // float v1[240]
  hls::stream<float > &v1
) {	// L3
#pragma HLS array_partition variable=v0 complete dim=1
  l_S_x_0_x: for (int x = 0; x < 240; x++) {	// L4
  #pragma HLS pipeline II=1
    float total;	// L5
    total = 0.000000;	// L7
    l_S_k_0_k: for (int k = 0; k < 260; k++) {	// L8
      float v5 = v0[k][x];	// L9
      float v6 = total;	// L10
      float v7 = v6 + v5;	// L11
      total = v7;	// L12
    }
    float v8 = total;	// L16
    float v9 = v8 / 260.000000;	// L17
    // v1[x] = v9;	// L18
    v1.write(v9);
  }
}

void compute_stddev(
  float v10[260][240],
  // float v11[240],
  // float v12[240],
  hls::stream<float > &v11,
  hls::stream<float > &v12,
  // float v13[240]
  hls::stream<float > &v13
) {	// L22
#pragma HLS array_partition variable=v10 complete dim=1
  l_S_x_0_x1: for (int x1 = 0; x1 < 240; x1++) {	// L23
  #pragma HLS pipeline II=1
    float variance;	// L24
    variance = 0.000000;	// L26
    float v18 = v11.read();	// L27
    l_S_m_0_m: for (int m = 0; m < 260; m++) {	// L27
      float v17 = v10[m][x1];	// L28
      // float v18 = v11[x1];	// L29
      float v19 = v17 - v18;	// L30
      float v20 = v19 * v19;	// L34
      float v21 = variance;	// L35
      float v22 = v21 + v20;	// L36
      variance = v22;	// L37
    }
    float v23 = variance;	// L39
    float v24 = v23 / 260.000000;	// L41
    float v25 = sqrt(v24);	// L42
    // v13[x1] = v25;	// L43
    v13.write(v25);
    // float v26 = v11[x1];	// L44
    // v12[x1] = v26;	// L45
    v12.write(v18);
  }
}

void center_reduce(
  float v27[260][240],
  float v28[260][240],
  // float v29[240],
  // float v30[240]
  hls::stream<float > &v29,
  hls::stream<float > &v30
) {	// L49
#pragma HLS array_partition variable=v27 complete dim=1
#pragma HLS array_partition variable=v28 complete dim=1
  l_S_y_0_y: for (int y = 0; y < 240; y++) {	// L50
  #pragma HLS pipeline II=1
    float v35 = v29.read();	// L51
    float v38 = v30.read();	// L62
    l_S_x_0_x2: for (int x2 = 0; x2 < 260; x2++) {	// L51
      float v33 = v27[x2][y];	// L52
      float d;	// L53
      d = v33;	// L54
      // float v35 = v29[y];	// L55
      float v36 = d;	// L56
      float v37 = v36 - v35;	// L57
      d = v37;	// L58
      // float v38 = v30[y];	// L62
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
  float v55[260][240],
  float v56[260][240],
  float v57[260][240],
  float v58[240][240]
) {	// L96
#pragma HLS dataflow
  // float mean[240];	// L97
  // float mean_passed_on[240];	// L98
  // float stddev[240];	// L99
  hls::stream<float > mean;
  #pragma HLS stream variable=mean depth=240
  hls::stream<float > mean_passed_on;
  #pragma HLS stream variable=mean_passed_on depth=240
  hls::stream<float > stddev;
  #pragma HLS stream variable=stddev depth=240
  compute_mean(v55, mean);	// L100
  compute_stddev(v56, mean, mean_passed_on, stddev);	// L101
  float data_centered[260][240];	// L102
  center_reduce(v57, data_centered, mean_passed_on, stddev);	// L103
  compute_corr(data_centered, v58);	// L104
}

