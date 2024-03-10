#!/bin/bash

# translate to MLIR
cgeist test_gemm.c \
    -function=test_gemm \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_gemm.mlir

scalehls-opt test_gemm.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_gemm target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_gemm_dse.cpp