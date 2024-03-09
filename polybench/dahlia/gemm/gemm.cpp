#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float A[200][240];
    #pragma HLS resource variable=A core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=A cyclic factor=24 dim=2
    float B[240][220];
    #pragma HLS resource variable=B core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=B cyclic factor=24 dim=1
    float C[200][220];
    #pragma HLS resource variable=C core=RAM_T2P_BRAM
    float beta;
    float alph;
    float out_AB[200][220];
    #pragma HLS resource variable=out_AB core=RAM_1P_BRAM
    for(int i0 = 0; i0 < 200; i0++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j0 = 0; j0 < 220; j0++) {
        #pragma HLS LOOP_FLATTEN off
        for(int k0 = 0; k0 < 240; k0++) {
          #pragma HLS LOOP_FLATTEN off
          #pragma HLS UNROLL factor=24 skip_exit_check
          float product = ((alph * A[i0][k0]) * B[k0][j0]);
          // combiner:
          out_AB[i0][j0] += product;
        }
      }
    }
    //---
    for(int i1 = 0; i1 < 200; i1++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j1 = 0; j1 < 220; j1++) {
        #pragma HLS LOOP_FLATTEN off
        C[i1][j1] = ((beta * C[i1][j1]) + out_AB[i1][j1]);
      }
    }
  }
}