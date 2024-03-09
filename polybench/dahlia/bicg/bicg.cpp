#include <ap_int.h>
extern "C" {
  void kernel(float A[410][390], float p[390], float r[410], float q[410], float s[390]) {
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=p offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=p bundle=control
    #pragma HLS INTERFACE m_axi port=r offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=r bundle=control
    #pragma HLS INTERFACE m_axi port=q offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=q bundle=control
    #pragma HLS INTERFACE m_axi port=s offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=s bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 390; i++) {
      #pragma HLS LOOP_FLATTEN off
      s[i] = 0.0;
    }
    //---
    for(int i = 0; i < 410; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 390; j++) {
        #pragma HLS LOOP_FLATTEN off
        float mul1 = (A[i][j] * r[i]);
        float mul2 = (A[i][j] * p[j]);
        // combiner:
        s[j] += mul1;
        q[i] += mul2;
      }
    }
  }
}