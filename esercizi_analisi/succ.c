// Introduciamo un'espressione mista aritmetica con dentro l'argomento

int successivo(int x)
{
    return x+1;
}

// E il doppio?

int doppio(int x)
{
    return x*2;
}

// E il successivo del doppio

int doppio_del_successivo1(int x)
{
    return 2*(x+1);
}

// Oppure?
//

int doppio_del_successivo2(int x)
{
    return 2*successivo(x);
}

// Oppure?

int doppio_del_successivo3(int x)
{
    return doppio(successivo(x));
}

// Ora, nella prospettiva di introdurre l'if
// Funzione che dice se un numero è dispari?
// Problema: codifica del risultato con intero (0 falso, 1 vero)

int dispari(int x)
{
    return x%2;
}

// E per vedere se NON è divisibile per 3?
// Tentativo:

int divper3(int x)
{
    return x%3;
}

// non va bene perché a volte ritorna 2
// per fargli scassare la testa, spieghiamo come funzionano
// gli operatori interi
