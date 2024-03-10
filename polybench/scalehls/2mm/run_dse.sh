#!/bin/bash

# translate to MLIR
cgeist test_2mm.c \
    -function=test_2mm \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_2mm.mlir

scalehls-opt test_2mm.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_2mm target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_2mm_dse.cpp