#include <stdio.h>

int s(int a)
{
    return a+1;
}

int g(int a)
{
    int n=0;
    while(s(n)<a) n=s(n);
    return n;
}

int h(int a, int b)
{
    if (b==0) return a;
    return h(s(a),g(b));
}

int j(int a, int b)
{
    if (b==0) return 0;
    return h(a,j(a,g(b)));
}

int k(int a, int b)
{
    int i;
    if (b==0) return 1;
    return j(a,k(a,g(b)));
}


int main()
{
    int i;
    int a[5]={1,2,2,1024,13};
    int b[5]={1024,2,12,1,2};
    for(i=0;i<5;i=s(i))
        printf ("%i\n", k(a[i],b[i]));
}

