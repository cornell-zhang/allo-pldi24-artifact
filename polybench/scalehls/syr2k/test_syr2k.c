#define M 200
#define N 240
void test_syr2k(float alpha, float beta, float C[N][N], float A[N][M],
                float B[N][M]) {
#pragma scop
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      if (j < i + 1) {
        C[i][j] *= beta;
      }

    for (int k = 0; k < M; k++)
      for (int j = 0; j < N; j++) {
        if (j < i + 1) {
          C[i][j] += A[j][k] * alpha * B[i][k] + B[j][k] * alpha * A[i][k];
        }
      }
  }
#pragma endscop
}