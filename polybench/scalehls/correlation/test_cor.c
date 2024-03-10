#define M 240
#define N 260
#include <math.h>
void test_cor(float data[N][M], float mean[M], float stddev[M],
                        float corr[M][M]) {
#pragma scop
  // Compute mean
  for (int x = 0; x < M; x++) {
    float total = 0.0;
    for (int k = 0; k < N; k++) {
      total += data[k][x];
    }
    mean[x] = total / N;
  }

  // Compute stddev
  for (int x = 0; x < M; x++) {
    float variance = 0.0;
    for (int m = 0; m < N; m++) {
      variance += (data[m][x] - mean[x]) * (data[m][x] - mean[x]);
    }
    stddev[x] = sqrt(variance / N);
  }

  // Center and reduce the column vectors
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < M; y++) {
      data[x][y] -= mean[y];
      data[x][y] /= sqrt(N) * stddev[y];
    }
  }

  // Compute the correlation matrix
  for (int i = 0; i < M - 1; i++) {
    for (int j = 0; j < M; j++) {
      if (j > i) {
        corr[i][j] = 0.0;
        for (int k = 0; k < N; k++) {
          corr[i][j] += data[k][i] * data[k][j];
        }
        corr[j][i] = corr[i][j];
      }
    }
  }

  corr[M - 1][M - 1] = 1.0;

#pragma endscop
}