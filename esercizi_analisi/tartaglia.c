#include <stdio.h>
#include <stdlib.h>

int* t(int n,int* a)
{
	int i;
	int *r=(int*)malloc(sizeof(int)*(n+1));
	r[0]=1;
	for (i=1;i<n;i++)
		r[i]=a[i-1]+a[i];
	r[n]=1;
	return r;
}

void s(int n, int* a)
{
	int i;
	for (i=0;i<=n;i++)
		printf ("%d\t",a[i]);
	
	printf ("\n");
}

void tr(int n)
{
	int *p=(int*)malloc(sizeof(int));
	int* tmp;
	int i;
	
	p[0]=1;
	
	s(0,p);
	
	for (i=1;i<=n;i++)
	{
		p=t(i,p);
		s(i,p);
	}
}

int main(int argc,char** argv)
{
	tr(5);
}
		
		