#include <ap_int.h>
extern "C" {
  void kernel(float alpha, float beta, float A[250][250], float B[250][250], float C[250][250]) {
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
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        float sum_ = 0.0;
        for(int k = 0; k < 200; k++) {
          #pragma HLS LOOP_FLATTEN off
          if ((k < i)) {
            float ab = ((alpha * B[i][j]) * A[i][k]);
            //---
            float sc = (C[k][j] + ab);
            //---
            C[k][j] = sc;
            //---
            sum_ = (sum_ + (B[k][j] * A[i][k]));
          }
        }
        //---
        float c = (beta * C[i][j]);
        float ab = ((alpha * B[i][j]) * A[i][i]);
        float sum = (alpha * sum_);
        //---
        C[i][j] = ((c + ab) + sum);
      }
    }
  }
}