# Project name
set hls_prj resnet18_scalehls.prj

# Open/reset the project
open_project ${hls_prj} -reset

open_solution -reset solution1 -flow_target vivado

# Top function of the design is "top"
set_top main_graph

# Add design and testbench files
add_files resnet18_g7l7d.cpp
# add_files -tb host.cpp -cflags "-std=gnu++0x"

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
