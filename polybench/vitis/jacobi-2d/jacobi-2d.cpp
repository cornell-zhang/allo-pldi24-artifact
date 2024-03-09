#   define TSTEPS 100
#   define N 250

void kernel(
	float A[N][N],
	float B[N][N])
{
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
  int t, i, j;

  for (t = 0; t < TSTEPS; t++)
    {
      for (i = 1; i < N - 1; i++)
	for (j = 1; j < N - 1; j++)
	  B[i][j] = 0.2 * (A[i][j] + A[i][j-1] + A[i][1+j] + A[1+i][j] + A[i-1][j]);
      for (i = 1; i < N - 1; i++)
	for (j = 1; j < N - 1; j++)
	  A[i][j] = 0.2 * (B[i][j] + B[i][j-1] + B[i][1+j] + B[1+i][j] + B[i-1][j]);
    }
}