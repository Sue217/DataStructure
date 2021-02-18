//基于带头节点的单链表
#include<stdio.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;
//按位查找，返回第i个元素
LNode * GetElem(Linklist L,int i)
{
    LNode *p;
    if(i < 0)return NULL;//此处若i=0表示头节点,在下段j<i不成立,一样会return p
    p = L;
    for(int j=0;j<i && p!=NULL;j++)p = p->next;//若i值不合法,返回NULL,使代码更有健壮性
    return p;
}
//按值查找，返回数据域=e节点
LNode * LocataElem(Linklist L,int e)
{
    LNode *p = L->next;
    while (p!=NULL && p->data!=e)p = p->next;
    return p;
}