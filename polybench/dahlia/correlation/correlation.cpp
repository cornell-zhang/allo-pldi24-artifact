#include <ap_int.h>
extern "C" {
  void kernel(float float_n, float data[260][240], float mean[240], float stddev[240], float corr[240][240]) {
    #pragma HLS INTERFACE s_axilite port=float_n bundle=control
    #pragma HLS INTERFACE m_axi port=data offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=data bundle=control
    #pragma HLS INTERFACE m_axi port=mean offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=mean bundle=control
    #pragma HLS INTERFACE m_axi port=stddev offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=stddev bundle=control
    #pragma HLS INTERFACE m_axi port=corr offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=corr bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
    for(int j = 0; j < 240; j++) {
      #pragma HLS LOOP_FLATTEN off
      mean[j] = 0.0;
      //---
      for(int i = 0; i < 260; i++) {
        #pragma HLS LOOP_FLATTEN off
        float sum = data[i][j];
        // combiner:
        mean[j] += (sum / float_n);
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
        stddev[j] += (variance / float_n);
      }
      //---
      float s = stddev[j];
      //---
      stddev[j] = s;
    }
    //---
    for(int i = 0; i < 260; i++) {
      #pragma HLS LOOP_FLATTEN off
      for(int j = 0; j < 240; j++) {
        #pragma HLS LOOP_FLATTEN off
        float sub = (data[i][j] - mean[j]);
        //---
        data[i][j] = sub;
        //---
        float div = ((data[i][j] / float_n) * stddev[j]);
        //---
        data[i][j] = div;
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
            float ki = data[k][i];
            //---
            float kj = data[k][j];
            //---
            float add = (corr[i][j] + (ki * kj));
            //---
            corr[i][j] = add;
          }
          //---
          float ij = corr[i][j];
          //---
          corr[j][i] = ij;
        }
      }
    }
    //---
    corr[239][239] = 1.0;
  }
}