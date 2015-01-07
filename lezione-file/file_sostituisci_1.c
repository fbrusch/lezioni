#include <stdio.h>
#include <stdlib.h>

#define FILENAME "file2.dat"

void sostituisci(int pos, int val)
{
    FILE* f;
    int i;
    int j;
    f = fopen(FILENAME,"r+");
    fseek(f, pos*sizeof(int), SEEK_SET);
    /*for(i=0;i<pos;i++)*/
    /*{*/
       /*printf("%li\n",ftell(f));*/
       /*fread(&j, sizeof(int), 1, f);*/
    /*}*/

    fwrite(&val, sizeof(int), 1, f);

    fclose(f);
    
}

int main(int argc, char** argv)
{
    sostituisci(atoi(argv[1]),atoi(argv[2]));

}
