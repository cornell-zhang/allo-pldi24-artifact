# This script segment is generated automatically by AutoPilot

# Memory (RAM/ROM)  definition:
set ID 455
set hasByteEnable 0
set MemName kernel_atax_stage_N_v11_RAM_AUTO_1R1W
set CoreName ap_simcore_mem
set PortList { 2 3 }
set DataWd 32
set AddrRange 390
set AddrWd 9
set impl_style auto
set TrueReset 0
set IsROM 0
set ROMData { }
set HasInitializer 0
set Initializer $ROMData
set NumOfStage 2
set DelayBudget 1.196
if {${::AESL::PGuard_simmodel_gen}} {
if {[info proc ap_gen_simcore_mem] == "ap_gen_simcore_mem"} {
    eval "ap_gen_simcore_mem { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem  \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    port_num 2 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
} else {
    puts "@W \[IMPL-102\] Cannot find ap_gen_simcore_mem, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $MemName BINDTYPE {storage} TYPE {ram} IMPL {auto} LATENCY 2 ALLOW_PRAGMA 1
}


set CoreName RAM
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_RAM] == "::AESL_LIB_VIRTEX::xil_gen_RAM"} {
    eval "::AESL_LIB_VIRTEX::xil_gen_RAM { \
    id ${ID} \
    name ${MemName} \
    corename ${CoreName}  \
    op mem  \
    hasByteEnable ${hasByteEnable} \
    reset_level 1 \
    sync_rst true \
    stage_num ${NumOfStage}  \
    port_num 2 \
    port_list \{${PortList}\} \
    data_wd ${DataWd} \
    addr_wd ${AddrWd} \
    addr_range ${AddrRange} \
    style ${impl_style} \
    true_reset ${TrueReset} \
    delay_budget ${DelayBudget} \
    HasInitializer ${HasInitializer} \
    rom_data \{${ROMData}\} \
 } "
  } else {
    puts "@W \[IMPL-104\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_RAM, check your platform lib"
  }
}


# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 456 \
    name v21_0 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_0 \
    op interface \
    ports { v21_0_address0 { O 12 vector } v21_0_ce0 { O 1 bit } v21_0_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_0'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 457 \
    name v21_1 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_1 \
    op interface \
    ports { v21_1_address0 { O 12 vector } v21_1_ce0 { O 1 bit } v21_1_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_1'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 458 \
    name v21_2 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_2 \
    op interface \
    ports { v21_2_address0 { O 12 vector } v21_2_ce0 { O 1 bit } v21_2_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_2'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 459 \
    name v21_3 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_3 \
    op interface \
    ports { v21_3_address0 { O 12 vector } v21_3_ce0 { O 1 bit } v21_3_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_3'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 460 \
    name v21_4 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_4 \
    op interface \
    ports { v21_4_address0 { O 12 vector } v21_4_ce0 { O 1 bit } v21_4_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_4'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 461 \
    name v21_5 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_5 \
    op interface \
    ports { v21_5_address0 { O 12 vector } v21_5_ce0 { O 1 bit } v21_5_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_5'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 462 \
    name v21_6 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_6 \
    op interface \
    ports { v21_6_address0 { O 12 vector } v21_6_ce0 { O 1 bit } v21_6_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_6'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 463 \
    name v21_7 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_7 \
    op interface \
    ports { v21_7_address0 { O 12 vector } v21_7_ce0 { O 1 bit } v21_7_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_7'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 464 \
    name v21_8 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_8 \
    op interface \
    ports { v21_8_address0 { O 12 vector } v21_8_ce0 { O 1 bit } v21_8_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_8'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 465 \
    name v21_9 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_9 \
    op interface \
    ports { v21_9_address0 { O 12 vector } v21_9_ce0 { O 1 bit } v21_9_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_9'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 466 \
    name v21_10 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_10 \
    op interface \
    ports { v21_10_address0 { O 12 vector } v21_10_ce0 { O 1 bit } v21_10_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_10'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 467 \
    name v21_11 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_11 \
    op interface \
    ports { v21_11_address0 { O 12 vector } v21_11_ce0 { O 1 bit } v21_11_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_11'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 468 \
    name v21_12 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_12 \
    op interface \
    ports { v21_12_address0 { O 12 vector } v21_12_ce0 { O 1 bit } v21_12_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_12'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 469 \
    name v21_13 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_13 \
    op interface \
    ports { v21_13_address0 { O 12 vector } v21_13_ce0 { O 1 bit } v21_13_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_13'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 470 \
    name v21_14 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_14 \
    op interface \
    ports { v21_14_address0 { O 12 vector } v21_14_ce0 { O 1 bit } v21_14_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_14'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 471 \
    name v21_15 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_15 \
    op interface \
    ports { v21_15_address0 { O 12 vector } v21_15_ce0 { O 1 bit } v21_15_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_15'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 472 \
    name v21_16 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_16 \
    op interface \
    ports { v21_16_address0 { O 12 vector } v21_16_ce0 { O 1 bit } v21_16_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_16'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 473 \
    name v21_17 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_17 \
    op interface \
    ports { v21_17_address0 { O 12 vector } v21_17_ce0 { O 1 bit } v21_17_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_17'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 474 \
    name v21_18 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_18 \
    op interface \
    ports { v21_18_address0 { O 12 vector } v21_18_ce0 { O 1 bit } v21_18_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_18'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 475 \
    name v21_19 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_19 \
    op interface \
    ports { v21_19_address0 { O 12 vector } v21_19_ce0 { O 1 bit } v21_19_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_19'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 476 \
    name v21_20 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_20 \
    op interface \
    ports { v21_20_address0 { O 12 vector } v21_20_ce0 { O 1 bit } v21_20_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_20'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 477 \
    name v21_21 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_21 \
    op interface \
    ports { v21_21_address0 { O 12 vector } v21_21_ce0 { O 1 bit } v21_21_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_21'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 478 \
    name v21_22 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_22 \
    op interface \
    ports { v21_22_address0 { O 12 vector } v21_22_ce0 { O 1 bit } v21_22_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_22'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 479 \
    name v21_23 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_23 \
    op interface \
    ports { v21_23_address0 { O 12 vector } v21_23_ce0 { O 1 bit } v21_23_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_23'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 480 \
    name v21_24 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_24 \
    op interface \
    ports { v21_24_address0 { O 12 vector } v21_24_ce0 { O 1 bit } v21_24_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_24'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 481 \
    name v21_25 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_25 \
    op interface \
    ports { v21_25_address0 { O 12 vector } v21_25_ce0 { O 1 bit } v21_25_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_25'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 482 \
    name v21_26 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_26 \
    op interface \
    ports { v21_26_address0 { O 12 vector } v21_26_ce0 { O 1 bit } v21_26_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_26'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 483 \
    name v21_27 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_27 \
    op interface \
    ports { v21_27_address0 { O 12 vector } v21_27_ce0 { O 1 bit } v21_27_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_27'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 484 \
    name v21_28 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_28 \
    op interface \
    ports { v21_28_address0 { O 12 vector } v21_28_ce0 { O 1 bit } v21_28_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_28'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 485 \
    name v21_29 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_29 \
    op interface \
    ports { v21_29_address0 { O 12 vector } v21_29_ce0 { O 1 bit } v21_29_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_29'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 486 \
    name v21_30 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_30 \
    op interface \
    ports { v21_30_address0 { O 12 vector } v21_30_ce0 { O 1 bit } v21_30_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_30'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 487 \
    name v21_31 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_31 \
    op interface \
    ports { v21_31_address0 { O 12 vector } v21_31_ce0 { O 1 bit } v21_31_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_31'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 488 \
    name v21_32 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_32 \
    op interface \
    ports { v21_32_address0 { O 12 vector } v21_32_ce0 { O 1 bit } v21_32_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_32'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 489 \
    name v21_33 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_33 \
    op interface \
    ports { v21_33_address0 { O 12 vector } v21_33_ce0 { O 1 bit } v21_33_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_33'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 490 \
    name v21_34 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_34 \
    op interface \
    ports { v21_34_address0 { O 12 vector } v21_34_ce0 { O 1 bit } v21_34_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_34'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 491 \
    name v21_35 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_35 \
    op interface \
    ports { v21_35_address0 { O 12 vector } v21_35_ce0 { O 1 bit } v21_35_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_35'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 492 \
    name v21_36 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_36 \
    op interface \
    ports { v21_36_address0 { O 12 vector } v21_36_ce0 { O 1 bit } v21_36_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_36'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 493 \
    name v21_37 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_37 \
    op interface \
    ports { v21_37_address0 { O 12 vector } v21_37_ce0 { O 1 bit } v21_37_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_37'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 494 \
    name v21_38 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_38 \
    op interface \
    ports { v21_38_address0 { O 12 vector } v21_38_ce0 { O 1 bit } v21_38_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_38'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 495 \
    name v21_39 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_39 \
    op interface \
    ports { v21_39_address0 { O 12 vector } v21_39_ce0 { O 1 bit } v21_39_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_39'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 496 \
    name v21_40 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v21_40 \
    op interface \
    ports { v21_40_address0 { O 12 vector } v21_40_ce0 { O 1 bit } v21_40_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v21_40'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 498 \
    name v23_0 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_0 \
    op interface \
    ports { v23_0_address0 { O 4 vector } v23_0_ce0 { O 1 bit } v23_0_we0 { O 1 bit } v23_0_d0 { O 32 vector } v23_0_address1 { O 4 vector } v23_0_ce1 { O 1 bit } v23_0_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_0'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 499 \
    name v23_1 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_1 \
    op interface \
    ports { v23_1_address0 { O 4 vector } v23_1_ce0 { O 1 bit } v23_1_we0 { O 1 bit } v23_1_d0 { O 32 vector } v23_1_address1 { O 4 vector } v23_1_ce1 { O 1 bit } v23_1_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_1'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 500 \
    name v23_2 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_2 \
    op interface \
    ports { v23_2_address0 { O 4 vector } v23_2_ce0 { O 1 bit } v23_2_we0 { O 1 bit } v23_2_d0 { O 32 vector } v23_2_address1 { O 4 vector } v23_2_ce1 { O 1 bit } v23_2_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_2'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 501 \
    name v23_3 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_3 \
    op interface \
    ports { v23_3_address0 { O 4 vector } v23_3_ce0 { O 1 bit } v23_3_we0 { O 1 bit } v23_3_d0 { O 32 vector } v23_3_address1 { O 4 vector } v23_3_ce1 { O 1 bit } v23_3_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_3'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 502 \
    name v23_4 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_4 \
    op interface \
    ports { v23_4_address0 { O 4 vector } v23_4_ce0 { O 1 bit } v23_4_we0 { O 1 bit } v23_4_d0 { O 32 vector } v23_4_address1 { O 4 vector } v23_4_ce1 { O 1 bit } v23_4_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_4'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 503 \
    name v23_5 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_5 \
    op interface \
    ports { v23_5_address0 { O 4 vector } v23_5_ce0 { O 1 bit } v23_5_we0 { O 1 bit } v23_5_d0 { O 32 vector } v23_5_address1 { O 4 vector } v23_5_ce1 { O 1 bit } v23_5_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_5'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 504 \
    name v23_6 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_6 \
    op interface \
    ports { v23_6_address0 { O 4 vector } v23_6_ce0 { O 1 bit } v23_6_we0 { O 1 bit } v23_6_d0 { O 32 vector } v23_6_address1 { O 4 vector } v23_6_ce1 { O 1 bit } v23_6_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_6'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 505 \
    name v23_7 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_7 \
    op interface \
    ports { v23_7_address0 { O 4 vector } v23_7_ce0 { O 1 bit } v23_7_we0 { O 1 bit } v23_7_d0 { O 32 vector } v23_7_address1 { O 4 vector } v23_7_ce1 { O 1 bit } v23_7_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_7'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 506 \
    name v23_8 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_8 \
    op interface \
    ports { v23_8_address0 { O 4 vector } v23_8_ce0 { O 1 bit } v23_8_we0 { O 1 bit } v23_8_d0 { O 32 vector } v23_8_address1 { O 4 vector } v23_8_ce1 { O 1 bit } v23_8_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_8'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 507 \
    name v23_9 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_9 \
    op interface \
    ports { v23_9_address0 { O 4 vector } v23_9_ce0 { O 1 bit } v23_9_we0 { O 1 bit } v23_9_d0 { O 32 vector } v23_9_address1 { O 4 vector } v23_9_ce1 { O 1 bit } v23_9_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_9'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 508 \
    name v23_10 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_10 \
    op interface \
    ports { v23_10_address0 { O 4 vector } v23_10_ce0 { O 1 bit } v23_10_we0 { O 1 bit } v23_10_d0 { O 32 vector } v23_10_address1 { O 4 vector } v23_10_ce1 { O 1 bit } v23_10_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_10'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 509 \
    name v23_11 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_11 \
    op interface \
    ports { v23_11_address0 { O 4 vector } v23_11_ce0 { O 1 bit } v23_11_we0 { O 1 bit } v23_11_d0 { O 32 vector } v23_11_address1 { O 4 vector } v23_11_ce1 { O 1 bit } v23_11_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_11'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 510 \
    name v23_12 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_12 \
    op interface \
    ports { v23_12_address0 { O 4 vector } v23_12_ce0 { O 1 bit } v23_12_we0 { O 1 bit } v23_12_d0 { O 32 vector } v23_12_address1 { O 4 vector } v23_12_ce1 { O 1 bit } v23_12_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_12'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 511 \
    name v23_13 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_13 \
    op interface \
    ports { v23_13_address0 { O 4 vector } v23_13_ce0 { O 1 bit } v23_13_we0 { O 1 bit } v23_13_d0 { O 32 vector } v23_13_address1 { O 4 vector } v23_13_ce1 { O 1 bit } v23_13_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_13'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 512 \
    name v23_14 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_14 \
    op interface \
    ports { v23_14_address0 { O 4 vector } v23_14_ce0 { O 1 bit } v23_14_we0 { O 1 bit } v23_14_d0 { O 32 vector } v23_14_address1 { O 4 vector } v23_14_ce1 { O 1 bit } v23_14_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_14'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 513 \
    name v23_15 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_15 \
    op interface \
    ports { v23_15_address0 { O 4 vector } v23_15_ce0 { O 1 bit } v23_15_we0 { O 1 bit } v23_15_d0 { O 32 vector } v23_15_address1 { O 4 vector } v23_15_ce1 { O 1 bit } v23_15_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_15'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 514 \
    name v23_16 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_16 \
    op interface \
    ports { v23_16_address0 { O 4 vector } v23_16_ce0 { O 1 bit } v23_16_we0 { O 1 bit } v23_16_d0 { O 32 vector } v23_16_address1 { O 4 vector } v23_16_ce1 { O 1 bit } v23_16_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_16'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 515 \
    name v23_17 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_17 \
    op interface \
    ports { v23_17_address0 { O 4 vector } v23_17_ce0 { O 1 bit } v23_17_we0 { O 1 bit } v23_17_d0 { O 32 vector } v23_17_address1 { O 4 vector } v23_17_ce1 { O 1 bit } v23_17_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_17'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 516 \
    name v23_18 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_18 \
    op interface \
    ports { v23_18_address0 { O 4 vector } v23_18_ce0 { O 1 bit } v23_18_we0 { O 1 bit } v23_18_d0 { O 32 vector } v23_18_address1 { O 4 vector } v23_18_ce1 { O 1 bit } v23_18_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_18'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 517 \
    name v23_19 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_19 \
    op interface \
    ports { v23_19_address0 { O 4 vector } v23_19_ce0 { O 1 bit } v23_19_we0 { O 1 bit } v23_19_d0 { O 32 vector } v23_19_address1 { O 4 vector } v23_19_ce1 { O 1 bit } v23_19_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_19'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 518 \
    name v23_20 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_20 \
    op interface \
    ports { v23_20_address0 { O 4 vector } v23_20_ce0 { O 1 bit } v23_20_we0 { O 1 bit } v23_20_d0 { O 32 vector } v23_20_address1 { O 4 vector } v23_20_ce1 { O 1 bit } v23_20_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_20'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 519 \
    name v23_21 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_21 \
    op interface \
    ports { v23_21_address0 { O 4 vector } v23_21_ce0 { O 1 bit } v23_21_we0 { O 1 bit } v23_21_d0 { O 32 vector } v23_21_address1 { O 4 vector } v23_21_ce1 { O 1 bit } v23_21_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_21'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 520 \
    name v23_22 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_22 \
    op interface \
    ports { v23_22_address0 { O 4 vector } v23_22_ce0 { O 1 bit } v23_22_we0 { O 1 bit } v23_22_d0 { O 32 vector } v23_22_address1 { O 4 vector } v23_22_ce1 { O 1 bit } v23_22_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_22'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 521 \
    name v23_23 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_23 \
    op interface \
    ports { v23_23_address0 { O 4 vector } v23_23_ce0 { O 1 bit } v23_23_we0 { O 1 bit } v23_23_d0 { O 32 vector } v23_23_address1 { O 4 vector } v23_23_ce1 { O 1 bit } v23_23_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_23'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 522 \
    name v23_24 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_24 \
    op interface \
    ports { v23_24_address0 { O 4 vector } v23_24_ce0 { O 1 bit } v23_24_we0 { O 1 bit } v23_24_d0 { O 32 vector } v23_24_address1 { O 4 vector } v23_24_ce1 { O 1 bit } v23_24_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_24'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 523 \
    name v23_25 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_25 \
    op interface \
    ports { v23_25_address0 { O 4 vector } v23_25_ce0 { O 1 bit } v23_25_we0 { O 1 bit } v23_25_d0 { O 32 vector } v23_25_address1 { O 4 vector } v23_25_ce1 { O 1 bit } v23_25_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_25'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 524 \
    name v23_26 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_26 \
    op interface \
    ports { v23_26_address0 { O 4 vector } v23_26_ce0 { O 1 bit } v23_26_we0 { O 1 bit } v23_26_d0 { O 32 vector } v23_26_address1 { O 4 vector } v23_26_ce1 { O 1 bit } v23_26_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_26'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 525 \
    name v23_27 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_27 \
    op interface \
    ports { v23_27_address0 { O 4 vector } v23_27_ce0 { O 1 bit } v23_27_we0 { O 1 bit } v23_27_d0 { O 32 vector } v23_27_address1 { O 4 vector } v23_27_ce1 { O 1 bit } v23_27_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_27'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 526 \
    name v23_28 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_28 \
    op interface \
    ports { v23_28_address0 { O 4 vector } v23_28_ce0 { O 1 bit } v23_28_we0 { O 1 bit } v23_28_d0 { O 32 vector } v23_28_address1 { O 4 vector } v23_28_ce1 { O 1 bit } v23_28_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_28'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 527 \
    name v23_29 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_29 \
    op interface \
    ports { v23_29_address0 { O 4 vector } v23_29_ce0 { O 1 bit } v23_29_we0 { O 1 bit } v23_29_d0 { O 32 vector } v23_29_address1 { O 4 vector } v23_29_ce1 { O 1 bit } v23_29_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_29'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 528 \
    name v23_30 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_30 \
    op interface \
    ports { v23_30_address0 { O 4 vector } v23_30_ce0 { O 1 bit } v23_30_we0 { O 1 bit } v23_30_d0 { O 32 vector } v23_30_address1 { O 4 vector } v23_30_ce1 { O 1 bit } v23_30_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_30'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 529 \
    name v23_31 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_31 \
    op interface \
    ports { v23_31_address0 { O 4 vector } v23_31_ce0 { O 1 bit } v23_31_we0 { O 1 bit } v23_31_d0 { O 32 vector } v23_31_address1 { O 4 vector } v23_31_ce1 { O 1 bit } v23_31_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_31'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 530 \
    name v23_32 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_32 \
    op interface \
    ports { v23_32_address0 { O 4 vector } v23_32_ce0 { O 1 bit } v23_32_we0 { O 1 bit } v23_32_d0 { O 32 vector } v23_32_address1 { O 4 vector } v23_32_ce1 { O 1 bit } v23_32_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_32'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 531 \
    name v23_33 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_33 \
    op interface \
    ports { v23_33_address0 { O 4 vector } v23_33_ce0 { O 1 bit } v23_33_we0 { O 1 bit } v23_33_d0 { O 32 vector } v23_33_address1 { O 4 vector } v23_33_ce1 { O 1 bit } v23_33_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_33'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 532 \
    name v23_34 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_34 \
    op interface \
    ports { v23_34_address0 { O 4 vector } v23_34_ce0 { O 1 bit } v23_34_we0 { O 1 bit } v23_34_d0 { O 32 vector } v23_34_address1 { O 4 vector } v23_34_ce1 { O 1 bit } v23_34_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_34'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 533 \
    name v23_35 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_35 \
    op interface \
    ports { v23_35_address0 { O 4 vector } v23_35_ce0 { O 1 bit } v23_35_we0 { O 1 bit } v23_35_d0 { O 32 vector } v23_35_address1 { O 4 vector } v23_35_ce1 { O 1 bit } v23_35_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_35'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 534 \
    name v23_36 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_36 \
    op interface \
    ports { v23_36_address0 { O 4 vector } v23_36_ce0 { O 1 bit } v23_36_we0 { O 1 bit } v23_36_d0 { O 32 vector } v23_36_address1 { O 4 vector } v23_36_ce1 { O 1 bit } v23_36_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_36'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 535 \
    name v23_37 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_37 \
    op interface \
    ports { v23_37_address0 { O 4 vector } v23_37_ce0 { O 1 bit } v23_37_we0 { O 1 bit } v23_37_d0 { O 32 vector } v23_37_address1 { O 4 vector } v23_37_ce1 { O 1 bit } v23_37_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_37'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 536 \
    name v23_38 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_38 \
    op interface \
    ports { v23_38_address0 { O 4 vector } v23_38_ce0 { O 1 bit } v23_38_we0 { O 1 bit } v23_38_d0 { O 32 vector } v23_38_address1 { O 4 vector } v23_38_ce1 { O 1 bit } v23_38_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_38'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 537 \
    name v23_39 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_39 \
    op interface \
    ports { v23_39_address0 { O 4 vector } v23_39_ce0 { O 1 bit } v23_39_we0 { O 1 bit } v23_39_d0 { O 32 vector } v23_39_address1 { O 4 vector } v23_39_ce1 { O 1 bit } v23_39_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_39'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 538 \
    name v23_40 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v23_40 \
    op interface \
    ports { v23_40_address0 { O 4 vector } v23_40_ce0 { O 1 bit } v23_40_we0 { O 1 bit } v23_40_d0 { O 32 vector } v23_40_address1 { O 4 vector } v23_40_ce1 { O 1 bit } v23_40_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v23_40'"
}
}


# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 497 \
    name out_Ax_fifo1 \
    type fifo \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_out_Ax_fifo1 \
    op interface \
    ports { out_Ax_fifo1_dout { I 32 vector } out_Ax_fifo1_num_data_valid { I 10 vector } out_Ax_fifo1_fifo_cap { I 10 vector } out_Ax_fifo1_empty_n { I 1 bit } out_Ax_fifo1_read { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } ap_continue { I 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


