#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_gemm(float C[200][220], float A[200][240], float B[240][220])
{
  #pragma HLS INTERFACE m_axi port=C offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=C bundle=ctrl
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=B offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=B bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  float alpha = 1.0;
  float beta = 1.0;
  int NI = 200;
  int NJ = 220;
  int NK = 240;
  for (int i = 0; i < NI; i += 1)
  {
    for (int j = 0; j < NJ; j += 1)
    {
      #pragma HLS unroll
      C[i][j] *= beta;
    }

    for (int k = 0; k < NK; k += 1)
    {
      for (int j = 0; j < NJ; j += 1)
      {
        #pragma HLS unroll
        C[i][j] += (alpha * A[i][k]) * B[k][j];
      }

    }

  }

}

