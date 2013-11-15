// funzione che rappresenta la mossa del primo giocatore
int p1(int numero)
{
    return numero-1;
}

// funzione che rappresenta la mossa del secondo giocatore
int p2(int numero)
{
    return numero-1;
}

// funzione che rappresenta una generica mossa di una partita di un gioco multigiocatore
int mossa(int stato, int giocatore)
{
    int risultato;
    
    if(giocatore==1)
   risultato = p1(stato);
    else
        risultato = p2(stato);
    
    giocatore=3-giocatore;
    
    if(risultato==1 || risultato!=stato-1)
        return giocatore;
    
    return mossa(risultato,giocatore);
}
