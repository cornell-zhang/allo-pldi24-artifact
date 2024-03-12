# Copyright Allo authors. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

#=============================================================================
# run_base.tcl 
#=============================================================================
# @brief: A Tcl script for synthesizing the design.

# Project name
set hls_prj output_100.prj

# Open/reset the project
open_project ${hls_prj} -reset

open_solution -reset solution1 -flow_target vivado

# Top function of the design is "top"
set_top test_jacobi

# Add design and testbench files
add_files test_jacobi.cpp
add_files -tb host.cpp -cflags "-std=gnu++0x"

open_solution "solution1"
# Use Zynq device
set_part {xcu280-fsvh2892-2L-e}

# Target clock period is 10ns
create_clock -name ap_clk -period 3.33


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