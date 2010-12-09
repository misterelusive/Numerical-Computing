/*
Milne's method for solving first order IVP (Initial Value Problem).

Program to solve an IVP, dy/dx = f(x,y), y(x0) = y0, using
Milne-Simpson method. The initial values x0, y0, the final value
xf and the step size are to be read. Starting values are calculated
using classical fourth order Runge-Kutta method.
Adams-Bashforth method of third order is used as predictor and
Milne-Simpson method is iterated till abs(yold-ynew) <= err,
where err is error tolerance.
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x, float y)
{
float func;
func = -2.0 * x * y * y;
return(func);
}

void main()
{
float x[21],y[21],k1,k2,k3,k4,x0,y0;
float h,f0,f1,f2,f3,f4,x1,y1,p,yold,eps;
int n,i,miter,iter,niter,m;
clrscr();
printf("Enter initial point x0 :");
scanf("%f",&x0);
printf("Enter initial value y0 :");
scanf("%f",&y0);
printf("Enter number of steps, m : ");
scanf("%d",&m);
printf("Enter step size, h :");
scanf("%f",&h);
printf("Enter error tolerance, eps :");
scanf("%E",&eps);
printf("Input maximum number of iterations per step : ");
scanf("%d",&niter);
x[0] = x0;
y[0] = y0;
for(i=1;i<=2;i++)
{
x1 = x[i-1];
y1 = y[i-1];
k1 = h*f(x1,y1);
k2 = h*f(x1+0.5*h,y1+0.5*k1);
k3 = h*f(x1+0.5*h,y1+0.5*k2);
k4 = h*f(x1+h,y1+k3);
y[i] = y1+(k1+2.0*k2+2.0*k3+k4)/6.0;
x[i] = x1 + h;
}
miter = 0;
for(i=3;i<=m;i++)
{
iter = 0;
x1 = x[i-1];
y1 = y[i-1];
f0 = f(x[i-3],y[i-3]);
f1 = f(x[i-2],y[i-2]);
f2 = f(x1,y1);
y[i] = y1 + h*(23.0*f2-16.0*f1+5.0*f0)/12.0;
x[i] = x1 + h;
p = y[i-2] + h*(4.0*f2+f1)/3.0;
l2: yold = y[i];
iter = iter + 1;
miter = miter + 1;
f3 = f(x[i], yold);
y[i] = p+h*f3/3.0;
if((fabs(yold-y[i]) - eps)<=0)
goto l3;
if(iter>niter)
{
printf("Iteration bound is not sufficient");
goto l1;
}
goto l2;
l3: printf("");
}
printf("\nStep = %6.4f\n",h);
printf("Total number of Milne correctors used = %d\n",miter);
printf("\nSolution at nodal points:\n\n");
for(i=1;i<=m;i++)
{
printf("%6.4f ",y[i]);
if(i==5)
printf("\n");
}
l1: getch();
}
