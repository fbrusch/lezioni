#define LEN 3

#include <stdio.h>

int f(int a,int b)
{
    int r=0;
    for (;(a%b)==0;a/=b)
        r++;
    return r;
}

int g(int a)
{
    int r=0; int i;
    for (i=2;i<a;i++)
        if (f(a,i)>r)
            r=f(a,i);
    return r;
}

int h(int a[LEN])
{
    int i,m=g(a[0]),n=a[0];
    for (i=1;i<LEN;i++)
        if (g(a[i])>m)
        {
            m=g(a[i]);
            n=a[i];
        }
    return n;
}

int main()
{
    int a[]={1,2,20};
    int b[]={125,40,99};
    int c[]={3*3*3*3,11*11*11*11*11,1024};
    printf ("%i, %i, %i\n",h(a),h(b),h(c));
}
