#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_jacobi_2d(float A[250][250], float B[250][250])
{
  #pragma HLS INTERFACE m_axi port=A offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=A bundle=ctrl
  #pragma HLS INTERFACE m_axi port=B offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=B bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int TSTEPS = 100;
  int N = 250;
  for (int m = 0; m < TSTEPS; m += 1)
  {
    for (int i = 1; i < (N - 1); i += 1)
    {
      for (int j = 1; j < (N - 1); j += 1)
      {
        #pragma HLS unroll
        B[i][j] = 0.2 * ((((A[i][j] + A[i][j - 1]) + A[i][j + 1]) + A[i + 1][j]) + A[i - 1][j]);
      }

    }

    for (int i = 1; i < (N - 1); i += 1)
    {
      for (int j = 1; j < (N - 1); j += 1)
      {
        #pragma HLS unroll
        A[i][j] = 0.2 * ((((B[i][j] + B[i][j - 1]) + B[i][j + 1]) + B[i + 1][j]) + B[i - 1][j]);
      }

    }

  }

}

