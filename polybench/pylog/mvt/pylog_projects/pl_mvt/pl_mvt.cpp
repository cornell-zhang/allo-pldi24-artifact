#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_mvt(float A[400][400], float y1[400], float y2[400], float x1[400], float x2[400])
{
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=y1 offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=y1 bundle=ctrl
  #pragma HLS INTERFACE m_axi port=y2 offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=y2 bundle=ctrl
  #pragma HLS INTERFACE m_axi port=x1 offset=slave bundle=data3
  #pragma HLS INTERFACE s_axilite register port=x1 bundle=ctrl
  #pragma HLS INTERFACE m_axi port=x2 offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=x2 bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int N = 400;
  for (int i0 = 0; i0 < N; i0 += 1)
  {
    for (int j0 = 0; j0 < N; j0 += 1)
    {
      #pragma HLS unroll
      x1[i0] = x1[i0] + (A[i0][j0] * y1[j0]);
    }

  }

  for (int i1 = 0; i1 < N; i1 += 1)
  {
    for (int j1 = 0; j1 < N; j1 += 1)
    {
      #pragma HLS unroll
      x2[i1] = x2[i1] + (A[j1][i1] * y2[j1]);
    }

  }

}

