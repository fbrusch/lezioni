#include <stdio.h>
#include <string.h>

int b(int n, int i)
{
    if (i==0) return n%2;
    return b(n/2, i-1);
}

int u(int n, int i)
{
    if (i==0) return 1;
    return n*u(n,i-1);
}

void p(char* s, int c)
{
    int i;
    for (i=0;s[i]!='\0';i++)
        if (b(c,i)) printf ("%c",s[i]);
    printf ("\n");
}

int f(char* s)
{
    int i,l=u(2,strlen(s));
    for (i=0;i<l;i++)
        p(s,i);
}

int main(int argc, char** argv)
{
    f("ciao");
}
