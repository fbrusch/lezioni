#include <stdio.h>

int minuscola(char c)
{
    return c <= 'z' && c >= 'a';
}

void capitalizza(char *c)
{
    if(minuscola(*c))
        *c = *c -'a' + 'A';
}

int trasforma(char* src, char* dest) {
    FILE *f_src = fopen(src, "r");
    FILE *f_dest = fopen(dest, "w");
    
    char c;
    char prev = ' ';

    while(!feof(f_src)) {
        fread(&c, sizeof(char), 1, f_src);
        if(prev != c) fwrite(&c, sizeof(char), 1, f_dest);
        prev = c;
    }

    fclose(f_src);
    fclose(f_dest);
}

int main(int argc, char** argv)
{
    trasforma(argv[1], argv[2]);
    return 0;
}

