/*
Fourth order Runge-Kutta method.
*/

#include <stdio.h>
#include <conio.h>

static float const one_sixth = 1.0/6.0;

float f(float x, float y)
{
float result;
result = ((y*y)+x);
return result;
}

void main()
{
float x0,y0,h,h2,k1,k2,k3,k4,value;
int i,iterations;
clrscr();
printf("Enter the value of x0 : ");
scanf("%f",&x0);
printf("Enter the value of y0 : ");
scanf("%f",&y0);
printf("Enter the value of h : ");
scanf("%f",&h);
printf("Enter the number of iterations : ");
scanf("%d",&iterations);
h2 = 0.5*h;
printf("h = %f\n",h);
printf("h/2 = %f\n\n",h2);
printf("x0 y0 k1 k2 k3 k4 value\n");
for(i=1;i<=iterations;i++)
{
k1 = h*f(x0,y0);
k2 = h*f(x0+h2,y0+(0.5*k1));
k3 = h*f(x0+h2,y0+(0.5*k2));
k4 = h*f(x0+h,y0+k3);
value = (y0+one_sixth*(k1+k2+k2+k3+k3+k4));
printf("%f %f %f %f %f %f %f\n",x0,y0,k1,k2,k3,k4,value);
x0 = x0+h;
y0 = value;
}
getch();
}
