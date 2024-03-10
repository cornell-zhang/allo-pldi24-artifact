# Copyright Allo authors. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

import allo
import os
import json
import pytest
import allo
import numpy as np
from allo.ir.types import int32, float32
import allo.ir.types as T


def bicg_np(A, s, q, p, r):
    N = A.shape[0]
    M = A.shape[1]
    for i in range(N):
        for j in range(M):
            s[j] += r[i] * A[i][j]
            q[i] += A[i][j] * p[j]


def top_bicg(concrete_type, M, N):
    def stageS[
        T: (float32, int32), M: int32, N: int32
    ](A: "T[N, M]", r: "T[N]", s: "T[M]"):
        for i0 in range(N):  # pipeline
            r: T = r[i0]
            for j0 in range(M):  # unroll
                s[j0] += r * A[i0, j0]

    def stageQ[
        T: (float32, int32), M: int32, N: int32
    ](A: "T[N, M]", p: "T[M]", q: "T[N]"):
        for i1 in range(N):
            for j1 in range(M):
                q[i1] += A[i1, j1] * p[j1]

    def kernel_bicg[
        T: (float32, int32), M: int32, N: int32
    ](A: "T[N, M]", A_copy: "T[N, M]", p: "T[M]", r: "T[N]", q: "T[N]", s: "T[M]"):
        stageS(A, r, s)
        stageQ(A_copy, p, q)

    sch0 = allo.customize(stageS, instantiate=[concrete_type, M, N])
    sch0.pipeline("i0")
    sch0.partition(sch0.A, dim=2)
    sch0.partition(sch0.s, dim=1)

    sch1 = allo.customize(stageQ, instantiate=[concrete_type, M, N])
    sch1.reorder("j1", "i1")
    sch1.pipeline("j1")
    sch1.partition(sch1.A, dim=1)
    sch1.partition(sch1.q, dim=1)

    sch = allo.customize(kernel_bicg, instantiate=[concrete_type, M, N])
    sch.compose(sch0)
    sch.compose(sch1)
    # sch.dataflow("kernel_bicg")

    return sch


def test_bicg():
    # read problem size settings
    setting_path = os.path.join(os.path.dirname(__file__), "../psize.json")
    with open(setting_path, "r") as fp:
        psize = json.load(fp)
    test_psize = "medium"
    M = psize["bicg"][test_psize]["M"]
    N = psize["bicg"][test_psize]["N"]
    concrete_type = float32
    sch = top_bicg(concrete_type, M, N)
    sch.build(target="vitis_hls", mode="hw", project="bicg.prj")


if __name__ == "__main__":
    test_bicg()