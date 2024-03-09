#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_bicg(float A[410][390], float s[390], float q[410], float p[390], float r[410])
{
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=s offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=s bundle=ctrl
  #pragma HLS INTERFACE m_axi port=q offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=q bundle=ctrl
  #pragma HLS INTERFACE m_axi port=p offset=slave bundle=data3
  #pragma HLS INTERFACE s_axilite register port=p bundle=ctrl
  #pragma HLS INTERFACE m_axi port=r offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=r bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int M = 390;
  int N = 410;
  for (int i = 0; i < M; i += 1)
  {
    s[i] = 0;
  }

  for (int i = 0; i < N; i += 1)
  {
    q[i] = 0.0;
    for (int j = 0; j < M; j += 1)
    {
      #pragma HLS unroll
      s[j] = s[j] + (r[i] * A[i][j]);
      q[i] = q[i] + (A[i][j] * p[j]);
    }

  }

}

