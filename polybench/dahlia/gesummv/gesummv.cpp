#include <ap_int.h>
extern "C" {
  void kernel(float alpha, float beta, float A[250][250], float B[250][250], float tmp[250], float x[250], float y[250]) {
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE s_axilite port=beta bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=tmp bundle=control
    #pragma HLS INTERFACE m_axi port=x offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=x bundle=control
    #pragma HLS INTERFACE m_axi port=y offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=y bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 250; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 250; j++) {
        #pragma HLS LOOP_FLATTEN off
        float tmp_val = (A[i][j] * x[j]);
        float mul = (B[i][j] * x[j]);
        // combiner:
        tmp[i] += tmp_val;
        y[i] += mul;
      }
      //---
      float a = (alpha * tmp[i]);
      float b = (beta * y[i]);
      //---
      y[i] = (a + b);
    }
  }
}