/*
Muller's method.
Given:
f(x) = x^3 - 2x - 5
x1 = 0, x2 = 1, x3 = 2
*/
#include <stdio.h>
#include <conio.h>
#include <math.h>

float fx(float x)
{
float result;
result = ((x*x*x)-(2*x)-5);
return result;
}

void main()
{
float x1,x2,x3,f1,f2,f3,h1,h2,d1,d2,D,a0,a1,a2,h_1,h_2,x4;
int count=0;
clrscr();
printf("Enter the value of x1, x2 and x3:");
scanf("%f %f %f",&x1,&x2,&x3);
start:
f1 = fx(x1);
f2 = fx(x2);
f3 = fx(x3);
h1 = x1-x3;
h2 = x2-x3;
d1 = f1-f3;
d2 = f2-f3;
D = h1*h2*(h1-h2);
a0 = f3;
a1 = ((d2*h1*h1)-(d1*h2*h2))/D;
a2 = (d1*h2-d2*h1)/D;
h_1 = (-2*a0)/(a1+sqrt(a1*a1-4*a2*a0));
h_2 = (-2*a0)/(a1-sqrt(a1*a1-4*a2*a0));
if(h_1>h_2)
{
x4 = x3 + h_1;
}
else
{
x4 = x3 + h_2;
}
if((x4-x3)<0.0001)
{
printf("x4 = %f",x4);
}
else
{
if(count<10)
{
x1 = x2;
x2 = x3;
x3 = x4;
count++;
goto start;
}
else
{
printf("Not possible");
}
}
getch();
}