#include <stdio.h>

int r(int n)
{
    if (n<10)
        return n;
    return 10*(n%10)+r(n/10);
}

int main()
{
    int i;
    for (i=0;i<101;i++)
        if (i==r(i)) printf("%i\n",i);
}
