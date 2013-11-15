#include <stdio.h>
#include <stdlib.h>


int f(int a, int b)
{
    while ((a%b)==0)
        a/=b;
    return a;
}

int g(int a)
{
    int r=0,i;
    for (i=2;i<=a;i++)
    {
        if((a%i)==0) r++;
        a=f(a,i);
    }
    return r;
}

int main(int argc, char** argv)
{
    printf ("%i,%i\n", atoi(argv[1]), g(atoi(argv[1])));
}
