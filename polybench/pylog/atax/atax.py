import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_atax(A, x, y, tmp):
    M = 390
    N = 410
    for i in range(N):
        y[i] = 0
    for i in range(M):
        tmp[i] = 0.0
        for j in range(N).unroll():
            tmp[i] += A[i][j] * x[j]
        for j in range(N).unroll():
            y[j] += A[i][j] * tmp[i]


if __name__ == "__main__":
    M = 390
    N = 410
    A = np.random.rand(M, N).astype(np.float32)
    x = np.random.rand(N).astype(np.float32)
    y = np.zeros(N, dtype=np.float32)
    tmp = np.zeros(M, dtype=np.float32)
    pl_atax(A, x, y, tmp)
