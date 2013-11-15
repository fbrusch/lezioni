#include <stdio.h>

int k(int l)
{
    int i,n=0;
    for (i=0;i<l;i++)
    {
        n*=2;
        if (fork()) n+=1;
    }
    return n;
}

int main()
{
    printf ("%i\n",k(4));
}
