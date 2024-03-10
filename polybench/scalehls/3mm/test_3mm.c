#define P 180
#define R 190
#define Q 200
#define T 210
#define S 220

void test_3mm(float A[P][Q], float B[Q][R], float C[R][S], float D[S][T],
                float output[P][T], float out_AB[P][R], float out_CD[R][T]) {
#pragma scop
  // Compute out_AB = A * B
  for (int i0 = 0; i0 < P; i0++) {
    for (int j0 = 0; j0 < R; j0++) {
      for (int k0 = 0; k0 < Q; k0++) {
        out_AB[i0][j0] += A[i0][k0] * B[k0][j0];
      }
    }
  }
  // Compute out_CD = C * D
  for (int i1 = 0; i1 < R; i1++) {
    for (int j1 = 0; j1 < T; j1++) {
      for (int k1 = 0; k1 < S; k1++) {
        out_CD[i1][j1] += C[i1][k1] * D[k1][j1];
      }
    }
  }
  // Compute output = out_AB * out_CD
  for (int i2 = 0; i2 < P; i2++) {
    for (int j2 = 0; j2 < T; j2++) {
      for (int k2 = 0; k2 < R; k2++) {
        output[i2][j2] += out_AB[i2][k2] * out_CD[k2][j2];
      }
    }
  }
#pragma endscop
}
