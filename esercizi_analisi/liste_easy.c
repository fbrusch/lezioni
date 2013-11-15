#include <stdio.h>
#include <stdlib.h>

typedef struct node {int data; struct node* next;} node;


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

void p(node* l)
{
    if (l==NULL)
        return;
    p(l->next);
    printf ("%i\t",l->data);
}

int main()
{
    int i;
    node* l=h(0);
    for (i=1;i<10;i++)
        f(l,h(i*i));
    p(l);
    printf ("\n");
}

