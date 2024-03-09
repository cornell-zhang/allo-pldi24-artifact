#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_syrk(float A[240][200], float C[240][240])
{
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=C offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=C bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int M = 200;
  int N = 240;
  float alpha = 1.5;
  float beta = 1.2;
  for (int i = 0; i < N; i += 1)
  {
    for (int j = 0; j < (i + 1); j += 1)
    {
      #pragma HLS unroll
      C[i][j] *= beta;
    }

    for (int k = 0; k < M; k += 1)
    {
      for (int j = 0; j < (i + 1); j += 1)
      {
        #pragma HLS unroll
        C[i][j] += (alpha * A[i][k]) * A[j][k];
      }

    }

  }

}

