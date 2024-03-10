import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_trmm(A, B):
    M = 200
    N = 240
    alpha = 1.5

    for i in range(M):
        for j in range(N):
            for k in range(M).pipeline():
                if k > i:
                    B[i, j] += A[k, i] * B[k, j]
            B[i, j] *= alpha


if __name__ == "__main__":
    M = 200
    N = 240
    A = np.random.rand(M, M).astype(np.float32)
    B = np.random.rand(M, N).astype(np.float32)
    pl_trmm(A, B)
