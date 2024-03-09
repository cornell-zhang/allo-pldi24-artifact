#include <ap_int.h>
extern "C" {
  void kernel(float A[390][410], float x[410], float y[410], float tmp[390]) {
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=x offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=x bundle=control
    #pragma HLS INTERFACE m_axi port=y offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=y bundle=control
    #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=tmp bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 410; i++) {
      #pragma HLS LOOP_FLATTEN off
      y[i] = 0.0;
    }
    //---
    for(int i = 0; i < 390; i++) {
      #pragma HLS LOOP_FLATTEN off
      tmp[i] = 0.0;
      //---
      for(int j = 0; j < 410; j++) {
        #pragma HLS LOOP_FLATTEN off
        float mul = (A[i][j] * x[j]);
        // combiner:
        tmp[i] += mul;
      }
      //---
      for(int j = 0; j < 410; j++) {
        #pragma HLS LOOP_FLATTEN off
        float mul = (A[i][j] * tmp[i]);
        // combiner:
        y[j] += mul;
      }
    }
  }
}