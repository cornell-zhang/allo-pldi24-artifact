import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_jacobi_2d(A, B):
    TSTEPS = 100
    N = 250
    for m in range(TSTEPS):
        for i in range(1, N - 1):
            for j in range(1, N - 1).unroll():
                B[i, j] = 0.2 * (
                    A[i, j] + A[i, j - 1] + A[i, j + 1] + A[i + 1, j] + A[i - 1, j]
                )

        for i in range(1, N - 1):
            for j in range(1, N - 1).unroll():
                A[i, j] = 0.2 * (
                    B[i, j] + B[i, j - 1] + B[i, j + 1] + B[i + 1, j] + B[i - 1, j]
                )


if __name__ == "__main__":
    TSTEPS = 100
    N = 250
    A = np.random.rand(N, N).astype(np.float32)
    B = np.random.rand(N, N).astype(np.float32)
    pl_jacobi_2d(A, B)
