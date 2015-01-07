#include <stdio.h>
#include <stdlib.h>

#define FILENAME "primo_file.dat"

void scrivi(int x)
{
    FILE* f;
    f = fopen(FILENAME,"w");
    fwrite(&x, sizeof(int), 1, f);
}

int main(int argc, char** argv)
{
    scrivi(atoi(argv[1]));
}
