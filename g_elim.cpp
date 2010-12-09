/*
Gauss Elimination.
*/
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

int nun,neq;
double **sys, *back;
int moreeq=0;

void solution();
double evaluate(int);
void result();
int consistent();

double evaluate(int g)
{
int u;
double rt=0;
rt = sys[g][nun];
for(u=0;u<nun;u++)
{
if(g==u) continue;
rt -= sys[g][u] * back[u];
}
rt /= sys[g][g];
return rt;
}

int consistent()
{
int i,j,n=0;
for(i=0;i<neq;i++)
{
for(j=0;j<nun;j++)
{
if(sys[i][j] != 0)
{
n++;
break;
}
}
}
if(n==neq)
return 1;
return 0;
}

void result()
{
int i,j;
if(!consistent())
{
getch();
clrscr();
cout<<"\n\nGiven system is inconsistent system...\nSolution can't be found.\n";
getch();
return;
}
else
{
for(i=nun-1;i>=0;i--)
{
back[i] = evaluate(i);
}
return;
}
}

void solution()
{
int i,j,k,r;
float c;
for(r=0;r<neq;r++)
{
c=sys[r][r];
for(k=0;k<=nun;k++)
{
sys[r][k] /= c;
}
for(i=r+1;i<neq;i++)
{
c = sys[i][r];
for(j=0;j<=nun;j++)
{
sys[i][j] -= c*sys[r][j];
}
}
for(i=0;i<neq;i++)
{
cout<<"\n\n";
for(j=0;j<=nun;j++)
{
printf("%15.4f",sys[i][j]);
}
}
cout<<"\n\n";
getch();
}
result();
}

void main()
{
int i,j;
char ch='y';
do
{
clrscr();
cout<<"GAUSS ELIMINATION METHOD\n";
cout<<"Enter the number of equations : ";
cin>>neq;
cout<<"Enter the number of unknowns : ";
cin>>nun;
if(nun>neq)
{
cout<<"Data Inadequate!";
getch();
exit(0);
}
if(neq>nun)
moreeq=1;
sys = (double **)malloc((neq)*sizeof(double *));
back = (double *)malloc((nun)*sizeof(double ));
for(i=0;i<neq;i++)
{
*(sys+i) = (double *)malloc((nun+1)*sizeof(double));
}
clrscr();
cout<<"Enter the coefficients : \n";
for(i=0;i<neq;i++)
{
cout<<"\nEquation "<<i+1<<" : ";
for(j=0;j<nun;j++)
{
cout<<"\nx"<<j+1<<" : ";
cin>>*(*(sys+i)+j);
back[i] = 0;
}
cout<<"b"<<i+1<<" : ";
cin>>*(*(sys+i)+j);
}
clrscr();
cout<<"\n\nGiven system of equation\n\n";
for(i=0;i<neq;i++)
{
cout<<"\n\t";
for(j=0;j<nun;j++)
{
if(*(*(sys+i)+j)<0)
{
cout<<"\b\b";
}
cout<<*(*(sys+i)+j)<<"x"<<j+1;
if(!(j==nun-1))
cout<<" + ";
}
cout<<" = ";
cout<<*(*(sys+i)+j);
}
solution();
getch();
clrscr();
cout<<"\n\nThe solution is : \n";
for(i=0;i<nun;i++)
{
cout<<"\n\t";
cout<<"x"<<i+1<<" : "<<back[i];
}
cout<<"\nDo you want to continue (y/n)? ";
ch = getch();
}while(ch == 'y');
}