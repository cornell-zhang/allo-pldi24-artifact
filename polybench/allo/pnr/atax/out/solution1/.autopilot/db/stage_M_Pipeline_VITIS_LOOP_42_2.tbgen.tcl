set moduleName stage_M_Pipeline_VITIS_LOOP_42_2
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set C_modelName {stage_M_Pipeline_VITIS_LOOP_42_2}
set C_modelType { void 0 }
set C_modelArgList {
	{ v2 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_1 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_2 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_3 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_4 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_5 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_6 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_7 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_8 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_9 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_10 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_11 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_12 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_13 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_14 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_15 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_16 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_17 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_18 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_19 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_20 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_21 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_22 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_23 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_24 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_25 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_26 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_27 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_28 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_29 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_30 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_31 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_32 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_33 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_34 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_35 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_36 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_37 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ v2_38 float 32 regular {array 10 { 1 3 } 1 1 }  }
	{ out_Ax_fifo1 int 32 regular {fifo 1 volatile }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "v2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_3", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_4", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_5", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_6", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_7", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_8", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_9", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_10", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_11", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_12", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_13", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_14", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_15", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_16", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_17", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_18", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_19", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_20", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_21", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_22", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_23", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_24", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_25", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_26", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_27", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_28", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_29", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_30", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_31", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_32", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_33", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_34", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_35", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_36", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_37", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "v2_38", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "out_Ax_fifo1", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 128
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ out_Ax_fifo1_din sc_out sc_lv 32 signal 39 } 
	{ out_Ax_fifo1_num_data_valid sc_in sc_lv 10 signal 39 } 
	{ out_Ax_fifo1_fifo_cap sc_in sc_lv 10 signal 39 } 
	{ out_Ax_fifo1_full_n sc_in sc_logic 1 signal 39 } 
	{ out_Ax_fifo1_write sc_out sc_logic 1 signal 39 } 
	{ v2_address0 sc_out sc_lv 4 signal 0 } 
	{ v2_ce0 sc_out sc_logic 1 signal 0 } 
	{ v2_q0 sc_in sc_lv 32 signal 0 } 
	{ v2_1_address0 sc_out sc_lv 4 signal 1 } 
	{ v2_1_ce0 sc_out sc_logic 1 signal 1 } 
	{ v2_1_q0 sc_in sc_lv 32 signal 1 } 
	{ v2_2_address0 sc_out sc_lv 4 signal 2 } 
	{ v2_2_ce0 sc_out sc_logic 1 signal 2 } 
	{ v2_2_q0 sc_in sc_lv 32 signal 2 } 
	{ v2_3_address0 sc_out sc_lv 4 signal 3 } 
	{ v2_3_ce0 sc_out sc_logic 1 signal 3 } 
	{ v2_3_q0 sc_in sc_lv 32 signal 3 } 
	{ v2_4_address0 sc_out sc_lv 4 signal 4 } 
	{ v2_4_ce0 sc_out sc_logic 1 signal 4 } 
	{ v2_4_q0 sc_in sc_lv 32 signal 4 } 
	{ v2_5_address0 sc_out sc_lv 4 signal 5 } 
	{ v2_5_ce0 sc_out sc_logic 1 signal 5 } 
	{ v2_5_q0 sc_in sc_lv 32 signal 5 } 
	{ v2_6_address0 sc_out sc_lv 4 signal 6 } 
	{ v2_6_ce0 sc_out sc_logic 1 signal 6 } 
	{ v2_6_q0 sc_in sc_lv 32 signal 6 } 
	{ v2_7_address0 sc_out sc_lv 4 signal 7 } 
	{ v2_7_ce0 sc_out sc_logic 1 signal 7 } 
	{ v2_7_q0 sc_in sc_lv 32 signal 7 } 
	{ v2_8_address0 sc_out sc_lv 4 signal 8 } 
	{ v2_8_ce0 sc_out sc_logic 1 signal 8 } 
	{ v2_8_q0 sc_in sc_lv 32 signal 8 } 
	{ v2_9_address0 sc_out sc_lv 4 signal 9 } 
	{ v2_9_ce0 sc_out sc_logic 1 signal 9 } 
	{ v2_9_q0 sc_in sc_lv 32 signal 9 } 
	{ v2_10_address0 sc_out sc_lv 4 signal 10 } 
	{ v2_10_ce0 sc_out sc_logic 1 signal 10 } 
	{ v2_10_q0 sc_in sc_lv 32 signal 10 } 
	{ v2_11_address0 sc_out sc_lv 4 signal 11 } 
	{ v2_11_ce0 sc_out sc_logic 1 signal 11 } 
	{ v2_11_q0 sc_in sc_lv 32 signal 11 } 
	{ v2_12_address0 sc_out sc_lv 4 signal 12 } 
	{ v2_12_ce0 sc_out sc_logic 1 signal 12 } 
	{ v2_12_q0 sc_in sc_lv 32 signal 12 } 
	{ v2_13_address0 sc_out sc_lv 4 signal 13 } 
	{ v2_13_ce0 sc_out sc_logic 1 signal 13 } 
	{ v2_13_q0 sc_in sc_lv 32 signal 13 } 
	{ v2_14_address0 sc_out sc_lv 4 signal 14 } 
	{ v2_14_ce0 sc_out sc_logic 1 signal 14 } 
	{ v2_14_q0 sc_in sc_lv 32 signal 14 } 
	{ v2_15_address0 sc_out sc_lv 4 signal 15 } 
	{ v2_15_ce0 sc_out sc_logic 1 signal 15 } 
	{ v2_15_q0 sc_in sc_lv 32 signal 15 } 
	{ v2_16_address0 sc_out sc_lv 4 signal 16 } 
	{ v2_16_ce0 sc_out sc_logic 1 signal 16 } 
	{ v2_16_q0 sc_in sc_lv 32 signal 16 } 
	{ v2_17_address0 sc_out sc_lv 4 signal 17 } 
	{ v2_17_ce0 sc_out sc_logic 1 signal 17 } 
	{ v2_17_q0 sc_in sc_lv 32 signal 17 } 
	{ v2_18_address0 sc_out sc_lv 4 signal 18 } 
	{ v2_18_ce0 sc_out sc_logic 1 signal 18 } 
	{ v2_18_q0 sc_in sc_lv 32 signal 18 } 
	{ v2_19_address0 sc_out sc_lv 4 signal 19 } 
	{ v2_19_ce0 sc_out sc_logic 1 signal 19 } 
	{ v2_19_q0 sc_in sc_lv 32 signal 19 } 
	{ v2_20_address0 sc_out sc_lv 4 signal 20 } 
	{ v2_20_ce0 sc_out sc_logic 1 signal 20 } 
	{ v2_20_q0 sc_in sc_lv 32 signal 20 } 
	{ v2_21_address0 sc_out sc_lv 4 signal 21 } 
	{ v2_21_ce0 sc_out sc_logic 1 signal 21 } 
	{ v2_21_q0 sc_in sc_lv 32 signal 21 } 
	{ v2_22_address0 sc_out sc_lv 4 signal 22 } 
	{ v2_22_ce0 sc_out sc_logic 1 signal 22 } 
	{ v2_22_q0 sc_in sc_lv 32 signal 22 } 
	{ v2_23_address0 sc_out sc_lv 4 signal 23 } 
	{ v2_23_ce0 sc_out sc_logic 1 signal 23 } 
	{ v2_23_q0 sc_in sc_lv 32 signal 23 } 
	{ v2_24_address0 sc_out sc_lv 4 signal 24 } 
	{ v2_24_ce0 sc_out sc_logic 1 signal 24 } 
	{ v2_24_q0 sc_in sc_lv 32 signal 24 } 
	{ v2_25_address0 sc_out sc_lv 4 signal 25 } 
	{ v2_25_ce0 sc_out sc_logic 1 signal 25 } 
	{ v2_25_q0 sc_in sc_lv 32 signal 25 } 
	{ v2_26_address0 sc_out sc_lv 4 signal 26 } 
	{ v2_26_ce0 sc_out sc_logic 1 signal 26 } 
	{ v2_26_q0 sc_in sc_lv 32 signal 26 } 
	{ v2_27_address0 sc_out sc_lv 4 signal 27 } 
	{ v2_27_ce0 sc_out sc_logic 1 signal 27 } 
	{ v2_27_q0 sc_in sc_lv 32 signal 27 } 
	{ v2_28_address0 sc_out sc_lv 4 signal 28 } 
	{ v2_28_ce0 sc_out sc_logic 1 signal 28 } 
	{ v2_28_q0 sc_in sc_lv 32 signal 28 } 
	{ v2_29_address0 sc_out sc_lv 4 signal 29 } 
	{ v2_29_ce0 sc_out sc_logic 1 signal 29 } 
	{ v2_29_q0 sc_in sc_lv 32 signal 29 } 
	{ v2_30_address0 sc_out sc_lv 4 signal 30 } 
	{ v2_30_ce0 sc_out sc_logic 1 signal 30 } 
	{ v2_30_q0 sc_in sc_lv 32 signal 30 } 
	{ v2_31_address0 sc_out sc_lv 4 signal 31 } 
	{ v2_31_ce0 sc_out sc_logic 1 signal 31 } 
	{ v2_31_q0 sc_in sc_lv 32 signal 31 } 
	{ v2_32_address0 sc_out sc_lv 4 signal 32 } 
	{ v2_32_ce0 sc_out sc_logic 1 signal 32 } 
	{ v2_32_q0 sc_in sc_lv 32 signal 32 } 
	{ v2_33_address0 sc_out sc_lv 4 signal 33 } 
	{ v2_33_ce0 sc_out sc_logic 1 signal 33 } 
	{ v2_33_q0 sc_in sc_lv 32 signal 33 } 
	{ v2_34_address0 sc_out sc_lv 4 signal 34 } 
	{ v2_34_ce0 sc_out sc_logic 1 signal 34 } 
	{ v2_34_q0 sc_in sc_lv 32 signal 34 } 
	{ v2_35_address0 sc_out sc_lv 4 signal 35 } 
	{ v2_35_ce0 sc_out sc_logic 1 signal 35 } 
	{ v2_35_q0 sc_in sc_lv 32 signal 35 } 
	{ v2_36_address0 sc_out sc_lv 4 signal 36 } 
	{ v2_36_ce0 sc_out sc_logic 1 signal 36 } 
	{ v2_36_q0 sc_in sc_lv 32 signal 36 } 
	{ v2_37_address0 sc_out sc_lv 4 signal 37 } 
	{ v2_37_ce0 sc_out sc_logic 1 signal 37 } 
	{ v2_37_q0 sc_in sc_lv 32 signal 37 } 
	{ v2_38_address0 sc_out sc_lv 4 signal 38 } 
	{ v2_38_ce0 sc_out sc_logic 1 signal 38 } 
	{ v2_38_q0 sc_in sc_lv 32 signal 38 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "out_Ax_fifo1_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "out_Ax_fifo1", "role": "din" }} , 
 	{ "name": "out_Ax_fifo1_num_data_valid", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "out_Ax_fifo1", "role": "num_data_valid" }} , 
 	{ "name": "out_Ax_fifo1_fifo_cap", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "out_Ax_fifo1", "role": "fifo_cap" }} , 
 	{ "name": "out_Ax_fifo1_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_Ax_fifo1", "role": "full_n" }} , 
 	{ "name": "out_Ax_fifo1_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_Ax_fifo1", "role": "write" }} , 
 	{ "name": "v2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2", "role": "address0" }} , 
 	{ "name": "v2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2", "role": "ce0" }} , 
 	{ "name": "v2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2", "role": "q0" }} , 
 	{ "name": "v2_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_1", "role": "address0" }} , 
 	{ "name": "v2_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_1", "role": "ce0" }} , 
 	{ "name": "v2_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_1", "role": "q0" }} , 
 	{ "name": "v2_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_2", "role": "address0" }} , 
 	{ "name": "v2_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_2", "role": "ce0" }} , 
 	{ "name": "v2_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_2", "role": "q0" }} , 
 	{ "name": "v2_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_3", "role": "address0" }} , 
 	{ "name": "v2_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_3", "role": "ce0" }} , 
 	{ "name": "v2_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_3", "role": "q0" }} , 
 	{ "name": "v2_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_4", "role": "address0" }} , 
 	{ "name": "v2_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_4", "role": "ce0" }} , 
 	{ "name": "v2_4_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_4", "role": "q0" }} , 
 	{ "name": "v2_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_5", "role": "address0" }} , 
 	{ "name": "v2_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_5", "role": "ce0" }} , 
 	{ "name": "v2_5_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_5", "role": "q0" }} , 
 	{ "name": "v2_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_6", "role": "address0" }} , 
 	{ "name": "v2_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_6", "role": "ce0" }} , 
 	{ "name": "v2_6_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_6", "role": "q0" }} , 
 	{ "name": "v2_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_7", "role": "address0" }} , 
 	{ "name": "v2_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_7", "role": "ce0" }} , 
 	{ "name": "v2_7_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_7", "role": "q0" }} , 
 	{ "name": "v2_8_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_8", "role": "address0" }} , 
 	{ "name": "v2_8_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_8", "role": "ce0" }} , 
 	{ "name": "v2_8_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_8", "role": "q0" }} , 
 	{ "name": "v2_9_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_9", "role": "address0" }} , 
 	{ "name": "v2_9_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_9", "role": "ce0" }} , 
 	{ "name": "v2_9_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_9", "role": "q0" }} , 
 	{ "name": "v2_10_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_10", "role": "address0" }} , 
 	{ "name": "v2_10_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_10", "role": "ce0" }} , 
 	{ "name": "v2_10_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_10", "role": "q0" }} , 
 	{ "name": "v2_11_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_11", "role": "address0" }} , 
 	{ "name": "v2_11_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_11", "role": "ce0" }} , 
 	{ "name": "v2_11_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_11", "role": "q0" }} , 
 	{ "name": "v2_12_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_12", "role": "address0" }} , 
 	{ "name": "v2_12_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_12", "role": "ce0" }} , 
 	{ "name": "v2_12_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_12", "role": "q0" }} , 
 	{ "name": "v2_13_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_13", "role": "address0" }} , 
 	{ "name": "v2_13_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_13", "role": "ce0" }} , 
 	{ "name": "v2_13_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_13", "role": "q0" }} , 
 	{ "name": "v2_14_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_14", "role": "address0" }} , 
 	{ "name": "v2_14_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_14", "role": "ce0" }} , 
 	{ "name": "v2_14_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_14", "role": "q0" }} , 
 	{ "name": "v2_15_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_15", "role": "address0" }} , 
 	{ "name": "v2_15_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_15", "role": "ce0" }} , 
 	{ "name": "v2_15_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_15", "role": "q0" }} , 
 	{ "name": "v2_16_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_16", "role": "address0" }} , 
 	{ "name": "v2_16_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_16", "role": "ce0" }} , 
 	{ "name": "v2_16_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_16", "role": "q0" }} , 
 	{ "name": "v2_17_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_17", "role": "address0" }} , 
 	{ "name": "v2_17_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_17", "role": "ce0" }} , 
 	{ "name": "v2_17_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_17", "role": "q0" }} , 
 	{ "name": "v2_18_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_18", "role": "address0" }} , 
 	{ "name": "v2_18_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_18", "role": "ce0" }} , 
 	{ "name": "v2_18_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_18", "role": "q0" }} , 
 	{ "name": "v2_19_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_19", "role": "address0" }} , 
 	{ "name": "v2_19_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_19", "role": "ce0" }} , 
 	{ "name": "v2_19_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_19", "role": "q0" }} , 
 	{ "name": "v2_20_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_20", "role": "address0" }} , 
 	{ "name": "v2_20_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_20", "role": "ce0" }} , 
 	{ "name": "v2_20_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_20", "role": "q0" }} , 
 	{ "name": "v2_21_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_21", "role": "address0" }} , 
 	{ "name": "v2_21_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_21", "role": "ce0" }} , 
 	{ "name": "v2_21_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_21", "role": "q0" }} , 
 	{ "name": "v2_22_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_22", "role": "address0" }} , 
 	{ "name": "v2_22_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_22", "role": "ce0" }} , 
 	{ "name": "v2_22_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_22", "role": "q0" }} , 
 	{ "name": "v2_23_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_23", "role": "address0" }} , 
 	{ "name": "v2_23_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_23", "role": "ce0" }} , 
 	{ "name": "v2_23_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_23", "role": "q0" }} , 
 	{ "name": "v2_24_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_24", "role": "address0" }} , 
 	{ "name": "v2_24_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_24", "role": "ce0" }} , 
 	{ "name": "v2_24_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_24", "role": "q0" }} , 
 	{ "name": "v2_25_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_25", "role": "address0" }} , 
 	{ "name": "v2_25_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_25", "role": "ce0" }} , 
 	{ "name": "v2_25_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_25", "role": "q0" }} , 
 	{ "name": "v2_26_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_26", "role": "address0" }} , 
 	{ "name": "v2_26_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_26", "role": "ce0" }} , 
 	{ "name": "v2_26_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_26", "role": "q0" }} , 
 	{ "name": "v2_27_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_27", "role": "address0" }} , 
 	{ "name": "v2_27_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_27", "role": "ce0" }} , 
 	{ "name": "v2_27_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_27", "role": "q0" }} , 
 	{ "name": "v2_28_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_28", "role": "address0" }} , 
 	{ "name": "v2_28_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_28", "role": "ce0" }} , 
 	{ "name": "v2_28_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_28", "role": "q0" }} , 
 	{ "name": "v2_29_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_29", "role": "address0" }} , 
 	{ "name": "v2_29_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_29", "role": "ce0" }} , 
 	{ "name": "v2_29_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_29", "role": "q0" }} , 
 	{ "name": "v2_30_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_30", "role": "address0" }} , 
 	{ "name": "v2_30_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_30", "role": "ce0" }} , 
 	{ "name": "v2_30_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_30", "role": "q0" }} , 
 	{ "name": "v2_31_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_31", "role": "address0" }} , 
 	{ "name": "v2_31_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_31", "role": "ce0" }} , 
 	{ "name": "v2_31_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_31", "role": "q0" }} , 
 	{ "name": "v2_32_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_32", "role": "address0" }} , 
 	{ "name": "v2_32_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_32", "role": "ce0" }} , 
 	{ "name": "v2_32_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_32", "role": "q0" }} , 
 	{ "name": "v2_33_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_33", "role": "address0" }} , 
 	{ "name": "v2_33_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_33", "role": "ce0" }} , 
 	{ "name": "v2_33_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_33", "role": "q0" }} , 
 	{ "name": "v2_34_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_34", "role": "address0" }} , 
 	{ "name": "v2_34_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_34", "role": "ce0" }} , 
 	{ "name": "v2_34_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_34", "role": "q0" }} , 
 	{ "name": "v2_35_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_35", "role": "address0" }} , 
 	{ "name": "v2_35_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_35", "role": "ce0" }} , 
 	{ "name": "v2_35_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_35", "role": "q0" }} , 
 	{ "name": "v2_36_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_36", "role": "address0" }} , 
 	{ "name": "v2_36_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_36", "role": "ce0" }} , 
 	{ "name": "v2_36_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_36", "role": "q0" }} , 
 	{ "name": "v2_37_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_37", "role": "address0" }} , 
 	{ "name": "v2_37_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_37", "role": "ce0" }} , 
 	{ "name": "v2_37_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_37", "role": "q0" }} , 
 	{ "name": "v2_38_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "v2_38", "role": "address0" }} , 
 	{ "name": "v2_38_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "v2_38", "role": "ce0" }} , 
 	{ "name": "v2_38_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "v2_38", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "stage_M_Pipeline_VITIS_LOOP_42_2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "393", "EstimateLatencyMax" : "393",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "v2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_10", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_11", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_12", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_13", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_14", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_15", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_16", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_17", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_18", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_19", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_20", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_21", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_22", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_23", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_24", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_25", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_26", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_27", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_28", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_29", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_30", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_31", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_32", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_33", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_34", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_35", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_36", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_37", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "v2_38", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_Ax_fifo1", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "out_Ax_fifo1_blk_n", "Type" : "RtlSignal"}]}],
		"Loop" : [
			{"Name" : "VITIS_LOOP_42_2", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mux_399_32_1_1_U203", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	stage_M_Pipeline_VITIS_LOOP_42_2 {
		v2 {Type I LastRead 0 FirstWrite -1}
		v2_1 {Type I LastRead 0 FirstWrite -1}
		v2_2 {Type I LastRead 0 FirstWrite -1}
		v2_3 {Type I LastRead 0 FirstWrite -1}
		v2_4 {Type I LastRead 0 FirstWrite -1}
		v2_5 {Type I LastRead 0 FirstWrite -1}
		v2_6 {Type I LastRead 0 FirstWrite -1}
		v2_7 {Type I LastRead 0 FirstWrite -1}
		v2_8 {Type I LastRead 0 FirstWrite -1}
		v2_9 {Type I LastRead 0 FirstWrite -1}
		v2_10 {Type I LastRead 0 FirstWrite -1}
		v2_11 {Type I LastRead 0 FirstWrite -1}
		v2_12 {Type I LastRead 0 FirstWrite -1}
		v2_13 {Type I LastRead 0 FirstWrite -1}
		v2_14 {Type I LastRead 0 FirstWrite -1}
		v2_15 {Type I LastRead 0 FirstWrite -1}
		v2_16 {Type I LastRead 0 FirstWrite -1}
		v2_17 {Type I LastRead 0 FirstWrite -1}
		v2_18 {Type I LastRead 0 FirstWrite -1}
		v2_19 {Type I LastRead 0 FirstWrite -1}
		v2_20 {Type I LastRead 0 FirstWrite -1}
		v2_21 {Type I LastRead 0 FirstWrite -1}
		v2_22 {Type I LastRead 0 FirstWrite -1}
		v2_23 {Type I LastRead 0 FirstWrite -1}
		v2_24 {Type I LastRead 0 FirstWrite -1}
		v2_25 {Type I LastRead 0 FirstWrite -1}
		v2_26 {Type I LastRead 0 FirstWrite -1}
		v2_27 {Type I LastRead 0 FirstWrite -1}
		v2_28 {Type I LastRead 0 FirstWrite -1}
		v2_29 {Type I LastRead 0 FirstWrite -1}
		v2_30 {Type I LastRead 0 FirstWrite -1}
		v2_31 {Type I LastRead 0 FirstWrite -1}
		v2_32 {Type I LastRead 0 FirstWrite -1}
		v2_33 {Type I LastRead 0 FirstWrite -1}
		v2_34 {Type I LastRead 0 FirstWrite -1}
		v2_35 {Type I LastRead 0 FirstWrite -1}
		v2_36 {Type I LastRead 0 FirstWrite -1}
		v2_37 {Type I LastRead 0 FirstWrite -1}
		v2_38 {Type I LastRead 0 FirstWrite -1}
		out_Ax_fifo1 {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "393", "Max" : "393"}
	, {"Name" : "Interval", "Min" : "393", "Max" : "393"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	v2 { ap_memory {  { v2_address0 mem_address 1 4 }  { v2_ce0 mem_ce 1 1 }  { v2_q0 in_data 0 32 } } }
	v2_1 { ap_memory {  { v2_1_address0 mem_address 1 4 }  { v2_1_ce0 mem_ce 1 1 }  { v2_1_q0 in_data 0 32 } } }
	v2_2 { ap_memory {  { v2_2_address0 mem_address 1 4 }  { v2_2_ce0 mem_ce 1 1 }  { v2_2_q0 in_data 0 32 } } }
	v2_3 { ap_memory {  { v2_3_address0 mem_address 1 4 }  { v2_3_ce0 mem_ce 1 1 }  { v2_3_q0 in_data 0 32 } } }
	v2_4 { ap_memory {  { v2_4_address0 mem_address 1 4 }  { v2_4_ce0 mem_ce 1 1 }  { v2_4_q0 in_data 0 32 } } }
	v2_5 { ap_memory {  { v2_5_address0 mem_address 1 4 }  { v2_5_ce0 mem_ce 1 1 }  { v2_5_q0 in_data 0 32 } } }
	v2_6 { ap_memory {  { v2_6_address0 mem_address 1 4 }  { v2_6_ce0 mem_ce 1 1 }  { v2_6_q0 in_data 0 32 } } }
	v2_7 { ap_memory {  { v2_7_address0 mem_address 1 4 }  { v2_7_ce0 mem_ce 1 1 }  { v2_7_q0 in_data 0 32 } } }
	v2_8 { ap_memory {  { v2_8_address0 mem_address 1 4 }  { v2_8_ce0 mem_ce 1 1 }  { v2_8_q0 in_data 0 32 } } }
	v2_9 { ap_memory {  { v2_9_address0 mem_address 1 4 }  { v2_9_ce0 mem_ce 1 1 }  { v2_9_q0 in_data 0 32 } } }
	v2_10 { ap_memory {  { v2_10_address0 mem_address 1 4 }  { v2_10_ce0 mem_ce 1 1 }  { v2_10_q0 in_data 0 32 } } }
	v2_11 { ap_memory {  { v2_11_address0 mem_address 1 4 }  { v2_11_ce0 mem_ce 1 1 }  { v2_11_q0 in_data 0 32 } } }
	v2_12 { ap_memory {  { v2_12_address0 mem_address 1 4 }  { v2_12_ce0 mem_ce 1 1 }  { v2_12_q0 in_data 0 32 } } }
	v2_13 { ap_memory {  { v2_13_address0 mem_address 1 4 }  { v2_13_ce0 mem_ce 1 1 }  { v2_13_q0 in_data 0 32 } } }
	v2_14 { ap_memory {  { v2_14_address0 mem_address 1 4 }  { v2_14_ce0 mem_ce 1 1 }  { v2_14_q0 in_data 0 32 } } }
	v2_15 { ap_memory {  { v2_15_address0 mem_address 1 4 }  { v2_15_ce0 mem_ce 1 1 }  { v2_15_q0 in_data 0 32 } } }
	v2_16 { ap_memory {  { v2_16_address0 mem_address 1 4 }  { v2_16_ce0 mem_ce 1 1 }  { v2_16_q0 in_data 0 32 } } }
	v2_17 { ap_memory {  { v2_17_address0 mem_address 1 4 }  { v2_17_ce0 mem_ce 1 1 }  { v2_17_q0 in_data 0 32 } } }
	v2_18 { ap_memory {  { v2_18_address0 mem_address 1 4 }  { v2_18_ce0 mem_ce 1 1 }  { v2_18_q0 in_data 0 32 } } }
	v2_19 { ap_memory {  { v2_19_address0 mem_address 1 4 }  { v2_19_ce0 mem_ce 1 1 }  { v2_19_q0 in_data 0 32 } } }
	v2_20 { ap_memory {  { v2_20_address0 mem_address 1 4 }  { v2_20_ce0 mem_ce 1 1 }  { v2_20_q0 in_data 0 32 } } }
	v2_21 { ap_memory {  { v2_21_address0 mem_address 1 4 }  { v2_21_ce0 mem_ce 1 1 }  { v2_21_q0 in_data 0 32 } } }
	v2_22 { ap_memory {  { v2_22_address0 mem_address 1 4 }  { v2_22_ce0 mem_ce 1 1 }  { v2_22_q0 in_data 0 32 } } }
	v2_23 { ap_memory {  { v2_23_address0 mem_address 1 4 }  { v2_23_ce0 mem_ce 1 1 }  { v2_23_q0 in_data 0 32 } } }
	v2_24 { ap_memory {  { v2_24_address0 mem_address 1 4 }  { v2_24_ce0 mem_ce 1 1 }  { v2_24_q0 in_data 0 32 } } }
	v2_25 { ap_memory {  { v2_25_address0 mem_address 1 4 }  { v2_25_ce0 mem_ce 1 1 }  { v2_25_q0 in_data 0 32 } } }
	v2_26 { ap_memory {  { v2_26_address0 mem_address 1 4 }  { v2_26_ce0 mem_ce 1 1 }  { v2_26_q0 in_data 0 32 } } }
	v2_27 { ap_memory {  { v2_27_address0 mem_address 1 4 }  { v2_27_ce0 mem_ce 1 1 }  { v2_27_q0 in_data 0 32 } } }
	v2_28 { ap_memory {  { v2_28_address0 mem_address 1 4 }  { v2_28_ce0 mem_ce 1 1 }  { v2_28_q0 in_data 0 32 } } }
	v2_29 { ap_memory {  { v2_29_address0 mem_address 1 4 }  { v2_29_ce0 mem_ce 1 1 }  { v2_29_q0 in_data 0 32 } } }
	v2_30 { ap_memory {  { v2_30_address0 mem_address 1 4 }  { v2_30_ce0 mem_ce 1 1 }  { v2_30_q0 in_data 0 32 } } }
	v2_31 { ap_memory {  { v2_31_address0 mem_address 1 4 }  { v2_31_ce0 mem_ce 1 1 }  { v2_31_q0 in_data 0 32 } } }
	v2_32 { ap_memory {  { v2_32_address0 mem_address 1 4 }  { v2_32_ce0 mem_ce 1 1 }  { v2_32_q0 in_data 0 32 } } }
	v2_33 { ap_memory {  { v2_33_address0 mem_address 1 4 }  { v2_33_ce0 mem_ce 1 1 }  { v2_33_q0 in_data 0 32 } } }
	v2_34 { ap_memory {  { v2_34_address0 mem_address 1 4 }  { v2_34_ce0 mem_ce 1 1 }  { v2_34_q0 in_data 0 32 } } }
	v2_35 { ap_memory {  { v2_35_address0 mem_address 1 4 }  { v2_35_ce0 mem_ce 1 1 }  { v2_35_q0 in_data 0 32 } } }
	v2_36 { ap_memory {  { v2_36_address0 mem_address 1 4 }  { v2_36_ce0 mem_ce 1 1 }  { v2_36_q0 in_data 0 32 } } }
	v2_37 { ap_memory {  { v2_37_address0 mem_address 1 4 }  { v2_37_ce0 mem_ce 1 1 }  { v2_37_q0 in_data 0 32 } } }
	v2_38 { ap_memory {  { v2_38_address0 mem_address 1 4 }  { v2_38_ce0 mem_ce 1 1 }  { v2_38_q0 in_data 0 32 } } }
	out_Ax_fifo1 { ap_fifo {  { out_Ax_fifo1_din fifo_port_we 1 32 }  { out_Ax_fifo1_num_data_valid fifo_status_num_data_valid 0 10 }  { out_Ax_fifo1_fifo_cap fifo_update 0 10 }  { out_Ax_fifo1_full_n fifo_status 0 1 }  { out_Ax_fifo1_write fifo_data 1 1 } } }
}
