### Input/Output e Files

Fino ad ora abbiamo considerato, come modello di esecuzione dei programmi, la valuazione di *funzioni*: 
          
          +---------+ 
          |  def f: | 
 x ------>|   [...] +-----> f(x)
          |         |
          +---------+

Noi programmiamo (in python, in C) il calcolatore per calcolare *f*, dopodiché
chiediamo di valutare *f* per i valori per i quali ci interessa farlo. 

    def sqr(x):
        return x*x

    sqr(2)

Riflettiamo un momento: il fatto di calcolare *sqr(x)*, ha in qualche modo
cambiato il mondo?
Potremmo rispondere: sì, certo. Prima non sapevamo che il quadrato di 2 fosse 4,
e ora invece lo sappiamo! Secondo questo modello, però, una funzione che non
produca un risultato ignoto non cambia il mondo. D'altra parte, sappiamo anche
che i computer agiscono sul mondo costantemente (esempi?)

[aggiungere lista di esempi che si allungano a volontà]

Cosa manca al nostro modello di computazione? Di cosa non abbiamo tenuto conto?
Prima di tutto, si potrebbe obiettare che il calcolo di f potrebbe richiedere
l'interazione con la memoria. Per calcolare *f* potrebbe essere necessario
interagire con la memoria, per salvare/leggere qualche variabile, memorizzare
qualche lista, etc. 

Una rappresentazione più accurata di cosa succede valutando una funzione è
quindi:

          +-------------+
          |             |
 -------->|    CPU      +---------> 
          |             |           
          +--------+----+           
              ^    |                
              |    v                
          +---+---------+           
          |             |           
          |   MEMORIA   |           
          |             |           
          +-------------+           


Quindi la valutazione della funzione qualche effetto ce l'ha! Cambia il
contenuto della memoria!
E' quello che succede in un pezzo di codice come questo:

    void f(int* a)
    {
        a++;
    }

    void g()
    {
        int b=1;
        f(&b);
        
        /* l'esecuzione di f(&b) lascia una traccia: il dato contenuto
        in memoria all'indirizzo della variabile b viene modificato */
        
        return b;
    }


Però: c'è sempre una funzione che viene chiamata per prima. Quando viene
chiamata questa, la memoria deve essere idealmente libera.
Esecuzione di una funzione, partendo da tanta memoria idealmente libera =
processo.
Esempi di processo: le applicazioni che fate girare.

Problema: se un'applicazione quando comincia ha la memoria "libera" (sinonimi:
*resettata*, *inizializzata*), come fa a ricordarsi delle sue "vite precedenti"
(i documenti che avete editato, le preferenze, etc?)

Soluzione: consentiamo alla funzione di cambiare lo stato del mondo!

Una funzione che attinga allo stato del mondo, oltre che al valore di ingresso,
per calcolare il suo valore, si dice che faccia INPUT.

Una funzione che, oltre a produrre un risultato, cambi lo stato del mondo, si
dice che faccia OUTPUT.

Ecco che la nostra rappresentazione di un calcolatore in azione cambia ancora:

```
       +------------------+
       |                  |
       |    MONDO         |
       |                  |
       |                  |
       +------------------+
              ^    |
            O |    | I
              |    v
          +---+---------+
          |             |
 -------->|    CPU      +---------> 
          |             |           
          +--------+----+           
              ^    |                
              |    v                
          +---+---------+           
          |             |           
          |   MEMORIA   |           
          |             |           
          +-------------+           
```

Consideriamo un particolare esempio di I/O: l'interazione con sistemi di
memorizzazione di massa.
Dicevamo: come fa il nostro processo appena nato a sapere quali sono le
preferenze che abbiamo impostato? O i documenti che abbiamo creato/modificato
l'ultima volta che abbiamo usato la nostra applicazione?

[
    Introdurre le seguenti astrazioni:
        *) file: un nastro che contiene una sequenza di parole (byte)
        *) file-system: un sistema di cartelle/nomi che consente di riferirsi a
        files: crearli, leggerli, scriverli
        *) API: un'insieme di funzioni, invocabili in un certo linguaggio, che
        consentono di interagire con i files:
            - fopen
            - fwrite
            - fread
            - fseek
            - ftell
            - fclose
]

Ok. Via con gli esempi:

1. scrivere una funzione che crea un file e ci scrive dentro la rappresentazione
del numero intero ricevuto in ingresso (file_scrivi_1)
2. scrivere una funzione che apre un file, legge il contenuto, lo interpreta
come un numero intero e lo restituisce (file_leggi_1)
3. scrivere una funzione che crea un file e ci scrive la rappresentazione
binaria dei numeri da 1 a 10 (file_scrivi_2)
4. scrivere una funzione che apre un file che contiene 10 numeri, e sostituisce
l'xsimo con y (file_sostituisci_1)
5. scrivere una funzione che apre un file, lo interpreta come una sequenza di
numeri interi, e li scrive tutti...
5.5. scrivere una funzione che apre un file di testo (che contiene caratteri da
un byte) e lo stampa
6. scrivere una funzione che apre un file di testo e trasforma tutte le lettere
in maiuscole
7. scrivere una funzione che apre un file di testo e capitalizza solo la prima
lettera di ogni parola

