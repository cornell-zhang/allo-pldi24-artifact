#include <ap_int.h>
#include <math.h>
extern "C" {
  void kernel() {
    
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    float data[260][240];
    #pragma HLS resource variable=data core=RAM_T2P_BRAM
    float mean[240];
    #pragma HLS resource variable=mean core=RAM_T2P_BRAM
    float stddev[240];
    #pragma HLS resource variable=stddev core=RAM_T2P_BRAM
    float cov[240][240];
    #pragma HLS resource variable=cov core=RAM_1P_BRAM
    float corr[240][240];
    #pragma HLS resource variable=corr core=RAM_T2P_BRAM
    for(int j = 0; j < 240; j++) {
      #pragma HLS LOOP_FLATTEN off
      mean[j] = 0.0;
      //---
      for(int i = 0; i < 260; i++) {
        #pragma HLS LOOP_FLATTEN off
        float total = data[i][j];
        // combiner:
        mean[j] += (total / 260.0);
      }
    }
    //---
    for(int j = 0; j < 240; j++) {
      #pragma HLS LOOP_FLATTEN off
      stddev[j] = 0.0;
      //---
      for(int i = 0; i < 260; i++) {
        #pragma HLS LOOP_FLATTEN off
        float variance = ((data[i][j] - mean[j]) * (data[i][j] - mean[j]));
        // combiner:
        stddev[j] += sqrt(variance / 260.0);
      }
    }
    //---
    for(int i = 0; i < 260; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        data[i][j] = (data[i][j] - mean[j]);
        //---
        data[i][j] = (data[i][j] / (sqrt(260.0) * stddev[j]));
      }
    }
    //---
    for(int i = 0; i < 239; i++) {
      #pragma HLS LOOP_FLATTEN off
      corr[i][i] = 1.0;
      //---
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        if ((j >= (i + 1))) {
          corr[i][j] = 0.0;
          //---
          for(int k = 0; k < 260; k++) {
            #pragma HLS LOOP_FLATTEN off
            corr[i][j] = (corr[i][j] + (data[k][i] * data[k][j]));
          }
          //---
          corr[j][i] = corr[i][j];
        }
      }
    }
    //---
    corr[239][239] = 1.0;
  }
}