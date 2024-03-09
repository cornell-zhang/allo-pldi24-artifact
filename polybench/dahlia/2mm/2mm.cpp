#include <ap_int.h>
extern "C" {
  void kernel(float alpha, float beta, float tmp[180][190], float A[180][210], float B[210][190], float C[190][220], float D[180][220]) {
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE s_axilite port=beta bundle=control
    #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=tmp bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE m_axi port=D offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=D bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 190; j++) {
        #pragma HLS LOOP_FLATTEN off
        tmp[i][j] = 0.0;
        //---
        for(int k = 0; k < 210; k++) {
          #pragma HLS LOOP_FLATTEN off
          float mul = ((alpha * A[i][k]) * B[k][j]);
          // combiner:
          tmp[i][j] += mul;
        }
      }
    }
    //---
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 220; j++) {
        #pragma HLS LOOP_FLATTEN off
        float bd = (D[i][j] * beta);
        //---
        D[i][j] = bd;
        //---
        for(int k = 0; k < 190; k++) {
          #pragma HLS LOOP_FLATTEN off
          float mul = (tmp[i][k] * C[k][j]);
          // combiner:
          D[i][j] += mul;
        }
      }
    }
  }
}