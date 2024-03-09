#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_3mm(float E[180][190], float A[180][200], float B[200][190], float F[190][210], float C[190][220], float D[220][210], float G[180][210])
{
  #pragma HLS INTERFACE m_axi port=E offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=E bundle=ctrl
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=B offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=B bundle=ctrl
  #pragma HLS INTERFACE m_axi port=F offset=slave bundle=data3
  #pragma HLS INTERFACE s_axilite register port=F bundle=ctrl
  #pragma HLS INTERFACE m_axi port=C offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=C bundle=ctrl
  #pragma HLS INTERFACE m_axi port=D offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=D bundle=ctrl
  #pragma HLS INTERFACE m_axi port=G offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=G bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int NI = 180;
  int NJ = 190;
  int NK = 200;
  int NL = 210;
  int NM = 220;
  for (int i = 0; i < NI; i += 1)
  {
    for (int j = 0; j < NJ; j += 1)
    {
      #pragma HLS pipeline
      E[i][j] = 0.0;
      for (int k = 0; k < NK; k += 1)
      {
        E[i][j] += A[i][k] * B[k][j];
      }

    }

  }

  for (int i = 0; i < NJ; i += 1)
  {
    for (int j = 0; j < NL; j += 1)
    {
      #pragma HLS pipeline
      F[i][j] = 0.0;
      for (int k = 0; k < NM; k += 1)
      {
        F[i][j] += C[i][k] * D[k][j];
      }

    }

  }

  for (int i = 0; i < NI; i += 1)
  {
    for (int j = 0; j < NL; j += 1)
    {
      #pragma HLS pipeline
      G[i][j] = 0.0;
      for (int k = 0; k < NJ; k += 1)
      {
        G[i][j] += E[i][k] * F[k][j];
      }

    }

  }

}

