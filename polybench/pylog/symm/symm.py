import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_symm(A, B, C):
    M = 200
    N = 240
    alpha = 1.5
    beta = 1.2
    for i in range(M):
        for j in range(N):
            sum_ = 0.0
            for k in range(i).unroll():
                C[k, j] = C[k, j] + alpha * B[i, j] * A[i, k]
                sum_ += B[k, j] * A[i, k]
            C[i, j] = beta * C[i, j] + alpha * B[i, j] * A[i, i] + alpha * sum_


if __name__ == "__main__":
    M = 200
    N = 240
    A = np.random.rand(M, M).astype(np.float32)
    B = np.random.rand(M, N).astype(np.float32)
    C = np.random.rand(M, N).astype(np.float32)
    pl_symm(A, B, C)
