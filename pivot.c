/*
Gauss elimination with partial pivoting.
Given equation:
    2x + y + 4z = 12
    8x - 3y + 2z = 23
    4x + 11y - z = 33
NOTE: A file named "matrix.txt" needs to be created and passed to the program as a parameter at the time of execution. In the above case, "matrix.txt" will contain the following data:
3

2 1 4
8 -3 2
4 11 -1

12
23
33
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef double ** Matrix;
typedef double * Row;
typedef double * Col;
typedef double Elem;

Matrix allocate_matrix(int n);
Col allocate_col(int n);
Row allocate_row(int n);
void free_matrix(Matrix M, int n);

void pivot_partial(Matrix A, Col S,Col B, int n);
void forward_elimination(Matrix A,Col B,int n);
Col back_substitution(Matrix A, Col B, int n);
Col scale_factor(Matrix A,int n);
void gauss(Matrix A, Col B, int n);

void swap_rows(Row *r1, Row*r2);
void print_matrix(Matrix M, int n, char * name);
void print_col(Col C, int n, char *name);
void print_row(Row R, int n, char *name);



int main(int argc, char *argv[])
{
FILE *ifp;
int n,i,j;
Matrix A;
Col B;
clrscr();
if(argc < 2)
{
printf("\nInput filename not passed \n");
exit(1);
}

ifp = fopen(argv[1],"r");

if(ifp == NULL)
{
printf("\nCould not open file %s\n",argv[1]);
exit(1);
}
fscanf(ifp,"%i",&n);
printf("\nDimension = %i\n",n);

A = allocate_matrix(n);
for( i = 1; i <= n; ++i)
for(j = 1; j <= n; ++j)
fscanf(ifp,"%lf", &A[i][j]);

B = allocate_col(n); 

for(j = 1; j <= n; ++j)
fscanf(ifp,"%lf",&B[j]);
fclose(ifp); 


print_matrix(A,n,"A");
print_col(B,n,"B");

gauss(A,B,n); 

free_matrix(A,n);
free(B + 1);

printf("\nDone");
getchar();
return 0;
}




void print_matrix(Matrix M, int n, char * name)
{
int i,j;
printf("\n[%s] = ",name);
printf("\n\n");
for(i = 1; i <= n; i++)
{
for(j = 1; j <= n; ++j)
printf("%6lG ",M[i][j]);
printf("\n");
}
}

void print_col(Col C, int n, char * name)
{
int j;
printf("\n[%s] = ",name);
printf("\n\n");
for(j = 1; j <= n; ++j)
printf("%6lg\n",C[j]);

}
void print_row(Row R, int n, char * name)
{
int i;
printf("\n[%s] = ",name);
for(i = 1; i <= n; ++i)
printf("%6lg ",R[i]);
printf("\n");
}

Matrix allocate_matrix(int n)
{
Matrix A;
int i,j;
A = malloc(n * sizeof(Row));
if(!A)
{
printf("\nError : Could not allocate memory for matrix\n");
exit(1);
} 
--A;

for(i = 1; i <= n; ++i)
{
A[i] = malloc(n * sizeof(Elem));
if(!A[i])
{
printf("\nError : Could not allocate memory for matrix\n");
exit(1);
}
--A[i];
}
return A;
}

void free_matrix(Matrix M, int n)
{
int i;
for(i = 1; i <= n; ++i)
free(M[i] + 1);
free(M + 1);
}

Col allocate_col(int n)
{
Col B;

B = malloc(n * sizeof(Elem));

if(!B)
{
printf("\nError : could not allocate memory\n");
exit(1);
}
--B;
return B;
}

Row allocate_row(int n)
{
Row B;
B = malloc(n * sizeof(Elem));
if(!B)
{
printf("\nError : could not allocate memory\n");
exit(1);
}
--B;
return B;
}


Col scale_factor(Matrix A, int n)
{
int i,j;
Col S ;
S = allocate_col(n);

for(i = 1; i <= n; ++i)
{
S[i] = A[i][1];
for(j = 2; j <= n; ++j)
{
if(S[i] < fabs(A[i][j]))
S[i] = fabs(A[i][j]);
}

}
return S;

}

void pivot_partial(Matrix A, Col S,Col B, int n)
{
int i,j;
Elem temp;
for(j = 1; j <= n; ++j)
{
for(i = j + 1; i <= n; ++i)
{
if(S[i] == 0)
{
if(B[i] == 0)
printf("\nSystem doesnt have a unique solution");
else 
printf("\nSystem is inconsistent");
exit(1);
}
if(fabs(A[i][j]/S[i]) > fabs(A[j][j]/S[j]))
{
swap_rows(&A[i],&A[j]);
temp = B[i];
B[i] = B[j];
B[j] = temp;
}
}

if(A[j][j] == 0)
{
printf("\nSingular System Detected\n");
exit(1);
}
}

}

void swap_rows(Row *r1, Row*r2)
{
Row temp;
temp = *r1;
*r1 = *r2;
*r2 = temp; 
}

void forward_elimination(Matrix A,Col B,int n)
{
int i,j,k;
double m;

for(k = 1; k <= n-1; ++k)
{
for(i = k + 1; i <= n; ++i)
{
m = A[i][k] / A[k][k];
for(j = k + 1; j <= n; ++j)
{
A[i][j] -= m * A[k][j];
if(i == j && A[i][j] == 0)
{
printf("\nSingular system detected");
exit(1);
} 
}
B[i] -= m * B[k];

}
}

}

Col back_substitution(Matrix A, Col B, int n)
{
int i,j;
Elem sum;
Col X = allocate_col(n);
X[n] = B[n]/A[n][n];
for(i = n - 1; i >= 1; --i)
{
sum = 0;
for(j = i + 1; j <= n; ++j)
sum += A[i][j] * X[j];
X[i] = (B[i] - sum) / A[i][i];
}
return X;
}

void gauss(Matrix A, Col B, int n)
{
int i,j;
Col S, X;
S = scale_factor(A,n);
pivot_partial(A,S,B,n);
forward_elimination(A,B,n);
X = back_substitution(A,B,n);
print_col(X,n,"X");

free(S + 1);
free(X + 1);
}
