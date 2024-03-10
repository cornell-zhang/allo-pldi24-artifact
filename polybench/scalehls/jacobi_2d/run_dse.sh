#!/bin/bash

# translate to MLIR
cgeist test_jacobi.c \
    -function=test_jacobi \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_jacobi.mlir

scalehls-opt test_jacobi.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_jacobi target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_jacobi_dse.cpp