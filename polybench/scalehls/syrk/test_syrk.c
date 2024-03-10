#define M 200
#define N 240

void test_syrk(float alpha, float beta, float A[N][M], float C[N][N]) {
#pragma scop
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      if (j < i + 1) {
        C[i][j] *= beta;
      }
    for (int k = 0; k < M; k++) {
      for (int j = 0; j < N; j++) {
        if (j < i + 1) {
          C[i][j] += alpha * A[i][k] * A[j][k];
        }
      }
    }
  }
#pragma endscop
}
