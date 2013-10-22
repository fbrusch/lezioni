Riprendiamo dall'algoritmo di Euclide per il calcolo del MCD tra due numeri.
Proviamo ad esprimerlo ricorsivamente.

Inizialmente possiamo esprimere la soluzione in questo modo, mischiando
linguaggio C e linguaggio naturale, nel modo che ci è più comodo per "chiarirci
le idee": 
```C
    int MCD(int a, int b)
    {
        if (a==b) 
            return a;    
        else
            return il massimo tra a e b meno il minimo tra a e b
    }
```

Ovviamente questa funzione non è definita in modo sintatticamente corretto.
Il misto di linguaggio formale e informale che si usa durante la risoluzione di
un problema, per chiarirsi le idee, o per formalizzare parti di soluzione, è
spesso chiamato _pseudocodice_. Spesso si parte da una soluzione espressa in
pseudocodice, e man mano la si trasforma fino ad ottenere del codice scritto
completamente nel linguaggio formale che ci interessa.
In questo caso, la parte che deve essere "formalizzata" è l'argomento del
`return` del ramo else. La formalizzazione è concettualmente molto semplice, ma
è interessante notare come possa essere fatta in modi diversi. Cogliamo
l'occasione per valutare pro e contro di diverse alternative, e per introdurre
una nuova amica, che unisce il mondo delle _espressioni intere_ con quello delle
_espressioni booleane_.

#### Prima soluzione: il sentiero dei nidi di `if`
```C
    int MCD(int a, int b)
    {
        if (a==b)
            return a;
        else
            if (a>b)
                return MCD(a-b,b);
            else
                return MCD(b-a,a);
    }
```

#### Seconda soluzione: neologismi FTW
```C
    int max(int a, int b)
    {
        if (a>b) return a;
        return b;    
    }

    int min(int a, int b)
    {
        if (a>b) return b;
        return a;    
    }

    int MCD(int a, int b)
    {
        if (a==b)
            return a;
        else
            return MCD(max(a,b)-min(a,b),min(a,b));    
    }
```
#### Terza soluzione: esprimiamoci, facendoci condizionare
```C
    int max(int a, int b)
    {
        if (a==b)
            return a;
        else
            return a>b ? MCD(a-b,b) : MCD(b-a,a)
```
In questa terza soluzione troviamo una forma nuova:

```C 
    x ? y : z
```

Questa forma si chiama _espressione condizionale_, e funziona così:
`x` è un'espressione booleana, che dunque può essere vera o falsa.
Per valutare l'espressione globale, prima viene valutata `x`: se `x` è
vera, allora il valore dell'espressione è quello di `y`, altrimenti è quello 
di `z`.

Quale delle tre soluzioni preferiamo?
[discussione su pro e contro...]

### Euclide Umanizzato

La funzione `MCD` che abbiamo scritto sopra è pane per i denti del nostro 
esecutore `C`. Ora immaginiamo una situazione drammatica: non abbiamo un
calcolatore, e dobbiamo comunque calcolare il MCD di due numeri. (D'altra parte,
quando Euclide ha _inventato_ (o _scoperto_? o _progettato_?) il suo
_algoritmo_, gli esecutori che aveva in mente probabilmente non erano i
calcolatori elettronici). Proviamo allora ad eseguire l'algoritmo su un paio di
numeri, senza usare il calcolatore. Avendo a disposizione carta e penna,
probabilmente quello che faremmo sarebbe riformulare il problema in questi
termini:

1. Scrivi i due numeri `a` e `b` di cui vuoi calcolare il MCD su un foglio. (Es:
a:69, b:92)
2. Se `a` è uguale a `b`, il MCD è il valore di `a`, e _hai finito_
3. Prendi il maggiore tra `a` e `b`, e _cambia il suo valore_ con la differenza
dei valori tra il maggiore e il minore. (Es, dopo la prima esecuzione di questo
passo, i valori delle variabili saranno: `a:69`, `b:23`)
4. Ritorna al passo 2

Come vedete, la formulazione non è ricorsiva. Un certo tipo di ricorsione è una cosa che
riesce bene ai calcolatori, ma molto difficile agli esseri umani (con notevoli
eccezioni: secondo Douglas Hofstadter, la coscienza emergerebbe dalla
possibilità di un sistema di fare riferimento a sé stesso. La cosa è spiegata
nel suo libro [I am a Strange
Loop](http://en.wikipedia.org/wiki/I_Am_a_Strange_Loop) ).

Se eseguissimo l'algoritmo di sopra, un passo al minuto (ce la prendiamo
comoda), ecco come _evolverebbe_ il contenuto del nostro foglio:


 Minuto | Passo | Prossimo Passo | `a`  | `b`
 -------|-------|:---------------|------|------
 1      | 1     |  	2        |  69  |  92
 2      | 2     |  	3	 |  69  |  92
 3      | 3     |  	4	 |  69  |  23
 4      | 4     |  	2	 |  69  |  23
 5      | 2     |  	3	 |  69  |  23
 6      | 3     |  	4	 |  69  |  46
 7      | 4     |  	2	 |  69  |  46
 8      | 2     |  	3	 |  69  |  46
 9      | 3     |  	4	 |  23  |  46
 10     | 4     |  	2	 |  23  |  46
 11     | 2     |  	3	 |  23  |  46
 12     | 3     |  	4	 |  23  |  23
 13     | 4     |  	2	 |  23  |  23
 14     | 2     |  		 |  23  |  23


FINITO!

Questo comportamento è un po' diverso da quello che siamo in grado di far
eseguire al nostro esecutore C, utilizzando gli strumenti visti fino ad ora.
In particolare:
1. non abbiamo niente che equivalga al foglio sul quale annotiamo i valori di
`a` e `b`
2. non sappiamo come far ritornare l'esecuzione ad un punto particolare (il
_salto_ che c'è in 4)

Ebbene, il C non ci lascia soli, e ci offre alcuni strumenti con cui possiamo
esprimere questo tipo di comportamento.

Partiamo subito dal codice:
```C
	int MCD(int a, int b)
	{
	   loop: if (a==b) 
	       	return a;
	   if (a>b)
	       a=a-b;
	   else
	       b=b-a;
	   goto loop;
	
	}
```
Facciamo la conoscenza di due nuovi elementi:

1. l'assegnamento `=`
2. la coppia `<etichetta>:`, `goto <etichetta>`

L'assegnamento assume che in ogni momento l'esecutore tenga a mente un valore associato ad un simbolo.
La possibilità di "saltare" assume che l'esecutore, in ogni momento, tenga a mente quale istruzione deve essere eseguita al prossimo passo.

Esercizi successivi:

1. test di primalità
2. ritornare l'n-simo numero primo
3. dire se un numero ha un amico
4. ritornare l'n-simo numero amicabile

### Enough spaghetti: FOR to the rescue

`goto` è un potente costrutto di controllo del _flusso di esecuzione_, ma nella programmazione moderna è praticamente inutilizzato. Perché? Il dio della computer science Edsger W. Dijkstra arriva addirittura a sostenere una correlazione inversa tra la qualità di un programmatore e il numero di istruzioni `goto` che dissemina nei programmi.
Prendiamo ad esempio la seguente funzione, che somma i numeri da 1 a `n`:
```C
	int somma(int n)
	{
		int i,s;
		i=1;
		s=0;
		loop: if (!(i<n)) goto exit;
		s=s+i;
		i=i+1;
		goto loop;
		exit: return s;
	}
```
Che cosa fa il codice sopra?

1. `int i` dichiara la variabile `i`
2. `i=2` assegna ad `i` il valore inizale 2 (azione alla quale tecnicamente ci si riferisce con _inizializzare_)
3. `s=0` assegna a s il valore iniziale 0
4. `loop: if (!(i<n)) goto exit` controlla che sia soddisfatta la condizione `i<n`. In caso contrario, salta all'etichetta `exit`
5. `s=s+i` _incrementa_ il valore di `s` del valore di `i` (a volte ci si riferisce alla cosa dicendo che si _accumula_ i in s)
6. `i=i+1` incrementa `i` di 1
7. _salta_ a `loop`

Proviamo a vedere come varia il valore delle variabili durante la valutazione della funzione con parametro `3`:

| Minuto | Passo | i  |  s |
|--------|-------|----|----|
|  1 | 1 |  0 |  0 |
|  2 | 2 |  1 |  0 |
|  3 | 3 |  1 |  0 |
|  4 | 4 |  1 |  0 |
|  5 | 5 |  1 |  1 |
|  6 | 6 |  2 |  1 |
|  7 | 7 |  2 |  1 |
|  8 | 5 |  2 |  3 |
|  9 | 6 |  3 |  3 |
| 10 | 7 |  3 |  3 |
| 11 | 5 |  3 |  6 |
| 12 | 6 |  4 |  6 |
| 13 | 7 | ND | ND |

Come possiamo descrivere `semplicemente` quello che succede? Beh, in italiano,
un modo potrebbe essere questo:

_conta per `i` che va da 1 a 3. Ad ogni giro, aggiungi accumula il valore di `i`
in `s`._

Ora, questo è un modo _comprensibile_ di descrivere quello che succede quando
viene eseguita la nostra funzione.

Consideriamo ora la seguente funzione, che testa la primalità di un numero:

```C
	int isprimo(int n)
	{
		int i;
		i=2;
		loop: if (!(i<n)) goto exit;
		if (n%i==0) return 0;
		i=i+1;
		goto loop;
		exit: return 1;
	}
```

Anche qui, dopo un'attenta e faticosa analisi, potremmo descrivere il codice
con la seguente sequenza di _imperativi_:

    (conta) per `i` che va da 2 a n-1:
        se `i` divide `n`, allora `return 0`
    se hai finito di contare, `return 1`

Perché farsi tutto questo male, ed esprimere una cosa così semplice con un tale
intrico di etichette e salti?
La stessa domanda se la sono fatta Brian Kernighan e Dennis Ritchie, i padri
del linguaggio C. E la risposta è stata un costrutto che consente di esprimere
in maniera sintetica l'imperativo _conta!_.

Il costrutto in questione si chiama `for`, e lo vediamo subito in azione nelle
due funzioni `somma` e `isprimo`:

```C
    int somma(int n)
    {
        int i,s;
        s=0;
        for(i=1;i<=n;i++) //La scrittura 'i++' è equivalente a 'i = i + 1'
        {
            s=s+i;
        }
        return s;
    }

	int isprimo(int n)
	{
		int i;
		for (i=2;i<n;i++)
			if (n%i==0) return 0;
		return 1;
	}
```

C'è una regola che _traduce_ un ciclo for in una serie di etichette e di
istruzioni di salto. La regola possiamo descriverla così:
```C
	for (a;b;c) 
		d;
```

Diventa:

```C
	a;
	loop: if (!b) goto exit;
	d;
	c;
	goto loop;
	exit:
```

Esercizi:

1. scrivere una funzione che, dato n, somma tutti i numeri _pari_ tra 1 e n;
2. scrivere una funzione che verifica se un numero `n` è primo, calcolando il
minor numero possibile di operazioni di modulo `%`.

##Soluzioni esercizi:
1.
int sommapari(int n)
{	
	int i, int s;
	for (i=2;i<=n;i=i+2)
		{ s=s+i};
	return s;
}

2.
int numeroprimo(int n)
{
	for (i=2;i<n;i++)
		{
			if (n%i==0)
				return 0;
		}
	return 1;
}
 
