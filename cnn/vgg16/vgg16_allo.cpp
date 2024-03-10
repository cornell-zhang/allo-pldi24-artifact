
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

void l14_conv_relu(
  int8_t inp[1][512][6][6],
  int8_t weight[512][512][3][3],
  int8_t out[1][512][2][2]
) {	// L13

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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v30;  // L53
                temp += v30;
              }
            }
          }
          if (ho > 1 && wo > 1 && ho % 2 == 0 && wo % 2 == 0) {
            out[b][co][(ho / 2) - 1][(wo / 2) - 1] = temp;
          }

        } 
      }
    }
  }

}

void l7_relu_pad(
  int8_t inp[1][256][8][8],
  int8_t out[1][256][10][10]
) {	// L1125

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 9 && w >= 1 && w < 9) { // L35
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

void l0_pad_conv(
  int8_t inp[1][3][32][32],
  int8_t out[1][64][32][32],
  int8_t weight[64][3][3][3]
) {	// L1595

  #pragma HLS dataflow
  int8_t padding[1][3][34][34];	// L1596
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 3; c++) {  // L5
      for (int h = 0; h < 34; h++) {       // L6
        for (int w = 0; w < 34; w++) {     // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 33 && w >= 1 && w < 33) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }

  // conv
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
            int8_t v12 = padding[b][v9][ho][wo];     // L18
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
              int8_t v = 0;
              l_S_ci_r_c_0_ci: for (int ci = 0; ci < 3; ci++) { // L33
                l_r: for (int r = 0; r < 3; r++) {      // L34
                  for (int c = 0; c < 3; c++) {    // L35
                    int8_t v21 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L36
                    int8_t v22 = weight[co][ci][r][c];      // L37
                    int16_t v23 = v21;  // L38
                    int16_t v24 = v22;  // L39
                    int16_t v25 = v23 * v24;    // L40
                    int8_t v26 = v;     // L41
                    int8_t v27 = v25;   // L42
                    int8_t v28 = v26 + v27;     // L43
                    out[b][co][(ho - 2)][(wo - 2)] = v28;        // L44
                  }
                }
              }
            }
          }
        }
      }
    }
  }

}

void l19_relu(
  int8_t v1611[1][512][1][1],
  int8_t v1613[1][512][1][1]
) {	// L2741

  l_S_b_c_0_b: for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {    // L5
      #pragma HLS pipeline II=1
      int8_t v1612 = v1611[b][c][0][0];     // L6
      int8_t v1614 = v1612; // L7
      int8_t v1615 = 0;     // L8
      bool v1616 = v1614 < v1615;  // L9, S[10,10)
      int8_t v1617 = v1616 ? v1615 : v1614;    // L10
      v1613[b][c][0][0] = v1617;      // L11
    }
  }

}

void l12_pad_conv(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][4][4],
  int8_t weight[512][512][3][3]
) {	// L3713

  #pragma HLS dataflow
  int8_t padding[1][512][6][6];	// L3714
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
              for (int v13 = 0; v13 < 512; v13++) {       // L22
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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 512; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
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

void l5_conv_relu(
  int8_t inp[1][128][18][18],
  int8_t weight[128][128][3][3],
  int8_t out[1][128][8][8]
) {	// L4767
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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v30;  // L53
                temp += v30;
              }
            }
          }
          if (ho >= 2 && wo >= 2 && ho % 2 == 0 && wo % 2 == 0) {
            out[b][co][ho/2 - 1][wo/2 - 1] = temp;
          }

        }
      }
    }
  }
}

void l17_conv_relu(
  int8_t inp[1][512][4][4],
  int8_t weight[512][512][3][3],
  int8_t out[1][512][2][2]
) {	// L5879

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][4];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 4; ho++) {    // L11
        for (int wo = 0; wo < 4; wo++) {  // L12

          int8_t temp = 0;
          for (int v9o = 0; v9o < 64; v9o++) {
            #pragma HLS pipeline II=1 

            for (int v9 = 0; v9 < 8; v9++) {    // L13
              int8_t v10 = S_b_co_ho_wo_0_reuse_2[v9][1][wo];     // L14
              S_b_co_ho_wo_0_reuse_2[v9][0][wo] = v10;    // L15
              int8_t v11 = S_b_co_ho_wo_0_reuse_2[v9][2][wo];     // L16
              S_b_co_ho_wo_0_reuse_2[v9][1][wo] = v11;    // L17
              int8_t v12 = inp[b][v9][ho][wo];     // L18
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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
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

void l10_relu_pad(
  int8_t inp[1][256][4][4],
  int8_t out[1][256][6][6]
) {	// L6991

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
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

void l3_pad_conv(
  int8_t inp[1][64][16][16],
  int8_t out[1][128][16][16],
  int8_t weight[128][64][3][3]
) {	// L7461

  #pragma HLS dataflow
  int8_t padding[1][64][18][18];	// L7462
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 64; c++) { // L5
      for (int h = 0; h < 18; h++) {       // L6
        for (int w = 0; w < 18; w++) {     // L7
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

  
  int8_t S_b_co_ho_wo_0_reuse_2[8][3][18];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];      // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 128; co++) {    // L10
      for (int ho = 0; ho < 18; ho++) {   // L11
        for (int wo = 0; wo < 18; wo++) { // L12

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
                int8_t v = 0;
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {        // L33
                  l_r: for (int r = 0; r < 3; r++) {      // L34
                    for (int c = 0; c < 3; c++) {    // L35
                      int8_t v21 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L36
                      int8_t v22 = weight[co][ci][r][c];      // L37
                      int16_t v23 = v21;  // L38
                      int16_t v24 = v22;  // L39
                      int16_t v25 = v23 * v24;    // L40
                      int8_t v26 = v;     // L41
                      int8_t v27 = v25;   // L42
                      int8_t v28 = v26 + v27;     // L43
                      // v2 = v28;        // L44
                      temp += v28;
                    }
                  }
                }
              }
            }
          }
          if (ho > 2 && wo > 2) {
              out[b][co][(ho - 2)][(wo - 2)] = temp;
          }

        }
      }
    }
  }
}

void l15_pad_conv(
  int8_t inp[1][512][2][2],
  int8_t out[1][512][2][2],
  int8_t weight[512][512][3][3]
) {	// L8511

  #pragma HLS dataflow
  int8_t padding[1][512][4][4];	// L8512
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 4; h++) {        // L6
        for (int w = 0; w < 4; w++) {      // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 3 && w >= 1 && w < 3) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }  

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][4];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 4; ho++) {    // L11
        for (int wo = 0; wo < 4; wo++) {  // L12

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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
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

void l8_conv_relu(
  int8_t inp[1][256][10][10],
  int8_t weight[256][256][3][3],
  int8_t out[1][256][8][8]
) {	// L9565

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
              int8_t v12 = inp[b][v9][ho][wo];     // L18
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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }
          if ((ho - 2) >= 0 && (wo - 2) >= 0) {      // L57
            out[b][co][(ho - 2)][(wo - 2)] = temp;
          }

        }
      }
    }
  }

}

void l1_relu_pad(
  int8_t inp[1][64][32][32],
  int8_t out[1][64][34][34]
) {	// L10677

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

void l20_linear(
  int8_t inp[1][512][1][1],
  int8_t out[1][10],
  int8_t weight[10][512]
) {	// L11141

  // linear kernel: matrix multiply
  for (int b = 0; b < 1; b++) {
    for (int co = 0; co < 10; co++) {
      int8_t temp = 0;
      for (int ci = 0; ci < 512; ci++) {
        #pragma HLS pipeline II=1
        int8_t v1 = inp[b][ci][0][0];
        int8_t v2 = weight[co][ci];
        int16_t v3 = v1;
        int16_t v4 = v2;
        int16_t v5 = v3 * v4;
        int8_t v6 = v5;
        int8_t v7 = temp;
        int8_t v8 = v6;
        int8_t v9 = v7 + v8;
        temp = v9;
      }
      out[b][co] = temp;
    }
  }



}

void l13_relu_pad(
  int8_t inp[1][512][4][4],
  int8_t out[1][512][6][6]
) {	// L11944
  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 6; h++) {        // L6
        for (int w = 0; w < 6; w++) {      // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 5 && w >= 1 & w < 5) { // L35
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

void l6_pad_conv(
  int8_t inp[1][128][8][8],
  int8_t out[1][256][8][8],
  int8_t weight[256][128][3][3]
) {	// L12414
  
  #pragma HLS dataflow
  int8_t padding[1][128][10][10];	// L12415
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 128; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 9 && w >= 1 & w < 9) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
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

void l18_pad_conv(
  int8_t inp[1][512][2][2],
  int8_t out[1][512][1][1],
  int8_t weight[512][512][3][3]
) {	// L13468

  #pragma HLS dataflow
  int8_t padding[1][512][4][4];	// L13469
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 4; h++) {        // L6
        for (int w = 0; w < 4; w++) {      // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 & h < 3 && w >= 1 & w < 3) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
            v = v11;    // L37
          }
          int8_t v12 = v;       // L39
          padding[b][c][h][w] = v12; // L40
        }
      }
    }
  }  

  int8_t S_b_co_ho_wo_0_reuse_2[8][3][4];     // L7
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_2 complete dim=1

  int8_t S_b_co_ho_wo_0_reuse_3[8][3][3];     // L8
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=1
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=2
  #pragma HLS array_partition variable=S_b_co_ho_wo_0_reuse_3 complete dim=3

  for (int b = 0; b < 1; b++) {     // L9
    for (int co = 0; co < 512; co++) {    // L10
      for (int ho = 0; ho < 4; ho++) {    // L11
        for (int wo = 0; wo < 4; wo++) {  // L12

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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
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

void l11_conv_relu(
  int8_t inp[1][256][6][6],
  int8_t weight[512][256][3][3],
  int8_t out[1][512][4][4]
) {	// L14518

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
              int8_t v12 = inp[b][v9][ho][wo];     // L18
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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][(ho - 2)][(wo - 2)] = v30;      // L53
                temp += v30;
              }
            }
          }
          if ((ho - 2) >= 0 && (wo - 2) >= 0) {    // L57
            out[b][co][(ho - 2)][(wo - 2)] = temp;   // L62
          }

        }
      }
    }
  }
}

void l4_relu_pad(
  int8_t inp[1][128][16][16],
  int8_t out[1][128][18][18]
) {	// L15630

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

void l16_relu_pad(
  int8_t inp[1][512][2][2],
  int8_t out[1][512][4][4]
) {	// L16100

 for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 512; c++) {        // L5
      for (int h = 0; h < 4; h++) {        // L6
        for (int w = 0; w < 4; w++) {      // L7
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 3 && w >= 1 && w < 3) { // L35
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

void l9_pad_conv(
  int8_t inp[1][256][8][8],
  int8_t out[1][256][4][4],
  int8_t weight[256][256][3][3]
) {	// L16570

  #pragma HLS dataflow
  int8_t padding[1][256][10][10];	// L16571
  #pragma HLS STREAM variable=padding depth=12 type=fifo

  for (int b = 0; b < 1; b++) {        // L4
    for (int c = 0; c < 256; c++) {        // L5
      for (int h = 0; h < 10; h++) {       // L6
        for (int w = 0; w < 10; w++) {     // L7
          #pragma HLS pipeline II=1
          int8_t v;     // L10
          v = 0;        // L11
          if (h >= 1 && h < 9 && w >= 1 && w < 9) { // L35
            int8_t v11 = inp[b][c][(h - 1)][(w - 1)];    // L36
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
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {       // L37
                  l_r: for (int r = 0; r < 3; r++) {      // L38
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
                // v2[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = v30;  // L53
                temp += v30;
              }
            }
          }
          if (ho >= 2 && wo >= 2 && ho % 2 == 0 && wo % 2 == 0) {
            out[b][co][(ho/2)-1][(wo/2)-1] = temp;
          }
        }
      }
    }
  }


}

void l2_conv_relu(
  int8_t inp[1][64][34][34],
  int8_t weight[64][64][3][3],
  int8_t out[1][64][16][16]
) {	// L17624

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

                int8_t v = 0;
                l_S_ci_r_c_0_ci: for (int ci = 0; ci < 8; ci++) {        // L33
                  l_r: for (int r = 0; r < 3; r++) {      // L34
                    for (int c = 0; c < 3; c++) {    // L35
                      int8_t v21 = S_b_co_ho_wo_0_reuse_3[ci][r][c];      // L36
                      int8_t v22 = weight[co][ci][r][c];      // L37
                      int16_t v23 = v21;  // L38
                      int16_t v24 = v22;  // L39
                      int16_t v25 = v23 * v24;    // L40
                      int8_t v26 = v;     // L41
                      int8_t v27 = v25;   // L42
                      int8_t v28 = v26 + v27;     // L43
                      int8_t v29 = v28 > 0 ? v28 : 0;     // L44
                      temp += v29;      // L45
                    }
                  }
                }
              }
            }
          }

          if (wo > 1 && ho > 1 && wo % 2 == 0 && ho % 2 == 0) {
              out[b][co][((ho / 2) - 1)][((wo / 2) - 1)] = temp;
          }
        }
      }
    }
  }

}

/// This is top function.
void main_graph(
  int8_t ori_inp[1][3][32][32],
  int8_t l0_weight[64][3][3][3],
  int8_t l2_weight[64][64][3][3],
  int8_t l3_weight[128][64][3][3],
  int8_t l5_weight[128][128][3][3],
  int8_t l6_weight[256][128][3][3],
  int8_t l8_weight[256][256][3][3],
  int8_t l9_weight[256][256][3][3],
  int8_t l11_weight[512][256][3][3],
  int8_t l12_weight[512][512][3][3],
  int8_t l14_weight[512][512][3][3],
  int8_t l15_weight[512][512][3][3],
  int8_t l17_weight[512][512][3][3],
  int8_t l18_weight[512][512][3][3],
  int8_t l20_weight[10][512],
  int8_t l20_out[1][10]
) {	// L18732
  #pragma HLS dataflow

  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma HLS interface bram port=ori_inp
  #pragma HLS interface bram port=l0_weight
  #pragma HLS interface bram port=l2_weight
  #pragma HLS interface bram port=l3_weight
  #pragma HLS interface bram port=l5_weight
  #pragma HLS interface bram port=l6_weight
  #pragma HLS interface bram port=l8_weight
  #pragma HLS interface bram port=l9_weight
  #pragma HLS interface bram port=l11_weight
  #pragma HLS interface bram port=l12_weight
  #pragma HLS interface bram port=l14_weight
  #pragma HLS interface bram port=l15_weight
  #pragma HLS interface bram port=l17_weight
  #pragma HLS interface bram port=l18_weight
  #pragma HLS interface bram port=l20_weight

  // #pragma HLS array_partition variable=ori_inp cyclic factor=3 dim=2
  // #pragma HLS array_partition variable=ori_inp cyclic factor=32 dim=3

  // #pragma HLS array_partition variable=l0_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l0_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l2_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l2_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l3_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l3_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l5_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l5_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l6_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l6_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l8_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l8_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l9_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l9_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l11_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l11_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l12_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l12_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l14_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l14_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l15_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l15_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l17_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l17_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l18_weight cyclic factor=64 dim=1
  // #pragma HLS resource variable=l18_weight core=ram_s2p_bram

  // //#pragma HLS array_partition variable=l20_weight cyclic factor=10 dim=1
  // //#pragma HLS array_partition variable=l20_weight cyclic factor=8 dim=2
  // #pragma HLS resource variable=l20_weight core=ram_s2p_bram

  //#pragma HLS array_partition variable=l20_out cyclic factor=10 dim=2

  int8_t l19_out[1][512][1][1];	// L18737
  #pragma HLS STREAM variable=l19_out depth=12 type=fifo

  int8_t l18_out[1][512][1][1];	// L18738
  #pragma HLS STREAM variable=l18_out depth=12 type=fifo

  int8_t l17_out[1][512][2][2];	// L18739
  #pragma HLS STREAM variable=l17_out depth=12 type=fifo

  int8_t l16_out[1][512][4][4];	// L18740
  #pragma HLS STREAM variable=l16_out depth=12 type=fifo

  int8_t l15_out[1][512][2][2];	// L18741
  #pragma HLS STREAM variable=l15_out depth=12 type=fifo

  int8_t l14_out[1][512][2][2];	// L18742
  #pragma HLS STREAM variable=l14_out depth=12 type=fifo

  int8_t l13_out[1][512][6][6];	// L18743
  #pragma HLS STREAM variable=l13_out depth=12 type=fifo

  int8_t l12_out[1][512][4][4];	// L18744
  #pragma HLS STREAM variable=l12_out depth=12 type=fifo

  int8_t l11_out[1][512][4][4];	// L18745
  #pragma HLS STREAM variable=l11_out depth=12 type=fifo

  int8_t l10_out[1][256][6][6];	// L18746
  #pragma HLS STREAM variable=l10_out depth=12 type=fifo

  int8_t l9_out[1][256][4][4];	// L18747
  #pragma HLS STREAM variable=l9_out depth=12 type=fifo

  int8_t l8_out[1][256][8][8];	// L18748
  #pragma HLS STREAM variable=l8_out depth=12 type=fifo

  int8_t l7_out[1][256][10][10];	// L18749
  #pragma HLS STREAM variable=l7_out depth=12 type=fifo

  int8_t l6_out[1][256][8][8];	// L18750
  #pragma HLS STREAM variable=l6_out depth=12 type=fifo

  int8_t l5_out[1][128][8][8];	// L18751
  #pragma HLS STREAM variable=l5_out depth=12 type=fifo

  int8_t l4_out[1][128][18][18];	// L18752
  #pragma HLS STREAM variable=l4_out depth=12 type=fifo

  int8_t l3_out[1][128][16][16];	// L18753
  #pragma HLS STREAM variable=l3_out depth=12 type=fifo

  int8_t l2_out[1][64][16][16];	// L18754
  #pragma HLS STREAM variable=l2_out depth=12 type=fifo

  int8_t l1_out[1][64][34][34];	// L18755
  #pragma HLS STREAM variable=l1_out depth=12 type=fifo

  int8_t l0_out[1][64][32][32];	// L18756
  #pragma HLS STREAM variable=l0_out depth=12 type=fifo

  l0_pad_conv(ori_inp, l0_out, l0_weight);	// L18757
  l1_relu_pad(l0_out, l1_out);	// L18758

  l2_conv_relu(l1_out, l2_weight, l2_out);	// L18759
  l3_pad_conv(l2_out, l3_out, l3_weight);	// L18760

  l4_relu_pad(l3_out, l4_out);	// L18761
  l5_conv_relu(l4_out, l5_weight, l5_out);	// L18762

  l6_pad_conv(l5_out, l6_out, l6_weight);	// L18763
  l7_relu_pad(l6_out, l7_out);	// L18764

  l8_conv_relu(l7_out, l8_weight, l8_out);	// L18765
  l9_pad_conv(l8_out, l9_out, l9_weight);	// L18766

  l10_relu_pad(l9_out, l10_out);	// L18767
  l11_conv_relu(l10_out, l11_weight, l11_out);	// L18768

  l12_pad_conv(l11_out, l12_out, l12_weight);	// L18769
  l13_relu_pad(l12_out, l13_out);	// L18770

  l14_conv_relu(l13_out, l14_weight, l14_out);	// L18771
  l15_pad_conv(l14_out, l15_out, l15_weight);	// L18772

  l16_relu_pad(l15_out, l16_out);	// L18773
  l17_conv_relu(l16_out, l17_weight, l17_out);	// L18774

  l18_pad_conv(l17_out, l18_out, l18_weight);	// L18775
  l19_relu(l18_out, l19_out);	// L18776

  l20_linear(l19_out, l20_out, l20_weight);	// L18778
}

