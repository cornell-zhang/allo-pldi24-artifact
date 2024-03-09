#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_math.h"

void pl_correlation(float data[260][240], float mean[240], float stddev[240], float corr[240][240])
{
  #pragma HLS INTERFACE m_axi port=data offset=slave bundle=data0
  #pragma HLS INTERFACE s_axilite register port=data bundle=ctrl
  #pragma HLS INTERFACE m_axi port=mean offset=slave bundle=data1
  #pragma HLS INTERFACE s_axilite register port=mean bundle=ctrl
  #pragma HLS INTERFACE m_axi port=stddev offset=slave bundle=data2
  #pragma HLS INTERFACE s_axilite register port=stddev bundle=ctrl
  #pragma HLS INTERFACE m_axi port=corr offset=slave bundle=data3
  #pragma HLS INTERFACE s_axilite register port=corr bundle=ctrl
  #pragma HLS INTERFACE s_axilite register port=return bundle=ctrl
  int M = 240;
  int N = 260;
  float N_float = 260.0;
  for (int x = 0; x < M; x += 1)
  {
    float total = 0.0;
    for (int k = 0; k < N; k += 1)
    {
      #pragma HLS unroll
      total += data[k][x];
    }

    mean[x] = total / N;
  }

  for (int x = 0; x < M; x += 1)
  {
    float variance = 0.0;
    for (int m = 0; m < N; m += 1)
    {
      #pragma HLS unroll
      variance += (data[m][x] - mean[x]) * (data[m][x] - mean[x]);
    }

    stddev[x] = pow((variance / N_float),0.5);
  }

  for (int x = 0; x < N; x += 1)
  {
    for (int y = 0; y < M; y += 1)
    {
      #pragma HLS unroll
      data[x][y] -= mean[y];
      data[x][y] /= (pow(N_float,0.5)) * stddev[y];
    }

  }

  for (int i = 0; i < (M - 1); i += 1)
  {
    corr[i][i] = 1.0;
    for (int j = i + 1; j < M; j += 1)
    {
      corr[i][j] = 0.0;
      for (int k = 0; k < N; k += 1)
      {
        #pragma HLS unroll
        corr[i][j] += data[k][i] * data[k][j];
      }

      corr[j][i] = corr[i][j];
    }

  }

  corr[M - 1][M - 1] = 1.0;
}

