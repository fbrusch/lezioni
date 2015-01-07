#include <stdio.h>

#define FILENAME "primo_file.dat"

void leggi()
{
    FILE* f;
    int x;
    f = fopen(FILENAME, "r");
    fread(&x, sizeof(int), 1, f);
    printf("%i",x);
    fclose(f);
}

int main()
{
    leggi();
}
