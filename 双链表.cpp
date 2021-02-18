#include<stdio.h>
#include<stdlib.h>
typedef struct DLNode
{
    int data;
    struct DLNode *prior,*next;
}DLNode,*DLinklist;
//带头节点双链表初始化
bool InitDLinkList(DLinklist &L)
{
    L = (DLNode *)malloc(sizeof(DLNode));
    if(L == NULL)return false;
    L->next = NULL;
    L->prior = NULL;//头节点的prior永远指向NULL
    return true;
}
//带头节点双链表判空
bool IfEmpty(DLinklist L)
{
    if(L->next == NULL)
        return true;
        return false;
}
//双链表插入
bool InsertNextNode(DLNode *p)
{
    DLNode *s = (DLNode *)malloc(sizeof(DLNode));
    if(p==NULL || s==NULL)return false;
    s->next = p->next;
    if(p->next != NULL)p->next->prior = s;//若p有后继节点
    s->prior = p;
    p->next = s;
    return true;
}
//双链表删除
bool DeleteNextNode(DLNode *p)
{//删除p的后继节点
    if(p == NULL)return false;
    DLNode *q = p->next;
    if(q == NULL)return false;//p无后继
    p->next = q->next;
    if(q->next != NULL)p->next->prior = p;
    free(q);
    return true;
}
//销毁双链表
void DestoryList(DLinklist &L)
{//循环释放各数据节点
    while(L->next != NULL)DeleteNextNode(L);
    free(L);
    L = NULL;//头指针指向NULL
}
//双链表遍历操作O(n)
//注:按位查找i++,按值查找->data
void SearchList(DLinklist L,DLNode *p)
{
    //后向遍历
    while(p != NULL)p = p->next;
    //前向遍历
    while(p != NULL)p = p->prior;
    //前向遍历(跳过头节点)
    while(p->prior != NULL)p = p->prior;
}