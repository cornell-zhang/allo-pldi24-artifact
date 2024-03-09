#include <ap_int.h>
extern "C" {
  void kernel(ap_int<32> A[400][400], ap_int<32> y1[400], ap_int<32> y2[400], ap_int<32> x1[400], ap_int<32> x2[400]) {
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=y1 offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=y1 bundle=control
    #pragma HLS INTERFACE m_axi port=y2 offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=y2 bundle=control
    #pragma HLS INTERFACE m_axi port=x1 offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=x1 bundle=control
    #pragma HLS INTERFACE m_axi port=x2 offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=x2 bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 400; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 400; j++) {
        #pragma HLS LOOP_FLATTEN off
        ap_int<32> acc = (x1[i] + (A[i][j] * y1[j]));
        // combiner:
        x1[i] += acc;
      }
    }
    //---
    for(int i = 0; i < 400; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 400; j++) {
        #pragma HLS LOOP_FLATTEN off
        ap_int<32> acc = (x2[i] + (A[j][i] * y2[j]));
        // combiner:
        x2[i] += acc;
      }
    }
  }
}