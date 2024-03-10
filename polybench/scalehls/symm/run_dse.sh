#!/bin/bash

# translate to MLIR
cgeist test_symm.c \
    -function=test_symm \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_symm.mlir

scalehls-opt test_symm.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_symm target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_symm_dse.cpp