#   define M 200
#   define N 240

void kernel(
	float alpha,
	float beta,
	float C[N][N],
	float A[N][M],
	float B[N][M])
{
    #pragma HLS INTERFACE s_axilite port=alpha bundle=control
    #pragma HLS INTERFACE s_axilite port=beta bundle=control
    #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=A bundle=control
    #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=B bundle=control
    #pragma HLS INTERFACE m_axi port=C offset=slave bundle=gmem
    #pragma HLS INTERFACE s_axilite port=C bundle=control
    #pragma HLS INTERFACE s_axilite port=return bundle=control
  int i, j, k;

//BLAS PARAMS
//UPLO  = 'L'
//TRANS = 'N'
//A is NxM
//B is NxM
//C is NxN
  for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++)
      C[i][j] *= beta;
    for (k = 0; k < M; k++)
      for (j = 0; j <= i; j++)
	{
	  C[i][j] += A[j][k]*alpha*B[i][k] + B[j][k]*alpha*A[i][k];
	}
  }

}