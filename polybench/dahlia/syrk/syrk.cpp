#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float alpha;
    float beta;
    float A[240][240];
    #pragma HLS resource variable=A core=RAM_T2P_BRAM
    float C[240][240];
    #pragma HLS resource variable=C core=RAM_T2P_BRAM
    for(int i = 0; i < 240; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        if ((j < (i + 1))) {
          C[i][j] = (C[i][j] * beta);
        }
      }
      //---
      for(int k = 0; k < 200; k++) {
        #pragma HLS LOOP_FLATTEN off
        for(int j = 0; j < 240; j++) {
          #pragma HLS LOOP_FLATTEN off
          if ((j < (i + 1))) {
            C[i][j] = (C[i][j] + ((alpha * A[i][k]) * A[j][k]));
          }
        }
      }
    }
  }
}