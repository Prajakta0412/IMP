#include <iostream>
using namespace std;
#define N 4
void multiply(int mat1[][N],
   int mat2[][N],
   int res[][N])
{
 int i, j, k;
 for (i = 0; i < N; i++) {
  for (j = 0; j < N; j++) {
   res[i][j] = 0;
   for (k = 0; k < N; k++)
    res[i][j] += mat1[i][k] * mat2[k][j];
  }
 }
}

int main()
{
 int i, j;
 int res[N][N]; 
 int mat1[N][N] = { { 2,5,1,3},
     {1,4,2,3 },
     { 4,1,3,1 },
     { 2,2,1,1 } };

 int mat2[N][N] = { { 1, 1,4,2 },
     { 1,3,5, 2 },
     { 2,3,1,1 },
     { 3,2,1,4 } };

 multiply(mat1, mat2, res);

 cout << "Result matrix is \n";
 for (i = 0; i < N; i++) {
  for (j = 0; j < N; j++)
   cout << res[i][j] << " ";
  cout << "\n";
 }

 return 0;
}
