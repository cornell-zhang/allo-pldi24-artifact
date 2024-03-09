#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float alpha;
    float A[200][240];
    #pragma HLS resource variable=A core=RAM_1P_BRAM
    float B[200][240];
    #pragma HLS resource variable=B core=RAM_T2P_BRAM
    for(int i = 0; i < 200; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        for(int k = 0; k < 200; k++) {
          #pragma HLS LOOP_FLATTEN off
          if ((k >= (i + 1))) {
            float sum = (A[k][i] * B[k][j]);
            //---
            B[i][j] = (B[i][j] + sum);
          }
        }
        //---
        B[i][j] = (B[i][j] * alpha);
      }
    }
  }
}