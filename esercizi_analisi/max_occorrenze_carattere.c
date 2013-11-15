#include <stdio.h>

int f(char a[], char b)
{
    int i, n=0;
    for (i=0;a[i]!='\0';i++)
        if (a[i]==b) n++;
    return n;
}

char g(char a[])
{
    char c; int i,m=0;
    for (i=0;a[i]!='\0';i++)
        if (f(a,a[i])>m)
        { c=a[i]; m=f(a,a[i]);}
    return c;
}

int main()
{
    printf ("%c\n",g("quare id faciam"));
    printf ("%c\n",g("fortasse requiris"));
    printf ("%c\n",g("nescio, sed fieri sentior, et exrucior"));
}

