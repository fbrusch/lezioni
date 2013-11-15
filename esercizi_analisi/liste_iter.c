#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    char dato;
    struct nodo *prossimo;
};

struct nodo n;

int len(struct nodo *l)
{
    struct nodo *i;
    int lunghezza;
    for (lunghezza=0,i=l;i!=NULL;i=i->prossimo,lunghezza++)
        ;
    return lunghezza;
}

void append(struct nodo* l, char c)
{
    struct nodo* i;

    for (i=l;i->prossimo!=NULL;i=i->prossimo)
        ;
    i->prossimo=malloc(sizeof(struct nodo));
    i->prossimo->dato=c;
    i->prossimo->prossimo=NULL;
}

void stampa_lista(struct nodo *l)
{
    struct nodo* i;
    for (i=l;i!=NULL;i=i->prossimo)
        printf ("%c",i->dato);
    printf ("\n");
}

struct nodo *precedente(struct nodo *l,
        struct nodo *corrente)
{
    struct nodo *i;
    // printf ("chiamato: precedente\n");
    for (i=l;i->prossimo!=corrente;i=i->prossimo)
    {
    //    printf ("provo ad andare indietro\n");
    }
    return i;
}

void stampa_al_contrario(struct nodo *l)
{
    struct nodo *i;

    if (l==NULL)
        return;

    for (i=l;i!=NULL;i=i->prossimo)
        ;
    for (i=precedente(l,i);i!=l;i=precedente(l,i))
        printf("%c",i->dato);

    printf ("%c",i->dato);
}

int main()
{
    struct nodo *l;
    l=malloc(sizeof(struct nodo));
    l->dato='c';
    l->prossimo=NULL;

    append(l,'i');
    append(l,'a');
    append(l,'o');

    printf ("la lista l e' lunga: %i\n",len(l));
    printf ("stampo la lista: ");
    stampa_lista(l);
    stampa_al_contrario(l);
    printf("\n");

    printf ("lunghezza di una lista vuota: %i\n",len(NULL));
    printf ("provo a stampare una lista vuota: ");
    stampa_lista(NULL);
    printf ("provo a stampare una lista vuota, al contrario: ");
    stampa_al_contrario(NULL);

}

