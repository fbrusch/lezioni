#include <stdio.h>

int vincente(int n, int k)
{
    int i;
    if (n<3) return 1;
    if (n<6) return 0;
    if (n<11) return 1;
    if (n<14) return 0;
    if (n<19) return 1;
    for(i=n/2+1;i>0;i--)
    //for(i=1;i<n/2+1;i++)
    {
        printf("%d (%d) = %d + %d\n",n,k,i,n-i);
        if (vincente(i,k+1)==0 && vincente(n-i,k+1)==0)
            return 1;
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    int num;
    
    for(num=1;num<1000;num++)
        if(vincente(num,0)==1)
            printf("Il numero %d è vincente! ^_^\n", num);
        else
            printf("Il numero %d è perdente! :(\n", num);

    return 0;
}

