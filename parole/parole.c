#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 80

int contaParole(char *nomeFile)
{
    return 100;
}

int main()
{
    FILE *f;
    char parola[MAXLEN];
    char **parole;
    char **parole_ordinate;
    char *strtmp;
    int tmp;
    f=fopen("testo.txt","r");
    int i,j,k;
    int numeroParole = contaParole("testo.txt");
    parole = malloc(sizeof(char *)*numeroParole);
    parole_ordinate =
        malloc(sizeof(char*)*numeroParole);

    i=0;
    while(!feof(f))
    {
        fscanf(f,"%s",parola);
        printf("parola letta: %s\n",parola);
        parole[i]=strdup(parola);
        i++;
    }

    for(k=0;k<i;k++)
    {
        tmp = k;

        for(j=k+1;j<i;j++)
            if(strcmp(parole[tmp],parole[j]) > 0)
                tmp=j;

        strtmp = parole[k];
        parole[k] = parole[tmp];
        parole[tmp] = strtmp;
    }

    for(k=0;k<i;k++)
        printf("%s\n",parole[k]);

    printf("prima parola:%s\n",parole[tmp]);

}

