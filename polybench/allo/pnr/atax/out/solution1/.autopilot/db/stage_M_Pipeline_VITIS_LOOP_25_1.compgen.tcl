# This script segment is generated automatically by AutoPilot

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
    id 1 \
    name v2 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2 \
    op interface \
    ports { v2_address0 { O 4 vector } v2_ce0 { O 1 bit } v2_we0 { O 1 bit } v2_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 2 \
    name v2_1 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_1 \
    op interface \
    ports { v2_1_address0 { O 4 vector } v2_1_ce0 { O 1 bit } v2_1_we0 { O 1 bit } v2_1_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_1'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 3 \
    name v2_2 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_2 \
    op interface \
    ports { v2_2_address0 { O 4 vector } v2_2_ce0 { O 1 bit } v2_2_we0 { O 1 bit } v2_2_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_2'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 4 \
    name v2_3 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_3 \
    op interface \
    ports { v2_3_address0 { O 4 vector } v2_3_ce0 { O 1 bit } v2_3_we0 { O 1 bit } v2_3_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_3'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 5 \
    name v2_4 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_4 \
    op interface \
    ports { v2_4_address0 { O 4 vector } v2_4_ce0 { O 1 bit } v2_4_we0 { O 1 bit } v2_4_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_4'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 6 \
    name v2_5 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_5 \
    op interface \
    ports { v2_5_address0 { O 4 vector } v2_5_ce0 { O 1 bit } v2_5_we0 { O 1 bit } v2_5_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_5'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 7 \
    name v2_6 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_6 \
    op interface \
    ports { v2_6_address0 { O 4 vector } v2_6_ce0 { O 1 bit } v2_6_we0 { O 1 bit } v2_6_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_6'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 8 \
    name v2_7 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_7 \
    op interface \
    ports { v2_7_address0 { O 4 vector } v2_7_ce0 { O 1 bit } v2_7_we0 { O 1 bit } v2_7_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_7'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 9 \
    name v2_8 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_8 \
    op interface \
    ports { v2_8_address0 { O 4 vector } v2_8_ce0 { O 1 bit } v2_8_we0 { O 1 bit } v2_8_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_8'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 10 \
    name v2_9 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_9 \
    op interface \
    ports { v2_9_address0 { O 4 vector } v2_9_ce0 { O 1 bit } v2_9_we0 { O 1 bit } v2_9_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_9'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 11 \
    name v2_10 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_10 \
    op interface \
    ports { v2_10_address0 { O 4 vector } v2_10_ce0 { O 1 bit } v2_10_we0 { O 1 bit } v2_10_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_10'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 12 \
    name v2_11 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_11 \
    op interface \
    ports { v2_11_address0 { O 4 vector } v2_11_ce0 { O 1 bit } v2_11_we0 { O 1 bit } v2_11_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_11'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 13 \
    name v2_12 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_12 \
    op interface \
    ports { v2_12_address0 { O 4 vector } v2_12_ce0 { O 1 bit } v2_12_we0 { O 1 bit } v2_12_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_12'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 14 \
    name v2_13 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_13 \
    op interface \
    ports { v2_13_address0 { O 4 vector } v2_13_ce0 { O 1 bit } v2_13_we0 { O 1 bit } v2_13_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_13'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 15 \
    name v2_14 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_14 \
    op interface \
    ports { v2_14_address0 { O 4 vector } v2_14_ce0 { O 1 bit } v2_14_we0 { O 1 bit } v2_14_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_14'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 16 \
    name v2_15 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_15 \
    op interface \
    ports { v2_15_address0 { O 4 vector } v2_15_ce0 { O 1 bit } v2_15_we0 { O 1 bit } v2_15_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_15'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 17 \
    name v2_16 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_16 \
    op interface \
    ports { v2_16_address0 { O 4 vector } v2_16_ce0 { O 1 bit } v2_16_we0 { O 1 bit } v2_16_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_16'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 18 \
    name v2_17 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_17 \
    op interface \
    ports { v2_17_address0 { O 4 vector } v2_17_ce0 { O 1 bit } v2_17_we0 { O 1 bit } v2_17_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_17'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 19 \
    name v2_18 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_18 \
    op interface \
    ports { v2_18_address0 { O 4 vector } v2_18_ce0 { O 1 bit } v2_18_we0 { O 1 bit } v2_18_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_18'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 20 \
    name v2_19 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_19 \
    op interface \
    ports { v2_19_address0 { O 4 vector } v2_19_ce0 { O 1 bit } v2_19_we0 { O 1 bit } v2_19_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_19'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 21 \
    name v2_20 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_20 \
    op interface \
    ports { v2_20_address0 { O 4 vector } v2_20_ce0 { O 1 bit } v2_20_we0 { O 1 bit } v2_20_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_20'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 22 \
    name v2_21 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_21 \
    op interface \
    ports { v2_21_address0 { O 4 vector } v2_21_ce0 { O 1 bit } v2_21_we0 { O 1 bit } v2_21_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_21'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 23 \
    name v2_22 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_22 \
    op interface \
    ports { v2_22_address0 { O 4 vector } v2_22_ce0 { O 1 bit } v2_22_we0 { O 1 bit } v2_22_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_22'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 24 \
    name v2_23 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_23 \
    op interface \
    ports { v2_23_address0 { O 4 vector } v2_23_ce0 { O 1 bit } v2_23_we0 { O 1 bit } v2_23_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_23'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 25 \
    name v2_24 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_24 \
    op interface \
    ports { v2_24_address0 { O 4 vector } v2_24_ce0 { O 1 bit } v2_24_we0 { O 1 bit } v2_24_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_24'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 26 \
    name v2_25 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_25 \
    op interface \
    ports { v2_25_address0 { O 4 vector } v2_25_ce0 { O 1 bit } v2_25_we0 { O 1 bit } v2_25_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_25'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 27 \
    name v2_26 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_26 \
    op interface \
    ports { v2_26_address0 { O 4 vector } v2_26_ce0 { O 1 bit } v2_26_we0 { O 1 bit } v2_26_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_26'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 28 \
    name v2_27 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_27 \
    op interface \
    ports { v2_27_address0 { O 4 vector } v2_27_ce0 { O 1 bit } v2_27_we0 { O 1 bit } v2_27_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_27'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 29 \
    name v2_28 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_28 \
    op interface \
    ports { v2_28_address0 { O 4 vector } v2_28_ce0 { O 1 bit } v2_28_we0 { O 1 bit } v2_28_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_28'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 30 \
    name v2_29 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_29 \
    op interface \
    ports { v2_29_address0 { O 4 vector } v2_29_ce0 { O 1 bit } v2_29_we0 { O 1 bit } v2_29_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_29'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 31 \
    name v2_30 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_30 \
    op interface \
    ports { v2_30_address0 { O 4 vector } v2_30_ce0 { O 1 bit } v2_30_we0 { O 1 bit } v2_30_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_30'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 32 \
    name v2_31 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_31 \
    op interface \
    ports { v2_31_address0 { O 4 vector } v2_31_ce0 { O 1 bit } v2_31_we0 { O 1 bit } v2_31_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_31'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 33 \
    name v2_32 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_32 \
    op interface \
    ports { v2_32_address0 { O 4 vector } v2_32_ce0 { O 1 bit } v2_32_we0 { O 1 bit } v2_32_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_32'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 34 \
    name v2_33 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_33 \
    op interface \
    ports { v2_33_address0 { O 4 vector } v2_33_ce0 { O 1 bit } v2_33_we0 { O 1 bit } v2_33_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_33'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 35 \
    name v2_34 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_34 \
    op interface \
    ports { v2_34_address0 { O 4 vector } v2_34_ce0 { O 1 bit } v2_34_we0 { O 1 bit } v2_34_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_34'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 36 \
    name v2_35 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_35 \
    op interface \
    ports { v2_35_address0 { O 4 vector } v2_35_ce0 { O 1 bit } v2_35_we0 { O 1 bit } v2_35_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_35'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 37 \
    name v2_36 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_36 \
    op interface \
    ports { v2_36_address0 { O 4 vector } v2_36_ce0 { O 1 bit } v2_36_we0 { O 1 bit } v2_36_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_36'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 38 \
    name v2_37 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_37 \
    op interface \
    ports { v2_37_address0 { O 4 vector } v2_37_ce0 { O 1 bit } v2_37_we0 { O 1 bit } v2_37_d0 { O 32 vector } } \
} "
} else {
puts "@W \[IMPL-110\] Cannot find bus interface model in the library. Ignored generation of bus interface for 'v2_37'"
}
}


# XIL_BRAM:
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc ::AESL_LIB_XILADAPTER::xil_bram_gen] == "::AESL_LIB_XILADAPTER::xil_bram_gen"} {
eval "::AESL_LIB_XILADAPTER::xil_bram_gen { \
    id 39 \
    name v2_38 \
    reset_level 1 \
    sync_rst true \
    dir O \
    corename v2_38 \
    op interface \
    ports { v2_38_address0 { O 4 vector } v2_38_ce0 { O 1 bit } v2_38_we0 { O 1 bit } v2_38_d0 { O 32 vector } } \
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


