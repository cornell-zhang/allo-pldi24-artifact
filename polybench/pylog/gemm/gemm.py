import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_gemm(C, A, B):
    alpha = 1.0
    beta = 1.0
    NI = 200
    NJ = 220
    NK = 240
    for i in range(NI):
        for j in range(NJ).unroll():
            C[i][j] *= beta
        for k in range(NK):
            for j in range(NJ).unroll():
                C[i][j] += alpha * A[i][k] * B[k][j]


if __name__ == "__main__":
    NI = 200
    NJ = 220
    NK = 240
    alpha = 1.0
    beta = 1.0
    A = np.random.rand(NI, NK).astype(np.float32)
    B = np.random.rand(NK, NJ).astype(np.float32)
    C = np.random.rand(NI, NJ).astype(np.float32)
    pl_gemm(C, A, B)
