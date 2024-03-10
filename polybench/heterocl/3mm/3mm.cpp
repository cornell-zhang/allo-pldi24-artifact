
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
  float v0[180][200],
  float v1[200][190],
  float v2[180][190]
) {	// L4
  #pragma HLS array_partition variable=v1 complete dim=2

  l_mm1_i0: for (int i0 = 0; i0 < 180; i0++) {	// L5
    float v4[190];	// L6
    #pragma HLS array_partition variable=v4 complete dim=0
    l_j0_init: for (int j0_init = 0; j0_init < 190; j0_init++) {	// L8
    #pragma HLS pipeline II=1
      v4[j0_init] = 0.000000;	// L9
    }
    l_S_k0_0_k0: for (int k0 = 0; k0 < 200; k0++) {	// L11
    #pragma HLS pipeline II=1
      l_j0: for (int j0 = 0; j0 < 190; j0++) {	// L12
        float v8 = v0[i0][k0];	// L13
        float v9 = v1[k0][j0];	// L14
        float v10 = v8 * v9;	// L15
        float v11 = v4[j0];	// L16
        float v12 = v11 + v10;	// L17
        v4[j0] = v12;	// L18
      }
    }
    l_j0_back: for (int j0_back = 0; j0_back < 190; j0_back++) {	// L21
    #pragma HLS pipeline II=1
      float v14 = v4[j0_back];	// L22
      v2[i0][j0_back] = v14;	// L23
    }
  }
}

void mm2(
  float v15[190][220],
  float v16[220][210],
  float v17[190][210]
) {	// L28
  #pragma HLS array_partition variable=v16 complete dim=2

  l_mm2_i1: for (int i1 = 0; i1 < 190; i1++) {	// L29
    float v19[210];	// L30
    #pragma HLS array_partition variable=v19 complete dim=0 
    l_j1_init: for (int j1_init = 0; j1_init < 210; j1_init++) {	// L32
    #pragma HLS pipeline II=1
      v19[j1_init] = 0.000000;	// L33
    }
    l_S_k1_0_k1: for (int k1 = 0; k1 < 220; k1++) {	// L35
    #pragma HLS pipeline II=1
      l_j1: for (int j1 = 0; j1 < 210; j1++) {	// L36
        float v23 = v15[i1][k1];	// L37
        float v24 = v16[k1][j1];	// L38
        float v25 = v23 * v24;	// L39
        float v26 = v19[j1];	// L40
        float v27 = v26 + v25;	// L41
        v19[j1] = v27;	// L42
      }
    }
    l_j1_back: for (int j1_back = 0; j1_back < 210; j1_back++) {	// L45
    #pragma HLS pipeline II=1
      float v29 = v19[j1_back];	// L46
      v17[i1][j1_back] = v29;	// L47
    }
  }
}

void mm3(
  float v30[180][190],
  float v31[190][210],
  float v32[180][210]
) {	// L52
  #pragma HLS array_partition variable=v31 complete dim=2

  l_mm3_i2: for (int i2 = 0; i2 < 180; i2++) {	// L53
    float v34[210];	// L54
    #pragma HLS array_partition variable=v34 complete dim=0
    l_j2_init: for (int j2_init = 0; j2_init < 210; j2_init++) {	// L56
    #pragma HLS pipeline II=1
      v34[j2_init] = 0.000000;	// L57
    }
    l_S_k2_0_k2: for (int k2 = 0; k2 < 190; k2++) {	// L59
    #pragma HLS pipeline II=1
      l_j2: for (int j2 = 0; j2 < 210; j2++) {	// L60
        float v38 = v30[i2][k2];	// L61
        float v39 = v31[k2][j2];	// L62
        float v40 = v38 * v39;	// L63
        float v41 = v34[j2];	// L64
        float v42 = v41 + v40;	// L65
        v34[j2] = v42;	// L66
      }
    }
    l_j2_back: for (int j2_back = 0; j2_back < 210; j2_back++) {	// L69
    #pragma HLS pipeline II=1
      float v44 = v34[j2_back];	// L70
      v32[i2][j2_back] = v44;	// L71
    }
  }
}

void kernel(
  float v45[180][200],
  float v46[200][190],
  float v47[190][220],
  float v48[220][210],
  float v49[180][210]
) {	// L76

  float out_AB[180][190];	// L77
  float out_CD[190][210];	// L78

  mm1(v45, v46, out_AB);	// L80
  mm2(v47, v48, out_CD);	// L81
  mm3(out_AB, out_CD, v49);	// L82
}

