#include <stdio.h>
#include <string.h>

void i(char* s, char b, int c)
{
    if (*s=='\0') return;
    if ((*s-b)<c-1) (*s)++;
    else
    {
        *s=b; i(s+1,b,c);
    }
}

int main(int argc, char** argv)
{
    char *s=strdup("xxx"), c=*s;
    int j;
    for (j=0;j<12;j++,i(s,c,3))
        printf ("%s\n",s);
}
