#include <stdio.h>
#include <string.h>

char* i(char* s, char b)
{
    if (*s=='\0') return;
    if ((*s)==b) (*s)++;
    else
    {
        (*s)--; i(s+1,b);
    }
}

int main(int argc, char** argv)
{
    char *s=strdup("aaaaaaaa");
    int j;
    for (j=0;j<127;j++)
        i(s,'a');
    printf ("%s\n",s);
}
