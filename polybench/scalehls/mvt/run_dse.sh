#!/bin/bash

# translate to MLIR
cgeist test_mvt.c \
    -function=test_mvt \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_mvt.mlir

scalehls-opt test_mvt.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_mvt target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_mvt_dse.cpp