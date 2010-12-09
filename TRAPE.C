/*
Trapezoidal rule.
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAX 20

float f(float x)
{
float value;
value = (1/(1+(x*x)));
return value;
}

void main()
{
float a,b,h,value,sum=0;
float x[MAX],y[MAX];
int i,n;
clrscr();
printf("Enter the value of a : ");
scanf("%f",&a);
printf("Enter the value of b : ");
scanf("%f",&b);
printf("Enter the number of intervals : ");
scanf("%d",&n);
h = ((b-a)/n);
printf("h = %f\n\n",h);
x[0] = a;
x[n] = b;
printf("\nValues of x:\n");
printf("%f\n",x[0]);
for(i = 1;i<=n-1;i++)
{
x[i] = x[i-1]+h;
printf("%f\n",x[i]);
}
printf("%f\n",x[n]);
printf("\nValues of y:\n");
for(i=0;i<=n;i++)
{
y[i] = f(x[i]);
printf("%f\n",y[i]);
}
for(i=1;i<=n-1;i++)
{
sum = sum+y[i];
}
value = (h*(0.5*(y[0]+y[n])+sum));
printf("\n\nThe value of the integral is : %f",value);
getch();
}
