#!/bin/bash

# translate to MLIR
cgeist test_atax.c \
    -function=test_atax \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_atax.mlir

scalehls-opt test_atax.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_atax target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_atax_dse.cpp