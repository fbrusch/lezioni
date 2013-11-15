#include <stdio.h>
#include <strings.h>

char* h(char* s)
{
    char c;
    for (c=*s;c==*s;s++);
    return s;
}

void p(char* a, char* b)
{
    char t=*a;
    if (*a>*b) {*a=*b; *b=t;}
}

void o(char* s)
{
    int i,j,l=strlen(s);
    for (i=0;i<l;i++)
        for (j=0;j+1<l;j++)
            p(s+j,s+j+1);
}

char f(char *s)
{
    char c,m=0;
    o(s);
    for (c=*s;*s!='\0';s=h(s))
    {
        if ((h(s)-s)>m)
        {m=h(s)-s; c=*s;}
    }
    return c;
}

int main(int argc, char** argv)
{
    char *s=strdup("fortasse requiris");
    o(s);
    printf ("%s\n",s);
    printf ("%c\n",f(s));
}
