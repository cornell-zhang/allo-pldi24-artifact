#include <ap_int.h>
extern "C" {
  void kernel(float alpha, float beta, float A[240][240], float C[240][240]) {
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE s_axilite port=beta bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 240; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        if ((j < (i + 1))) {
          float acc = (C[i][j] * beta);
          //---
          C[i][j] = acc;
        }
      }
      //---
      for(int k = 0; k < 200; k++) {
        #pragma HLS LOOP_FLATTEN off
        for(int j = 0; j < 240; j++) {
          #pragma HLS LOOP_FLATTEN off
          if ((j < (i + 1))) {
            float a = A[j][k];
            //---
            float acc = (C[i][j] + ((alpha * A[i][k]) * a));
            //---
            C[i][j] = acc;
          }
        }
      }
    }
  }
}