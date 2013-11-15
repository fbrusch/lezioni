#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a;
    int n,i;

    printf ("quanti numeri interi vuoi che memorizzi?");
    scanf("%i",&n);

    a=malloc(n*sizeof(int));

    for (i=0;i<n;i++)
        a[i]=i;

    for (i=0;i<n;i++)
        printf ("%i\n",a[i]);

    free(p);

}
