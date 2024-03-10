#define TSTEPS 100
#define N 250

void test_jacobi(float A[N][N], float B[N][N]) {
#pragma scop
    for (int m = 0; m < TSTEPS; m++) {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                B[i][j] = 0.2 * (A[i][j] + A[i][j - 1] + A[i][j + 1] + A[i + 1][j] + A[i - 1][j]);
            }
        }

        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                A[i][j] = 0.2 * (B[i][j] + B[i][j - 1] + B[i][j + 1] + B[i + 1][j] + B[i - 1][j]);
            }
        }
    }
#pragma endscop
}