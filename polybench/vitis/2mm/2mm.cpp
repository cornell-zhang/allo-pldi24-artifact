#define NI 180
#define NJ 190
#define NK 210
#define NL 220

void kernel(
		float alpha,
		float beta,
		float tmp[NI][NJ],
		float A[NI][NK],
		float B[NK][NJ],
		float C[NJ][NL],
		float D[NI][NL])
{
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE s_axilite port=beta bundle=control
    #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=tmp bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE m_axi port=D offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=D bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
  int i, j, k;

  /* D := alpha*A*B*C + beta*D */
  for (i = 0; i < NI; i++)
    for (j = 0; j < NJ; j++)
      {
	tmp[i][j] = 0.0;
	for (k = 0; k < NK; ++k)
	  tmp[i][j] += alpha * A[i][k] * B[k][j];
      }
  for (i = 0; i < NI; i++)
    for (j = 0; j < NL; j++)
      {
	D[i][j] *= beta;
	for (k = 0; k < NJ; ++k)
	  D[i][j] += tmp[i][k] * C[k][j];
      }
}