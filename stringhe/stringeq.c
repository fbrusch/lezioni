#include <stdio.h>

int strEq(char str1[], char str2[])
{
    int i;
    for(i=0;str1[i]!='\0';i++)
        if(str1[i]!=str2[i])
            return 0;
    if(str2[i]=='\0') return 1;
    return 0;
}

int main()
{

    char str1[]="hello world!";
    char str2[]="hello";
    char str3[]="ciao";
    char str4[]="parole dolci";
    char str5[]="ciao";

    printf ("eq(str1,str1): %i\n",strEq(str1,str1));
    printf ("eq(str3,str5): %i\n",strEq(str3,str5));
    printf ("eq(str5,str3): %i\n",strEq(str5,str3));
    printf ("eq(str1,str2): %i\n",strEq(str1,str2));

}
