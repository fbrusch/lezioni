/*
title: cifre comuni a due numeri
tags: numeri,
suitable_for: prima_prova, appello
text:
    it: "Indicare che output produrrebbe l'esecuzione del seguente codice"
notes:
*/

#include <stdio.h>

int g(int a, int b,int c)
{
    for (; c > 0; c /= b)
        if ((c % b)==a) return 1;
}
