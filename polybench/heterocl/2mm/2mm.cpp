
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
  float v0[180][210],
  float v1[210][190],
  float v2[180][190]
) {	// L2
  #pragma HLS array_partition variable=v1 complete dim=2
  l_mm1_i0: for (int i0 = 0; i0 < 180; i0++) {	// L3
    float v4[190];	// L4
    #pragma HLS array_partition variable=v4 complete dim=0
    l_j0_init: for (int j0_init = 0; j0_init < 190; j0_init++) {	// L6
    #pragma HLS pipeline II=1
      v4[j0_init] = 0.000000;	// L7
    }
    l_S_k0_0_k0: for (int k0 = 0; k0 < 210; k0++) {	// L9
    #pragma HLS pipeline II=1
      l_j0: for (int j0 = 0; j0 < 190; j0++) {	// L10
        float v8 = v0[i0][k0];	// L11
        float v9 = v1[k0][j0];	// L12
        float v10 = v8 * v9;	// L13
        float v11 = v4[j0];	// L14
        float v12 = v11 + v10;	// L15
        v4[j0] = v12;	// L16
      }
    }
    l_j0_back: for (int j0_back = 0; j0_back < 190; j0_back++) {	// L19
    #pragma HLS pipeline II=1
      float v14 = v4[j0_back];	// L20
      v2[i0][j0_back] = v14;	// L21
    }
  }
}

void mm2(
  float v15[180][190],
  float v16[190][220],
  float v17[180][220]
) {	// L26
  #pragma HLS array_partition variable=v16 complete dim=2
  l_mm2_i1: for (int i1 = 0; i1 < 180; i1++) {	// L27
    float v19[220];	// L28
    #pragma HLS array_partition variable=v19 complete dim=0
    l_j1_init: for (int j1_init = 0; j1_init < 220; j1_init++) {	// L30
    #pragma HLS pipeline II=1
      v19[j1_init] = 0.000000;	// L31
    }
    l_S_k1_0_k1: for (int k1 = 0; k1 < 190; k1++) {	// L33
    #pragma HLS pipeline II=1
      l_j1: for (int j1 = 0; j1 < 220; j1++) {	// L34
        float v23 = v15[i1][k1];	// L35
        float v24 = v16[k1][j1];	// L36
        float v25 = v23 * v24;	// L37
        float v26 = v19[j1];	// L38
        float v27 = v26 + v25;	// L39
        v19[j1] = v27;	// L40
      }
    }
    l_j1_back: for (int j1_back = 0; j1_back < 220; j1_back++) {	// L43
    #pragma HLS pipeline II=1
      float v29 = v19[j1_back];	// L44
      v17[i1][j1_back] = v29;	// L45
    }
  }
}

void ele_add(
  float v30[180][220],
  float v31[180][220],
  float v32[180][220]
) {	// L50
  l_S_i2_j2_0_i2: for (int i2 = 0; i2 < 180; i2++) {	// L51
    l_j2: for (int j2 = 0; j2 < 220; j2++) {	// L52
      #pragma HLS pipeline II=1
      float v35 = v30[i2][j2];	// L53
      float v36 = v35 * 0.500000;	// L55
      float v37 = v31[i2][j2];	// L56
      float v38 = v37 * 0.100000;	// L58
      float v39 = v36 + v38;	// L59
      v32[i2][j2] = v39;	// L60
    }
  }
}

void kernel(
  float v40[180][210],
  float v41[210][190],
  float v42[190][220],
  float v43[180][220],
  float v44[180][220]
) {	// L65
  float out_AB[180][190];	// L66
  float out_ABC[180][220];	// L67
  mm1(v40, v41, out_AB);	// L69
  mm2(out_AB, v42, out_ABC);	// L70
  ele_add(out_ABC, v43, v44);	// L71
}

