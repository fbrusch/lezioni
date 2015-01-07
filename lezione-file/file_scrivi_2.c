#include <stdio.h>

#define FILENAME "file2.dat"

void scrivi(int n)
{
    int i;
    FILE* f;
    f = fopen(FILENAME,"w");
    for(i=1;i<=n;i++)
        fwrite(&i,sizeof(int),1,f);

}

int main()
{
    scrivi(10);
}
