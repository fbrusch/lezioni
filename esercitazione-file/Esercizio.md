[Introdurre fscanf, fprintf, feof]

## Esercizio

Scrivere una funzione `trasforma(char* filename)` che prenda il nome di un file,
e "capitalizzi" tutte le sue parole.

Strategie:

 1. in place: leggo carattere per carattere, e quando mi accorgo di essere sulla
    prima lettera di una parola, capitalizzo (concetto di stato), sovrascrivendo.
    problema: soluzione limitata alle trasformazioni della singola lettera.
    (altri esempi?)
 2. streaming: leggo un file, tengo un certo stato, e scrivo su file. Questa
    strategia consente di generalizzare bene a trasformazioni che variano la
    lunghezza del file (es: sostituisci tutte le 'a' con 'bb');
 3. Leggo in memoria, trasformo, scrivo su disco: posso fare più o meno quello
    che voglio.
    
     
