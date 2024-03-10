#include <stdint.h>

#define N 400

void test_mvt(int32_t A[N][N], int32_t y1[N], int32_t y2[N], int32_t x1[N],
                int32_t x2[N]) {
#pragma scop
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      x1[i] += A[i][j] * y1[j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      x2[i] += A[j][i] * y2[j];
    }
  }
#pragma endscop
}