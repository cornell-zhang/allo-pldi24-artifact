#include <ap_int.h>
extern "C" {
  void kernel(float alpha, float beta, float A[200][240], float B[240][220], float C[200][220]) {
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE s_axilite port=beta bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 200; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 220; j++) {
        #pragma HLS LOOP_FLATTEN off
        float b = beta;
        // combiner:
        C[i][j] *= b;
      }
      //---
      for(int k = 0; k < 240; k++) {
        #pragma HLS LOOP_FLATTEN off
        for(int j = 0; j < 220; j++) {
          #pragma HLS LOOP_FLATTEN off
          float acc = ((alpha * A[i][k]) * B[k][j]);
          // combiner:
          C[i][j] += acc;
        }
      }
    }
  }
}