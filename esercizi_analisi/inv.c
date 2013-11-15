#include <stdio.h>

int f(int a, int b)
{
	int res=0;
	while(a>0)
	{
		res*=b;
		res+=a%b;
		a/=b;
	}
	return res;
}

int main()
{
	int a[5]={1,54,532,198237,123987};
	int b[5]={2,3,10,10,123988};
	
	int i;
	for (i=0;i<5;i++)
		printf ("%i\n",f(a[i],b[i]));
}