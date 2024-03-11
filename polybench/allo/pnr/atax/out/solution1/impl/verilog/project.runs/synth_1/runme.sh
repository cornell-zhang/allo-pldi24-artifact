#!/bin/sh

# 
# Vivado(TM)
# runme.sh: a Vivado-generated Runs Script for UNIX
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# 

if [ -z "$PATH" ]; then
  PATH=/opt/xilinx/2022.1/Vitis/2022.1/bin:/opt/xilinx/2022.1/Vivado/2022.1/ids_lite/ISE/bin/lin64:/opt/xilinx/2022.1/Vivado/2022.1/bin
else
  PATH=/opt/xilinx/2022.1/Vitis/2022.1/bin:/opt/xilinx/2022.1/Vivado/2022.1/ids_lite/ISE/bin/lin64:/opt/xilinx/2022.1/Vivado/2022.1/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=
else
  LD_LIBRARY_PATH=:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD='/work/shared/users/phd/nz264/pldi/polybench/allo/atax/atax_ii_1/out.prj/solution1/impl/verilog/project.runs/synth_1'
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

EAStep vivado -log bd_0_wrapper.vds -m64 -product Vivado -mode batch -messageDb vivado.pb -notrace -source bd_0_wrapper.tcl
