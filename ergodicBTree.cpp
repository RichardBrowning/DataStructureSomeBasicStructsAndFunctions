##include <stdio.h>
#define	MaxSize 50

typedef ElemType SqBT[MaxSize];

typedef struct node{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

void PreOrder(BTNode *b)
{
	if(b!=NULL){
		printf("%c", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void MidOrder(BTNode *b)
{
	if(b!=NULL){
		MidOrder(b->lchild);
		printf("%c", b->data);
		MidOrder(b->rchild);
	}
}

void PostOrder(BTNode *b)
{
	if(b!=NULL){
		PostOrder(b->lchild);
		printf("%c", b->data);
		PostOrder(b->rchild);
	}
}

/*Bitch Please*/

void LevelOrder(BTNode *b)
{
	BTNode *p;
	BTNode *qu[MaxSize];
	int pre, post;
	
	pre=post=0;
	post++;
	qu[post]=b;
	
	while(pre!=post){
		pre=(pre+1)%MaxSize;
		p=qu[pre];
		printf("%c"; p->data);

		if(p->lchild!=NULL){
			post=(post+1)%MaxSize;
			qu[post]=p->lchild;
		}
		
		(p->rchild!=NULL){
			post=(post+1)%MaxSize;
			qu[post]=p->rchild;
		}
	}
}