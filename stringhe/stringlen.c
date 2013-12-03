#include <stdio.h>
#include <string.h>

int strLen(char str[])
{
    int i;
    for(i=0;str[i]!='\0';i++)
        ;
    return i;
}

int main()
{
    char str1[]="ciao a tutti";
    char str2[]="ciao a chi? ci conosciamo?";
    char str3[]="iosonolungaunpo";
    printf("str1 e' lunga %i\n",strLen(str1));
    printf("str2 e' lunga %i\n",strLen(str2));
    printf("str3 e' lunga %i\n",strLen(str3));

    printf("Ora vediamo che dice la stdlib\n");
    printf("str1 e' lunga %i\n",strlen(str1));
    printf("str2 e' lunga %i\n",strlen(str2));
    printf("str3 e' lunga %i\n",strlen(str3));
}
