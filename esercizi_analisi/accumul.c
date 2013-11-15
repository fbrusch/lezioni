#include <stdio.h>
#include <stdlib.h>

void f(int a, int b, int *c)
{
	while(a>0)
	{
		c[a%b]++;
		a/=b;
	}
}

int pw(b,e)
{
	int r=1;
	while (e-->0)
		r*=b;
	return r;
}
		
int main()
{
	int c1[2]={0,0},c2[10]={0,0,0,0,0,0,0,0,0,0},c3[3]={0,0,0};
	int i;
	
	f(10,2,c1); f(2,2,c1); f(pw(2,12),2,c1);
	printf ("%i %i\n",c1[0],c1[1]);
	
	f(10,10,c2); f(2,10,c2); f(16,10,c2); f(1627,10,c2);
	for (i=0;i<10;i++)
		printf ("%i ",c2[i]);
	printf ("\n");
}
	
