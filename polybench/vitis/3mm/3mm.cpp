#   define NI 180
#   define NJ 190
#   define NK 200
#   define NL 210
#   define NM 220

void kernel(
		float E[NI][NJ],
		float A[NI][NK],
		float B[NK][NJ],
		float F[NJ][NL],
		float C[NJ][NM],
		float D[NM][NL],
		float G[NI][NL])
{
    #pragma HLS INTERFACE m_axi port=E offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=E bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE m_axi port=F offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=F bundle=control
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE m_axi port=D offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=D bundle=control
    #pragma HLS INTERFACE m_axi port=G offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=G bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
  int i, j, k;

  /* E := A*B */
  for (i = 0; i < NI; i++)
    for (j = 0; j < NJ; j++)
      {
	E[i][j] = 0.0;
	for (k = 0; k < NK; ++k)
	  E[i][j] += A[i][k] * B[k][j];
      }
  /* F := C*D */
  for (i = 0; i < NJ; i++)
    for (j = 0; j < NL; j++)
      {
	F[i][j] = 0.0;
	for (k = 0; k < NM; ++k)
	  F[i][j] += C[i][k] * D[k][j];
      }
  /* G := E*F */
  for (i = 0; i < NI; i++)
    for (j = 0; j < NL; j++)
      {
	G[i][j] = 0.0;
	for (k = 0; k < NJ; ++k)
	  G[i][j] += E[i][k] * F[k][j];
      }

}