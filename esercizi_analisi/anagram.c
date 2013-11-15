#include <stdio.h>


int f(int n)
{
	int s=0;
	int i;
	for (i=1;i<n;i++)
		if (!(n%i))
			s+=i;
			
	return s;
}

int g(int n)
{
	return (f(n)==n);
}


int main(int argc,char** argv)
{
	int i;
	int a[6]={1,13,15,6,28,1000};
	
	for (i=0;i<6;i++)
		if (g(a[i])) printf ("%i\n",a[i]);
}
