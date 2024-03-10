# Copyright Allo authors. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

import os
import json
import pytest
import allo
import numpy as np
from allo.ir.types import int32, float32
import allo.ir.types as T


def mvt_np(A, x1, x2, y1, y2):
    N = A.shape[0]
    for i in range(N):
        for j in range(N):
            x1[i] += A[i, j] * y1[j]
            x2[i] += A[j, i] * y2[j]


def mvt(concrete_type, N):
    def stageA[
        T: (float32, int32), N: int32
    ](x1_in: "T[N]", x1_out: "T[N]", A: "T[N, N]", y1: "T[N]"):
        for i0 in allo.grid(N, name="A"):
            x: T = x1_in[i0]
            for j0 in allo.reduction(N):
                x += A[i0, j0] * y1[j0]
            x1_out[i0] = x

    def stageB[
        T: (float32, int32), N: int32
    ](x2_in: "T[N]", x2_out: "T[N]", A: "T[N, N]", y2: "T[N]"):
        for i1 in allo.grid(N, name="B"):
            x: T = x2_in[i1]
            for j1 in allo.reduction(N):
                x += A[j1, i1] * y2[j1]
            x2_out[i1] = x

    def kernel_mvt[
        T: (float32, int32), N: int32
    ](
        A: "T[N, N]",
        A_copy: "T[N, N]",
        y1: "T[N]",
        y2: "T[N]",
        x1: "T[N]",
        x2: "T[N]",
        x1_out: "T[N]",
        x2_out: "T[N]",
    ):
        stageA[T, N](x1, x1_out, A, y1)
        stageB[T, N](x2, x2_out, A_copy, y2)

    sch0 = allo.customize(stageA, instantiate=[concrete_type, N])
    sch0.pipeline("i0")
    sch0.partition(sch0.A, dim=2)
    sch0.partition(sch0.y1, dim=1)

    sch1 = allo.customize(stageB, instantiate=[concrete_type, N])
    sch1.pipeline("i1")
    sch1.partition(sch1.A, dim=1)
    sch1.partition(sch1.y2, dim=1)

    sch = allo.customize(kernel_mvt, instantiate=[concrete_type, N])
    sch.compose(sch0)
    sch.compose(sch1)
    return sch


def test_mvt():
    # read problem size settings
    setting_path = os.path.join(os.path.dirname(__file__), "../psize.json")
    with open(setting_path, "r") as fp:
        psize = json.load(fp)
    test_psize = "medium"
    N = psize["mvt"][test_psize]["N"]
    concrete_type = float32
    sch = mvt(concrete_type, N)
    sch.build(target="vitis_hls", mode="hw", project="mvt.prj")


if __name__ == "__main__":
    test_mvt()