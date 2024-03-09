#include <ap_int.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float alpha;
    float beta;
    float A[250][250];
    #pragma HLS resource variable=A core=RAM_1P_BRAM
    float B[250][250];
    #pragma HLS resource variable=B core=RAM_T2P_BRAM
    float C[250][250];
    #pragma HLS resource variable=C core=RAM_T2P_BRAM
    for(int i = 0; i < 200; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        float sum_ = 0.0;
        for(int k = 0; k < 200; k++) {
          #pragma HLS LOOP_FLATTEN off
          if ((k < i)) {
            float ab = ((alpha * B[i][j]) * A[i][k]);
            C[k][j] = (C[k][j] + ab);
            sum_ = (sum_ + (B[k][j] * A[i][k]));
          }
        }
        //---
        float c = (beta * C[i][j]);
        float ab = ((alpha * B[i][j]) * A[i][i]);
        float sum = (alpha * sum_);
        C[i][j] = ((c + ab) + sum);
      }
    }
  }
}