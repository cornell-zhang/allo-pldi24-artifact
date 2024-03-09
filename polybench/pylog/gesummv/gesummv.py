import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_gesummv(A, B, tmp, x, y):
    N = 250
    alpha = 1.0
    beta = 1.0
    for i in range(N):
        tmp[i] = 0.0
        y[i] = 0.0
        for j in range(N).unroll():
            tmp[i] += A[i][j] * x[j]
            y[i] += B[i][j] * x[j]
        y[i] = alpha * tmp[i] + beta * y[i]


if __name__ == "__main__":
    N = 250
    n = N
    alpha = 1.0
    beta = 1.0
    A = np.random.rand(N, N).astype(np.float32)
    B = np.random.rand(N, N).astype(np.float32)
    tmp = np.zeros(N, dtype=np.float32)
    x = np.random.rand(N).astype(np.float32)
    y = np.zeros(N, dtype=np.float32)
    pl_gesummv(A, B, tmp, x, y)