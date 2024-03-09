#include <ap_int.h>
extern "C" {
  void kernel(float A[250][250], float B[250][250]) {
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int m = 0; m < 100; m++) {
      #pragma HLS LOOP_FLATTEN off
      for(int i = 1; i < 249; i++) {
        #pragma HLS LOOP_FLATTEN off
        for(int j = 1; j < 249; j++) {
          #pragma HLS LOOP_FLATTEN off
          float a00 = A[i][(j + 1)];
          //---
          float a0 = (A[i][(j - 1)] + a00);
          //---
          float a10 = A[(i - 1)][j];
          //---
          float a1 = (A[(i + 1)][j] + a10);
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
          float b00 = B[i][(j + 1)];
          //---
          float b0 = (B[i][(j - 1)] + b00);
          //---
          float b10 = B[(i - 1)][j];
          //---
          float b1 = (B[(i + 1)][j] + b10);
          //---
          float b2 = B[i][j];
          A[i][j] = (0.2 * ((b0 + b1) + b2));
        }
      }
    }
  }
}