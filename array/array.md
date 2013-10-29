# Aggiungiamo Dimensioni

Esempio: dobbiamo rappresentare il campo di gioco del tris
(per avere un'idea del perché potrebbe servire. http://www.youtube.com/watch?v=F7qOV8xonfY). 
Come facciamo? Usiamo 9 variabili?
```c
int x00,x01,x02
int x10,x11,x12
int x20,x21,x22
```

Ok, ora vogliamo vedere se c'è un tris di `1` sulla prima riga.

Funzione:

```c
    int uno_prima_riga(int x00, intx01, int x02....)
    {
        if (x00==1 && x01==1 && x02==1) return 1;    
    }
```

E se volessimo generalizzare, scrivendo una funzione che controlla se nella
n-sima riga il giocatore `p` ha fatto tris?

```c
    int tris_in_riga(int riga, int p, int x00, int x01, int x02...)
    {
        if (riga == 0)
            if (x00 == p && x01 == p && x02 == p) return 1;
        else if (riga == 1)
                if (x10 == p && x11 == p && x12 == p) return 1;
        else if (riga == 2)
                if (x20 == p) && x21 == p && x22 == p) return 1;
        return 0;
    }
```

E se volessimo estendere alle colonne? E alle diagonali? E se volessimo variare
l'_ordine_ del gioco, passando per esempio a _forza 4_?

Se la soluzione sopra vi piace, se non vi sentite profondamente frustrati nello
scriverla, lasciate perdere con l'informatica.
Fateci caso: la quantità di codice che dobbiamo scrivere per gestire il problema
_aumenta con le dimensioni dei dati che dobbiamo gestire_. Esiste un'espressione
tecnica per esprimere questa dipendenza: la soluzione *non "scala"*. Immaginate
se Google avesse avuto lo stesso problema: dover scrivere il doppio del codice,
al raddoppiare delle pagine da indicizzare.

Nel cercare di risolvere i nostri problemi, siamo sempre alle ricerca di soluzioni
che _scalino_, cioè che funzionino per una maggior quantità di dati senza
richiedere ulteriori interventi.
Se riusciamo in questa impresa, possiamo fare una cosa notevole:
1. nello studiare il problema, possiamo concentrarci su una versione semplice
(per esempio, con pochi dati)
2. una volta che abbiamo risolto il problema semplice con una soluzione
generale, i problemi più complessi saranno risolti automaticamente
3. non fidatevi del 2., perché ci sono notevoli eccezioni...

Torniamo al nostro problema del tris. La prima cosa che ci secca è dover
dichiarare tante variabili intere con nomi diversi:

```c
    ...
    int x00, x01, x02, x10, x11, x12
```

Introduciamo gli `array`: il C ci permette di dichiarare `n` variabili
utilizzando un costrutto particolare:

```c
    int x[3];
```

Dopo questa dichiarazione, abbiamo a disposizione 3 variabili intere, alle quali
ci possiamo riferire con `x[0]`, `x[1]`, `x[2]`:

```c
    [...]
    x[0]=0;
    x[1]=1;
    x[2]=0;
    somma=x[0]+x[1]+x[2]
```

L'operatore `[...]` alla fine del nome della variabile dice che stiamo
dichiarando 10 variabili intere. L'insieme delle 10 variabili dichiarate in
questo modo si chiama `array`, e l'operatore `[]` si chiama _costruttore_
dell'array. 
 
Ma a noi servirebbe qualcosa con... una dimensione in più! Nessun problema,
possiamo riapplicare l'operatore di costruzione: 

```c
    int x[3][3];
```

Dopo questa dichiarazione, avremo a disposizione 9 variabili alle quali ci
potremo riferire esoticamente con:

```c
    [...]
    x[0][0] = 0;
    x[1][0] = 10;
    x[2][0] = x[1][1]*x[0][1];
    [...]
```
 
Ok, per ora abbiamo risolto il problema della dichiarazione delle variabili che
ci servono. Notare che possiamo anche passare i nostri array come parametri a
funzioni:

```c
    int somma(int x[2])
    {
        return x[0]+x[1];
    }

    int f()
    {
        int x[2];
        x[0]=1;
        x[1]=2;
        return somma(x);
    }
``` 

La dichiarazione però è un problema minore: se dobbiamo riferirci ad ogni 
componente dell'array con l'espressione _costante_ `x[0][0]`, non abbiamo
fatto un grande passo in avanti.
E qui viene il bello: in realtà il valore dell'indice potrà essere 
un'espressione intera, che verrà valutata nel momento in cui l'esecutore accederà
alla variabile:

```c
    int get_prime(int i)
    {
      int x[10]={2,3,5,7,11,13,17,19,23,29};
      return x[i-1];
    }
```

[....]

Esercizio: scrivere un programma che inizializza uno schema di tris e 
controlla che il giocatore `1` abbia fatto tris su una riga.
    }
