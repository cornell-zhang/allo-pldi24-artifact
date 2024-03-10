#define M 200
#define N 240

void test_symm(float A[M][M], float B[M][N], float C[M][N], float alpha,
               float beta) {
#pragma scop
  float sum_;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      sum_ = 0.0;
      for (int k = 0; k < M; k++) {
        if (k < i) {
          C[k][j] = C[k][j] + alpha * B[i][j] * A[i][k];
          sum_ += B[k][j] * A[i][k];
        }
      }
      C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * sum_;
    }
  }
#pragma endscop
}