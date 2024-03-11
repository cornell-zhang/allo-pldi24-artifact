
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
#include <string.h>

using namespace std;

/// This is top function.
/// Latency=38400012, interval=38400012
/// DSP=5, BRAM=0
void test_trmm(
  float v0,
  float v1[200][200],
  float v2[200][240]
) {	// L4, [0,38400012)
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface s_axilite port=v0 bundle=ctrl
  #pragma HLS resource variable=v1 core=ram_t2p_bram

  #pragma HLS resource variable=v2 core=ram_t2p_bram

  for (int v3 = 0; v3 < 200; v3 += 1) {	// L5, [0,38400010), iterCycle=12, II=4
    for (int v4 = 0; v4 < 200; v4 += 1) {	// L6, [0,192010), iterCycle=12, II=4
      for (int v5 = 0; v5 < 240; v5 += 1) {	// L7, [0,970), iterCycle=12, II=4
        #pragma HLS pipeline II=4
        if ((((-v4) - v3) + 198) >= 0) {	// L8, [0,12)
          float v6 = v1[((-v4) + 199)][v3];	// L9, [0,2)
          float v7 = v2[((-v4) + 199)][v5];	// L10, [0,2)
          float v8 = v6 * v7;	// L11, [2,6)
          float v9 = v2[v3][v5];	// L12, [4,6)
          float v10 = v9 + v8;	// L13, [6,11)
          v2[v3][v5] = v10;	// L14, [11,12)
        }
        float v11 = v2[v3][v5];	// L16, [5,7)
        float v12 = v11 * v0;	// L17, [7,11)
        if (((-v4) + 199) == 0) {	// L18, [11,12)
          v2[v3][v5] = v12;	// L19, [11,12)
        }
      }
    }
  }
}

