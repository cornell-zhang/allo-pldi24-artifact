import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_3mm(E, A, B, F, C, D, G):
    NI = 180
    NJ = 190
    NK = 200
    NL = 210
    NM = 220
    for i in range(NI):
        for j in range(NJ).pipeline():
            E[i][j] = 0.0
            for k in range(NK):
                E[i][j] += A[i][k] * B[k][j]

    for i in range(NJ):
        for j in range(NL).pipeline():
            F[i][j] = 0.0
            for k in range(NM):
                F[i][j] += C[i][k] * D[k][j]

    for i in range(NI):
        for j in range(NL).pipeline():
            G[i][j] = 0.0
            for k in range(NJ):
                G[i][j] += E[i][k] * F[k][j]


if __name__ == "__main__":
    NI = 180
    NJ = 190
    NK = 200
    NL = 210
    NM = 220
    E = np.random.rand(NI, NJ).astype(np.float32)
    A = np.random.rand(NI, NK).astype(np.float32)
    B = np.random.rand(NK, NJ).astype(np.float32)
    F = np.random.rand(NJ, NL).astype(np.float32)
    C = np.random.rand(NJ, NM).astype(np.float32)
    D = np.random.rand(NM, NL).astype(np.float32)
    G = np.random.rand(NI, NL).astype(np.float32)
    pl_3mm(E, A, B, F, C, D, G)
