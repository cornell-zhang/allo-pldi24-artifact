import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_mvt(A, y1, y2, x1, x2):
    N = 400
    for i0 in range(N):
        for j0 in range(N).unroll():
            x1[i0] = x1[i0] + A[i0, j0] * y1[j0]

    for i1 in range(N):
        for j1 in range(N).unroll():
            x2[i1] = x2[i1] + A[j1, i1] * y2[j1]


if __name__ == "__main__":
    N = 400
    A = np.random.rand(N, N).astype(np.float32)
    y1 = np.random.rand(N).astype(np.float32)
    y2 = np.random.rand(N).astype(np.float32)
    x1 = np.random.rand(N).astype(np.float32)
    x2 = np.random.rand(N).astype(np.float32)
    pl_mvt(A, y1, y2, x1, x2)
