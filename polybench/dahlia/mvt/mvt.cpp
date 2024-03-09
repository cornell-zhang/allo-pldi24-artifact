#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    ap_int<32> A[400][400];
    #pragma HLS resource variable=A core=RAM_T2P_BRAM
    ap_int<32> y1[400];
    #pragma HLS resource variable=y1 core=RAM_1P_BRAM
    ap_int<32> y2[400];
    #pragma HLS resource variable=y2 core=RAM_1P_BRAM
    ap_int<32> x1[400];
    #pragma HLS resource variable=x1 core=RAM_T2P_BRAM
    ap_int<32> x2[400];
    #pragma HLS resource variable=x2 core=RAM_T2P_BRAM
    for(int i = 0; i < 400; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 400; j++) {
        #pragma HLS LOOP_FLATTEN off
        x1[i] = (x1[i] + (A[i][j] * y1[j]));
      }
    }
    //---
    for(int i = 0; i < 400; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 400; j++) {
        #pragma HLS LOOP_FLATTEN off
        x2[i] = (x2[i] + (A[j][i] * y2[j]));
      }
    }
  }
}