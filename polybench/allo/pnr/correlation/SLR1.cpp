
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

void compute_stddev(
  float v10[260][240],
  float v11[240],
  float v13[240]
) {	// L22
#pragma HLS array_partition variable=v10 complete dim=1
  l_S_x_0_x1: for (int x1 = 0; x1 < 240; x1++) {	// L23
  #pragma HLS pipeline II=1
    float variance;	// L24
    variance = 0.000000;	// L26
    l_S_m_0_m: for (int m = 0; m < 260; m++) {	// L27
      float v17 = v10[m][x1];	// L28
      float v18 = v11[x1];	// L29
      float v19 = v17 - v18;	// L30
      float v20 = v19 * v19;	// L34
      float v21 = variance;	// L35
      float v22 = v21 + v20;	// L36
      variance = v22;	// L37
    }
    float v23 = variance;	// L39
    float v24 = v23 / 260.000000;	// L41
    float v25 = sqrt(v24);	// L42
    v13[x1] = v25;	// L43
  }
}



void kernel_correlation(
  float v56[260][240],
  float mean[240],
  float stddev[240]
) {	// L96
  compute_stddev(v56, mean, stddev);	// L101
}

