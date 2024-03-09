#   define N 250

void kernel(int n,
	float alpha,
	float beta,
	float A[N][N],
	float B[N][N],
	float tmp[N],
	float x[N],
	float y[N])
{
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE s_axilite port=beta bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE m_axi port=tmp offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=tmp bundle=control
    #pragma HLS INTERFACE m_axi port=x offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=x bundle=control
    #pragma HLS INTERFACE m_axi port=y offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=y bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
  int i, j;

  for (i = 0; i < N; i++)
    {
      tmp[i] = 0.0;
      y[i] = 0.0;
      for (j = 0; j < N; j++)
	{
	  tmp[i] = A[i][j] * x[j] + tmp[i];
	  y[i] = B[i][j] * x[j] + y[i];
	}
      y[i] = alpha * tmp[i] + beta * y[i];
    }

}