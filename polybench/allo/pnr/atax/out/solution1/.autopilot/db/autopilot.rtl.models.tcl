set SynModuleInfo {
  {SRCNAME stage_M_Pipeline_VITIS_LOOP_25_1 MODELNAME stage_M_Pipeline_VITIS_LOOP_25_1 RTLNAME kernel_atax_stage_M_Pipeline_VITIS_LOOP_25_1
    SUBMODULES {
      {MODELNAME kernel_atax_flow_control_loop_pipe_sequential_init RTLNAME kernel_atax_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME kernel_atax_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME stage_M_Pipeline_l_S_m_0_r_l_m MODELNAME stage_M_Pipeline_l_S_m_0_r_l_m RTLNAME kernel_atax_stage_M_Pipeline_l_S_m_0_r_l_m
    SUBMODULES {
      {MODELNAME kernel_atax_fadd_32ns_32ns_32_8_no_dsp_1 RTLNAME kernel_atax_fadd_32ns_32ns_32_8_no_dsp_1 BINDTYPE op TYPE fadd IMPL fabric LATENCY 7 ALLOW_PRAGMA 1}
      {MODELNAME kernel_atax_fmul_32ns_32ns_32_6_max_dsp_1 RTLNAME kernel_atax_fmul_32ns_32ns_32_6_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 5 ALLOW_PRAGMA 1}
      {MODELNAME kernel_atax_mul_mul_9ns_10ns_19_4_1 RTLNAME kernel_atax_mul_mul_9ns_10ns_19_4_1 BINDTYPE op TYPE all IMPL dsp48 LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME kernel_atax_mac_muladd_4ns_9ns_9ns_13_4_1 RTLNAME kernel_atax_mac_muladd_4ns_9ns_9ns_13_4_1 BINDTYPE op TYPE all IMPL dsp48 LATENCY 3 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME stage_M_Pipeline_VITIS_LOOP_42_2 MODELNAME stage_M_Pipeline_VITIS_LOOP_42_2 RTLNAME kernel_atax_stage_M_Pipeline_VITIS_LOOP_42_2
    SUBMODULES {
      {MODELNAME kernel_atax_mux_399_32_1_1 RTLNAME kernel_atax_mux_399_32_1_1 BINDTYPE op TYPE mux IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME stage_M MODELNAME stage_M RTLNAME kernel_atax_stage_M
    SUBMODULES {
      {MODELNAME kernel_atax_stage_M_v2_RAM_AUTO_1R1W RTLNAME kernel_atax_stage_M_v2_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME stage_N_Pipeline_VITIS_LOOP_57_1 MODELNAME stage_N_Pipeline_VITIS_LOOP_57_1 RTLNAME kernel_atax_stage_N_Pipeline_VITIS_LOOP_57_1}
  {SRCNAME stage_N_Pipeline_l_S_n_0_k_l_n MODELNAME stage_N_Pipeline_l_S_n_0_k_l_n RTLNAME kernel_atax_stage_N_Pipeline_l_S_n_0_k_l_n}
  {SRCNAME stage_N MODELNAME stage_N RTLNAME kernel_atax_stage_N
    SUBMODULES {
      {MODELNAME kernel_atax_stage_N_v11_RAM_AUTO_1R1W RTLNAME kernel_atax_stage_N_v11_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME kernel_atax MODELNAME kernel_atax RTLNAME kernel_atax IS_TOP 1
    SUBMODULES {
      {MODELNAME kernel_atax_fifo_w32_d390_A RTLNAME kernel_atax_fifo_w32_d390_A BINDTYPE storage TYPE fifo IMPL memory ALLOW_PRAGMA 1 INSTNAME {$InstName}}
    }
  }
}
