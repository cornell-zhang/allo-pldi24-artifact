#define P 180
#define R 190
#define Q 210
#define S 220

void test_2mm(float A[P][Q], float B[Q][R], float C[R][S], float D[P][S],
              float output[P][S], float alpha, float beta, float out_AB[P][R],
              float out_ABC[P][S]) {
#pragma scop
  for (int i0 = 0; i0 < P; i0++) {
    for (int j0 = 0; j0 < R; j0++) {
      for (int k0 = 0; k0 < Q; k0++) {
        out_AB[i0][j0] += A[i0][k0] * B[k0][j0];
      }
    }
  }
  for (int i1 = 0; i1 < P; i1++) {
    for (int j1 = 0; j1 < S; j1++) {
      for (int k1 = 0; k1 < R; k1++) {
        out_ABC[i1][j1] += out_AB[i1][k1] * C[k1][j1];
      }
    }
  }
  for (int i2 = 0; i2 < P; i2++) {
    for (int j2 = 0; j2 < S; j2++) {
      output[i2][j2] = out_ABC[i2][j2] * beta + D[i2][j2] * alpha;
    }
  }
#pragma scop
}