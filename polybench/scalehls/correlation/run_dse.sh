#!/bin/bash

# translate to MLIR
# cgeist test_cor.c \
#     -function=test_cor \
#     -S \
#     -memref-fullrank \
#     -raise-scf-to-affine > test_cor.mlir

scalehls-opt test_cor.mlir.fixedcast \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_cor target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_cor_dse.cpp