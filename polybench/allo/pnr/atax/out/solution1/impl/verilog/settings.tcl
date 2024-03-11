# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1.2 (64-bit)
# Tool Version Limit: 2022.04
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# ==============================================================
#
# Settings for Vivado implementation flow
#
set top_module kernel_atax
set language verilog
set family virtexuplushbm
set device xcu280
set package -fsvh2892
set speed -2L-e
set clock ap_clk
set fsm_ext "off"

# For customizing the implementation flow
set add_io_buffers false ;# true|false
