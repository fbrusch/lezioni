#include <stdio.h>
#include <string.h>

int inizia_con(int n, char str1[], char str2[])
{
    int i;
    for(i=0;str1[i]!='\0';i++)
        if(str1[i]!=str2[i+n]) return 0;
    return 1;
}

int subStr(char str1[], char str2[])
{
    int i;
    if (strlen(str1)>strlen(str2)) return 0;
    for (i=0;i<=strlen(str2)-strlen(str1) ;i++)
    {
        if(inizia_con(i,str1,str2)) return 1;
    }
    return 0;
}



int main()
{
    char str1[]="hello world!";
    char str2[]="hello";
    char str3[]="ciao";
    char str4[]="lo";

    printf("str1 in str2: %i\n",subStr(str1,str2));
    printf("str2 in str1: %i\n",subStr(str2,str1));
    printf("str3 in str2: %i\n",subStr(str3,str2));
    printf("str4 in str1: %i\n",subStr(str4,str1));
    printf("str2 inizia con str4 a partire da 2:%i\n",
            inizia_con(2,str4,str2));
    printf("str2 inizia con str4 a partire da 3:%i\n",
            inizia_con(3,str4,str2));
}
