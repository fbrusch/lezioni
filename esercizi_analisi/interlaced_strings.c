#include <stdio.h>

int f(char a[], char b[])
{
    int i=0,j=0;
    while (a[i] != '\0' && b[j] != '\0')
    {
        if (a[i]==b[j]) i++;
        j++;
    }
    if (a[i]=='\0') return 1;
    return 0;
}

int main()
{
    printf ("%i\n",f("ciao","acciacco"));
    printf ("%i\n",f("ciao","scaccio"));
    printf ("%i\n",f("osso","ostracismo"));
    printf ("%i\n",f("consistenza","insistenza"));
}
