#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_2mm(float tmp[180][190], float A[180][190], float B[190][210], float C[210][220], float D[180][220])
{
  #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=tmp bundle=ctrl
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=B offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=B bundle=ctrl
  #pragma HLS INTERFACE m_axi port=C offset=slave bundle=data3
  #pragma HLS INTERFACE s_axilite register port=C bundle=ctrl
  #pragma HLS INTERFACE m_axi port=D offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=D bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int NI = 180;
  int NJ = 190;
  int NK = 210;
  int NL = 220;
  float alpha = 0.1;
  float beta = 0.5;
  for (int i = 0; i < NI; i += 1)
  {
    for (int j = 0; j < NJ; j += 1)
    {
      tmp[i][j] = 0.0;
      for (int k = 0; k < NK; k += 1)
      {
        #pragma HLS unroll
        tmp[i][j] += (alpha * A[i][k]) * B[k][j];
      }

    }

  }

  for (int i = 0; i < NI; i += 1)
  {
    for (int j = 0; j < NL; j += 1)
    {
      D[i][j] *= beta;
      for (int k = 0; k < NJ; k += 1)
      {
        #pragma HLS unroll
        D[i][j] += tmp[i][k] * C[k][j];
      }

    }

  }

}

