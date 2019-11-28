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

BTNode FindNode(BTNode *b, ElemType x)
{
	BTNode *p;
	if(b->data==x)
		return b;
	else
	{
		p=FindNode(b->lchild, x);
		if(p!=NULL)
			return p;
		else
			FindNode(rchild, x);
	}
}

BTNode LchildNode(BTNode *p)
	return p->lchild;
BTNode RchildNode(BTNode *p)
	return p->rchild;
	
int BTNodeDepth(BTNode *b)
{
	int lchilddepth, rchilddepth;
	if(b==NULL)
		return (0);
	else
	{
		lchilddepth=BTNodeDepth(b->lchild);
		rchilddepth=BTNodeDepth(b->rchild);
		
		return(lchilddepth>rchilddepth)?(lchilddepth+1):(rchilddepth+1);
	}
}

void DispBTree(BTNode *b)
{
	if(b!=NULL)
	{
		printf("%c",b->data);
		if(b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");
			DispNTree(b->lchild);
			if(b->rchild!=NULL) printf(",");
			DispNTree(b->rchild);
			printf(")");
		}
	}
}