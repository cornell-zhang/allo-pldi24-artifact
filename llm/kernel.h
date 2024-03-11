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

#define seq_num 512
#define inp_len 1024
#define head_num 16
#define head_len 64
#define gelu_len 4096

#define inp_parallel 8
#define w_parallel 16

const int block_size_a = inp_parallel;
const int block_size_b = w_parallel / 2;

#define pack_seq_num_inp seq_num/inp_parallel
#define pack_inp_len_inp inp_len/inp_parallel
#define pack_head_len_inp head_len/inp_parallel
#define pack_gelu_len_inp gelu_len/inp_parallel

#define pack_seq_num_w seq_num/w_parallel
#define pack_inp_len_w inp_len/w_parallel
#define pack_head_len_w head_len/w_parallel
#define pack_gelu_len_w gelu_len/w_parallel

typedef ap_uint<32 * inp_parallel> io_pack_float;
typedef ap_uint<8 * inp_parallel> io_pack_int8;
typedef ap_uint<8 * w_parallel> io_pack_int16;
typedef ap_uint<64 * inp_parallel> io_pack_int64;

typedef ap_uint<32 * inp_parallel * 2> double_io_pack_float;
typedef ap_uint<8 * inp_parallel * 2> double_io_pack_int8;
typedef ap_uint<8 * w_parallel * 2> double_io_pack_int16;

typedef union {
  float f;
  uint32_t i;
} converter_t;


typedef ap_axiu<8*inp_parallel, 0, 0, 0> pkt_int8;
typedef ap_axiu<32*inp_parallel, 0, 0, 0> pkt_float;

typedef ap_axiu<8*inp_parallel*2, 0, 0, 0> double_pkt_int8;
typedef ap_axiu<32*inp_parallel*2, 0, 0, 0> double_pkt_float;

#endif