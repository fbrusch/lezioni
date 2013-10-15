int c1(int x)
{
    return 0;
}

// varianti
//

// numero diverso da 0

int c2(int x)
{
    return 42;
}

// con aritmetica
// Concetti da evidenziare:
// 1) l'argomento del return non è un numero intero, ma un'espressione intera
// 2) un'espressione intera è un oggetto che, "valutato", produce un intero
// 3) la regola di valutazione di un'espressione aritmetica è: fai i conti!

int c3(int x)
{
    return (6*7);
}

// senza argomento
// Far notare che l'argomento non è mai utilizzato nell'espressione, e quindi si
// può omettere

int c4()
{
    return (6*7);
}



