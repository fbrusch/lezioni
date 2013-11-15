#include <stdio.h>

int g(int a, int b, int c)
{
    int i;
    for (; c>0; c/=b)
        if (a == (c%b)) return 1;
    return 0;
}

int f(int a, int b)
{
    int n=0;
    for (; a>0; a /= b)
        if (!g(a%b, b, a/b))
            n++;
    return n;
}

int main()
{
    printf ("%i\n",f(123,10));
    printf ("%i\n",f(1223,10));
    printf ("%i\n",f(1*123+1*(123*123*123),123));
    printf ("%i\n",f(2+2*123+2*(123*123)+2*(123*123*123),123));
    return (0);
}
