#define P 200
#define R 220
#define Q 240

void test_gemm(float A[P][Q], float B[Q][R], float C[P][R], float beta, float alph,
               float out_AB[P][R]) {

  // Perform matrix multiplication A * B and store in out_AB
  for (int i0 = 0; i0 < P; i0++) {
    for (int j0 = 0; j0 < R; j0++) {
      for (int k0 = 0; k0 < Q; k0++) {
        out_AB[i0][j0] += alph * A[i0][k0] * B[k0][j0];
      }
    }
  }

  // Update C with the result, scaled by beta
  for (int i1 = 0; i1 < P; i1++) {
    for (int j1 = 0; j1 < R; j1++) {
      C[i1][j1] = beta * C[i1][j1] + out_AB[i1][j1];
    }
  }
}