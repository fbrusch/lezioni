### Le stringhe

Le stringhe sono la struttura dati con la quale, nella maggior
parte dei linguaggi di programmazione, rappresentiamo il testo.

In C, le stringhe sono _array_ di `char`, con una particolarità:
l'ultimo elemento di una stringa è *sempre* un carattere
speciale, detto *terminatore*, che nel codice sorgente si
rappresenta con `'\0'`.
Seppure "ante litteram", abbiamo già avuto il piacere di
conoscere le stringhe, in C: il primo argomento della `printf` è
difatti sempre una stringa:

    printf("ciao a tutti");

Ebbene, se è vero che una stringa è un array di `char`, dovremmo
poter scrivere:

    int main()
    {
        char msg[]="ciao a tutti";
        printf(msg);
    }

Inoltre, se è vero che una stringa è un array di `char`
terminato dal carattere speciale `'\0'`, dovremmo poter definire
`msg` anche così:

    int main()
    {
        char msg[]={'c','i','a','o',
        'a',' ','t','u','t','t','i','\0';
        
        printf(msg);
    }

Perché utilizzare una struttura di questo tipo, cioè un array
terminato da un carattere speciale? Perché questo offre molta
più flessibilità. Ad esempio, immaginiamo di voler "troncare"
`msg` alla prima parola: è sufficiente andare piazzare un `'\0'`
al posto del primo carattere che vorremmo escluso:

    msg[4] = '\0';
    printf(msg);

Bella idea per un esercizio: scriviamo una funzione `tronca`
che, presa in ingresso una stringa `str`, la modifichi in modo
da troncarla alla prima parola.

interessante è che la loro lunghezza non è variata! I caratteri
dopo la prima parola sono ancora tutti lì, semplicemente quando
`printf` li stampa non si spinga mai oltre il carattere
terminatore!
Per verificare, facciamo questo semplice esperimento:

    char msg[] = "ciao a tutti";
    printf("%s",msg);

    // tronchiamo

    char[4]='\0';

    printf("%s",msg);

    // ripristiniamo lo spazio

    char[4]=' ';

    printf("%s",msg);

Il sistema del terminatore non è l'unico che consenta questa
flessibilità: un altro modo tipico consiste nel rappresentare
una stringa con un array di caratteri insieme ad un numero
intero che dica quanti sono i caratteri validi. 


Forti di queste nuove conoscenze, possiamo applicarci a qualche
    esercizio: 

1. Scrivere una funzione `stringLen` che, ricevuta in ingresso
una stringa, ritorni la sua lunghezza (il numero di caratteri in
essa presenti).
2. Scrivere una funzione `strEq` che, ricevute in ingresso due stringhe,
ritorni `1` se le stringhe sono uguali, `0` altrimenti.
2. Scrivere una funzione `contaChar` che, ricevuti in ingresso
una stringa `str` e un carattere `c`, ritorni il numero delle
occorrenze di `c`in `str`.
3. Scrivere una funzione `subStr` che, ricevute in ingresso due
stringhe `str1` e `str2`, dica se la prima è una sottostringa
della seconda.
4. Scrivere un funzione `palindroma` che, data una stringa, dica
se è palindroma (cioè se si legge allo stesso modo da sinistra
verso destra o viceversa).
5. Scrivere una funzion `toInt` che, data una stringa di *cifre decimali*,
ritorni l'intero rappresentato (es: `toInt("10") deve ritornare l'intero 10)

Un'operazione che possiamo spesso voler fare, con le stringhe, è
*concatenarle*: scriviamo un funzione `append` che, ricevute in
ingresso le stringhe `str1` e `str2`, *aggiunga* `str2` in fondo
a `str1`.

