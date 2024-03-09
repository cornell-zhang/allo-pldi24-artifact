#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_atax(float A[390][410], float x[410], float y[410], float tmp[390])
{
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=x offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=x bundle=ctrl
  #pragma HLS INTERFACE m_axi port=y offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=y bundle=ctrl
  #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=data3
  #pragma HLS INTERFACE s_axilite register port=tmp bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int M = 390;
  int N = 410;
  for (int i = 0; i < N; i += 1)
  {
    y[i] = 0;
  }

  for (int i = 0; i < M; i += 1)
  {
    tmp[i] = 0.0;
    for (int j = 0; j < N; j += 1)
    {
      #pragma HLS unroll
      tmp[i] += A[i][j] * x[j];
    }

    for (int j = 0; j < N; j += 1)
    {
      #pragma HLS unroll
      y[j] += A[i][j] * tmp[i];
    }

  }

}

