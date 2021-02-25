#include<stdio.h>
#include<stdlib.h>
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}LinkNode;//链式节点
typedef struct
{
    LinkNode *front,*rear;
}LinkQueue;//链式队列
//初始化队列
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}
//判空
bool IfEmpty(LinkQueue &Q)
{
    if(Q.front == Q.rear)//OR:Q.front->==NULL;
        return true;
        return false;
}
//入队
void EnQueue(LinkQueue &Q,int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}
//出队
bool DeQueue(LinkQueue &Q,int &x)
{
    if(Q.front == Q.rear)return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p)Q.rear = Q.front;//最后一个节点出队
    free(p);
    return true;
}