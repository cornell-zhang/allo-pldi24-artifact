#!/bin/bash

# translate to MLIR
cgeist test_syr2k.c \
    -function=test_syr2k \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_syr2k.mlir

scalehls-opt test_syr2k.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_syr2k target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_syr2k_dse.cpp