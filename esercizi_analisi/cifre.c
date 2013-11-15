#include <stdio.h>

int f(int n, int c)
{
    if (n==0) return 0;
    if (n%10 == c) return (1 + f(n/10, c));
    else return f(n/10, c);
}


int main()
{
    printf("%i\n", f(12345,1));
    printf("%i\n", f(10*10*10-1,1));
    printf("%i\n", f(10*10*10-1,9));
}
