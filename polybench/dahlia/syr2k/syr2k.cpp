#include <ap_int.h>
extern "C" {
  void kernel(float alpha, float beta, float A[240][200], float B[240][200], float C[240][240]) {
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE s_axilite port=beta bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
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
            float sum0 = ((A[j][k] * alpha) * B[i][k]);
            //---
            float sum1 = ((B[j][k] * alpha) * A[i][k]);
            //---
            float sum = ((C[i][j] + sum0) + sum1);
            //---
            C[i][j] = sum;
          }
        }
      }
    }
  }
}