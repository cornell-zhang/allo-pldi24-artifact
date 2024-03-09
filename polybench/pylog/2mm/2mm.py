import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_2mm(tmp, A, B, C, D):
    NI = 180
    NJ = 190
    NK = 210
    NL = 220
    alpha = 0.1
    beta = 0.5
    for i in range(NI):
        for j in range(NJ).pipeline():
            tmp[i][j] = 0.0
            for k in range(NK):
                tmp[i][j] += alpha * A[i][k] * B[k][j]

    for i in range(NI):
        for j in range(NL).pipeline():
            D[i][j] *= beta
            for k in range(NJ):
                D[i][j] += tmp[i][k] * C[k][j]


if __name__ == "__main__":
    NI = 180
    NJ = 190
    NK = 210
    NL = 220
    tmp = np.random.rand(NI, NJ).astype(np.float32)
    A = np.random.rand(NI, NJ).astype(np.float32)
    B = np.random.rand(NJ, NK).astype(np.float32)
    C = np.random.rand(NK, NL).astype(np.float32)
    D = np.random.rand(NI, NL).astype(np.float32)
    pl_2mm(tmp, A, B, C, D)
