#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_gesummv(float A[250][250], float B[250][250], float tmp[250], float x[250], float y[250])
{
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=B offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=B bundle=ctrl
  #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=tmp bundle=ctrl
  #pragma HLS INTERFACE m_axi port=x offset=slave bundle=data3
  #pragma HLS INTERFACE s_axilite register port=x bundle=ctrl
  #pragma HLS INTERFACE m_axi port=y offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=y bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int N = 250;
  float alpha = 1.0;
  float beta = 1.0;
  for (int i = 0; i < N; i += 1)
  {
    tmp[i] = 0.0;
    y[i] = 0.0;
    for (int j = 0; j < N; j += 1)
    {
      #pragma HLS unroll
      tmp[i] += A[i][j] * x[j];
      y[i] += B[i][j] * x[j];
    }

    y[i] = (alpha * tmp[i]) + (beta * y[i]);
  }

}

