/*
notes: ''
suitable_for: [prima_prova, appello]
tags: ''
text:
    it: "Si dica cosa produce l'esecuzione del seguente codice"
    en:
title: 'Trova stringhe col maggior numero di caratteri in comune'
notes:
    it:
    en:


*/

int f(char a[], char b)
{
    int i, n=0;
    for (i=0;a[i]!='\0';i++)
        if (a[i]==b) n++;
    return n;
}

int g(char a[], char b[])
{

}
