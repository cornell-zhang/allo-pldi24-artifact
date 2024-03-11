
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

void l10_conv_relu(
  int8_t inp[1][128][18][18],
  int8_t weight[128][1][3][3],
  int8_t out[1][128][8][8]
) {	// L16

  int8_t S_b_co_ho_wo_0_reuse_2[3][18]; // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 128; co++) {    // L10
      for (int ho = 0; ho < 18; ho++) {   // L11
        for (int wo = 0; wo < 18; wo++) { // L12

          #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = inp[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho % 2) == 0 && (ho - 2) >= 0 && (((-ho) + ((ho / 2) * 2)) + 1) >= 0 && (ho % 2) >= 0) { // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo % 2) == 0 && (wo - 2) >= 0 && (((-wo) + ((wo / 2) * 2)) + 1) >= 0 && (wo % 2) >= 0) {       // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v;   // L49
              out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v28;  // L50
            }
          }
        }
      }
    }
  }

}

void l29_relu_pad(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][6][6]
) {	// L1252
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
          }
          int8_t v12 = v > 0 ? v : 0;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  }
}

void l3_relu_conv(
  int8_t inp[1][32][32][32],
  int8_t out[1][64][32][32],
  int8_t weight[64][32][1][1]
) {	// L1722

  #pragma HLS array_partition variable=weight cyclic factor=32 dim=1
  #pragma HLS array_partition variable=weight complete dim=2

  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 2; coo++) {     // L5
      for (int ho = 0; ho < 32; ho++) {   // L6
        for (int wo = 0; wo < 32; wo++) { // L7
          #pragma HLS pipeline II=1
          
          int8_t temp[32];
          #pragma HLS array_partition variable=temp complete dim=1

          for (int ci = 0; ci < 32; ci++) {    // L12
                for (int coi = 0; coi < 32; coi++) {
                  int co = coo << 5 + coi;
                  int8_t v12 = weight[co][ci][0][0];  // L16
                  int16_t v13 = inp[b][ci][ho][wo];      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
          }
          for (int coi = 0; coi < 32; coi++) {
            int co = coo * 32 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v16 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v16;       // L27
          }
        }
      }
    }
  }
}

void l22_pad_conv(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][4][4],
  int8_t weight[512][1][3][3]
) {	// L2826
  #pragma HLS dataflow
  int8_t padding[1][512][6][6];	// L2827
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
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[3][6];  // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12

        #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = padding[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v;   // L49
              out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }
        }
      }
    }
  }

}

void l15_conv_relu(
  int8_t inp[1][256][10][10],
  int8_t weight[256][1][3][3],
  int8_t out[1][256][4][4]
) {	// L4004

  int8_t S_b_co_ho_wo_0_reuse_2[3][10]; // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 256; co++) {    // L10
      for (int ho = 0; ho < 10; ho++) {   // L11
        for (int wo = 0; wo < 10; wo++) { // L12
        #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = inp[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho % 2) == 0 && (ho - 2) >= 0 && (((-ho) + ((ho / 2) * 2)) + 1) >= 0 && (ho % 2) >= 0) { // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo % 2) == 0 && (wo - 2) >= 0 && (((-wo) + ((wo / 2) * 2)) + 1) >= 0 && (wo % 2) >= 0) {       // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v > 0 ? v : 0;   // L49
              out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v28;  // L50
            }
          }
        }
      }
    }
  }

}

void l34_avgpool(
  int8_t inp[1][1024][2][2],
  int8_t out[1][1024][1][1]
) {	// L5240

  int8_t S_b_ci_ho_wo_0_reuse_2[2][2];  // L7
  #pragma HLS array_partition variable=S_b_ci_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_ci_ho_wo_0_reuse_3[2][2];  // L8
  #pragma HLS array_partition variable=S_b_ci_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_ci_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    l_ci: for (int ci = 0; ci < 1024; ci++) {   // L10
      for (int ho = 0; ho < 2; ho++) {    // L11
        for (int wo = 0; wo < 2; wo++) {  // L12
          #pragma HLS pipeline II=1
          int8_t v8 = S_b_ci_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_ci_ho_wo_0_reuse_2[0][wo] = v8;   // L14
          int8_t v9 = inp[0][ci][ho][wo];        // L16
          S_b_ci_ho_wo_0_reuse_2[1][wo] = v9;   // L17
          if ((ho - 1) >= 0) {  // L18
            for (int v10 = 0; v10 < 2; v10++) { // L19
              int8_t v11 = S_b_ci_ho_wo_0_reuse_3[v10][1];      // L20
              S_b_ci_ho_wo_0_reuse_3[v10][0] = v11;     // L21
              int8_t v12 = S_b_ci_ho_wo_0_reuse_2[v10][wo];     // L22
              S_b_ci_ho_wo_0_reuse_3[v10][1] = v12;     // L23
            }
            if ((wo - 1) >= 0) {        // L25
              int8_t v; // L28
              v = 0;    // L29
              l_S_r_c_0_r: for (int r = 0; r < 2; r++) {        // L30
                for (int c = 0; c < 2; c++) {      // L31
                  int8_t v16 = S_b_ci_ho_wo_0_reuse_3[r][c];    // L32
                  int8_t v17 = v;       // L33
                  int8_t v18 = v17 + v16;       // L34
                  v = v18;      // L35
                }
              }
              int8_t v19 = v;   // L42
              int8_t v20 = v19 / 4;     // L43
              out[b][ci][(ho - 1)][(wo - 1)] = v20;      // L44
            }
          }
        }
      }
    }
  }

}

// CC
void l8_relu_conv(
  int8_t inp[1][128][16][16],
  int8_t out[1][128][16][16],
  int8_t weight[128][128][1][1]
) {	// L6220

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1

  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 2; coo++) {    // L5
      for (int ho = 0; ho < 16; ho++) {   // L6
        for (int wo = 0; wo < 16; wo++) { // L7
      
          int8_t temp[1][64][1][1]; // L8
          for (int ci = 0; ci < 128; ci++) {   // L12
            #pragma HLS pipeline II=1
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15
                for  (int coi = 0; coi < 64; coi++) {
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  int8_t v16 = v15;       // L20
                  temp[b][co][ho][wo] += v16;
                }
              }
            }
          }
          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[b][co][ho][wo]; // L25
            int8_t v17 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v17;       // L27
          }

        }
      }
    }
  }

}

void l27_pad_conv(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][4][4],
  int8_t weight[512][1][3][3]
) {	// L7328
  #pragma HLS dataflow
  int8_t padding[1][512][6][6];	// L7329
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 6; h++) {        // L6
        for (int w = 0; w < 6; w++) {      // L7

          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 5 & w >= 1 & w < 5) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  } 

  int8_t S_b_co_ho_wo_0_reuse_2[3][6];  // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12
        #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = padding[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v;   // L49
              out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }
        }
      }
    }
  }


}

void l1_conv_relu(
  int8_t inp[1][3][34][34],
  int8_t weight[32][3][3][3],
  int8_t out[1][32][32][32]
) {	// L8506

  int8_t S_b_co_ho_wo_0_reuse_2[3][3][34];      // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3][3];       // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int coo = 0; coo < 1; coo++) {     // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12

          #pragma HLS pipeline II=1
          int8_t temp[32];
          for (int v9 = 0; v9 < 3; v9++) {      // L13
            int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
            S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
            int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
            S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
            int8_t v12 = inp[b][v9][ho][wo];     // L18
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
              for (int ci = 0; ci < 3; ci++) { // L37
                for (int r = 0; r < 3; r++) {      // L38
                  for (int c = 0; c < 3; c++) {    // L39
                    int8_t v22 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L40

                    for (int coi = 0; coi < 32; coi++) {
                      int co = coo * 32 + coi;
                      int8_t v23 = weight[co][ci][r][c];      // L41
                      int16_t v24 = v22;  // L42
                      int16_t v25 = v23;  // L43
                      int16_t v26 = v24 * v25;    // L44
                      temp[coi] += v26;
                    }
                  }
                }
              }
              // int8_t v30 = v > 0 ? v : 0;   // L52
              // out[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
            }
          }

          if ((wo - 2) >= 0  && (ho - 2) >= 0) {        // L32
            for (int coi = 0; coi < 32; coi++) {
              int co = coo * 32 + coi;
              int8_t v = temp[coi]; // L25
              int8_t v30 = v > 0 ? v : 0;   // L52
              out[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
            }
          }
        }
      }
    }
  }

}

void l20_conv_relu(
  int8_t inp[1][512][6][6],
  int8_t weight[512][1][3][3],
  int8_t out[1][512][4][4]
) {	// L9552


  int8_t S_b_co_ho_wo_0_reuse_2[3][6];  // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12

          #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = inp[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v > 0 ? v : 0;   // L49
              out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }
        }
      }
    }
  }

}

void l13_relu_conv(
  int8_t inp[1][256][8][8],
  int8_t out[1][256][8][8],
  int8_t weight[256][256][1][1]
) {	// L10788

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1

  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 4; coo++) {    // L5
      for (int ho = 0; ho < 8; ho++) {    // L6
        for (int wo = 0; wo < 8; wo++) {  // L7
          
          int8_t temp[64];
          for (int ci = 0; ci < 256; ci++) {   // L12
            #pragma HLS pipeline II=1
            
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15

                for (int coi = 0; coi < 64; coi++) {
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
              }
            }
          }
          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v19;       // L27
          }
        }
      }
    }
  }

}

void l32_pad_conv(
  int8_t inp[1][1024][2][2],
  int8_t out[1][1024][2][2],
  int8_t weight[1024][1][3][3]
) {	// L11896

  #pragma HLS dataflow
  int8_t padding[1][1024][4][4];	// L11897
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 1024; c++) {       // L5
      for (int h = 0; h < 4; h++) {        // L6
        for (int w = 0; w < 4; w++) {      // L7
        #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 3 & w >= 1 & w < 3) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[3][4];  // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 1024; co++) {   // L10
      for (int ho = 0; ho < 4; ho++) {    // L11
        for (int wo = 0; wo < 4; wo++) {  // L12
          #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = padding[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v;   // L49
              out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }
        }
      }
    }
  }

}

void l6_conv_relu(
  int8_t inp[1][64][16][16],
  int8_t weight[128][64][1][1],
  int8_t out[1][128][16][16]
) {	// L13074
#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 2; coo++) {    // L5
      for (int ho = 0; ho < 16; ho++) {   // L6
        for (int wo = 0; wo < 16; wo++) { // L7
          int8_t temp[64];

          for (int ci = 0; ci < 64; ci++) {    // L12

            #pragma HLS pipeline II=1
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15
                for (int coi = 0; coi < 64; coi++) {
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
              }
            }
          }
          // int8_t v19 = v;       // L27
          // out[b][co][ho][wo] = v19;      // L28
          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v;
            out[b][co][ho][wo] = v19;       // L27
          }
        }


      }
    }
  }

}

void l25_conv_relu(
  int8_t inp[1][512][6][6],
  int8_t weight[512][1][3][3],
  int8_t out[1][512][4][4]
) {	// L14182

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1

 int8_t S_b_co_ho_wo_0_reuse_2[3][6];  // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int coo = 0; coo < 8; coo++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12

          #pragma HLS pipeline II=1
          int8_t temp[64];

          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = inp[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    for (int coi = 0; coi < 64; coi++) {
                      int co = coo * 64 + coi;
                      int8_t v21 = weight[co][ci][r][c];      // L38
                      int16_t v22 = v20;  // L39
                      int16_t v23 = v21;  // L40
                      int16_t v24 = v22 * v23;    // L41
                      temp[coi] += v24;
                    }
                  }
                }
              }
              // int8_t v28 = v;   // L49
              // out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }

          if ((wo - 2) >= 0  && (ho - 2) >= 0) {        // L32
            for (int coi = 0; coi < 64; coi++) {
              int co = coo * 64 + coi;
              int8_t v = temp[coi]; // L25
              int8_t v19 = v;     // L26
              out[b][co][(ho - 2)][(wo - 2)] = v19;       // L27
            }
          }
        }
      }
    }
  }


}

void l18_relu_conv(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][4][4],
  int8_t weight[512][512][1][1]
) {	// L15418

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 8; coo++) {    // L5
      for (int ho = 0; ho < 4; ho++) {    // L6
        for (int wo = 0; wo < 4; wo++) {  // L7
          

          int8_t temp[64];
          for (int ci = 0; ci < 512; ci++) {   // L12
            #pragma HLS pipeline II=1
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15

                for (int coi = 0; coi < 64; coi++) {
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  int8_t v16 = v15;       // L20
                  temp[coi] += v16;
                }
              }
            }
          }
          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v19;       // L27
          }
        }
      }
    }
  }  

}

void l11_conv_relu(
  int8_t inp[1][128][8][8],
  int8_t weight[256][128][1][1],
  int8_t out[1][256][8][8]
) {	// L16526

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1

  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 8; coo++) {    // L5
      for (int ho = 0; ho < 8; ho++) {   // L6
        for (int wo = 0; wo < 8; wo++) { // L7
          int8_t temp[64];

          for (int ci = 0; ci < 128; ci++) {   // L12

            #pragma HLS pipeline II=1
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15
                for (int coi = 0; coi < 64; coi++) {
                  int co = coi + coo * 64;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;       // L20
                }
              }
            }
          }
          
          for (int coi = 0; coi < 64; coi++) {
            int co = coi + coo * 64;
            int8_t v19 = temp[coi];       // L27
            out[b][co][ho][wo] = v19;      // L28
          }
        }
      }
    }
  }

}

void l30_conv_relu(
  int8_t inp[1][512][6][6],
  int8_t weight[512][1][3][3],
  int8_t out[1][512][2][2]
) {	// L17634
  int8_t S_b_co_ho_wo_0_reuse_2[3][6];  // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12

          #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = inp[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho % 2) == 0 && (ho - 2) >= 0 && (((-ho) + ((ho / 2) * 2)) + 1) >= 0 && (ho % 2) >= 0) { // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo % 2) == 0 && (wo - 2) >= 0 && (((-wo) + ((wo / 2) * 2)) + 1) >= 0 && (wo % 2) >= 0) {       // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v > 0 ? v : 0;   // L49
              out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v28;  // L50
            }
          }
        }
      }
    }
  }

}

void l4_relu_pad(
  int8_t inp[1][64][32][32],
  int8_t out[1][64][34][34]
) {	// L18870

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 64; c++) { // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 33 && w >= 1 && w < 33) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v > 0 ? v : 0;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  }

}

void l23_relu_conv(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][4][4],
  int8_t weight[512][512][1][1]
) {	// L19334

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 8; coo++) {    // L5
      for (int ho = 0; ho < 4; ho++) {    // L6
        for (int wo = 0; wo < 4; wo++) {  // L7
          int8_t temp[64];
          for (int ci = 0; ci < 512; ci++) {   // L12
            #pragma HLS pipeline II=1

            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15

                for (int coi = 0; coi < 8; coi++) {
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
              }
            }
          }
          for (int coi = 0; coi < 8; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v19;       // L27
          }
        }
      }
    }
  }
}

void l16_conv_relu(
  int8_t inp[1][256][4][4],
  int8_t weight[512][256][1][1],
  int8_t out[1][512][4][4]
) {	// L20442

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 8; coo++) {    // L5
      for (int ho = 0; ho < 4; ho++) {    // L6
        for (int wo = 0; wo < 4; wo++) {  // L7
          int8_t temp[64];
          for (int ci = 0; ci < 256; ci++) {   // L12
            #pragma HLS pipeline II=1

            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15

                for (int coi = 0; coi < 64; coi++) {
                  int co = coo * 64 + coi; 
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
              }
            }
          }
          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v19;       // L27
          }
        }
      }
    }
  }

}

void l35_linear(
  int8_t inp[1][1024][1][1],
  int8_t out[1][10],
  int8_t weight[10][1024]
) {	// L21550

    // matrix multiply between inp and weight
    for (int b = 0; b < 1; b++) {     // L4
      for (int co = 0; co < 10; co++) {    // L5
        int8_t v;     // L10
        v = 0;        // L11
        for (int ci = 0; ci < 1024; ci++) {   // L12
        #pragma HLS pipeline II=1
          int8_t v11 = inp[b][ci][0][0];      // L13
          int8_t v12 = weight[co][ci];        // L14
          int16_t v13 = v11;      // L15
          int16_t v14 = v12;      // L16
          int16_t v15 = v13 * v14;        // L17
          int8_t v16 = v15;       // L18
          v += v16;       // L19
        }
        out[b][co] = v;     // L22
      }
    }

}

void l9_pad_relu(
  int8_t inp[1][128][16][16],
  int8_t out[1][128][18][18]
) {	// L22353
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 128; c++) {        // L5
      for (int h = 0; h < 18; h++) {       // L6
        for (int w = 0; w < 18; w++) {     // L7
        #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 17 && w >= 1 && w < 17) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v > 0 ? v : 0;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  }
}

void l28_conv_relu(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][4][4],
  int8_t weight[512][512][1][1]
) {	// L22823

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 8; coo++) {    // L5
      for (int ho = 0; ho < 4; ho++) {    // L6
        for (int wo = 0; wo < 4; wo++) {  // L7
          int8_t temp[64];
          for (int ci = 0; ci < 512; ci++) {   // L12
            #pragma HLS pipeline II=1
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15

                for (int coi = 0; coi < 64; coi++) { 
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
              }
            }
          }
          
          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v19;       // L27
          }
        }
      }
    }
  }
}

void l2_pad_conv(
  int8_t inp[1][32][32][32],
  int8_t out[1][32][32][32],
  int8_t weight[32][1][3][3]
) {	// L23931
  
  #pragma HLS dataflow
  int8_t padding[1][32][34][34];	// L23932
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 32; c++) { // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 33 && w >= 1 & w < 33) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[3][34]; // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 32; co++) {     // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12

          #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = padding[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v;   // L49
              out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }
        }
      }
    }
  }


}

void l21_conv_relu(
  int8_t inp[1][512][4][4],
  int8_t weight[512][512][1][1],
  int8_t out[1][512][4][4]
) {	// L25039

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1

  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 8; coo++) {    // L5
      for (int ho = 0; ho < 4; ho++) {    // L6
        for (int wo = 0; wo < 4; wo++) {  // L7
          
          int8_t temp[64];  // L8
          for (int ci = 0; ci < 512; ci++) {   // L12
            #pragma HLS pipeline II=1
            
                 // L15
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];
                for (int coi = 0; coi < 8; coi++) {
                  int co = coo * 64 + coi;
                  
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  int8_t v16 = v15;       // L20
                  temp[coi] += v16;
                }
              }
            }
          }

          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v19 = temp[coi];       // L27
            int8_t v20 = v19 > 0 ? v19 : 0;       // L39
            out[b][co][ho][wo] = v20;      // L28
          }


        }
      }
    }
  }

}

void l14_pad_relu(
  int8_t inp[1][256][8][8],
  int8_t out[1][256][10][10]
) {	// L26147
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7

          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 9 & w >= 1 & w < 9) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  }

}

void l33_relu_conv(
  int8_t inp[1][1024][2][2],
  int8_t out[1][1024][2][2],
  int8_t weight[1024][1024][1][1]
) {	// L26617

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 16; coo++) {   // L5
      for (int ho = 0; ho < 2; ho++) {    // L6
        for (int wo = 0; wo < 2; wo++) {  // L7
          int8_t temp[64];
          for (int ci = 0; ci < 1024; ci++) {  // L12

            #pragma HLS pipeline II=1
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15

                for (int coi = 0; coi < 64; coi++) {
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
              }
            }
          }
          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v19;       // L27
          }
        }
      }
    }
  }
}

void l7_pad_conv(
  int8_t inp[1][128][16][16],
  int8_t out[1][128][16][16],
  int8_t weight[128][1][3][3]
) {	// L27725

  #pragma HLS dataflow
  int8_t padding[1][128][18][18];	// L27726
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 128; c++) {        // L5
      for (int h = 0; h < 18; h++) {       // L6
        for (int w = 0; w < 18; w++) {     // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 17 && w >= 1 && w < 17) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[3][18]; // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 128; co++) {    // L10
      for (int ho = 0; ho < 18; ho++) {   // L11
        for (int wo = 0; wo < 18; wo++) { // L12

          #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = padding[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v;   // L49
              out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }
        }
      }
    }
  }
 

}

void l26_conv_relu(
  int8_t inp[1][512][4][4],
  int8_t weight[512][512][1][1],
  int8_t out[1][512][4][4]
) {	// L28903

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 8; coo++) {    // L5
      for (int ho = 0; ho < 4; ho++) {    // L6
        for (int wo = 0; wo < 4; wo++) {  // L7
          int8_t temp[64];

          for (int ci = 0; ci < 512; ci++) {   // L12
            #pragma HLS pipeline II=1

            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15
                for (int coi = 0; coi < 64; coi++) { 
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
              }
            }
          }
          
          for (int coi = 0; coi < 64; coi++) {
            #pragma HLS pipeline II=1
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v19;       // L27
          }
        }
      }
    }
  }


}

void l0_pad(
  int8_t inp[1][3][34][34],
  int8_t out[1][3][32][32]
) {	// L30011

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 3; c++) {  // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
        #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 33 &&  w >= 1 && w < 33) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  }
}

void l19_relu_pad(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][6][6]
) {	// L30312
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 6; h++) {        // L6
        for (int w = 0; w < 6; w++) {      // L7

          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 5 & w >= 1 & w < 5) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v > 0 ? v : 0;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  }
}

void l12_pad_conv(
  int8_t inp[1][256][8][8],
  int8_t out[1][256][8][8],
  int8_t weight[256][1][3][3]
) {	// L30782

  #pragma HLS dataflow
  int8_t padding[1][256][10][10];	// L30783
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 9 & w >= 1 & w < 9) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[3][10]; // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 256; co++) {    // L10
      for (int ho = 0; ho < 10; ho++) {   // L11
        for (int wo = 0; wo < 10; wo++) { // L12
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = padding[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v;   // L49
              out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }
        }
      }
    }
  }


}

void l31_conv_relu(
  int8_t inp[1][512][2][2],
  int8_t weight[1024][512][1][1],
  int8_t out[1][1024][2][2]
) {	// L31960
#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  for (int b = 0; b < 1; b++) {     // L4
    for (int coo = 0; coo < 16; coo++) {   // L5
      for (int ho = 0; ho < 2; ho++) {    // L6
        for (int wo = 0; wo < 2; wo++) {  // L7
          int8_t temp[64];
          for (int ci = 0; ci < 512; ci++) {   // L12

            #pragma HLS pipeline II=1
            for (int r = 0; r < 1; r++) {  // L13
              for (int c = 0; c < 1; c++) {        // L14
                int8_t v11 = inp[b][ci][(ho + r)][(wo + c)];     // L15

                for (int coi = 0; coi < 64; coi++) {
                  int co = coo * 64 + coi;
                  int8_t v12 = weight[co][ci][r][c];  // L16
                  int16_t v13 = v11;      // L17
                  int16_t v14 = v12;      // L18
                  int16_t v15 = v13 * v14;        // L19
                  temp[coi] += v15;
                }
              }
            }
          }
          // int8_t v19 = v > 0 ? v : 0;       // L27
          // out[b][co][ho][wo] = v19;      // L28
          for (int coi = 0; coi < 64; coi++) {
            int co = coo * 64 + coi;
            int8_t v = temp[coi]; // L25
            int8_t v19 = v > 0 ? v : 0;     // L26
            out[b][co][ho][wo] = v19;       // L27
          }
        }
      }
    }
  }
}

void l5_conv_relu(
  int8_t inp[1][64][34][34],
  int8_t weight[64][1][3][3],
  int8_t out[1][64][16][16]
) {	// L33068

#pragma HLS array_partition variable=weight cyclic factor=64 dim=1
  int8_t S_b_co_ho_wo_0_reuse_2[3][34]; // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int coo = 0; coo < 1; coo++) {     // L10
      for (int ho = 0; ho < 34; ho++) {   // L11
        for (int wo = 0; wo < 34; wo++) { // L12

          #pragma HLS pipeline II=1
          int8_t temp[64];

          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = inp[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho % 2) == 0 && (ho - 2) >= 0 && (((-ho) + ((ho / 2) * 2)) + 1) >= 0 && (ho % 2) >= 0) { // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo % 2) == 0 && (wo - 2) >= 0 && (((-wo) + ((wo / 2) * 2)) + 1) >= 0 && (wo % 2) >= 0) {       // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37

                    for (int coi = 0; coi < 64; coi++) {
                      int co = coo * 64 + coi;
                      int8_t v21 = weight[co][ci][r][c];      // L38
                      int16_t v22 = v20;  // L39
                      int16_t v23 = v21;  // L40
                      int16_t v24 = v22 * v23;    // L41
                      temp[coi] += v24;
                    }
                  }
                }
              }
              // int8_t v28 = v;   // L49
              // out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v28;  // L50
            }
          }

          if (ho > 1 && ho %2 ==0 && wo > 1 && wo %2 ==0) {
            for (int coi = 0; coi < 64; coi++) {
              int co = coo * 64 + coi;
              int8_t v = temp[coi]; // L25
              int8_t v19 = v > 0 ? v : 0;     // L26
              out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v19;  // L50
            }
          }
        }
      }
    }
  }

}

void l24_pad_relu(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][6][6]
) {	// L34300

   for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 6; h++) {        // L6
        for (int w = 0; w < 6; w++) {      // L7

          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 5 & w >= 1 & w < 5) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          out[b][c][h][w] = v12; // L40
        }
      }
    }
  } 

}

void l17_pad_conv(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][4][4],
  int8_t weight[512][1][3][3]
) {	// L34770

  #pragma HLS dataflow
  int8_t padding[1][512][6][6];	// L34771
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 6; h++) {        // L6
        for (int w = 0; w < 6; w++) {      // L7
          int8_t v;     // L10
          v = 0;        // L11

          if (h >= 1 & h < 5 & w >= 1 & w < 5) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  int8_t S_b_co_ho_wo_0_reuse_2[3][6];  // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[3][3];  // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 6; ho++) {    // L11
        for (int wo = 0; wo < 6; wo++) {  // L12

          #pragma HLS pipeline II=1
          int8_t v9 = S_b_co_ho_wo_0_reuse_2[1][wo];    // L13
          S_b_co_ho_wo_0_reuse_2[0][wo] = v9;   // L14
          int8_t v10 = S_b_co_ho_wo_0_reuse_2[2][wo];   // L15
          S_b_co_ho_wo_0_reuse_2[1][wo] = v10;  // L16
          int8_t v11 = padding[0][0][ho][wo];        // L18
          S_b_co_ho_wo_0_reuse_2[2][wo] = v11;  // L19
          if ((ho - 2) >= 0) {  // L20
            for (int v12 = 0; v12 < 3; v12++) { // L21
              int8_t v13 = S_b_co_ho_wo_0_reuse_3[v12][1];      // L22
              S_b_co_ho_wo_0_reuse_3[v12][0] = v13;     // L23
              int8_t v14 = S_b_co_ho_wo_0_reuse_3[v12][2];      // L24
              S_b_co_ho_wo_0_reuse_3[v12][1] = v14;     // L25
              int8_t v15 = S_b_co_ho_wo_0_reuse_2[v12][wo];     // L26
              S_b_co_ho_wo_0_reuse_3[v12][2] = v15;     // L27
            }
            if ((wo - 2) >= 0) {        // L29
              int8_t v; // L32
              v = 0;    // L33
              for (int ci = 0; ci < 1; ci++) { // L34
                for (int r = 0; r < 3; r++) {      // L35
                  for (int c = 0; c < 3; c++) {    // L36
                    int8_t v20 = S_b_co_ho_wo_0_reuse_3[r][c];  // L37
                    int8_t v21 = weight[co][ci][r][c];      // L38
                    int16_t v22 = v20;  // L39
                    int16_t v23 = v21;  // L40
                    int16_t v24 = v22 * v23;    // L41
                    int8_t v25 = v24;   // L42
                    int8_t v26 = v;     // L43
                    int8_t v27 = v26 + v25;     // L44
                    v = v27;    // L45
                  }
                }
              }
              int8_t v28 = v;   // L49
              out[b][co][(ho - 2)][(wo - 2)] = v28;      // L50
            }
          }
        }
      }
    }
  }  


}

/// This is top function.
void main_graph(
  int8_t l0_inp[1][3][32][32],
  int8_t l1_weight[32][3][3][3],
  int8_t l2_weight[32][1][3][3],
  int8_t l3_weight[64][32][1][1],
  int8_t l5_weight[64][1][3][3],
  int8_t l6_weight[128][64][1][1],
  int8_t l7_weight[128][1][3][3],
  int8_t l8_weight[128][128][1][1],
  int8_t l10_weight[128][1][3][3],
  int8_t l11_weight[256][128][1][1],
  int8_t l12_weight[256][1][3][3],
  int8_t l13_weight[256][256][1][1],
  int8_t l15_weight[256][1][3][3],
  int8_t l16_weight[512][256][1][1],
  int8_t l17_weight[512][1][3][3],
  int8_t l18_weight[512][512][1][1],
  int8_t l20_weight[512][1][3][3],
  int8_t l21_weight[512][512][1][1],
  int8_t l22_weight[512][1][3][3],
  int8_t l23_weight[512][512][1][1],
  int8_t l25_weight[512][1][3][3],
  int8_t l26_weight[512][512][1][1],
  int8_t l27_weight[512][1][3][3],
  int8_t l28_weight[512][512][1][1],
  int8_t l30_weight[512][1][3][3],
  int8_t l31_weight[1024][512][1][1],
  int8_t l32_weight[1024][1][3][3],
  int8_t l33_weight[1024][1024][1][1],
  int8_t l35_weight[10][1024],
  int8_t l35_out[1][10]
) {	// L35948
  #pragma HLS dataflow

  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=l0_inp
  #pragma HLS interface bram port=l1_weight
  #pragma HLS interface bram port=l2_weight
  #pragma HLS interface bram port=l3_weight
  #pragma HLS interface bram port=l5_weight
  #pragma HLS interface bram port=l6_weight
  #pragma HLS interface bram port=l7_weight
  #pragma HLS interface bram port=l8_weight
  #pragma HLS interface bram port=l10_weight
  #pragma HLS interface bram port=l11_weight
  #pragma HLS interface bram port=l12_weight
  #pragma HLS interface bram port=l13_weight
  #pragma HLS interface bram port=l15_weight
  #pragma HLS interface bram port=l16_weight
  #pragma HLS interface bram port=l17_weight
  #pragma HLS interface bram port=l18_weight
  #pragma HLS interface bram port=l20_weight
  #pragma HLS interface bram port=l21_weight
  #pragma HLS interface bram port=l22_weight
  #pragma HLS interface bram port=l23_weight
  #pragma HLS interface bram port=l25_weight
  #pragma HLS interface bram port=l26_weight
  #pragma HLS interface bram port=l27_weight
  #pragma HLS interface bram port=l28_weight
  #pragma HLS interface bram port=l30_weight
  #pragma HLS interface bram port=l31_weight
  #pragma HLS interface bram port=l32_weight
  #pragma HLS interface bram port=l33_weight
  #pragma HLS interface bram port=l35_weight


  // #pragma HLS array_partition variable=l35_out cyclic factor=10 dim=2

  int8_t l34_out[1][1024][1][1];	// L35954
  #pragma HLS STREAM variable=l34_out depth=12 type=fifo

  int8_t l33_out[1][1024][2][2];	// L35955
  #pragma HLS STREAM variable=l33_out depth=12 type=fifo

  int8_t l32_out[1][1024][2][2];	// L35956
  #pragma HLS STREAM variable=l32_out depth=12 type=fifo

  int8_t l31_out[1][1024][2][2];	// L35957
  #pragma HLS STREAM variable=l31_out depth=12 type=fifo

  int8_t l30_out[1][512][2][2];	// L35958
  #pragma HLS STREAM variable=l30_out depth=12 type=fifo

  int8_t l29_out[1][512][6][6];	// L35959
  #pragma HLS STREAM variable=l29_out depth=12 type=fifo

  int8_t l28_out[1][512][4][4];	// L35960
  #pragma HLS STREAM variable=l28_out depth=12 type=fifo

  int8_t l27_out[1][512][4][4];	// L35961
  #pragma HLS STREAM variable=l27_out depth=12 type=fifo

  int8_t l26_out[1][512][4][4];	// L35962
  #pragma HLS STREAM variable=l26_out depth=12 type=fifo

  int8_t l25_out[1][512][4][4];	// L35963
  #pragma HLS STREAM variable=l25_out depth=12 type=fifo

  int8_t l24_out[1][512][6][6];	// L35964
  #pragma HLS STREAM variable=l24_out depth=12 type=fifo

  int8_t l23_out[1][512][4][4];	// L35965
  #pragma HLS STREAM variable=l23_out depth=12 type=fifo

  int8_t l22_out[1][512][4][4];	// L35966
  #pragma HLS STREAM variable=l22_out depth=12 type=fifo

  int8_t l21_out[1][512][4][4];	// L35967
  #pragma HLS STREAM variable=l21_out depth=12 type=fifo

  int8_t l20_out[1][512][4][4];	// L35968
  #pragma HLS STREAM variable=l20_out depth=12 type=fifo

  int8_t l19_out[1][512][6][6];	// L35969
  #pragma HLS STREAM variable=l19_out depth=12 type=fifo

  int8_t l18_out[1][512][4][4];	// L35970
  #pragma HLS STREAM variable=l18_out depth=12 type=fifo

  int8_t l17_out[1][512][4][4];	// L35971
  #pragma HLS STREAM variable=l17_out depth=12 type=fifo

  int8_t l16_out[1][512][4][4];	// L35972
  #pragma HLS STREAM variable=l16_out depth=12 type=fifo

  int8_t l15_out[1][256][4][4];	// L35973
  #pragma HLS STREAM variable=l15_out depth=12 type=fifo

  int8_t l14_out[1][256][10][10];	// L35974
  #pragma HLS STREAM variable=l14_out depth=12 type=fifo

  int8_t l13_out[1][256][8][8];	// L35975
  #pragma HLS STREAM variable=l13_out depth=12 type=fifo

  int8_t l12_out[1][256][8][8];	// L35976
  #pragma HLS STREAM variable=l12_out depth=12 type=fifo

  int8_t l11_out[1][256][8][8];	// L35977
  #pragma HLS STREAM variable=l11_out depth=12 type=fifo

  int8_t l10_out[1][128][8][8];	// L35978
  #pragma HLS STREAM variable=l10_out depth=12 type=fifo

  int8_t l9_out[1][128][18][18];	// L35979
  #pragma HLS STREAM variable=l9_out depth=12 type=fifo

  int8_t l8_out[1][128][16][16];	// L35980
  #pragma HLS STREAM variable=l8_out depth=12 type=fifo

  int8_t l7_out[1][128][16][16];	// L35981
  #pragma HLS STREAM variable=l7_out depth=12 type=fifo

  int8_t l6_out[1][128][16][16];	// L35982
  #pragma HLS STREAM variable=l6_out depth=12 type=fifo

  int8_t l5_out[1][64][16][16];	// L35983
  #pragma HLS STREAM variable=l5_out depth=12 type=fifo

  int8_t l4_out[1][64][34][34];	// L35984
  #pragma HLS STREAM variable=l4_out depth=12 type=fifo

  int8_t l3_out[1][64][32][32];	// L35985
  #pragma HLS STREAM variable=l3_out depth=12 type=fifo

  int8_t l2_out[1][32][32][32];	// L35986
  #pragma HLS STREAM variable=l2_out depth=12 type=fifo

  int8_t l1_out[1][32][32][32];	// L35987
  #pragma HLS STREAM variable=l1_out depth=12 type=fifo

  int8_t l0_out[1][3][34][34];	// L35988
  #pragma HLS STREAM variable=l0_out depth=12 type=fifo

  l0_pad(l0_out, l0_inp);	// L35989
  l1_conv_relu(l0_out, l1_weight, l1_out);	// L35990
  
  l2_pad_conv(l1_out, l2_out, l2_weight);	// L35991
  l3_relu_conv(l2_out, l3_out, l3_weight);	// L35992

  l4_relu_pad(l3_out, l4_out);	// L35993
  l5_conv_relu(l4_out, l5_weight, l5_out);	// L35994

  l6_conv_relu(l5_out, l6_weight, l6_out);	// L35995
  l7_pad_conv(l6_out, l7_out, l7_weight);	// L35996

  l8_relu_conv(l7_out, l8_out, l8_weight);	// L35997
  l9_pad_relu(l8_out, l9_out);	// L35998

  l10_conv_relu(l9_out, l10_weight, l10_out);	// L35999
  l11_conv_relu(l10_out, l11_weight, l11_out);	// L36000

  l12_pad_conv(l11_out, l12_out, l12_weight);	// L36001
  l13_relu_conv(l12_out, l13_out, l13_weight);	// L36002

  l14_pad_relu(l13_out, l14_out);	// L36003
  l15_conv_relu(l14_out, l15_weight, l15_out);	// L36004

  l16_conv_relu(l15_out, l16_weight, l16_out);	// L36005
  l17_pad_conv(l16_out, l17_out, l17_weight);	// L36006

  l18_relu_conv(l17_out, l18_out, l18_weight);	// L36007
  l19_relu_pad(l18_out, l19_out);	// L36008

  l20_conv_relu(l19_out, l20_weight, l20_out);	// L36009
  l21_conv_relu(l20_out, l21_weight, l21_out);	// L36010

  l22_pad_conv(l21_out, l22_out, l22_weight);	// L36011
  l23_relu_conv(l22_out, l23_out, l23_weight);	// L36012

  l24_pad_relu(l23_out, l24_out);	// L36013
  l25_conv_relu(l24_out, l25_weight, l25_out);	// L36014
  
  l26_conv_relu(l25_out, l26_weight, l26_out);	// L36015
  l27_pad_conv(l26_out, l27_out, l27_weight);	// L36016

  l28_conv_relu(l27_out, l28_out, l28_weight);	// L36017
  l29_relu_pad(l28_out, l29_out);	// L36018

  l30_conv_relu(l29_out, l30_weight, l30_out);	// L36019
  l31_conv_relu(l30_out, l31_weight, l31_out);	// L36020

  l32_pad_conv(l31_out, l32_out, l32_weight);	// L36021
  l33_relu_conv(l32_out, l33_out, l33_weight);	// L36022

  l34_avgpool(l33_out, l34_out);	// L36023
  l35_linear(l34_out, l35_out, l35_weight);	// L36025
}