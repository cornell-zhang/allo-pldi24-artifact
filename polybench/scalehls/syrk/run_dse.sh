#!/bin/bash

# translate to MLIR
cgeist test_syrk.c \
    -function=test_syrk \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_syrk.mlir

scalehls-opt test_syrk.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_syrk target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_syrk_dse.cpp