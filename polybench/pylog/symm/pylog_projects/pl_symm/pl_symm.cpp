#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_symm(float A[200][200], float B[200][240], float C[200][240])
{
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=B offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=B bundle=ctrl
  #pragma HLS INTERFACE m_axi port=C offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=C bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int M = 200;
  int N = 240;
  float alpha = 1.5;
  float beta = 1.2;
  for (int i = 0; i < M; i += 1)
  {
    for (int j = 0; j < N; j += 1)
    {
      float sum_ = 0.0;
      for (int k = 0; k < i; k += 1)
      {
        #pragma HLS unroll
        C[k][j] = C[k][j] + ((alpha * B[i][j]) * A[i][k]);
        sum_ += B[k][j] * A[i][k];
      }

      C[i][j] = ((beta * C[i][j]) + ((alpha * B[i][j]) * A[i][i])) + (alpha * sum_);
    }

  }

}

