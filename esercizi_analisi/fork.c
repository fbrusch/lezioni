#include <unistd.h>
#include <stdio.h>

int main()
{
    int a[2]={1,2};
    int b[3]={10,11,100};
    int i=0,j=0;
    if (fork()) i++;
    if (fork())
    {
        j++;
        if (fork())
            j++;
    }
    printf ("%i\n",a[i]*b[j]);
}
