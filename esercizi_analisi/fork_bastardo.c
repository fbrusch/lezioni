#include <unistd.h>
#include <stdio.h>

void f(int *i,int n)
{
    if (n==1) return;
    if (fork())
    {
        (*i)++;
        f(i,n-1);
    }
}

int r(int n)
{
    if (n<10)
        return n;
    return 10*(n%10)+r(n/10);
}

int main()
{
    int i=10,j=1;
    f(&i,3);
    f(&j,10);
    if (r(i*j)==(i*j))
        printf ("%i\n",i*j);;
}
