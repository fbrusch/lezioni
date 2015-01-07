#include <stdio.h>

void capitalize(char* filename)
{
    FILE* f;
    char c;
    int len;
    f = fopen(filename, "r+");
    fseek(f, 0, SEEK_END);
    len = ftell(f);
    fseek(f, 0, SEEK_SET);
    while(ftell(f)<len-1)
    {
        fread(&c, sizeof(char), 1, f);
        fseek(f, -1*sizeof(char), SEEK_CUR);
        c = toupper(c);;
        printf("%c,%li\n",c,ftell(f));
        fwrite(&c, sizeof(char), 1, f);
        printf("%c,%li\n",c,ftell(f));
    }
    fclose(f);
}

int main(int argc, char** argv)
{
    capitalize(argv[1]);
}
