#include <stdio.h> 
#define MaxSize 50

typedef ElemType int;

typedef struct tnode{
	ElemType data;
	struct tnode *bro
	struct tnode *child
}TSBNode;

int TreeHeight(TSBNode *t)
{
	TBSNode *p;
	int h, maxh = 0;
	if(t==NULL)
		return 0;
	else{
		t=p->child;
		while(p!=NULL)
		{
			h=TreeHeight(p);
			if(maxh<h) 
				maxh = h;
			p=p->bro;
		}
		return (maxh+1);
	}
}
