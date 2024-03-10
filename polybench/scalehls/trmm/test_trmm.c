#define M 200
#define N 240
void test_trmm(float alpha, float A[M][M], float B[M][N]) {
#pragma scop
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (k >= i + 1) {
                    B[i][j] += A[k][i] * B[k][j];
                }
                B[i][j] *= alpha;
            }
        }
    }

#pragma endscop
}