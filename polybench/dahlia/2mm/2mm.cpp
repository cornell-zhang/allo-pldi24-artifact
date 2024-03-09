#include <ap_int.h>
extern "C" {
  void kernel(float out_ABC[180][220], float output[180][220]) {
    #pragma HLS INTERFACE m_axi port=out_ABC offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=out_ABC bundle=control
    #pragma HLS INTERFACE m_axi port=output offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=output bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float A[180][210];
    #pragma HLS resource variable=A core=RAM_1P_BRAM
    float B[210][190];
    #pragma HLS resource variable=B core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=B cyclic factor=19 dim=2
    float C[190][220];
    #pragma HLS resource variable=C core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=C cyclic factor=19 dim=1
    float D[180][220];
    #pragma HLS resource variable=D core=RAM_1P_BRAM
    float out_AB[180][190];
    #pragma HLS resource variable=out_AB core=RAM_1P_BRAM
    #pragma HLS ARRAY_PARTITION variable=out_AB cyclic factor=19 dim=2
    float alpha = 0.5;
    float beta = 0.5;
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 190; j++) {
        #pragma HLS LOOP_FLATTEN off
        #pragma HLS UNROLL factor=19 skip_exit_check
        for(int k = 0; k < 210; k++) {
          #pragma HLS LOOP_FLATTEN off
          float mul = (A[i][k] * B[k][j]);
          // combiner:
          out_AB[i][j] += mul;
        }
      }
    }
    //---
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 220; j++) {
        #pragma HLS LOOP_FLATTEN off
        for(int k = 0; k < 190; k++) {
          #pragma HLS LOOP_FLATTEN off
          #pragma HLS UNROLL factor=19 skip_exit_check
          float mul = (out_AB[i][k] * C[k][j]);
          // combiner:
          out_ABC[i][j] += mul;
        }
      }
    }
    //---
    for(int i = 0; i < 180; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 220; j++) {
        #pragma HLS LOOP_FLATTEN off
        float mul = (out_ABC[i][j] * beta);
        float add = (D[i][j] * alpha);
        output[i][j] = add;
      }
    }
  }
}