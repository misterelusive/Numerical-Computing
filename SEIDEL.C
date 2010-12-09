/*
GAUSS-SEIDEL ITERATIVE TECHNIQUE

NOTE: It requires input from an external file. So, a file containing the
      coefficients must be created beforehand. Here, we have created a file
      named "s.txt" which contains the following data:

	20 1 -2 17
	3 20 -1 -18
	2 -3 20 25
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double *, double [][11], double *, int *, int *);
void OUTPUT(int, double *, int, double);

void main()
{
double A[10][11],X1[10];
double S,ERR,TOL;
int N,I,J,NN,K,OK;
clrscr();
INPUT(&OK, X1, A, &TOL, &N, &NN);
if (OK) {
/* STEP 1 */
K = 1;
OK = false;
/* STEP 2 */
while ((!OK) && (K <= NN )) {
/* err is used to test accuracy - it measures the
infinity-norm */
ERR = 0.0;
/* STEP 3 */
for (I=1; I<=N; I++) {
S = 0.0;
for (J=1; J<=N; J++) S = S - A[I-1][J-1] * X1[J-1];
S = (S + A[I-1][N]) / A[I-1][I-1];
if (absval(S) > ERR) ERR = absval(S);
X1[I-1] = X1[I-1] + S;
}
/* STEP 4 */
if (ERR <= TOL) OK = true;
/* process is complete */
/* STEP 5 */
K++;
/* STEP 6 - is not used since only one vector is required */
}
if (!OK) printf("Maximum Number of Iterations Exceeded.\n");
/* STEP 7 */
/* procedure completed unsuccessfully */
else OUTPUT(N, X1, K, TOL);
}
getch();
}

void INPUT(int *OK, double *X1, double A[][11], double *TOL, int *N, int *NN)
{
int I, J;
char AA;
char NAME[30];
FILE *INP;

*OK = false;
printf("Has the input file been created? - enter Y or N.\n");
scanf("%c",&AA);
if ((AA == 'Y') || (AA == 'y')) {
printf("Input the file name in the form - drive:name.ext\n");
printf("for example: A:DATA.DTA\n");
scanf("%s", NAME);
INP = fopen(NAME, "r");
*OK = false;
while (!(*OK)) {
printf("Input the number of equations - an integer.\n");
scanf("%d", N);
if (*N > 0) {
for (I=1; I<=*N; I++) {
for (J=1; J<=*N+1; J++) fscanf(INP, "%lf", &A[I-1][J-1]);
fscanf(INP, "\n");
}
for (I=1; I<=*N; I++) fscanf(INP, "%lf", &X1[I-1]);
/* use X1 for XO */
*OK = true;
fclose(INP);
}
else printf("The number must be a positive integer.\n");
}
*OK = false;
while(!(*OK)) {
printf("Input the accuracy required (e.g.10000).\n");
scanf("%lf", TOL);
if (*TOL > 0) *OK = true;
else printf("Accuracy must be a positive number.\n");
}
*OK = false;
while(!(*OK)) {
printf("Input maximum number of iterations.\n");
scanf("%d", NN);
if (*NN > 0) *OK = true;
else printf("Number must be a positive integer.\n");
}
}
else printf("The program will end so the input file can be created.\n");
}


void OUTPUT(int N, double *X1, int K, double TOL)
{
int I, J, FLAG;
char NAME[30];
FILE *OUP;

printf("Choice of output method:\n");
printf("1. Output to screen\n");
printf("2. Output to text file\n");
printf("Please enter 1 or 2.\n");
scanf("%d", &FLAG);
if (FLAG == 2) {
printf("Input the file name in the form - drive:name.ext\n");
printf("for example: A:OUTPUT.DTA\n");
scanf("%s", NAME);
OUP = fopen(NAME, "w");
}
else OUP = stdout;
fprintf(OUP, "The solution vector is :\n");
for (I=1; I<=N; I++) fprintf(OUP, " %11.8f", X1[I-1]);
fprintf(OUP, "\nusing %d iterations\n", K);
fprintf(OUP, "with accuracy %.10e in infinity-norm\n", TOL);
fclose(OUP);
}
/* Absolute Value Function */
double absval(double val)
{
if (val >= 0) return val;
else return -val;
}