#ifndef _GEinp_numinp_num_SYSTOLIC_ARRAY_H_
#define _GEinp_numinp_num_SYSTOLIC_ARRAY_H_

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>

#define seq_num 128
#define inp_num 8
#define inp_len 1024
#define head_num 16
#define head_len 64
#define gelu_len 4096

#define pack_seq_num seq_num/inp_num
#define pack_inp_len inp_len/inp_num
#define pack_head_len head_len/inp_num
#define pack_inp_len_half inp_len/inp_num/2
#define pack_gelu_len_half gelu_len/inp_num/2

typedef ap_int<48> int48_t;
typedef ap_int<24> int24_t;
typedef ap_int<12> int12_t;

typedef ap_uint<256> io_pack_float;
typedef ap_uint<128> bus_pack_int8;
typedef ap_uint<64> io_pack_int8;
typedef ap_uint<192> io_pack_int24;
typedef ap_uint<384> io_pack_int48;

typedef ap_uint<512> double_io_pack_float;
typedef ap_uint<128> double_io_pack_int8;

typedef union {
  float f;
  uint32_t i;
} converter_t;


typedef ap_axiu<64, 0, 0, 0> pkt_int8;
typedef ap_axiu<256, 0, 0, 0> pkt_float;

typedef ap_axiu<128, 0, 0, 0> double_pkt_int8;
typedef ap_axiu<512, 0, 0, 0> double_pkt_float;

#endif