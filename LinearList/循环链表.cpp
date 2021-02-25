//循环链表对于操作链表首尾方便O(1)
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;
typedef struct DLNode
{
    int data;
    struct DLNode *prior,*next;
}DLNode,*DLinklist;
//初始化循环单链表
bool InitList(Linklist &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)return false;
    L->next = L;
    return true;
}
bool IfEmpty(Linklist L)
{
    if(L->next == L)
        return true;
        return false;
}
//初始化循环双链表
bool InitDLinklist(DLinklist &L)
{
    L = (DLNode *)malloc(sizeof(DLNode));
    if(L == NULL)return false;
    L->prior = L;
    L->next = L;
    return true;
}
bool IfDEmpty(DLinklist L)
{
    if(L->next == L)
        return true;
        return false;
}
//循环双链表插入
bool InsertNextNode(DLNode *p,DLNode *s)
{
    s->next = p->next;
    p->next->prior = s;//注与普通双链表区别
    s->prior = p;
    p->next = s;
}
//循环双链表删除
bool DeleteNextNode(DLNode *p)
{
    DLNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;//注与普通双链表区别
    free(q);
}