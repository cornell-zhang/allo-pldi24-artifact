
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
  float v1[240]
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
    v1[x] = v9;	// L18
  }
}

void kernel_correlation(
  float v55[260][240],
  float mean[240]
) {	// L96
  compute_mean(v55, mean);	// L100
}

