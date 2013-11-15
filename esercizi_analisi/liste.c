#include <stdio.h>
#include <stdlib.h>

typedef struct node {int data; struct node* next;} node;


int s(int n)
{
    if (n==0) return 1; else return 0;
}

node* h(int i)
{
    node* n=malloc(sizeof(node));
    n->data=i; n->next=NULL;
    return n;
}

void f(node* l, node* n)
{
    if (l->next==NULL)
        l->next=n;
    else f(l->next, n);
}

node* c(node* l, int i)
{
    if (i==0) return l;
    if (l==NULL) return NULL;
    return c(l->next, i-1);
}

void k(node* l, int n)
{
    int i;
    for (i=n;c(l,i)!=NULL;i+=n)
        c(l,i)->data=s(c(l,i)->data);
}

int main()
{
    node *n=h(0);
    int i;
    for (i=0;i<10;i++)
        f(n,h(0));
    for (i=1;i<10;i++)
        k(n,i);
    for (i=1;i<10;i++)
        printf ("%i\t ",c(n,i)->data);
    printf ("\n");
}

