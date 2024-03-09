#include <ap_int.h>
extern "C" {
  void kernel(float E[180][190], float A[180][200], float B[200][190], float F[190][210], float C[190][220], float D[220][210], float G[180][210]) {
    #pragma HLS INTERFACE m_axi port=E offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=E bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE m_axi port=F offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=F bundle=control
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE m_axi port=D offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=D bundle=control
    #pragma HLS INTERFACE m_axi port=G offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=G bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 190; j++) {
        #pragma HLS LOOP_FLATTEN off
        E[i][j] = 0.0;
        //---
        for(int k = 0; k < 200; k++) {
          #pragma HLS LOOP_FLATTEN off
          float mul = (A[i][k] * B[k][j]);
          // combiner:
          E[i][j] += mul;
        }
      }
    }
    //---
    for(int i = 0; i < 190; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 210; j++) {
        #pragma HLS LOOP_FLATTEN off
        F[i][j] = 0.0;
        //---
        for(int k = 0; k < 220; k++) {
          #pragma HLS LOOP_FLATTEN off
          float mul = (C[i][k] * D[k][j]);
          // combiner:
          F[i][j] += mul;
        }
      }
    }
    //---
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 210; j++) {
        #pragma HLS LOOP_FLATTEN off
        G[i][j] = 0.0;
        //---
        for(int k = 0; k < 190; k++) {
          #pragma HLS LOOP_FLATTEN off
          float mul = (E[i][k] * F[k][j]);
          // combiner:
          G[i][j] += mul;
        }
      }
    }
  }
}