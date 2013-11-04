#include <stdio.h>

#define DIM 20000

int vincente(int n, int k, int array[DIM])
{
    int i;
    if (n<3) return 1;
    if (n<6) return 0;
    if (n<11) return 1;
    if (n<14) return 0;
    if (n<19) return 1;
    
    if(n<DIM && array[n]!=3)
        return array[n];
    
    for(i=n/2+1;i>0;i--)
        //for(i=1;i<n/2+1;i++)
    {
        //printf("%d (%d) = %d + %d\n",n,k,i,n-i);
        if (vincente(i,k+1,array)==0 && vincente(n-i,k+1,array)==0)
        {
            if(n<DIM)
                array[n]=1;
            return 1;
        }
    }
    
    if(n<DIM)
        array[n]=0;
    return 0;
}

int main(int argc, const char * argv[])
{
    int i,num;
    
    int array[DIM];
    
    for(i=0;i<DIM;i++)
        array[i]=3;
    
    for(num=1;num<20000;num++)
        if(vincente(num,0,array)==1)
            printf("Il numero %d è vincente! ^_^\n", num);
        else
            printf("Il numero %d è perdente! :(\n", num);
    
    return 0;
}
