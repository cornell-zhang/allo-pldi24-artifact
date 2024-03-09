#   define M 200
#   define N 240

void kernel(
	float alpha,
	float A[M][M],
	float B[M][N])
{
   #pragma HLS INTERFACE s_axilite port=alpha bundle=control
   #pragma HLS INTERFACE m_axi port=A offset=slave bundle=gmem
   #pragma HLS INTERFACE s_axilite port=A bundle=control
   #pragma HLS INTERFACE m_axi port=B offset=slave bundle=gmem
   #pragma HLS INTERFACE s_axilite port=B bundle=control
   #pragma HLS INTERFACE s_axilite port=return bundle=control
  int i, j, k;

//BLAS parameters
//SIDE   = 'L'
//UPLO   = 'L'
//TRANSA = 'T'
//DIAG   = 'U'
// => Form  B := alpha*A**T*B.
// A is MxM
// B is MxN
  for (i = 0; i < M; i++)
     for (j = 0; j < N; j++) {
        for (k = 0; k < M; k++)
           if (k >= i+1)
               B[i][j] += A[k][i] * B[k][j];
        B[i][j] = alpha * B[i][j];
     }
}