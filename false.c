/*
Regula-Falsi method.
*/
#include <stdio.h>
#include <conio.h>

float fx(float x)
{
float result;
result = ((x*x*x)-x-1);
return result;
}

void main()
{
int cnt=0;
float x0,x1,x2;
clrscr();
printf("Enter the value of x0 and x1 : ");
scanf("%f %f",&x0,&x1);
printf("x0 x1 F(x0) F(x1) x2 Count\n");
x2 = x1-(fx(x1)/(fx(x1)-fx(x0)))*(x1-x0);
cnt=1;
printf("%f %f %f %f %f %d\n",x0,x1,fx(x0),fx(x1),x2,cnt);
while(((x1-x0)/x0)>=0.0001)
{
if((fx(x2)*fx(x0))<0)
{
x1 = x2;
x2 = x1 - (fx(x1)/(fx(x1)-fx(x0)))*(x1-x0);
if(x2==x1)
{
break;
}
}
else
{
x0 = x2;
x2 = x1 - (fx(x1)/(fx(x1)-fx(x0)))*(x1-x0);
if(x2==x0)
{
break;
}
}
cnt++;
printf("%f %f %f %f %f %d\n",x0,x1,fx(x0),fx(x1),x2,cnt);
}
getch();
}