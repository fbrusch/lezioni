#include <stdio.h>

int conta_n(char nome[])
{
    int i,count=0;
    for(i=0;nome[i]!='\0';i++)
        if (nome[i]=='n') count++;
    return count;
}

int main()
{
    char nome[]="Francesco";
    printf("il numero di caratteri n è: %i\n", conta_n(nome));

}
