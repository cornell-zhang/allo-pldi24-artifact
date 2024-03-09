#   define NI 200
#   define NJ 220
#   define NK 240

void kernel(
	float alpha,
	float beta,
	float C[NI][NJ],
	float A[NI][NK],
	float B[NK][NJ])
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
//TRANSA = 'N'
//TRANSB = 'N'
// => Form C := alpha*A*B + beta*C,
//A is NIxNK
//B is NKxNJ
//C is NIxNJ
  for (i = 0; i < NI; i++) {
    for (j = 0; j < NJ; j++)
	C[i][j] *= beta;
    for (k = 0; k < NK; k++) {
       for (j = 0; j < NJ; j++)
	  C[i][j] += alpha * A[i][k] * B[k][j];
    }
  }
}