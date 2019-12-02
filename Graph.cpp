#include <stdio.h>
#define MAX 50

typedef struct ANode
{
    int adjvex;
    struct ANode *nextare;
    InfoType info;
}ArcNode;

typedef struct Vnode
{
    Vertex data;
    ArcNode *firstarc;
}VNode;
    
typedef struct
{
    VNode adjlist[MAX];
    int n,e;
}ALGraph;

