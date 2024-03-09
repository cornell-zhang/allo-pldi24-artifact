#   define M 390
#   define N 410

void kernel(
		float A[M][N],
		float x[N],
		float y[N],
		float tmp[M])
{
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=x offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=x bundle=control
    #pragma HLS INTERFACE m_axi port=y offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=y bundle=control
    #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=tmp bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
  int i, j;

  for (i = 0; i < N; i++)
    y[i] = 0;
  for (i = 0; i < M; i++)
    {
      tmp[i] = 0.0;
      for (j = 0; j < N; j++)
	tmp[i] = tmp[i] + A[i][j] * x[j];
      for (j = 0; j < N; j++)
	y[j] = y[j] + A[i][j] * tmp[i];
    }
}