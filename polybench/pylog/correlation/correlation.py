import numpy as np
from pylog import *


@pylog(mode="cgen")
def pl_correlation(data, mean, stddev, corr):
    M = 240
    N = 260
    N_float = 260.0

    # Compute mean
    for x in range(M):
        total = 0.0
        for k in range(N).unroll():
            total += data[k, x]
        mean[x] = total / N

    # Compute stddev
    for x in range(M):
        variance = 0.0
        for m in range(N).unroll():
            variance += (data[m, x] - mean[x]) * (data[m, x] - mean[x])
        stddev[x] = (variance / N_float) ** 0.5
        # This is to avoid a division by zero situation
        # if stddev[x] <= epsilon:
        #     stddev[x] = 1.0

    # Center and reduce the column vectors.
    for x in range(N):
        for y in range(M).unroll():
            data[x, y] -= mean[y]
            data[x, y] /= (N_float) ** 0.5 * stddev[y]

    # Calculate the m * m correlation matrix.
    for i in range(M - 1):
        corr[i, i] = 1.0
        for j in range(i + 1, M):
            corr[i, j] = 0.0
            for k in range(N).unroll():
                corr[i, j] += data[k, i] * data[k, j]
            corr[j, i] = corr[i, j]

    corr[M - 1, M - 1] = 1.0


if __name__ == "__main__":
    M = 240
    N = 260
    N_float = 260.0
    data = np.random.rand(N, M).astype(np.float32)
    mean = np.zeros((M), np.float32)
    stddev = np.zeros((M), np.float32)
    corr = np.zeros((M, M), np.float32)
    pl_correlation(data, mean, stddev, corr)
