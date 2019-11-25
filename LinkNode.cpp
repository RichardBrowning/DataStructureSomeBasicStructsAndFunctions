#include "stdio.h"
#include "stdlib.h"
#include "iostream"

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkNode;

void CreateList1(LinkNode *&L, ElemType a[], int n)//节点顺序与逻辑顺序相反
{
    LinkNode *s;
    int i;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;//置空
    for (i=0; i<n; i++) {
        s=(LinkNode *)malloc(sizeof(LinkNode));//分配节点空间
        s->data = a[i];//创建数据节点
        s->next=L->next;//开始节点之前
        L->next=s;//头节点之后
    }
}

void CreateList2(LinkNode *&L, ElemType a[], int n)//节点顺序与逻辑顺序相同
{
    LinkNode *s, *r;//’插入节点‘与r
    int i;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    r = L;//开始时指向头节点
    for (i=0; i<n; i++) {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];//创建数据节点
        r->next = s;//*s插入*r后，s链接在链尾
        r = s;//r指向给s
    }
    r->next = NULL;//r的下一个，s的下一个，置空
}

void InitList(LinkNode *L)
{
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
}

void DestroyList(LinkNode *L)
{
    LinkNode *pre = L, *p = L->next;//pre指向头节点
    while (p!=NULL) { //表未结束
        free(pre);
        pre = p;//p赋给pre
        p = pre->next;//p向后移
    }
    free(pre);
}

bool ListEmpty(LinkNode *L)
{
    return (L->next == NULL);
}

int ListLength(LinkNode *L)
{
    int n = 0;
    LinkNode *p=L;
    while(p->next != NULL)
    {
        p=p->next;
        n++;
    }
    return n;
}

void DispList(LinkNode *L)
{
    LinkNode *p=L;//p指向开始节点
    while (p!=NULL) { //p不为NULL，输出*p节点的数据
        std::cout<<p->data;
        p=p->next;
    }
    std::cout<<std::endl;
}

bool GetElem(LinkNode *L, int i, ElemType &e)//找第i个节点
{
    int j=0;
    LinkNode *p=L;

    while (p != NULL && i>j) {
        j++;
        p=p->next;
    }

    if(p==NULL)//不存在
        return false;
    else//i=j存在
    {
        e = p->data;
        return true;
    }
}

int LocateElem(LinkNode *L, ElemType e)
{
    int i=1;//从开始节点开始计
    LinkNode *p = L->next; //指向开始节点

    while (p!=NULL && p->data!=e) {
        p=p->next;
        i++;
    }

    if(p==NULL) return false;
    else return e;
}

bool ListInsert(LinkNode *L, int i, ElemType e)
{
    int j=0;
    LinkNode *p = L, *s;

    while(j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }

    if(p == NULL) return false;
    else{//链表插入方式重点
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data = e;

        s->next=p->next;//s插入在post之前
        p->next=s;//s插入在p之后
        return true;
    }
}

bool ListDelete(LinkNode *L, int i, ElemType &e)
{
    int j=0;
    LinkNode *p=L, *q;

    while(j<i-1 && p!=NULL)
    {
        j++;
        p = p->next;
    }

    if(p==NULL)
        return false;
    else
    {
        q = p->next;
        if(q == NULL)
            return false;
        e=q->data;
        p->next=q->next;
        free(q);
        return true;
    }
}
