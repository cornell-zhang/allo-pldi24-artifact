# Copyright Allo authors. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0​
#=============================================================================
# run_base.tcl 
#=============================================================================
# @brief: A Tcl script for synthesizing the design.

# Project name
set hls_prj 2mm.prj

# Open/reset the project
open_project ${hls_prj} -reset

open_solution -reset solution1 -flow_target vivado

# Top function of the design is "top"
set_top test_2mm

# Add design and testbench files
add_files test_2mm_dse.cpp

open_solution "solution1"
# Use Zynq device
set_part {xcu280-fsvh2892-2L-e}

# Target clock period is 3.33ns
create_clock -period 3.33

# Directives 

############################################

# Simulate the C++ design
#csim_design -O
# Synthesize the design
csynth_design
# Co-simulate the design
#cosim_design
# Implement the design
#export_design -flow impl

exit