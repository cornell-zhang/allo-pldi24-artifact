#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float A[410][390];
    #pragma HLS resource variable=A core=RAM_1P_BRAM
    float p[390];
    #pragma HLS resource variable=p core=RAM_1P_BRAM
    float r[410];
    #pragma HLS resource variable=r core=RAM_1P_BRAM
    float q[410];
    #pragma HLS resource variable=q core=RAM_T2P_BRAM
    float s[390];
    #pragma HLS resource variable=s core=RAM_T2P_BRAM
    for(int i = 0; i < 410; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 390; j++) {
        #pragma HLS LOOP_FLATTEN off
        float mul1 = (A[i][j] * r[i]);
        //---
        s[j] = (s[j] + mul1);
        //---
        float mul2 = (A[i][j] * p[j]);
        //---
        q[i] = (q[i] + mul2);
      }
    }
  }
}