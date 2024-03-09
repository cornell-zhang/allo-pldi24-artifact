#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float A[390][410];
    #pragma HLS resource variable=A core=RAM_1P_BRAM
    float x[410];
    #pragma HLS resource variable=x core=RAM_1P_BRAM
    float y[410];
    #pragma HLS resource variable=y core=RAM_1P_BRAM
    float out_Ax[390];
    #pragma HLS resource variable=out_Ax core=RAM_1P_BRAM
    for(int m = 0; m < 390; m++) {
      #pragma HLS LOOP_FLATTEN off
      for(int r = 0; r < 410; r++) {
        #pragma HLS LOOP_FLATTEN off
        float mul = (A[m][r] * x[r]);
        // combiner:
        out_Ax[m] += mul;
      }
    }
    //---
    for(int n = 0; n < 410; n++) {
      #pragma HLS LOOP_FLATTEN off
      for(int k = 0; k < 390; k++) {
        #pragma HLS LOOP_FLATTEN off
        float mul = (A[k][n] * out_Ax[k]);
        // combiner:
        y[n] += mul;
      }
    }
  }
}