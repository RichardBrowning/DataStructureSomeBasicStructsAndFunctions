#include "stdio.h"
#include "stdlib.h"
#define MaxSize 50

typedef int ElemType;

typedef struct{
  ElemType data[MaxSize];
  int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n)//顺序表指针：通过指针操纵顺序表
{//顺序表指针引用：引用号&：引用指针将型参值返回实参
    int i;//计数器
    L = (SqList *)malloc(sizeof(SqList));//分配空间
    for(i=0;i<n;i++)
        L->data[i]=a[i];//录入数据
    L->length=n;//定义长度
}

void InitList(SqList *&L)
{
    L=(SqList *)malloc(sizeof(SqList));//分配空间
    L->length=0;
}

void DestroyList(SqList *&L)
{
    free(L);//销毁指针
}

bool ListEmpty(SqList *&L)
{
    return(L->length == 0);
}

int ListLength(SqList *L)
{
    return(L->length);
}

void DispList(SqList *L)
{
    int i;
    if(ListEmpty(L)) return;
    for(i=0; i<L->length; i++)
        printf("%d" ,L->data[i]);
    printf("\n");
}

bool GetElem(SqList *&L, ElemType &e, int i)
{
    if(i<1 || i>L->length)
        return false;//表外无意义
    e=L->data[i-1];//e在表中对应的下标是i-1
        return true;
}//

int LocateElem(SqList *&L, ElemType e)
{
    int i=0;
    while(i<L->length && L->data[i]!=e)
    {
        i++;
    }
    if(i>=L->length) return 0;
    else return i+1;//i+1号元素角标i
}

bool ListInsert(SqList *&L, ElemType e, int i)
{
    int j;
    if(i<1 || i>L->length+1)
        return false;
    i--;

    for(j=L->length; j>i;j--)
        L->data[j] = L->data[j-1];
    L->data[i] = e;

    L->length++;
    return true;
}
