#   define N 400

void kernel(
	int x1[N],
	int x2[N],
	int y1[N],
	int y2[N],
	int A[N][N])
{
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=y1 offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=y1 bundle=control
    #pragma HLS INTERFACE m_axi port=y2 offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=y2 bundle=control
    #pragma HLS INTERFACE m_axi port=x1 offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=x1 bundle=control
    #pragma HLS INTERFACE m_axi port=x2 offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=x2 bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
  int i, j;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      x1[i] = x1[i] + A[i][j] * y1[j];
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      x2[i] = x2[i] + A[j][i] * y2[j];

}