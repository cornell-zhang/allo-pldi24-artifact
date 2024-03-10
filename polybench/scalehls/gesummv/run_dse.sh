#!/bin/bash

# translate to MLIR
cgeist test_gesummv.c \
    -function=test_gesummv \
    -S \
    -memref-fullrank \
    -raise-scf-to-affine > test_gesummv.mlir

scalehls-opt test_gesummv.mlir \
    -debug-only=scalehls \
    -scalehls-dse-pipeline="top-func=test_gesummv target-spec=../config.json" \
    | scalehls-translate -scalehls-emit-hlscpp > test_gesummv_dse.cpp