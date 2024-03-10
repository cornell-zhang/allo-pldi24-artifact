
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
void mm1(
  float v0[200][240]
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
void compute_tmp(
  float v0[250],
  float v1[250],
  float v2[250][250],
  float v3[250][250],
  float v4[250],
  float v5[250]
) {	// L2
#pragma HLS array_partition variable=v2 complete dim=1
#pragma HLS array_partition variable=v3 complete dim=1

  float tt[250];	// L3
  #pragma HLS array_partition variable=tt complete dim=0
  for (int v7 = 0; v7 < 250; v7++) {	// L5
  #pragma HLS unroll
    tt[v7] = 0.000000;	// L5
  }
  float yy[250];	// L6
  #pragma HLS array_partition variable=yy complete dim=0
  l_load_i0: for (int i0 = 0; i0 < 250; i0++) {	// L7
  #pragma HLS pipeline II=1
    float v10 = v0[i0];	// L8
    yy[i0] = v10;	// L9
  }
  l_tmp_j: for (int j = 0; j < 250; j++) {	// L11
  #pragma HLS pipeline II=1
    l_i: for (int i = 0; i < 250; i++) {	// L12
      float v13 = v2[i][j];	// L13
      float v14 = v4[j];	// L14
      float v15 = v13 * v14;	// L15
      float v16 = tt[i];	// L16
      float v17 = v16 + v15;	// L17
      tt[i] = v17;	// L18
      float v18 = v3[i][j];	// L19
      float v19 = v4[j];	// L20
      float v20 = v18 * v19;	// L21
      float v21 = yy[i];	// L22
      float v22 = v21 + v20;	// L23
      yy[i] = v22;	// L24
    }
  }
  l_store_i1: for (int i1 = 0; i1 < 250; i1++) {	// L27
    float v24 = tt[i1];	// L28
    v5[i1] = v24;	// L29
    float v25 = yy[i1];	// L30
    v1[i1] = v25;	// L31
  }
}

void compute_y(
  float v26[250],
  float v27[250],
  float v28[250]
) {	// L35
  l_load_i01: for (int i01 = 0; i01 < 250; i01++) {	// L36
  #pragma HLS pipeline II=1
    float v30 = v28[i01];	// L37
    float v31 = v30 * 0.100000;	// L39
    float v32 = v26[i01];	// L40
    float v33 = v32 * 0.100000;	// L41
    float v34 = v31 + v33;	// L42
    v27[i01] = v34;	// L43
  }
}

void kernel_gesummv(
  float v35[250][250],
  float v36[250][250],
  float v37[250],
  float v38[250]
) {	// L47
  float y_init[250];	// L48
  for (int v40 = 0; v40 < 250; v40++) {	// L50
    y_init[v40] = 0.000000;	// L50
  }
  float y_fifo[250];	// L51
  float tmp[250];	// L52
  compute_tmp(y_init, y_fifo, v35, v36, v37, tmp);	// L53
  compute_y(y_fifo, v38, tmp);	// L54
}

,
  float v1[240][220],
  float v2[200][220]
) {	// L2
#pragma HLS array_partition variable=v1 complete dim=2
  l_mm1_i0: for (int i0 = 0; i0 < 200; i0++) {	// L3
    float v4[220];	// L4
    #pragma HLS array_partition variable=v4 complete dim=1
    l_j0_init: for (int j0_init = 0; j0_init < 220; j0_init++) {	// L6
    // #pragma HLS pipeline II=1
    #pragma HLS unroll
      v4[j0_init] = 0.000000;	// L7
    }
    l_S_k0_0_k0: for (int k0 = 0; k0 < 240; k0++) {	// L9
    #pragma HLS pipeline II=1
      l_j0: for (int j0 = 0; j0 < 220; j0++) {	// L10
        float v8 = v0[i0][k0];	// L11
        float v9 = v1[k0][j0];	// L12
        float v10 = v8 * v9;	// L13
        float v11 = v4[j0];	// L14
        float v12 = v11 + v10;	// L15
        v4[j0] = v12;	// L16
      }
    }
    l_j0_back: for (int j0_back = 0; j0_back < 220; j0_back++) {	// L19
    // #pragma HLS pipeline II=1
    #pragma HLS unroll
      float v14 = v4[j0_back];	// L20
      v2[i0][j0_back] = v14;	// L21
    }
  }
}

void ele_add(
  float v15[200][220],
  float v16[200][220],
  float v17[200][220]
) {	// L26
#pragma HLS array_partition variable=v15 complete dim=2
#pragma HLS array_partition variable=v16 complete dim=2
#pragma HLS array_partition variable=v17 complete dim=2
  l_S_i2_j2_0_i2: for (int i2 = 0; i2 < 200; i2++) {	// L27
    l_j2: for (int j2 = 0; j2 < 220; j2++) {	// L28
    #pragma HLS pipeline II=1
      float v20 = v16[i2][j2];	// L29
      float v21 = v20 * 0.100000;	// L31
      float v22 = v15[i2][j2];	// L32
      float v23 = v21 + v22;	// L33
      v17[i2][j2] = v23;	// L34
    }
  }
}

void kernel(
  float v24[200][240],
  float v25[240][220],
  float v26[200][220],
  float v27[200][220]
) {	// L39
  float out_AB[200][220];	// L40
  mm1(v24, v25, out_AB);	// L41
  ele_add(out_AB, v26, v27);	// L42
}

