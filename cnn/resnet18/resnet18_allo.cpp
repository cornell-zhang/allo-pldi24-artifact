
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>

using namespace std;

// CC
void l4_conv_copy(
  int8_t inp[1][64][32][32],
  int8_t out[1][64][32][32],
  int8_t weight[64][64][3][3],
  int8_t inp_copy[1][64][32][32]
) {	// L13

  int8_t padding[1][64][34][34];	// padding
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  #pragma HLS dataflow

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 64; c++) { // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 33 && w >= 1 && w < 33) {    // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
            inp_copy[b][c][(h - 1)][(w - 1)] = v11;      // L38 
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][34];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];      // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 64; co++) {     // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 8; v9o++) {     // L13
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {     // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = padding[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {        // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {        // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                // out[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }
          if ((ho - 2) >= 0 && (wo - 2) >= 0) {
            out[b][co][(ho - 2)][(wo - 2)] = temp;
          }
        }
      }
    }
  }

}

void l23_two_conv(
  int8_t inp0[1][512][4][4],
  int8_t out0[1][512][4][4],
  int8_t weight0[512][512][3][3],

  int8_t inp1[1][256][8][8],
  int8_t out1[1][512][4][4],
  int8_t weight1[512][256][1][1]
) {	// L1193

  #pragma HLS dataflow
  int8_t padding[1][512][6][6];	// L1194
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 6; h++) {        // L6
        for (int w = 0; w < 6; w++) {      // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 5 && w >= 1 && w < 5) {    // L35
            int8_t v11 = inp0[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }  

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][6];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 64; v9o++) {
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = padding[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight0[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                // out0[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }
          if ((ho - 2) >= 0 && (wo - 2) >= 0) {
            out0[b][co][(ho - 2)][(wo - 2)] = temp;
          }


        }
      }
    }
  }

  for (int b = 0; b < 1; b++) {     // L4
    for (int co = 0; co < 512; co++) {    // L5
      for (int ho = 0; ho < 4; ho++) {    // L6
        for (int wo = 0; wo < 4; wo++) {  // L7
          int8_t v;     // L10
          v = 0;        // L11
          for (int ci = 0; ci < 256; ci++) {   // L12
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp1[b][ci][((ho * 2) + r)][((wo * 2) + c)]; // L15
                int8_t v12 = weight1[co][ci][r][c];  // L16
                int16_t v13 = v11;      // L17
                int16_t v14 = v12;      // L18
                int16_t v15 = v13 * v14;        // L19
                int8_t v16 = v15;       // L20
                int8_t v17 = v; // L21
                int8_t v18 = v17 + v16; // L22
                v = v18;        // L23
              }
            }
          }
          int8_t v19 = v;       // L27
          out1[b][co][ho][wo] = v19;      // L28
        }
      }
    }
  }

}

void l16_two_conv(
  int8_t inp0[1][256][8][8],
  int8_t out0[1][256][8][8],
  int8_t weight0[256][256][3][3],

  int8_t inp1[1][128][16][16],
  int8_t out1[1][256][8][8],
  int8_t weight1[256][128][1][1]
) {	// L3089
  int8_t padding[1][256][10][10];	// L3090
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  #pragma HLS dataflow

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 9 && w >= 1 && w < 9) {    // L35
            int8_t v11 = inp0[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][10];    // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 256; co++) {    // L10
      for (int ho = 0; ho < 10; ho++) {   // L11
        for (int wo = 0; wo < 10; wo++) { // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 64; v9o++) {
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = padding[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight0[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                out0[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
              }
            }
          }
          if ((ho - 2) >= 0 && (wo - 2) >= 0) {
            out0[b][co][(ho - 2)][(wo - 2)] = temp;
          }

        }
      }
    }
  }


  for (int b = 0; b < 1; b++) {     // L4
    for (int co = 0; co < 256; co++) {    // L5
      for (int ho = 0; ho < 8; ho++) {    // L6
        for (int wo = 0; wo < 8; wo++) {  // L7
          int8_t v;     // L10
          v = 0;        // L11
          for (int ci = 0; ci < 128; ci++) {   // L12
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp1[b][ci][((ho * 2) + r)][((wo * 2) + c)]; // L15
                int8_t v12 = weight1[co][ci][r][c];  // L16
                int16_t v13 = v11;      // L17
                int16_t v14 = v12;      // L18
                int16_t v15 = v13 * v14;        // L19
                int8_t v16 = v15;       // L20
                int8_t v17 = v; // L21
                int8_t v18 = v17 + v16; // L22
                v = v18;        // L23
              }
            }
          }
          int8_t v19 = v;       // L27
          out1[b][co][ho][wo] = v19;      // L28
        }
      }
    }
  }

}

void l9_two_conv(
  int8_t inp0[1][128][16][16],
  int8_t out0[1][128][16][16],
  int8_t weight0[128][128][3][3],

  int8_t inp1[1][64][32][32],
  int8_t out1[1][128][16][16],
  int8_t weight1[128][64][1][1]

) {	// L4985
  int8_t inp_padded[1][128][18][18];	// L4986
  #pragma HLS STREAM variable=inp_padded depth=12 type=fifo

  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 128; c++) {        // L5
      for (int h = 0; h < 18; h++) {       // L6
        for (int w = 0; w < 18; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 17 && w >= 1 && w < 17) {    // L35
            int8_t v11 = inp0[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          inp_padded[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][18];    // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3


  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 128; co++) {    // L10
      for (int ho = 0; ho < 18; ho++) {   // L11
        for (int wo = 0; wo < 18; wo++) { // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 16; v9o++) { 
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = inp_padded[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight0[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                // out0[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }
          if ((ho - 2) >= 0 && (wo - 2) >= 0) {
            out0[b][co][(ho - 2)][(wo - 2)] = temp;
          }

        }
      }
    }
  }


  for (int b = 0; b < 1; b++) {     // L4
    for (int co = 0; co < 128; co++) {    // L5
      for (int ho = 0; ho < 16; ho++) {   // L6
        for (int wo = 0; wo < 16; wo++) { // L7
          int8_t v;     // L10
          v = 0;        // L11
          for (int ci = 0; ci < 64; ci++) {    // L12
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp1[b][ci][((ho * 2) + r)][((wo * 2) + c)]; // L15
                int8_t v12 = weight1[co][ci][r][c];  // L16
                int16_t v13 = v11;      // L17
                int16_t v14 = v12;      // L18
                int16_t v15 = v13 * v14;        // L19
                int8_t v16 = v15;       // L20
                int8_t v17 = v; // L21
                int8_t v18 = v17 + v16; // L22
                v = v18;        // L23
              }
            }
          }
          int8_t v19 = v;       // L27
          out1[b][co][ho][wo] = v19;      // L28
        }
      }
    }
  }

}

void l28_avg_pool(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][1][1]
) {	// L6881

  int8_t S_b_ci_ho_wo_0_reuse_2[4][4];  // L7
  #pragma HLS array_partition variable=S_b_ci_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_ci_ho_wo_0_reuse_3[4][4];  // L8
  #pragma HLS array_partition variable=S_b_ci_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_ci_ho_wo_0_reuse_3 complete dim=2

  l_S_b_ci_ho_wo_0_b: for (int b = 0; b < 1; b++) {     // L9
    l_ci: for (int ci = 0; ci < 512; ci++) {    // L10
      for (int ho = 0; ho < 4; ho++) {    // L11
        for (int wo = 0; wo < 4; wo++) {  // L12
          int8_t v8 = S_b_ci_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_ci_ho_wo_0_reuse_2[0][wo] = v8;   // L14
          int8_t v9 = S_b_ci_ho_wo_0_reuse_2[2][wo];    // L15
          S_b_ci_ho_wo_0_reuse_2[1][wo] = v9;   // L16
          int8_t v10 = S_b_ci_ho_wo_0_reuse_2[3][wo];   // L17
          S_b_ci_ho_wo_0_reuse_2[2][wo] = v10;  // L18
          int8_t v11 = inp[0][ci][ho][wo];       // L20
          S_b_ci_ho_wo_0_reuse_2[3][wo] = v11;  // L21
          if ((ho - 3) >= 0) {  // L22
            for (int v12 = 0; v12 < 4; v12++) { // L23
              int8_t v13 = S_b_ci_ho_wo_0_reuse_3[v12][1];      // L24
              S_b_ci_ho_wo_0_reuse_3[v12][0] = v13;     // L25
              int8_t v14 = S_b_ci_ho_wo_0_reuse_3[v12][2];      // L26
              S_b_ci_ho_wo_0_reuse_3[v12][1] = v14;     // L27
              int8_t v15 = S_b_ci_ho_wo_0_reuse_3[v12][3];      // L28
              S_b_ci_ho_wo_0_reuse_3[v12][2] = v15;     // L29
              int8_t v16 = S_b_ci_ho_wo_0_reuse_2[v12][wo];     // L30
              S_b_ci_ho_wo_0_reuse_3[v12][3] = v16;     // L31
            }
            if ((wo - 3) >= 0) {        // L33
              int8_t v; // L36
              v = 0;    // L37
              l_S_r_c_0_r: for (int r = 0; r < 4; r++) {        // L38
                for (int c = 0; c < 4; c++) {      // L39
                  int8_t v20 = S_b_ci_ho_wo_0_reuse_3[r][c];    // L40
                  int8_t v21 = v;       // L41
                  int8_t v22 = v21 + v20;       // L42
                  v = v22;      // L43
                }
              }
              int8_t v23 = v;   // L50
              int8_t v24 = v23 / 16;    // L51
              out[b][ci][(ho - 3)][(wo - 3)] = v24;      // L52
            }
          }
        }
      }
    }
  }

}

void l2_conv_copy(
  int8_t inp[1][64][32][32],
  int8_t out[1][64][32][32],
  int8_t weight[64][64][3][3],

  int8_t cpy_in[1][64][32][32],
  int8_t cpy_out[1][64][32][32]
) {	// L7861

  int8_t padding[1][64][34][34];	// inp padding
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 64; c++) { // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 33 && w >= 1 && w < 33) {    // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][34];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];      // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 64; co++) {     // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 8; v9o++) {
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {     // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = padding[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {        // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {        // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                // out[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }

          if ((ho - 2) >= 0 && (wo - 2) >= 0) {
            out[b][co][(ho - 2)][(wo - 2)] = temp;
          }
        }
      }
    }
  }

  // copy from cpy_in to cpy_out
  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 64; co++) {     // L10
      for (int ho = 0; ho < 32; ho++) {   // L11
        for (int wo = 0; wo < 32; wo++) { // L12
          cpy_out[b][co][ho][wo] = cpy_in[b][co][ho][wo];
        }
      }
    }
  }

}

void l21_relu_pad_copy(
  int8_t inp0[1][256][8][8],
  int8_t out0[1][256][10][10],
  int8_t inp0_copy[1][256][8][8]
) {	// L9041

  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 9 && w >= 1 && w < 9) {    // L35
            int8_t v11 = inp0[b][c][(h - 1)][(w - 1)];    // L36
            v = v11 > 0 ? v11 : 0;    // L37
            inp0_copy[b][c][(h - 1)][(w - 1)] = v11;    // L38
          }
          int8_t v12 = v;       // L39
          out0[b][c][h][w] = v12; // L40
        }
      }
    }
  }  

}

void l14_relu_pad(
  int8_t inp0[1][128][16][16],
  int8_t out0[1][128][18][18], // relu out + pad
  int8_t out1[1][128][16][16]  // relu out
) {	// L9645
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 128; c++) {        // L5
      for (int h = 0; h < 18; h++) {       // L6
        for (int w = 0; w < 18; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 17 && w >= 1 && w < 17) {    // L35
            int8_t v11 = inp0[b][c][(h - 1)][(w - 1)];    // L36
            v = v11 > 0 ? v11 : 0;    // L37
            out1[b][c][(h - 1)][(w - 1)] = v;    // L38
          }
          int8_t v12 = v;       // L39
          out0[b][c][h][w] = v12; // L40
        }
      }
    }
  }
}

void l7_relu_pad(
  int8_t inp[1][64][32][32],
  int8_t padded_relu_out[1][64][34][34],
  int8_t relu_out[1][64][32][32]
) {	// L10249
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 64; c++) { // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && w >= 1 && h < 33 && w < 33) { // L16
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11 > 0 ? v11 : 0;    // L37
            relu_out[b][c][(h - 1)][(w - 1)] = v;    // L38
          }
          int8_t v12 = v;       // L39
          padded_relu_out[b][c][h][w] = v12; // L40
        }
      }
    }
  }

}

void l26_relu_pad_copy(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][6][6],
  
  int8_t copy_in[1][512][4][4],
  int8_t copy_out[1][512][4][4]
) {	// L10845

  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 6; h++) {        // L6
        for (int w = 0; w < 6; w++) {      // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && w >= 1 && h < 5 && w < 5) { // L16
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11 > 0 ? v11 : 0;    // L37
          }
          int8_t v12 = v;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  // copt from copy_in to copy_out
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 4; h++) {        // L6
        for (int w = 0; w < 4; w++) {      // L7
          copy_out[b][c][h][w] = copy_in[b][c][h][w];
        }
      }
    }
  }

}

void layer0_res(
  int8_t inp[1][64][32][32],
  int8_t relu_pad[1][64][34][34],
  int8_t relu[1][64][32][32]
) {	// L11449

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 64; c++) { // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && w >= 1 && h < 33 && w < 33) { // L16
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
            int8_t v12 = v > 0 ? v : 0;
            relu[b][c][h-1][w-1] = v12;    // L38
          }
          int8_t v13 = v;       // L39
          relu_pad[b][c][h][w] = v13; // L40
        }
      }
    }
  }


}

void l19_relu_pad_copy(
  int8_t inp[1][256][8][8],
  int8_t out[1][256][10][10],
  int8_t copy_in[1][256][8][8],
  int8_t copy_out[1][256][8][8]
) {	// L12045

  #pragma HLS dataflow
   for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && w >= 1 && h < 9 && w < 9) { // L16
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11 > 0 ? v11 : 0;    // L37
          }
          int8_t v12 = v;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  } 

  // copy from copy_in to copy_out
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 8; h++) {       // L6
        for (int w = 0; w < 8; w++) {     // L7
          copy_out[b][c][h][w] = copy_in[b][c][h][w];
        }
      }
    }
  }

}

void l12_relu_pad(
  int8_t inp[1][128][16][16],
  int8_t out[1][128][18][18], // padding
  int8_t copy_in[1][128][16][16],
  int8_t copy_out[1][128][16][16]
) {	// L12649

  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 128; c++) {        // L5
      for (int h = 0; h < 18; h++) {       // L6
        for (int w = 0; w < 18; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && w >= 1 && h < 17 && w < 17) { // L16
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11 > 0 ? v11 : 0;    // L37
          }
          int8_t v12 = v;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  // copy from copy_in to copy_out
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 128; c++) {        // L5
      for (int h = 0; h < 16; h++) {       // L6
        for (int w = 0; w < 16; w++) {     // L7
          copy_out[b][c][h][w] = copy_in[b][c][h][w];
        }
      }
    }
  }

}

void l5_relu_pad(
  int8_t inp0[1][64][32][32],
  int8_t out_padded_relu[1][64][34][34], // padding on relu
  int8_t inp1[1][64][32][32],
  int8_t inp1_cpy[1][64][32][32]
) {	// L13253

  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 64; c++) { // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && w >= 1 && h < 33 && w < 33) { // L16
            int8_t v11 = inp0[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v > 0 ? v : 0;       // L39
          out_padded_relu[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  // copy inp1 to inp1_cpy
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 64; c++) { // L5
      for (int h = 0; h < 32; h++) {       // L6
        for (int w = 0; w < 32; w++) {     // L7
          inp1_cpy[b][c][h][w] = inp1[b][c][h][w];
        }
      }
    }
  }

}

void l24_merge_relu(
  int8_t inp0[1][512][4][4],
  int8_t inp1[1][512][4][4],
  int8_t out0[1][512][4][4]
) {	// L13849

  // add inp0 and inp1
  for (int v7744 = 0; v7744 < 512; v7744 += 64) {	// L13850
    for (int v7745 = 0; v7745 < 4; v7745 += 1) {	// L13851
      for (int v7746 = 0; v7746 < 4; v7746 += 1) {	// L13852
        #pragma HLS pipeline II=1
        int8_t v7747 = inp0[0][v7744][v7745][v7746];	// L13853
        int8_t v7748 = inp1[0][v7744][v7745][v7746];	// L13854
        int8_t v7749 = v7747 + v7748;	// L13855
        int8_t v7750 = v7749 > 0 ? v7749 : 0;	// L13856
        out0[0][v7744][v7745][v7746] = v7750;	// L13856
      }
    }
  }

}

void l17_merge_relu(
  int8_t inp0[1][256][8][8],
  int8_t inp1[1][256][8][8],
  int8_t out0[1][256][8][8]
) {	// L14569

  // add inp0 and inp1
  for (int v8660 = 0; v8660 < 256; v8660 += 1) {	// L14570
    for (int v8661 = 0; v8661 < 8; v8661 += 1) {	// L14571
      for (int v8662 = 0; v8662 < 8; v8662 += 1) {	// L14572
        int8_t v8663 = inp0[0][v8660][v8661][v8662];	// L14573
        int8_t v8664 = inp1[0][v8660][v8661][v8662];	// L14574
        int8_t v8665 = v8663 + v8664;	// L14575
        int8_t v8666 = v8665 > 0 ? : v8665;	// L14576
        out0[0][v8660][v8661][v8662] = v8666;	// L14576
      }
    }
  }

}

void l10_merge_relu(
  int8_t inp0[1][128][16][16],
  int8_t inp1[1][128][16][16],
  int8_t out0[1][128][16][16]
) {	// L15289


  // add inp0 and inp1
  for (int v9246 = 0; v9246 < 128; v9246 += 1) {	// L15290
    for (int v9247 = 0; v9247 < 16; v9247 += 1) {	// L15291
      for (int v9248 = 0; v9248 < 16; v9248 += 1) {	// L15292
        int8_t v9249 = inp0[0][v9246][v9247][v9248];	// L15293
        int8_t v9250 = inp1[0][v9246][v9247][v9248];	// L15294
        int8_t v9251 = v9249 + v9250;	// L15305
        int8_t v9253 = v9251 > 0 ? v9251 : 0;	// L15306
        out0[0][v9246][v9247][v9248] = v9253;	// L15306
      }
    }
  }

}

void l29_linear(
  int8_t inp[1][512][1][1],
  int8_t out[1][10],
  int8_t weight[10][512]
) {	// L16009

  // linear layer: matrix multiply
  for (int b = 0; b < 1; b++) {        // L4
    for (int co = 0; co < 10; co++) {  // L5
      int8_t v; // L6
      v = 0;    // L7
      for (int ci = 0; ci < 512; ci++) {        // L8
      
        int8_t v1 = inp[b][ci][0][0];   // L9
        int8_t v2 = weight[co][ci];     // L10
        int16_t v3 = v1;        // L11
        int16_t v4 = v2;        // L12
        int16_t v5 = v3 * v4;   // L13
        int8_t v6 = v5; // L14
        int8_t v7 = v;  // L15
        int8_t v8 = v7 + v6;     // L16
        v = v8; // L17
      }
      int8_t v9 = v;  // L19
      out[b][co] = v9;        // L20
    }
  }


}

void l3_add_relu(
  int8_t inp0[1][64][32][32],
  int8_t inp1[1][64][32][32],
  int8_t out0[1][64][32][32]
) {	// L16812
  // add inp0 and inp1
  for (int v10498 = 0; v10498 < 64; v10498 += 1) {	// L16813
    for (int v10499 = 0; v10499 < 32; v10499 += 1) {	// L16814
      for (int v10500 = 0; v10500 < 32; v10500 += 1) {	// L16815
        #pragma HLS pipeline II=1
        int8_t v10501 = inp0[0][v10498][v10499][v10500];	// L16816
        int8_t v10502 = inp1[0][v10498][v10499][v10500];	// L16817
        int8_t v10503 = v10501 + v10502;	// L16818
        int8_t v10504 = v10503 > 0 ? v10503 : 0;	// L16819
        out0[0][v10498][v10499][v10500] = v10504;	// L16819
      }
    }
  }
}

// CC
void l22_conv_relu_copy(
  int8_t inp[1][256][10][10],
  int8_t weight[512][256][3][3],
  int8_t out[1][512][4][4],

  int8_t copy_in[1][256][8][8],
  int8_t copy_out[1][256][8][8]
) {	// L17528

  #pragma HLS dataflow
  int8_t S_b_co_ho_wo_0_reuse_2[8][3][10];    // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 256; co++) {    // L10
      for (int ho = 0; ho < 10; ho++) {   // L11
        for (int wo = 0; wo < 10; wo++) { // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 256; v9o++) { 
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = inp[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho % 2) == 0 && (ho - 2) >= 0 && (((-ho) + ((ho / 2) * 2)) + 1) >= 0 && (ho % 2) >= 0) { // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo % 2) == 0 && (wo - 2) >= 0 && (((-wo) + ((wo / 2) * 2)) + 1) >= 0 && (wo % 2) >= 0) {       // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v > 0 ? v : 0;   // L52
                // out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v30;  // L53
              }
            }
          }
          if ( ho > 2 && wo > 2) {
            out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = temp;
          } 

        } 
      }
    }
  }

  // copy from copy_in to copy_out
  for (int v31 = 0; v31 < 1; v31++) {	// L59
    for (int v32 = 0; v32 < 256; v32++) {	// L60
      for (int v33 = 0; v33 < 8; v33++) {	// L61
        for (int v34 = 0; v34 < 8; v34++) {	// L62
          #pragma HLS pipeline II=1
          copy_out[v31][v32][v33][v34] = copy_in[v31][v32][v33][v34];	// L63
        }
      }
    }
  }
}

void l15_conv_copy(
  int8_t inp[1][128][18][18],
  int8_t weight[256][128][3][3],
  int8_t out[1][256][8][8], // conv + relu out

  int8_t copy_in[1][128][16][16],
  int8_t copy_out[1][128][16][16]
) {	// L18774

  #pragma HLS dataflow
  int8_t S_b_co_ho_wo_0_reuse_2[8][3][18];    // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 256; co++) {    // L10
      for (int ho = 0; ho < 18; ho++) {   // L11
        for (int wo = 0; wo < 18; wo++) { // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 16; v9o++) { 
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = inp[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho % 2) == 0 && (ho - 2) >= 0 && (((-ho) + ((ho / 2) * 2)) + 1) >= 0 && (ho % 2) >= 0) { // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo % 2) == 0 && (wo - 2) >= 0 && (((-wo) + ((wo / 2) * 2)) + 1) >= 0 && (wo % 2) >= 0) {       // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                // out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v30;  // L53
                temp += v30;
              }
            }
          }
          if ( ho > 1 && wo > 1 && (ho % 2 == 0) && (wo % 2 == 0)) {
            out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = temp;
          }

        }
      }
    }
  }

  // copy from copy_in to copy_out
  for (int v11867 = 0; v11867 < 128; v11867 += 64) {	// L18778
    for (int v11868 = 0; v11868 < 16; v11868 += 1) {	// L18779
      for (int v11869 = 0; v11869 < 16; v11869 += 1) {	// L18780
        #pragma HLS pipeline II=1
        copy_out[0][v11867][v11868][v11869] = copy_in[0][v11867][v11868][v11869];	// L18781
      }
    }
  }
}

void l8_conv_relu(
  int8_t inp[1][64][34][34],
  int8_t weight[128][64][3][3],
  int8_t out[1][128][16][16], // out after conv2d + relu

  int8_t copy_in[1][64][32][32],
  int8_t copy_out[1][64][32][32]
) {	// L20020

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][34];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];      // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3


  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 128; co++) {    // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 8; v9o++) { 
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {     // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = inp[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho % 2) == 0 && (ho - 2) >= 0 && (((-ho) + ((ho / 2) * 2)) + 1) >= 0 && (ho % 2) >= 0) { // L21
              for (int v13 = 0; v13 < 8; v13++) {        // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo % 2) == 0 && (wo - 2) >= 0 && (((-wo) + ((wo / 2) * 2)) + 1) >= 0 && (wo % 2) >= 0) {       // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {        // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v > 0 ? v : 0;   // L52
                // out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v30;  // L53
                temp += v30;
              }
            }
          }
          if ( ho > 1 && wo > 1 && ho % 2 == 0 && wo % 2 == 0) {
            out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = temp;
          }

        }
      }
    }
  }

  // copy copy_in to copy_out
  for (int v12663 = 0; v12663 < 64; v12663 += 1) {	// L20022
    for (int v12664 = 0; v12664 < 32; v12664 += 1) {	// L20023
      for (int v12665 = 0; v12665 < 32; v12665 += 1) {	// L20024
        #pragma HLS pipeline II=1
        int8_t v12666 = copy_in[0][v12663][v12664][v12665];	// L20025
        copy_out[0][v12663][v12664][v12665] = v12666;	// L20026
      }
    }
  }
}

void l27_conv_merge(
  int8_t inp0[1][512][6][6],
  int8_t weight0[512][512][3][3],

  int8_t inp1[1][512][4][4],
  int8_t merge[1][512][4][4]
) {	// L21264
  int8_t S_b_co_ho_wo_0_reuse_2[8][3][6];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 64; v9o++) { 
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = inp0[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight0[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                int8_t v31 = inp1[b][co][(ho - 2)][(wo - 2)];      // L53
                // merge[b][co][(ho - 2)][(wo - 2)] = v30 + v31;      // L53
                temp += v30 + v31;
              }
            }
          }

          if (ho > 1 && wo > 1) {
            merge[b][co][(ho - 2)][(wo - 2)] = temp;
          }

        } 
      }
    }
  }


}

void layer1_conv_copy(
  int8_t l1_inp0[1][64][34][34],
  int8_t l1_conv_weight[64][64][3][3],
  int8_t l1_conv_out_relu[1][64][32][32],

  int8_t l1_inp1[1][64][32][32],
  int8_t l1_inp1_copy[1][64][32][32]

) {	// L22568

  // conv + relu
  int8_t S_b_co_ho_wo_0_reuse_2[8][3][34];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];      // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  #pragma HLS dataflow

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 64; co++) {     // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 8; v9o++) { 
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {     // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = l1_inp0[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {        // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {        // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = l1_conv_weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                // l1_conv_out_relu[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }

          if (ho > 2 && wo > 2) {
            l1_conv_out_relu[b][co][(ho - 2)][(wo - 2)] = temp;
          }

        }
      }
    }
  }

  // copy l1_inp1 to l1_inp1_copy
  for (int v31 = 0; v31 < 1; v31++) { // L22569
    for (int v32 = 0; v32 < 64; v32++) { // L22570
      for (int v33 = 0; v33 < 32; v33++) { // L22571
        for (int v34 = 0; v34 < 32; v34++) { // L22572
          l1_inp1_copy[v31][v32][v33][v34] = l1_inp1[v31][v32][v33][v34]; // L22573
        }
      }
    }
  }

}

// CC
void l20_conv_merge(
  int8_t inp[1][256][10][10],
  int8_t weight[256][256][3][3],
  int8_t inp1[1][256][8][8],
  int8_t out[1][256][8][8]
) {	// L23808
  int8_t S_b_co_ho_wo_0_reuse_2[8][3][10];    // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 256; co++) {    // L10
      for (int ho = 0; ho < 10; ho++) {   // L11
        for (int wo = 0; wo < 10; wo++) { // L12

          int8_t temp = 0;
          for (int v9_o = 0; v9_o < 64; v9_o++) {
            #pragma HLS pipeline II=1
            for (int v9_i = 0; v9_i < 8; v9_i++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9_i][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9_i][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9_i][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9_i][1][wo] = v11;    // L17
              int8_t v12 = inp[b][v9_i][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9_i][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v + inp1[b][co][(ho - 2)][(wo - 2)];      // L52
                // out[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }
          if (ho >= 2 && wo >= 2) {
            out[b][co][(ho - 2)][(wo - 2)] = temp;
          }
        }
      }
    }
  }

}

// CC
void l13_conv_merge(
  int8_t inp0[1][128][18][18],
  int8_t weight0[128][128][3][3],

  int8_t inp1[1][128][16][16],
  int8_t out1[1][128][16][16]
) {	// L25112

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][18];    // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 128; co++) {    // L10
      for (int ho = 0; ho < 18; ho++) {   // L11
        for (int wo = 0; wo < 18; wo++) { // L12

          int8_t temp = 0;
          for (int v9_o = 0; v9_o < 16; v9_o++) {
            #pragma HLS pipeline II=1

            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = inp0[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight0[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                int8_t v31 = inp1[b][co][(ho - 2)][(wo - 2)];      // L53
                // out1[b][co][(ho - 2)][(wo - 2)] = v30 + v31;      // L53
                temp += v30 + v31;
              }
            }
          }

          if (ho >= 2 && wo >= 2) {
            out1[b][co][(ho - 2)][(wo - 2)] = temp;
          }

        }
      }
    }
  }

}

// CC
void l6_conv_merge(
  int8_t inp[1][64][34][34],
  int8_t weight[64][64][3][3],

  int8_t merge_in[1][64][32][32],
  int8_t merge_out[1][64][32][32] // merged
) {	// L26416
  int8_t out[1][64][32][32];	// conv out
  // #pragma HLS STREAM variable=out depth=12 type=fifo
  // #pragma HLS dataflow

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][34];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];      // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 64; co++) {     // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12

          int8_t temp = 0;
          for (int v9_o = 0; v9_o < 8; v9_o++) {
            #pragma HLS pipeline II=1

            for (int v9 = 0; v9 < 8; v9++) {     // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = inp[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {        // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {        // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                // out[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }
          if (ho >= 2 && wo >= 2) {
            // out[b][co][(ho - 2)][(wo - 2)] = temp;
            temp += merge_in[b][co][(ho - 2)][(wo - 2)];
            merge_out[b][co][(ho - 2)][(wo - 2)] = temp;
          }

        }
      }
    }
  }  

}

// CC
void l25_conv_copy(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][4][4],
  int8_t weight[512][512][3][3],
  int8_t inp_copy[1][512][4][4]
) {	// L27716

  #pragma HLS dataflow
  int8_t padding[1][512][6][6];	// L27717
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 6; h++) {        // L6
        for (int w = 0; w < 6; w++) {      // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 5 && w >= 1 && w < 5) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
            inp_copy[b][c][(h - 1)][(w - 1)] = v11;      // L38
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][6];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12
          int8_t temp_o = 0;
          for (int v9_o = 0; v9_o < 64; v9_o++) {
            #pragma HLS pipeline II=1
            for (int v9_i = 0; v9_i < 8; v9_i++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9_i][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9_i][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9_i][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9_i][1][wo] = v11;    // L17
              int8_t v12 = padding[b][v9_i][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9_i][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                temp_o += v30;      // L53
              }
            }
          }            
          if (wo > 2 && ho > 2) {
            out[b][co][(ho - 2)][(wo - 2)] = temp_o;
          }
        }
      }
    }
  }

}

void conv2d_layer0(
  int8_t v0[1][3][34][34],
  int8_t v1[64][3][3][3],
  int8_t v2[1][64][32][32]
) {     // L5
  int8_t S_b_co_ho_wo_0_reuse_2[3][3][34];      // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3][3];       // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 64; co++) {     // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12
          for (int v9 = 0; v9 < 3; v9++) {      // L13
            int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
            S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
            int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
            S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
            int8_t v12 = v0[b][v9][ho][wo];     // L18
            S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
          }
          if ((ho - 2) >= 0) {  // L21
            for (int v13 = 0; v13 < 3; v13++) { // L22
              for (int v14 = 0; v14 < 3; v14++) {       // L23
                int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
              }
            }
            if ((wo - 2) >= 0) {        // L32
              int8_t v; // L35
              v = 0;    // L36
              for (int ci = 0; ci < 3; ci++) { // L37
                for (int r = 0; r < 3; r++) {      // L38
                  for (int c = 0; c < 3; c++) {    // L39
                    int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                    int8_t v23 = v1[co][ci][r][c];      // L41
                    int16_t v24 = v22;  // L42
                    int16_t v25 = v23;  // L43
                    int16_t v26 = v24 * v25;    // L44
                    int8_t v27 = v26;   // L45
                    int8_t v28 = v;     // L46
                    int8_t v29 = v28 + v27;     // L47
                    v = v29;    // L48
                  }
                }
              }
              int8_t v30 = v;   // L52
              v2[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
            }
          }
        }
      }
    }
  }
}

void padding_layer0(
  int8_t v0[1][3][32][32],
  int8_t v1[1][3][34][34]
) {     // L2
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 3; c++) {  // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 33 && w >= 1 && w < 33) { // L35
            int8_t v11 = v0[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          v1[b][c][h][w] = v12; // L40
        }
      }
    }
  }
}

void layer0(
  int8_t inp[1][3][32][32], // inp, padding=1
  int8_t out[1][64][32][32], // output
  int8_t weight[64][3][3][3] // weight. OC=64
) {	

int8_t padded[1][3][34][34];
#pragma HLS STREAM variable=padded depth=12 type=fifo

#pragma HLS dataflow
padding_layer0(inp, padded);
conv2d_layer0(padded, weight, out);
}

// CC
void l18_pad_conv_copy(
  int8_t inp[1][256][8][8],
  int8_t out[1][256][8][8],
  int8_t weight[256][256][3][3],
  int8_t inp_copy[1][256][8][8]
) {	// L30050
  int8_t padding[1][256][10][10];	// L30051
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 9 && w >= 1 && w < 9) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
            inp_copy[b][c][(h - 1)][(w - 1)] = v11;   // L38
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][10];    // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 256; co++) {    // L10
      for (int ho = 0; ho < 10; ho++) {   // L11
        for (int wo = 0; wo < 10; wo++) { // L12

          int8_t temp = 0;
          for (int v9_o = 0; v9_o < 64; v9_o++) {   
            #pragma HLS pipeline II=1

            for (int v9_i = 0; v9_i < 8; v9_i++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9_i][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9_i][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9_i][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9_i][1][wo] = v11;    // L17
              int8_t v12 = padding[b][v9_i][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9_i][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                temp += v30;
              }
            }
          }
          if (wo > 2 && ho > 2) {
            out[b][co][(ho - 2)][(wo - 2)] = temp;
          }
        } 
      }
    }
  }
}

// CC
void l11_pad_conv(
  int8_t inp0[1][128][16][16],
  int8_t out0[1][128][16][16],
  int8_t weight0[128][128][3][3],
  int8_t inp0_cpy[1][128][16][16]
) {	// L31238

  int8_t padding[1][128][18][18];	// L31239
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  #pragma HLS dataflow
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 128; c++) {        // L5
      for (int h = 0; h < 18; h++) {       // L6
        for (int w = 0; w < 18; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 17 && w >= 1 && w < 17) { // L35
            int8_t v11 = inp0[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
            inp0_cpy[b][c][(h - 1)][(w - 1)] = v11;   // L38
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][18];    // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 128; co++) {    // L10
      for (int ho = 0; ho < 18; ho++) {   // L11
        for (int wo = 0; wo < 18; wo++) { // L12
          int8_t temp = 0;
          for (int v9o = 0; v9o < 16; v9o++) {
            #pragma HLS pipeline II=1
            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = padding[b][v9][ho][wo];     // L18
              S_b_co_ho_wo_0_reuse_2[v9][2][wo] = v12;    // L19
            }
            if ((ho - 2) >= 0) {  // L21
              for (int v13 = 0; v13 < 8; v13++) {       // L22
                for (int v14 = 0; v14 < 3; v14++) {       // L23
                  int8_t v15 = S_b_co_ho_wo_0_reuse_3[v13][v14][1];       // L24
                  S_b_co_ho_wo_0_reuse_3[v13][v14][0] = v15;      // L25
                  int8_t v16 = S_b_co_ho_wo_0_reuse_3[v13][v14][2];       // L26
                  S_b_co_ho_wo_0_reuse_3[v13][v14][1] = v16;      // L27
                  int8_t v17 = S_b_co_ho_wo_0_reuse_2[v13][v14][wo];      // L28
                  S_b_co_ho_wo_0_reuse_3[v13][v14][2] = v17;      // L29
                }
              }
              if ((wo - 2) >= 0) {        // L32
                int8_t v; // L35
                v = 0;    // L36
                for (int ci = 0; ci < 8; ci++) {       // L37
                  for (int r = 0; r < 3; r++) {      // L38
                    for (int c = 0; c < 3; c++) {    // L39
                      int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40
                      int8_t v23 = weight0[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      int8_t v27 = v26;   // L45
                      int8_t v28 = v;     // L46
                      int8_t v29 = v28 + v27;     // L47
                      v = v29;    // L48
                    }
                  }
                }
                int8_t v30 = v;   // L52
                // out0[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }
          if (wo > 2 && ho > 2) {
            out0[b][co][(ho - 2)][(wo - 2)] = temp;
          }
        }
      }
    }
  }

}

/// This is top function.
void main_graph(
  int8_t inp0[1][3][32][32],
  int8_t conv_weight[64][3][3][3],
  int8_t l1_conv_weight[64][64][3][3],
  int8_t l2_conv_weight[64][64][3][3],
  int8_t l4_weight[64][64][3][3],
  int8_t l6_conv_weight[64][64][3][3],
  int8_t l8_conv_weight[128][64][3][3],
  int8_t l9_weight0[128][128][3][3],
  int8_t l9_weight1[128][64][1][1],
  int8_t l11_conv_weight[128][128][3][3],
  int8_t l13_conv_weight[128][128][3][3],
  int8_t l15_weight[256][128][3][3],
  int8_t l16_weight0[256][256][3][3],
  int8_t l16_weight1[256][128][1][1],
  int8_t l18_weight[256][256][3][3],
  int8_t l20_conv_weight[256][256][3][3],
  int8_t l22_weight[512][256][3][3],
  int8_t l23_weight0[512][512][3][3],
  int8_t l23_weight1[512][256][1][1],
  int8_t l25_weight[512][512][3][3],
  int8_t l27_weight[512][512][3][3],
  int8_t l29_weight[10][512],
  int8_t l29_out[1][10]
) {	// L32426
  #pragma HLS dataflow

  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=inp0
  #pragma HLS interface bram port=conv_weight
  #pragma HLS interface bram port=l1_conv_weight
  #pragma HLS interface bram port=l2_conv_weight
  #pragma HLS interface bram port=l4_weight
  #pragma HLS interface bram port=l6_conv_weight
  #pragma HLS interface bram port=l8_conv_weight
  #pragma HLS interface bram port=l9_weight0
  #pragma HLS interface bram port=l9_weight1
  #pragma HLS interface bram port=l11_conv_weight
  #pragma HLS interface bram port=l13_conv_weight
  #pragma HLS interface bram port=l15_weight
  #pragma HLS interface bram port=l16_weight0
  #pragma HLS interface bram port=l16_weight1
  #pragma HLS interface bram port=l18_weight
  #pragma HLS interface bram port=l20_conv_weight
  #pragma HLS interface bram port=l22_weight
  #pragma HLS interface bram port=l23_weight0
  #pragma HLS interface bram port=l23_weight1
  #pragma HLS interface bram port=l25_weight
  #pragma HLS interface bram port=l27_weight
  #pragma HLS interface bram port=l29_weight

  int8_t l28_out[1][512][1][1];	// L32432
  #pragma HLS STREAM variable=l28_out depth=12 type=fifo

  int8_t l27_merge_out[1][512][4][4];	// L32433
  #pragma HLS STREAM variable=l27_merge_out depth=12 type=fifo
  int8_t l26_out[1][512][6][6];	// L32434
  #pragma HLS STREAM variable=l26_out depth=12 type=fifo

  int8_t l25_out[1][512][4][4];	// L32435
  #pragma HLS STREAM variable=l25_out depth=12 type=fifo

  int8_t l24_out[1][512][4][4];	// L32436
  #pragma HLS STREAM variable=l24_out depth=12 type=fifo

  int8_t l23_out1[1][512][4][4];	// L32437
  #pragma HLS STREAM variable=l23_out1 depth=12 type=fifo

  int8_t l23_out0[1][512][4][4];	// L32438
  #pragma HLS STREAM variable=l23_out0 depth=12 type=fifo

  int8_t l22_out[1][512][4][4];	// L32439
  #pragma HLS STREAM variable=l22_out depth=12 type=fifo

  int8_t l21_pad_out[1][256][10][10];	// L32440
  #pragma HLS STREAM variable=l21_pad_out depth=12 type=fifo

  int8_t l20_merge_out[1][256][8][8];	// L32441
  #pragma HLS STREAM variable=l20_merge_out depth=12 type=fifo

  int8_t l19_pad_out[1][256][10][10];	// L32442
  #pragma HLS STREAM variable=l19_pad_out depth=12 type=fifo

  int8_t l18_out[1][256][8][8];	// L32443
  #pragma HLS STREAM variable=l18_out depth=12 type=fifo

  int8_t l17_out[1][256][8][8];	// L32444
  #pragma HLS STREAM variable=l17_out depth=12 type=fifo

  int8_t l16_out1[1][256][8][8];	// L32445
  #pragma HLS STREAM variable=l16_out1 depth=12 type=fifo

  int8_t l16_out0[1][256][8][8];	// L32446
  #pragma HLS STREAM variable=l16_out0 depth=12 type=fifo

  int8_t l15_out[1][256][8][8];	// L32447
  #pragma HLS STREAM variable=l15_out depth=12 type=fifo

  int8_t l14_relu_pad_out[1][128][18][18];	// L32448
  #pragma HLS STREAM variable=l14_relu_pad_out depth=12 type=fifo

  int8_t l13_merge_out[1][128][16][16];	// L32449
  #pragma HLS STREAM variable=l13_merge_out depth=12 type=fifo

  int8_t l12_relu_padding_out[1][128][18][18];	// L32450
  #pragma HLS STREAM variable=l12_relu_padding_out depth=12 type=fifo

  int8_t l11_conv_out[1][128][16][16];	// L32451
  #pragma HLS STREAM variable=l11_conv_out depth=12 type=fifo

  int8_t l10_merge_out[1][128][16][16];	// L32452
  #pragma HLS STREAM variable=l10_merge_out depth=12 type=fifo

  int8_t l9_out1[1][128][16][16];	// L32453
  #pragma HLS STREAM variable=l9_out1 depth=12 type=fifo

  int8_t l9_out0[1][128][16][16];	// L32454
  #pragma HLS STREAM variable=l9_out0 depth=12 type=fifo

  int8_t l8_conv_out[1][128][16][16];	// L32455
  #pragma HLS STREAM variable=l8_conv_out depth=12 type=fifo

  int8_t l7_padded_relu_out[1][64][34][34];	// L32456
  #pragma HLS STREAM variable=l7_padded_relu_out depth=12 type=fifo

  int8_t l6_merge_out[1][64][32][32];	// L32457
  #pragma HLS STREAM variable=l6_merge_out depth=12 type=fifo

  int8_t l5_out[1][64][34][34];	// L32458
  #pragma HLS STREAM variable=l5_out depth=12 type=fifo

  int8_t l4_out[1][64][32][32];	// L32459
  #pragma HLS STREAM variable=l4_out depth=12 type=fifo

  int8_t l3_out[1][64][32][32];	// L32460
  #pragma HLS STREAM variable=l3_out depth=12 type=fifo

  int8_t l2_conv_out[1][64][32][32];	// L32461
  #pragma HLS STREAM variable=l2_conv_out depth=12 type=fifo

  int8_t l1_conv_out[1][64][32][32];	// L32462
  #pragma HLS STREAM variable=l1_conv_out depth=12 type=fifo

  int8_t out0[1][64][32][32];	// L32464
  #pragma HLS STREAM variable=out0 depth=12 type=fifo

  layer0(inp0, out0, conv_weight);	// padding + conv

  // ----------
  int8_t out1_0[1][64][34][34];	// L32463
  #pragma HLS STREAM variable=out1_0 depth=12 type=fifo

  int8_t out1_1[1][64][32][32];	// L32466
  #pragma HLS STREAM variable=out1_1 depth=12 type=fifo

  layer0_res(out0, out1_0, out1_1);	// L32467

  int8_t l1_copy_out[1][64][32][32];	// L32468
  #pragma HLS STREAM variable=l1_copy_out depth=12 type=fifo

  layer1_conv_copy(out1_0, l1_conv_weight, l1_conv_out, out1_1, l1_copy_out);	// L32469

  int8_t l2_copy_out[1][64][32][32];	// L32470
  #pragma HLS STREAM variable=l2_copy_out depth=12 type=fifo

  l2_conv_copy(l1_conv_out, l2_conv_out, l2_conv_weight, l1_copy_out, l2_copy_out);	// L32471
  l3_add_relu(l2_conv_out, l2_copy_out, l3_out);	// L32472

  int8_t l4_copy_out[1][64][32][32];	// L32473
  #pragma HLS STREAM variable=l4_copy_out depth=12 type=fifo

  l4_conv_copy(l3_out, l4_out, l4_weight, l4_copy_out);	// L32474

  int8_t l5_copy_out[1][64][32][32];	// L32475
  #pragma HLS STREAM variable=l5_copy_out depth=12 type=fifo

  l5_relu_pad(l4_out, l5_out, l4_copy_out, l5_copy_out);	// L32476
  l6_conv_merge(l5_out, l6_conv_weight, l5_copy_out, l6_merge_out);	// L32477
  
  int8_t l7_relu_out[1][64][32][32];	// L32478
  #pragma HLS STREAM variable=l7_relu_out depth=12 type=fifo

  l7_relu_pad(l6_merge_out, l7_padded_relu_out, l7_relu_out);	// L32479
  
  int8_t l8_copy_out[1][64][32][32];	// L32480
  #pragma HLS STREAM variable=l8_copy_out depth=12 type=fifo

  l8_conv_relu(l7_padded_relu_out, l8_conv_weight, l8_conv_out, l7_relu_out, l8_copy_out);	// L32481
  
  l9_two_conv(l8_conv_out, l9_out0, l9_weight0, l8_copy_out, l9_out1, l9_weight1);	// L32482
  l10_merge_relu(l9_out0, l9_out1, l10_merge_out);	// L32483

  int8_t l11_copy_out[1][128][16][16];	// L32484
  #pragma HLS STREAM variable=l11_copy_out depth=12 type=fifo

  l11_pad_conv(l10_merge_out, l11_conv_out, l11_conv_weight, l11_copy_out);	// L32485
  int8_t l12_copy_out[1][128][16][16];	// L32486
  #pragma HLS STREAM variable=l12_copy_out depth=12 type=fifo

  l12_relu_pad(l11_conv_out, l12_relu_padding_out, l11_copy_out, l12_copy_out);	// L32487
  l13_conv_merge(l12_relu_padding_out, l13_conv_weight, l12_copy_out, l13_merge_out);	// L32488
  int8_t l14_relu_out[1][128][16][16];	// L32489
  #pragma HLS STREAM variable=l14_relu_out depth=12 type=fifo

  l14_relu_pad(l13_merge_out, l14_relu_pad_out, l14_relu_out);	// L32490
  int8_t l15_copy_out[1][128][16][16];	// L32491
  #pragma HLS STREAM variable=l15_copy_out depth=12 type=fifo

  l15_conv_copy(l14_relu_pad_out, l15_weight, l15_out, l14_relu_out, l15_copy_out);	// L32492
  l16_two_conv(l15_out, l16_out0, l16_weight0, l15_copy_out, l16_out1, l16_weight1);	// L32493
  l17_merge_relu(l16_out0, l16_out1, l17_out);	// L32494

  int8_t l18_copy_out[1][256][8][8];	// L32495
  #pragma HLS STREAM variable=l18_copy_out depth=12 type=fifo

  l18_pad_conv_copy(l17_out, l18_out, l18_weight, l18_copy_out);	// L32496
  int8_t l19_copy_out[1][256][8][8];	// L32497
  #pragma HLS STREAM variable=l19_copy_out depth=12 type=fifo

  l19_relu_pad_copy(l18_out, l19_pad_out, l18_copy_out, l19_copy_out);	// L32498
  l20_conv_merge(l19_pad_out, l20_conv_weight, l19_copy_out, l20_merge_out);	// L32499
  
  int8_t l21_copy_out[1][256][8][8];	// L32500
  #pragma HLS STREAM variable=l21_copy_out depth=12 type=fifo

  l21_relu_pad_copy(l20_merge_out, l21_pad_out, l21_copy_out);	// L32501
  int8_t l22_copy_out[1][256][8][8];	// L32502
  #pragma HLS STREAM variable=l22_copy_out depth=12 type=fifo

  l22_conv_relu_copy(l21_pad_out, l22_weight, l22_out, l21_copy_out, l22_copy_out);	// L32503
  l23_two_conv(l22_out, l23_out0, l23_weight0, l22_copy_out, l23_out1, l23_weight1);	// L32504
  
  l24_merge_relu(l23_out0, l23_out1, l24_out);	// L32505
  int8_t l25_copy_out[1][512][4][4];	// L32506
  #pragma HLS STREAM variable=l25_copy_out depth=12 type=fifo

  l25_conv_copy(l24_out, l25_out, l25_weight, l25_copy_out);	// L32507
  int8_t l26_copy_out[1][512][4][4];	// L32508
  #pragma HLS STREAM variable=l26_copy_out depth=12 type=fifo

  l26_relu_pad_copy(l25_out, l26_out, l25_copy_out, l26_copy_out);	// L32509
  l27_conv_merge(l26_out, l27_weight, l26_copy_out, l27_merge_out);	// L32510
  
  l28_avg_pool(l27_merge_out, l28_out);	// L32511

  l29_linear(l28_out, l29_out, l29_weight);	// L32513
}

