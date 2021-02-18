#include<stdio.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;
//有头节点
int Length(Linklist L)
{
    LNode *p = L;
    int len;
    for(len=0;p->next!=NULL;p=p->next)len++;
    return len;
}
/*无头节点
int Length(Linklist L)
{
    LNode *p = L;
    if(p->next == NULL)return NULL;
    int len;
    for(len=1;p->next!=NULL;p=p->next)len++;
    return len;
}
*/