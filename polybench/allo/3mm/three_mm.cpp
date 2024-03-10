
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

extern "C" {

void mm1(
  float v0[180][200],
  float v1[200][190],
  // float v2[180][190]
  hls::stream<float> &v2
) {	// L4
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v1 complete dim=2

  #pragma HLS stream variable=v2 depth=34200

  l_mm1_i0: for (int i0 = 0; i0 < 180; i0++) {	// L5
  #pragma HLS dataflow
    float v4[190];	// L6
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
      // v2[i0][j0_back] = v14;	// L23
      v2.write(v14);
    }
  }
}

void mm2(
  float v15[190][220],
  float v16[220][210],
  float v17[190][210]
  // hls::stream<float> &v17
) {	// L28
  #pragma HLS dataflow
  #pragma HLS array_partition variable=v16 complete dim=2
  #pragma HLS array_partition variable=v17 complete dim=2

  // #pragma HLS array_partition variable=v17 complete dim=1
  // #pragma HLS array_partition variable=v17 complete dim=2

  // #pragma HLS stream variable=v17 depth=39900

  l_mm2_i1: for (int i1 = 0; i1 < 190; i1++) {	// L29
  #pragma HLS dataflow
    float v19[210];	// L30
    l_j1_init: for (int j1_init = 0; j1_init < 210; j1_init++) {	// L32
    // #pragma HLS pipeline II=1
    #pragma HLS unroll
      v19[j1_init] = 0.000000;	// L33
    }
    l_S_k1_0_k1: for (int k1 = 0; k1 < 220; k1++) {	// L35
    #pragma HLS pipeline II=1
      float v23 = v15[i1][k1];	// L37
      l_j1: for (int j1 = 0; j1 < 210; j1++) {	// L36
        float v24 = v16[k1][j1];	// L38
        float v25 = v23 * v24;	// L39
        float v26 = v19[j1];	// L40
        float v27 = v26 + v25;	// L41
        v19[j1] = v27;	// L42
      }
    }
    l_j1_back: for (int j1_back = 0; j1_back < 210; j1_back++) {	// L45
    #pragma HLS unroll
    // #pragma HLS pipeline II=1
      float v29 = v19[j1_back];	// L46
      v17[i1][j1_back] = v29;	// L47
      // v17.write(v29);
    }
  }
}

void mm3(
  // float v30[180][190],
  // float v31[190][210],
  hls::stream<float> &v30,
  float v31[190][210],
  float v32[180][210]
) {	// L52
  // #pragma HLS dataflow
  #pragma HLS array_partition variable=v32 complete dim=2

  #pragma HLS stream variable=v30 depth=34200
  #pragma HLS stream variable=v31 depth=39900

  l_mm3_i2: for (int i2 = 0; i2 < 180; i2++) {	// L53
  #pragma HLS dataflow
    float v34[210];	// L54
    #pragma HLS array_partition variable=v34 complete dim=1
    l_j2_init: for (int j2_init = 0; j2_init < 210; j2_init++) {	// L56
    #pragma HLS unroll
      v34[j2_init] = 0.000000;	// L57
    }
    l_S_k2_0_k2: for (int k2 = 0; k2 < 190; k2++) {	// L59
      #pragma HLS pipeline II=1
      float v38 = v30.read();	// L61
      l_j2: for (int j2 = 0; j2 < 210; j2++) {	// L60
        float v39 = v31[k2][j2];	// L62
        float v40 = v38 * v39;	// L63
        float v41 = v34[j2];	// L64
        float v42 = v41 + v40;	// L65
        v34[j2] = v42;	// L66
      }
    }
    l_j2_back: for (int j2_back = 0; j2_back < 210; j2_back++) {	// L69
    // #pragma HLS pipeline II=1
    #pragma HLS unroll
      float v44 = v34[j2_back];	// L70
      v32[i2][j2_back] = v44;	// L71
    }
  }
}

void kernel_3mm(
  float *v45,
  float *v46,
  float *v47,
  float *v48,
  float *v49
) {	// L76
  #pragma HLS interface m_axi port=v45 offset=slave bundle=gmem0
  #pragma HLS interface m_axi port=v46 offset=slave bundle=gmem1
  #pragma HLS interface m_axi port=v47 offset=slave bundle=gmem2
  #pragma HLS interface m_axi port=v48 offset=slave bundle=gmem3
  #pragma HLS interface m_axi port=v49 offset=slave bundle=gmem4

  #pragma HLS dataflow

  float buf0[180][200];	// L77
  l_S_buf0_buf0_l_0: for (int buf0_l_0 = 0; buf0_l_0 < 180; buf0_l_0++) {	// L78
    l_buf0_l_1: for (int buf0_l_1 = 0; buf0_l_1 < 200; buf0_l_1++) {	// L79
    #pragma HLS pipeline II=1
      float v53 = v45[((buf0_l_0 * 200) + buf0_l_1)];	// L80
      buf0[buf0_l_0][buf0_l_1] = v53;	// L81
    }
  }
  float buf1[200][190];	// L84
  // #pragma HLS array_partition variable=buf1 complete dim=2

  l_S_buf1_buf1_l_0: for (int buf1_l_0 = 0; buf1_l_0 < 200; buf1_l_0++) {	// L85
    l_buf1_l_1: for (int buf1_l_1 = 0; buf1_l_1 < 190; buf1_l_1++) {	// L86
    #pragma HLS pipeline II=1
      float v57 = v46[((buf1_l_0 * 190) + buf1_l_1)];	// L87
      buf1[buf1_l_0][buf1_l_1] = v57;	// L88
    }
  }
  float buf2[190][220];	// L91
  // #pragma HLS array_partition variable=buf2 complete dim=2

  l_S_buf2_buf2_l_0: for (int buf2_l_0 = 0; buf2_l_0 < 190; buf2_l_0++) {	// L92
    l_buf2_l_1: for (int buf2_l_1 = 0; buf2_l_1 < 220; buf2_l_1++) {	// L93
    #pragma HLS pipeline II=1
      float v61 = v47[((buf2_l_0 * 220) + buf2_l_1)];	// L94
      buf2[buf2_l_0][buf2_l_1] = v61;	// L95
    }
  }
  float buf3[220][210];	// L98
  l_S_buf3_buf3_l_0: for (int buf3_l_0 = 0; buf3_l_0 < 220; buf3_l_0++) {	// L99
    l_buf3_l_1: for (int buf3_l_1 = 0; buf3_l_1 < 210; buf3_l_1++) {	// L100
    #pragma HLS pipeline II=1
      float v65 = v48[((buf3_l_0 * 210) + buf3_l_1)];	// L101
      buf3[buf3_l_0][buf3_l_1] = v65;	// L102
    }
  }
  // float out_AB[180][190];	// L106
  float out_CD[190][210];	// L107
  #pragma HLS array_partition variable=out_CD complete dim=2

  hls::stream<float> out_AB;
  #pragma HLS stream variable=out_AB depth=34200

  float output[180][210];	// L108
  #pragma HLS array_partition variable=output complete dim=2
  mm1(buf0, buf1, out_AB);	// L109
  mm2(buf2, buf3, out_CD);	// L110
  mm3(out_AB, out_CD, output);	// L111
  l_S_result4_result4_l_0: for (int result4_l_0 = 0; result4_l_0 < 180; result4_l_0++) {	// L112
    l_result4_l_1: for (int result4_l_1 = 0; result4_l_1 < 210; result4_l_1++) {	// L113
    #pragma HLS pipeline II=1
      float v71 = output[result4_l_0][result4_l_1];	// L114
      v49[((result4_l_0 * 210) + result4_l_1)] = v71;	// L115
    }
  }
}


} // extern "C"
