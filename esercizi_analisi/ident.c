// primo esempio di utilizzo del parametro
// far notare che anche in questo caso l'argomento di return è
// un'espressione intera, ma che contiene l'argomento della funzione. 
// Come viene valutata? Viene preso il valore della x,
// che ad ogni "chiamata" (valutazione della funzione) corrisponde al valore in 
// ingresso alla funzione, ogni volta potenzialmente diverso.
// La regola di valutazione, in questo caso, è: sostituisci alla x il suo valore
// attuale

int ident(int x)
{
    return x;
}

