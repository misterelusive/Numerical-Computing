/*
Lagrange's method of interpolation.
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
float x[10], y[10], xin, yout, sum;
int n,i,j;
clrscr();
printf("Input number of points, n :");
scanf("%d",&n);
printf("Input the abscissas :\n");
for(i=1;i<=n;i++)
{
scanf("%f",&x[i]);
}
printf("Enter the ordinates :\n");
for(i=1;i<=n;i++)
{
scanf("%f",&y[i]);
}

printf("Input value of x for which y is required :");
scanf("%f",&xin);

yout = 0.0;
for(i=1;i<=n;i++)
{
sum = y[i];
for(j=1;j<=n;j++)
{
if(i!=j)
sum = sum*(xin-x[j])/(x[i]-x[j]);
}
yout = yout+sum;
}
printf("Lagrange interpolation based on %d points\n",n);
printf("at x = %5.3f, y = %8.5f\n",xin,yout);
getch();
}