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
    Q.front = NULL;
    Q.rear = NULL;
}
//判空
bool IfEmpty(LinkQueue &Q)
{
    if(Q.front == NULL)
        return true;
        return false;
}
void EnQueue(LinkQueue &Q,int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if(Q.front == NULL)//第一个元素入队时要特别处理
    {
        Q.front = s;
        Q.rear = s;
    }
    else
    {
        Q.rear->next = s;
        Q.rear = s;
    }
}
//出队
bool DeQueue(LinkQueue &Q,int &x)
{
    if(Q.front == NULL)return false;
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;
    if(Q.rear == p)
    {
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}