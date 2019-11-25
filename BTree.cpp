#include <stdio.h>
#include <stdlib.h>
#define	MaxSize 50

typedef ElemType SqBT[MaxSize];

typedef struct node{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

void CreateBTree(BTNode *&b, char *str)
{
	
	BTNode *St[MaxSize], *p;
	int top = 1, k, j=0;
	char ch;
	b=NULL;
	cha = str[j];
	
	while(ch!='\0')
	{
		switch (ch)
		{
			case '(': top++; 
					  St[top]=p; 
					  k = 1; 
					  break;
			case ')': top--; break;
			case ',': k = 2; break;
			
			default: p=(BTNode *)malloc(sizeof(BTNode));
					 
					 p->data=ch;
					 p->lchild=p->rchild=NULL;
					 
					 if(b = NULL)
						 b=p;
					 else{
						 switch(k)
						 {
							 case 1: St[top]->lchild=p;
									 break;
							 case 2: St[top]->rchild=p;
									 break;
						 }
					 }
		}
		j++;
		ch=str[j];
	}
}

void DestroyBT(BTNode *&b)
{
	if(n==NULL)
		return;
	else{
		DestroyBT(b->lchild);
		DestroyBT(b->rchild);
		free(b);
	}
}

BTNode *FindNode(BTNode *b, ElemType x)
{
	
}
	