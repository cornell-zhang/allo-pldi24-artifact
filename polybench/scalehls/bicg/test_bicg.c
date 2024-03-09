#define M 390
#define N 410
void test_bicg(float A[N][M], float p[M], float r[N], float q[N],
                 float s[M]) {
#pragma scop

  for (int i0 = 0; i0 < N; i0++) {
    for (int j0 = 0; j0 < M; j0++) {
      s[j0] += A[i0][j0] * r[i0];
      q[i0] += A[i0][j0] * p[j0];
    }
  }
#pragma endscop
}
