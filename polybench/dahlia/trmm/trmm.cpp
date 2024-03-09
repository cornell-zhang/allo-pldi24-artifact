#include <ap_int.h>
extern "C" {
  void kernel(float alpha, float A[200][240], float B[200][240]) {
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 200; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        for(int k = 0; k < 200; k++) {
          #pragma HLS LOOP_FLATTEN off
          if ((k >= (i + 1))) {
            float sum = (A[k][i] * B[k][j]);
            //---
            float b = (B[i][j] + sum);
            //---
            B[i][j] = b;
          }
        }
        //---
        float acc = (B[i][j] * alpha);
        //---
        B[i][j] = acc;
      }
    }
  }
}