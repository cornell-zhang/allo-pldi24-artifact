#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float alpha;
    float beta;
    float A[250][250];
    #pragma HLS resource variable=A core=RAM_1P_BRAM
    float B[250][250];
    #pragma HLS resource variable=B core=RAM_1P_BRAM
    float tmp[250];
    #pragma HLS resource variable=tmp core=RAM_T2P_BRAM
    float x[250];
    #pragma HLS resource variable=x core=RAM_1P_BRAM
    float y[250];
    #pragma HLS resource variable=y core=RAM_T2P_BRAM
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
      float a = (alpha * tmp[i]);
      float b = (beta * y[i]);
      //---
      y[i] = (a + b);
    }
  }
}