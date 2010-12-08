/*
Newton-Raphson's method.
Given:
f(x) = x^3-3x-5
f'(x) = 3x^2 - 3
*/

#include <stdio.h>
#include <conio.h>

float fx(float x)
{
float result;
result = ((x*x*x)-(3*x)-5);
return result;
}

float fdashx(float x)
{
float result;
result = ((3*x*x)-3);
return result;
}

void main()
{
float r1,r2;
int cnt=0;
float x0,x1;
clrscr();
printf("Enter the value of x0 : ");
scanf("%f",&x0);
r1=fx(x0);
r2=fdashx(x0);
x1=x0-(r1/r2);
cnt = 1;
while(((x1-x0)/x0)>=0.0001)
{
printf("\nx%d = %f",cnt,x1);
x0=x1;
r1=fx(x0);
r2=fdashx(x0);
x1=x0-(r1/r2);
cnt++;
printf("\nx%d = %f",cnt,x1);
}
printf("\nx%d = %f",cnt+1,x1);
printf("\nWe observe that the values for iterations %d and %d are same,",cnt,cnt+1);
printf("\ntherefore the value will be : %f",x1);
printf("\nand number of iterations required would be : %d",cnt);
getch();
}