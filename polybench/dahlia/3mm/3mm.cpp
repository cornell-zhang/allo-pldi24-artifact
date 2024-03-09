#include <ap_int.h>
extern "C" {
  void kernel(float out_ABC[180][220], float output[180][210]) {
    #pragma HLS INTERFACE m_axi port=out_ABC offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=out_ABC bundle=control
    #pragma HLS INTERFACE m_axi port=output offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=output bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float A[180][200];
    #pragma HLS resource variable=A core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=A cyclic factor=20 dim=2
    float B[200][190];
    #pragma HLS resource variable=B core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=B cyclic factor=20 dim=1
    float C[190][220];
    #pragma HLS resource variable=C core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=C cyclic factor=22 dim=2
    float D[220][210];
    #pragma HLS resource variable=D core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=D cyclic factor=22 dim=1
    float out_AB[180][190];
    #pragma HLS resource variable=out_AB core=RAM_1P_BRAM
    float out_CD[190][210];
    #pragma HLS resource variable=out_CD core=RAM_1P_BRAM
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 190; j++) {
        #pragma HLS LOOP_FLATTEN off
        for(int k = 0; k < 200; k++) {
          #pragma HLS LOOP_FLATTEN off
          #pragma HLS UNROLL factor=20 skip_exit_check
          float mul = (A[i][k] * B[k][j]);
          // combiner:
          out_AB[i][j] += mul;
        }
      }
    }
    //---
    for(int i = 0; i < 100; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 210; j++) {
        #pragma HLS LOOP_FLATTEN off
        for(int k = 0; k < 220; k++) {
          #pragma HLS LOOP_FLATTEN off
          #pragma HLS UNROLL factor=22 skip_exit_check
          float mul = (C[i][k] * D[k][j]);
          // combiner:
          out_CD[i][j] += mul;
        }
      }
    }
    //---
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 210; j++) {
        #pragma HLS LOOP_FLATTEN off
        for(int k = 0; k < 190; k++) {
          #pragma HLS LOOP_FLATTEN off
          float mul = (out_AB[i][k] * out_CD[k][j]);
          // combiner:
          output[i][j] += mul;
        }
      }
    }
  }
}