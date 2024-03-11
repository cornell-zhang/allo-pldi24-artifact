# Copyright Allo authors. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

#=============================================================================
# run_base.tcl 
#=============================================================================
# @brief: A Tcl script for synthesizing the design.

# Project name
set hls_prj out_slr1.prj

# Open/reset the project
open_project ${hls_prj} -reset

# Top function of the design is "top"
set_top kernel_symm

# Add design and testbench files
add_files SLR1.cpp
add_files -tb host.cpp -cflags "-std=gnu++0x"

open_solution "solution1"
# Use Zynq device
set_part {xcu280-fsvh2892-2L-e}

# Target clock period is 3.33ns
# create_clock -period 3.33
create_clock -name ap_clk -period 2.5

# Directives 

############################################

# Simulate the C++ design
#csim_design -O
# Synthesize the design
csynth_design
# Co-simulate the design
#cosim_design
# Implement the design
export_design -flow impl
get_clock_period -name ap_clk -ns

exit
