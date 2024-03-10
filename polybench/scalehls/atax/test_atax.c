#define M 390
#define N 410

void test_atax(float A[M][N], float x[N], float y[N], float out_Ax[M]) {
#pragma scop
  for (int m = 0; m < M; m++) {
    for (int r = 0; r < N; r++) {
      out_Ax[m] += A[m][r] * x[r];
    }
  }

  for (int n = 0; n < N; n++) {
    for (int k = 0; k < M; k++) {
      y[n] += A[k][n] * out_Ax[k];
    }
  }
#pragma endscop
}
