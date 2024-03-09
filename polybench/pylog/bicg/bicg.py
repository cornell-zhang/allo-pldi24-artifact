import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_bicg(A, s, q, p, r):
    M = 390
    N = 410
    for i in range(M):
        s[i] = 0
    for i in range(N):
        q[i] = 0.0
        for j in range(M).unroll():
            s[j] = s[j] + r[i] * A[i][j]
            q[i] = q[i] + A[i][j] * p[j]


if __name__ == "__main__":
    M = 390
    N = 410
    A = np.random.rand(N, M).astype(np.float32)
    s = np.zeros(M, dtype=np.float32)
    q = np.zeros(N, dtype=np.float32)
    p = np.random.rand(M).astype(np.float32)
    r = np.random.rand(N).astype(np.float32)
    pl_bicg(A, s, q, p, r)
