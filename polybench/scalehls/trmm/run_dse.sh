#!/bin/bash

# translate to MLIR
cgeist test_trmm.c \
    -function=test_trmm \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_trmm.mlir

scalehls-opt test_trmm.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_trmm target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_trmm_dse.cpp