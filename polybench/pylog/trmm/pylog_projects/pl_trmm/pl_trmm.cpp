#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_trmm(float A[200][200], float B[200][240])
{
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=B offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=B bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int M = 200;
  int N = 240;
  float alpha = 1.5;
  for (int i = 0; i < M; i += 1)
  {
    for (int j = 0; j < N; j += 1)
    {
      for (int k = i + 1; k < M; k += 1)
      {
        #pragma HLS unroll
        B[i][j] += A[k][i] * B[k][j];
      }

      B[i][j] *= alpha;
    }

  }

}

