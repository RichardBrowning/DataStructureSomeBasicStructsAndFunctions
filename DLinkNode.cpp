#include <stdio.h>
#include <stdlib.h>
#include "iostream"

typedef int Elemtype;

typedef struct DNode
{
    Elemtype data;
    struct DNode *prior;
    struct DNode *next;
}DLinkList;

void CreateListF(DLinkList *&L, ELemType a[], int n)
{
    DLinkList *s;
    
    L=(DLinkList *)malloc(sizeof(DLinkList);
    L->prior=L->next=NULL;
    
    for(int i=0; i<n;i++)
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));
        s->data=a[i];
        s->next=L->next;
        if(L->next!=NULL)
            L->next->prior=s;
        L->next=s;
        s->prior=L;
    }
}

void CreateListR(DLinkList *&L, ElemType a[], int n)
{
    DLinkList *s, *r;
    L=(DLinkList *)malloc(sizeof(DLinkList));
    r=L;
    
    for(int i = 0; i<n; i++)
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));
        s->data=a[i];
        r->next=s; s->prior=r;//
        r=s;
    }
    r->next=NULL;
}

void ListInsert(DLinkList *&L, int i, ElemType E)
{
    int j = 0;
    DLinkList *p=L, *s;
    while(i<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        reurn false;
    else
    {
        s=(DLinkList *)malloc(sizeof(DLinkList));
        s->data=e;
        s->next=p->next;
        if(p->next != NULL)
            p-next->prior=s;
        s->prior = p; p->next = s;
        return true;
    }
}

void Reverse(DLinkList *&L)
{
    DLinkList *p = L->next, *q;
    L->next = NULL;
    while(p!=NULL)
    {
        q=p->next;
        p->next=L->next;
        if(L->next!=NULL)
            L->next->prior=p;
        L->next=p;
        p->prior=L;
        p=q;
    }
}