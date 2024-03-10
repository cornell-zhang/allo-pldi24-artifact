#!/bin/bash

# translate to MLIR
cgeist test_3mm.c \
    -function=test_3mm \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_3mm.mlir

scalehls-opt test_3mm.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_3mm target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_3mm_dse.cpp