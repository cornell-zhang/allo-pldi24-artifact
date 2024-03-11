# This script segment is generated automatically by AutoPilot

set name kernel_atax_fadd_32ns_32ns_32_8_no_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {fadd} IMPL {fabric} LATENCY 7 ALLOW_PRAGMA 1
}


set name kernel_atax_fmul_32ns_32ns_32_6_max_dsp_1
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {fmul} IMPL {maxdsp} LATENCY 5 ALLOW_PRAGMA 1
}


set id 118
set name kernel_atax_mul_mul_9ns_10ns_19_4_1
set corename simcore_mul
set op mul
set stage_num 4
set clk_width 1
set clk_signed 0
set reset_width 1
set reset_signed 0
set in0_width 9
set in0_signed 0
set in1_width 10
set in1_signed 0
set ce_width 1
set ce_signed 0
set out_width 19
set arg_lists {i0 {9 0 +} i1 {10 0 +} p {19 1 +} acc {0} }
set TrueReset 0
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {all} IMPL {dsp48} LATENCY 3 ALLOW_PRAGMA 1
}


set op mul
set corename DSP48
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_dsp48] == "::AESL_LIB_VIRTEX::xil_gen_dsp48"} {
eval "::AESL_LIB_VIRTEX::xil_gen_dsp48 { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    clk_width ${clk_width} \
    clk_signed ${clk_signed} \
    reset_width ${reset_width} \
    reset_signed ${reset_signed} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    ce_width ${ce_width} \
    ce_signed ${ce_signed} \
    out_width ${out_width} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-101\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_dsp48, check your platform lib"
}
}


set id 119
set name kernel_atax_mac_muladd_4ns_9ns_9ns_13_4_1
set corename simcore_mac
set op mac
set stage_num 4
set clk_width 1
set clk_signed 0
set reset_width 1
set reset_signed 0
set in0_width 4
set in0_signed 0
set in1_width 9
set in1_signed 0
set in2_width 9
set in2_signed 0
set ce_width 1
set ce_signed 0
set out_width 13
set arg_lists {i0 {4 0 +} i1 {9 0 +} m {13 1 +} i2 {9 0 +} p {13 0 +} c_reg {1} rnd {0} acc {0} }
set TrueReset 0
if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $name BINDTYPE {op} TYPE {all} IMPL {dsp48} LATENCY 3 ALLOW_PRAGMA 1
}


set op mac
set corename DSP48
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_dsp48] == "::AESL_LIB_VIRTEX::xil_gen_dsp48"} {
eval "::AESL_LIB_VIRTEX::xil_gen_dsp48 { \
    id ${id} \
    name ${name} \
    corename ${corename} \
    op ${op} \
    reset_level 1 \
    sync_rst true \
    true_reset ${TrueReset} \
    stage_num ${stage_num} \
    clk_width ${clk_width} \
    clk_signed ${clk_signed} \
    reset_width ${reset_width} \
    reset_signed ${reset_signed} \
    in0_width ${in0_width} \
    in0_signed ${in0_signed} \
    in1_width ${in1_width} \
    in1_signed ${in1_signed} \
    in2_width ${in2_width} \
    in2_signed ${in2_signed} \
    ce_width ${ce_width} \
    ce_signed ${ce_signed} \
    out_width ${out_width} \
    arg_lists {${arg_lists}} \
}"
} else {
puts "@W \[IMPL-101\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_dsp48, check your platform lib"
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
    id 124 \
    name v22 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v22 \
    op interface \
    ports { v22_address0 { O 9 vector } v22_ce0 { O 1 bit } v22_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v22'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 125 \
    name v20_0 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_0 \
    op interface \
    ports { v20_0_address0 { O 13 vector } v20_0_ce0 { O 1 bit } v20_0_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_0'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 126 \
    name v20_1 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_1 \
    op interface \
    ports { v20_1_address0 { O 13 vector } v20_1_ce0 { O 1 bit } v20_1_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_1'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 127 \
    name v20_2 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_2 \
    op interface \
    ports { v20_2_address0 { O 13 vector } v20_2_ce0 { O 1 bit } v20_2_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_2'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 128 \
    name v20_3 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_3 \
    op interface \
    ports { v20_3_address0 { O 13 vector } v20_3_ce0 { O 1 bit } v20_3_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_3'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 129 \
    name v20_4 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_4 \
    op interface \
    ports { v20_4_address0 { O 13 vector } v20_4_ce0 { O 1 bit } v20_4_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_4'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 130 \
    name v20_5 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_5 \
    op interface \
    ports { v20_5_address0 { O 13 vector } v20_5_ce0 { O 1 bit } v20_5_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_5'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 131 \
    name v20_6 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_6 \
    op interface \
    ports { v20_6_address0 { O 13 vector } v20_6_ce0 { O 1 bit } v20_6_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_6'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 132 \
    name v20_7 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_7 \
    op interface \
    ports { v20_7_address0 { O 13 vector } v20_7_ce0 { O 1 bit } v20_7_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_7'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 133 \
    name v20_8 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_8 \
    op interface \
    ports { v20_8_address0 { O 13 vector } v20_8_ce0 { O 1 bit } v20_8_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_8'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 134 \
    name v20_9 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_9 \
    op interface \
    ports { v20_9_address0 { O 13 vector } v20_9_ce0 { O 1 bit } v20_9_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_9'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 135 \
    name v20_10 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_10 \
    op interface \
    ports { v20_10_address0 { O 13 vector } v20_10_ce0 { O 1 bit } v20_10_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_10'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 136 \
    name v20_11 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_11 \
    op interface \
    ports { v20_11_address0 { O 13 vector } v20_11_ce0 { O 1 bit } v20_11_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_11'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 137 \
    name v20_12 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_12 \
    op interface \
    ports { v20_12_address0 { O 13 vector } v20_12_ce0 { O 1 bit } v20_12_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_12'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 138 \
    name v20_13 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_13 \
    op interface \
    ports { v20_13_address0 { O 13 vector } v20_13_ce0 { O 1 bit } v20_13_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_13'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 139 \
    name v20_14 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_14 \
    op interface \
    ports { v20_14_address0 { O 13 vector } v20_14_ce0 { O 1 bit } v20_14_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_14'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 140 \
    name v20_15 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_15 \
    op interface \
    ports { v20_15_address0 { O 13 vector } v20_15_ce0 { O 1 bit } v20_15_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_15'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 141 \
    name v20_16 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_16 \
    op interface \
    ports { v20_16_address0 { O 13 vector } v20_16_ce0 { O 1 bit } v20_16_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_16'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 142 \
    name v20_17 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_17 \
    op interface \
    ports { v20_17_address0 { O 13 vector } v20_17_ce0 { O 1 bit } v20_17_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_17'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 143 \
    name v20_18 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_18 \
    op interface \
    ports { v20_18_address0 { O 13 vector } v20_18_ce0 { O 1 bit } v20_18_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_18'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 144 \
    name v20_19 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_19 \
    op interface \
    ports { v20_19_address0 { O 13 vector } v20_19_ce0 { O 1 bit } v20_19_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_19'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 145 \
    name v20_20 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_20 \
    op interface \
    ports { v20_20_address0 { O 13 vector } v20_20_ce0 { O 1 bit } v20_20_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_20'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 146 \
    name v20_21 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_21 \
    op interface \
    ports { v20_21_address0 { O 13 vector } v20_21_ce0 { O 1 bit } v20_21_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_21'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 147 \
    name v20_22 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_22 \
    op interface \
    ports { v20_22_address0 { O 13 vector } v20_22_ce0 { O 1 bit } v20_22_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_22'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 148 \
    name v20_23 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_23 \
    op interface \
    ports { v20_23_address0 { O 13 vector } v20_23_ce0 { O 1 bit } v20_23_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_23'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 149 \
    name v20_24 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_24 \
    op interface \
    ports { v20_24_address0 { O 13 vector } v20_24_ce0 { O 1 bit } v20_24_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_24'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 150 \
    name v20_25 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_25 \
    op interface \
    ports { v20_25_address0 { O 13 vector } v20_25_ce0 { O 1 bit } v20_25_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_25'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 151 \
    name v20_26 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_26 \
    op interface \
    ports { v20_26_address0 { O 13 vector } v20_26_ce0 { O 1 bit } v20_26_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_26'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 152 \
    name v20_27 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_27 \
    op interface \
    ports { v20_27_address0 { O 13 vector } v20_27_ce0 { O 1 bit } v20_27_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_27'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 153 \
    name v20_28 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_28 \
    op interface \
    ports { v20_28_address0 { O 13 vector } v20_28_ce0 { O 1 bit } v20_28_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_28'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 154 \
    name v20_29 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_29 \
    op interface \
    ports { v20_29_address0 { O 13 vector } v20_29_ce0 { O 1 bit } v20_29_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_29'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 155 \
    name v20_30 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_30 \
    op interface \
    ports { v20_30_address0 { O 13 vector } v20_30_ce0 { O 1 bit } v20_30_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_30'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 156 \
    name v20_31 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_31 \
    op interface \
    ports { v20_31_address0 { O 13 vector } v20_31_ce0 { O 1 bit } v20_31_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_31'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 157 \
    name v20_32 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_32 \
    op interface \
    ports { v20_32_address0 { O 13 vector } v20_32_ce0 { O 1 bit } v20_32_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_32'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 158 \
    name v20_33 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_33 \
    op interface \
    ports { v20_33_address0 { O 13 vector } v20_33_ce0 { O 1 bit } v20_33_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_33'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 159 \
    name v20_34 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_34 \
    op interface \
    ports { v20_34_address0 { O 13 vector } v20_34_ce0 { O 1 bit } v20_34_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_34'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 160 \
    name v20_35 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_35 \
    op interface \
    ports { v20_35_address0 { O 13 vector } v20_35_ce0 { O 1 bit } v20_35_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_35'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 161 \
    name v20_36 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_36 \
    op interface \
    ports { v20_36_address0 { O 13 vector } v20_36_ce0 { O 1 bit } v20_36_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_36'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 162 \
    name v20_37 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_37 \
    op interface \
    ports { v20_37_address0 { O 13 vector } v20_37_ce0 { O 1 bit } v20_37_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_37'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 163 \
    name v20_38 \
    reset_level 1 \
    sync_rst true \
    dir I \
    corename v20_38 \
    op interface \
    ports { v20_38_address0 { O 13 vector } v20_38_ce0 { O 1 bit } v20_38_q0 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v20_38'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 164 \
    name v2 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2 \
    op interface \
    ports { v2_address0 { O 4 vector } v2_ce0 { O 1 bit } v2_we0 { O 1 bit } v2_d0 { O 32 vector } v2_address1 { O 4 vector } v2_ce1 { O 1 bit } v2_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 165 \
    name v2_1 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_1 \
    op interface \
    ports { v2_1_address0 { O 4 vector } v2_1_ce0 { O 1 bit } v2_1_we0 { O 1 bit } v2_1_d0 { O 32 vector } v2_1_address1 { O 4 vector } v2_1_ce1 { O 1 bit } v2_1_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_1'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 166 \
    name v2_2 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_2 \
    op interface \
    ports { v2_2_address0 { O 4 vector } v2_2_ce0 { O 1 bit } v2_2_we0 { O 1 bit } v2_2_d0 { O 32 vector } v2_2_address1 { O 4 vector } v2_2_ce1 { O 1 bit } v2_2_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_2'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 167 \
    name v2_3 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_3 \
    op interface \
    ports { v2_3_address0 { O 4 vector } v2_3_ce0 { O 1 bit } v2_3_we0 { O 1 bit } v2_3_d0 { O 32 vector } v2_3_address1 { O 4 vector } v2_3_ce1 { O 1 bit } v2_3_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_3'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 168 \
    name v2_4 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_4 \
    op interface \
    ports { v2_4_address0 { O 4 vector } v2_4_ce0 { O 1 bit } v2_4_we0 { O 1 bit } v2_4_d0 { O 32 vector } v2_4_address1 { O 4 vector } v2_4_ce1 { O 1 bit } v2_4_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_4'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 169 \
    name v2_5 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_5 \
    op interface \
    ports { v2_5_address0 { O 4 vector } v2_5_ce0 { O 1 bit } v2_5_we0 { O 1 bit } v2_5_d0 { O 32 vector } v2_5_address1 { O 4 vector } v2_5_ce1 { O 1 bit } v2_5_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_5'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 170 \
    name v2_6 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_6 \
    op interface \
    ports { v2_6_address0 { O 4 vector } v2_6_ce0 { O 1 bit } v2_6_we0 { O 1 bit } v2_6_d0 { O 32 vector } v2_6_address1 { O 4 vector } v2_6_ce1 { O 1 bit } v2_6_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_6'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 171 \
    name v2_7 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_7 \
    op interface \
    ports { v2_7_address0 { O 4 vector } v2_7_ce0 { O 1 bit } v2_7_we0 { O 1 bit } v2_7_d0 { O 32 vector } v2_7_address1 { O 4 vector } v2_7_ce1 { O 1 bit } v2_7_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_7'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 172 \
    name v2_8 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_8 \
    op interface \
    ports { v2_8_address0 { O 4 vector } v2_8_ce0 { O 1 bit } v2_8_we0 { O 1 bit } v2_8_d0 { O 32 vector } v2_8_address1 { O 4 vector } v2_8_ce1 { O 1 bit } v2_8_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_8'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 173 \
    name v2_9 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_9 \
    op interface \
    ports { v2_9_address0 { O 4 vector } v2_9_ce0 { O 1 bit } v2_9_we0 { O 1 bit } v2_9_d0 { O 32 vector } v2_9_address1 { O 4 vector } v2_9_ce1 { O 1 bit } v2_9_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_9'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 174 \
    name v2_10 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_10 \
    op interface \
    ports { v2_10_address0 { O 4 vector } v2_10_ce0 { O 1 bit } v2_10_we0 { O 1 bit } v2_10_d0 { O 32 vector } v2_10_address1 { O 4 vector } v2_10_ce1 { O 1 bit } v2_10_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_10'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 175 \
    name v2_11 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_11 \
    op interface \
    ports { v2_11_address0 { O 4 vector } v2_11_ce0 { O 1 bit } v2_11_we0 { O 1 bit } v2_11_d0 { O 32 vector } v2_11_address1 { O 4 vector } v2_11_ce1 { O 1 bit } v2_11_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_11'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 176 \
    name v2_12 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_12 \
    op interface \
    ports { v2_12_address0 { O 4 vector } v2_12_ce0 { O 1 bit } v2_12_we0 { O 1 bit } v2_12_d0 { O 32 vector } v2_12_address1 { O 4 vector } v2_12_ce1 { O 1 bit } v2_12_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_12'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 177 \
    name v2_13 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_13 \
    op interface \
    ports { v2_13_address0 { O 4 vector } v2_13_ce0 { O 1 bit } v2_13_we0 { O 1 bit } v2_13_d0 { O 32 vector } v2_13_address1 { O 4 vector } v2_13_ce1 { O 1 bit } v2_13_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_13'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 178 \
    name v2_14 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_14 \
    op interface \
    ports { v2_14_address0 { O 4 vector } v2_14_ce0 { O 1 bit } v2_14_we0 { O 1 bit } v2_14_d0 { O 32 vector } v2_14_address1 { O 4 vector } v2_14_ce1 { O 1 bit } v2_14_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_14'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 179 \
    name v2_15 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_15 \
    op interface \
    ports { v2_15_address0 { O 4 vector } v2_15_ce0 { O 1 bit } v2_15_we0 { O 1 bit } v2_15_d0 { O 32 vector } v2_15_address1 { O 4 vector } v2_15_ce1 { O 1 bit } v2_15_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_15'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 180 \
    name v2_16 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_16 \
    op interface \
    ports { v2_16_address0 { O 4 vector } v2_16_ce0 { O 1 bit } v2_16_we0 { O 1 bit } v2_16_d0 { O 32 vector } v2_16_address1 { O 4 vector } v2_16_ce1 { O 1 bit } v2_16_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_16'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 181 \
    name v2_17 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_17 \
    op interface \
    ports { v2_17_address0 { O 4 vector } v2_17_ce0 { O 1 bit } v2_17_we0 { O 1 bit } v2_17_d0 { O 32 vector } v2_17_address1 { O 4 vector } v2_17_ce1 { O 1 bit } v2_17_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_17'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 182 \
    name v2_18 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_18 \
    op interface \
    ports { v2_18_address0 { O 4 vector } v2_18_ce0 { O 1 bit } v2_18_we0 { O 1 bit } v2_18_d0 { O 32 vector } v2_18_address1 { O 4 vector } v2_18_ce1 { O 1 bit } v2_18_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_18'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 183 \
    name v2_19 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_19 \
    op interface \
    ports { v2_19_address0 { O 4 vector } v2_19_ce0 { O 1 bit } v2_19_we0 { O 1 bit } v2_19_d0 { O 32 vector } v2_19_address1 { O 4 vector } v2_19_ce1 { O 1 bit } v2_19_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_19'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 184 \
    name v2_20 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_20 \
    op interface \
    ports { v2_20_address0 { O 4 vector } v2_20_ce0 { O 1 bit } v2_20_we0 { O 1 bit } v2_20_d0 { O 32 vector } v2_20_address1 { O 4 vector } v2_20_ce1 { O 1 bit } v2_20_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_20'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 185 \
    name v2_21 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_21 \
    op interface \
    ports { v2_21_address0 { O 4 vector } v2_21_ce0 { O 1 bit } v2_21_we0 { O 1 bit } v2_21_d0 { O 32 vector } v2_21_address1 { O 4 vector } v2_21_ce1 { O 1 bit } v2_21_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_21'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 186 \
    name v2_22 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_22 \
    op interface \
    ports { v2_22_address0 { O 4 vector } v2_22_ce0 { O 1 bit } v2_22_we0 { O 1 bit } v2_22_d0 { O 32 vector } v2_22_address1 { O 4 vector } v2_22_ce1 { O 1 bit } v2_22_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_22'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 187 \
    name v2_23 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_23 \
    op interface \
    ports { v2_23_address0 { O 4 vector } v2_23_ce0 { O 1 bit } v2_23_we0 { O 1 bit } v2_23_d0 { O 32 vector } v2_23_address1 { O 4 vector } v2_23_ce1 { O 1 bit } v2_23_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_23'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 188 \
    name v2_24 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_24 \
    op interface \
    ports { v2_24_address0 { O 4 vector } v2_24_ce0 { O 1 bit } v2_24_we0 { O 1 bit } v2_24_d0 { O 32 vector } v2_24_address1 { O 4 vector } v2_24_ce1 { O 1 bit } v2_24_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_24'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 189 \
    name v2_25 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_25 \
    op interface \
    ports { v2_25_address0 { O 4 vector } v2_25_ce0 { O 1 bit } v2_25_we0 { O 1 bit } v2_25_d0 { O 32 vector } v2_25_address1 { O 4 vector } v2_25_ce1 { O 1 bit } v2_25_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_25'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 190 \
    name v2_26 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_26 \
    op interface \
    ports { v2_26_address0 { O 4 vector } v2_26_ce0 { O 1 bit } v2_26_we0 { O 1 bit } v2_26_d0 { O 32 vector } v2_26_address1 { O 4 vector } v2_26_ce1 { O 1 bit } v2_26_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_26'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 191 \
    name v2_27 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_27 \
    op interface \
    ports { v2_27_address0 { O 4 vector } v2_27_ce0 { O 1 bit } v2_27_we0 { O 1 bit } v2_27_d0 { O 32 vector } v2_27_address1 { O 4 vector } v2_27_ce1 { O 1 bit } v2_27_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_27'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 192 \
    name v2_28 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_28 \
    op interface \
    ports { v2_28_address0 { O 4 vector } v2_28_ce0 { O 1 bit } v2_28_we0 { O 1 bit } v2_28_d0 { O 32 vector } v2_28_address1 { O 4 vector } v2_28_ce1 { O 1 bit } v2_28_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_28'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 193 \
    name v2_29 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_29 \
    op interface \
    ports { v2_29_address0 { O 4 vector } v2_29_ce0 { O 1 bit } v2_29_we0 { O 1 bit } v2_29_d0 { O 32 vector } v2_29_address1 { O 4 vector } v2_29_ce1 { O 1 bit } v2_29_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_29'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 194 \
    name v2_30 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_30 \
    op interface \
    ports { v2_30_address0 { O 4 vector } v2_30_ce0 { O 1 bit } v2_30_we0 { O 1 bit } v2_30_d0 { O 32 vector } v2_30_address1 { O 4 vector } v2_30_ce1 { O 1 bit } v2_30_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_30'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 195 \
    name v2_31 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_31 \
    op interface \
    ports { v2_31_address0 { O 4 vector } v2_31_ce0 { O 1 bit } v2_31_we0 { O 1 bit } v2_31_d0 { O 32 vector } v2_31_address1 { O 4 vector } v2_31_ce1 { O 1 bit } v2_31_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_31'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 196 \
    name v2_32 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_32 \
    op interface \
    ports { v2_32_address0 { O 4 vector } v2_32_ce0 { O 1 bit } v2_32_we0 { O 1 bit } v2_32_d0 { O 32 vector } v2_32_address1 { O 4 vector } v2_32_ce1 { O 1 bit } v2_32_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_32'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 197 \
    name v2_33 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_33 \
    op interface \
    ports { v2_33_address0 { O 4 vector } v2_33_ce0 { O 1 bit } v2_33_we0 { O 1 bit } v2_33_d0 { O 32 vector } v2_33_address1 { O 4 vector } v2_33_ce1 { O 1 bit } v2_33_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_33'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 198 \
    name v2_34 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_34 \
    op interface \
    ports { v2_34_address0 { O 4 vector } v2_34_ce0 { O 1 bit } v2_34_we0 { O 1 bit } v2_34_d0 { O 32 vector } v2_34_address1 { O 4 vector } v2_34_ce1 { O 1 bit } v2_34_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_34'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 199 \
    name v2_35 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_35 \
    op interface \
    ports { v2_35_address0 { O 4 vector } v2_35_ce0 { O 1 bit } v2_35_we0 { O 1 bit } v2_35_d0 { O 32 vector } v2_35_address1 { O 4 vector } v2_35_ce1 { O 1 bit } v2_35_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_35'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 200 \
    name v2_36 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_36 \
    op interface \
    ports { v2_36_address0 { O 4 vector } v2_36_ce0 { O 1 bit } v2_36_we0 { O 1 bit } v2_36_d0 { O 32 vector } v2_36_address1 { O 4 vector } v2_36_ce1 { O 1 bit } v2_36_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_36'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 201 \
    name v2_37 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_37 \
    op interface \
    ports { v2_37_address0 { O 4 vector } v2_37_ce0 { O 1 bit } v2_37_we0 { O 1 bit } v2_37_d0 { O 32 vector } v2_37_address1 { O 4 vector } v2_37_ce1 { O 1 bit } v2_37_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_37'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 202 \
    name v2_38 \
    reset_level 1 \
    sync_rst true \
    dir IO \
    corename v2_38 \
    op interface \
    ports { v2_38_address0 { O 4 vector } v2_38_ce0 { O 1 bit } v2_38_we0 { O 1 bit } v2_38_d0 { O 32 vector } v2_38_address1 { O 4 vector } v2_38_ce1 { O 1 bit } v2_38_q1 { I 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_38'"
}
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
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
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


# flow_control definition:
set InstName kernel_atax_flow_control_loop_pipe_sequential_init_U
set CompName kernel_atax_flow_control_loop_pipe_sequential_init
set name flow_control_loop_pipe_sequential_init
if {${::AESL::PGuard_autocg_gen} && ${::AESL::PGuard_autocg_ipmgen}} {
if {[info proc ::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control] == "::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control"} {
eval "::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control { \
    name ${name} \
    prefix kernel_atax_ \
}"
} else {
puts "@W \[IMPL-107\] Cannot find ::AESL_LIB_VIRTEX::xil_gen_UPC_flow_control, check your platform lib"
}
}


if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler $CompName BINDTYPE interface TYPE internal_upc_flow_control INSTNAME $InstName
}


