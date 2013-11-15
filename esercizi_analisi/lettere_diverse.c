#include <stdio.h>

int g(char a, char s[], int i)
{
    int n=0;
    for (;s[i]!='\0';i++)
        if (a==s[i]) n++;
    return n;
}

int f (char s[])
{
    int n=0,i;
    for (i=0;s[i]!=0;i++)
        if (g(s[i],s,i)==1) n++;
    return n;
}

int main()
{
    printf ("%i, %i, %i\n",f("quare id faciam"), f("fortasse requiris"),
                         f("nescio, sed fieri sentio"));

}
