#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float A[250][250];
    #pragma HLS resource variable=A core=RAM_T2P_BRAM
    float B[250][250];
    #pragma HLS resource variable=B core=RAM_T2P_BRAM
    for(int m = 0; m < 100; m++) {
      #pragma HLS LOOP_FLATTEN off
      for(int i = 1; i < 249; i++) {
        #pragma HLS LOOP_FLATTEN off
        for(int j = 1; j < 249; j++) {
          #pragma HLS LOOP_FLATTEN off
          float a0 = (A[i][(j - 1)] + A[i][(j + 1)]);
          //---
          float a1 = (A[(i + 1)][j] + A[(i - 1)][j]);
          //---
          float a2 = A[i][j];
          B[i][j] = (0.2 * ((a0 + a1) + a2));
        }
      }
      //---
      for(int i = 1; i < 249; i++) {
        #pragma HLS LOOP_FLATTEN off
        for(int j = 1; j < 249; j++) {
          #pragma HLS LOOP_FLATTEN off
          float b0 = (B[i][(j - 1)] + B[i][(j + 1)]);
          //---
          float b1 = (B[(i + 1)][j] + B[(i - 1)][j]);
          //---
          float b2 = B[i][j];
          A[i][j] = (0.2 * ((b0 + b1) + b2));
        }
      }
    }
  }
}