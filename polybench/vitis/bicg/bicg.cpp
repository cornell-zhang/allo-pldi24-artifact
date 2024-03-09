#   define M 390
#   define N 410

void kernel(
	float A[N][M],
	float s[M],
	float q[N],
	float p[M],
	float r[N])
{
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=p offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=p bundle=control
    #pragma HLS INTERFACE m_axi port=r offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=r bundle=control
    #pragma HLS INTERFACE m_axi port=q offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=q bundle=control
    #pragma HLS INTERFACE m_axi port=s offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=s bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
  int i, j;

  for (i = 0; i < M; i++)
    s[i] = 0;
  for (i = 0; i < N; i++)
    {
      q[i] = 0.0;
      for (j = 0; j < M; j++)
	{
	  s[j] = s[j] + r[i] * A[i][j];
	  q[i] = q[i] + A[i][j] * p[j];
	}
    }
}