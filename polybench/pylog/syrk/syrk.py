import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_syrk(A, C):
    M = 200
    N = 240
    alpha = 1.5
    beta = 1.2

    for i in range(N):
        for j in range(i + 1).unroll():
            C[i, j] *= beta
        for k in range(M):
            for j in range(i + 1).unroll():
                C[i, j] += alpha * A[i, k] * A[j, k]


if __name__ == "__main__":
    M = 200
    N = 240
    A = np.random.rand(N, M).astype(np.float32)
    C = np.random.rand(N, N).astype(np.float32)
    pl_syrk(A, C)
