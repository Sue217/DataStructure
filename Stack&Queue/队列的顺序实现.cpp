//队列判空:Q.rear == Q.front
//队列判满:(Q.rear+1)%MAXSIZE == Q.front
//队列元素个数:(rear+MAXSIZE-front)%MAXSIZE
#include<stdio.h>
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int front,rear;
}SqQueue;
//入队操作(循环队列)
bool EnQueue(SqQueue &Q,int x)
{
    if((Q.rear+1)%MAXSIZE == Q.front)return false;//队列判满
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MAXSIZE;//取模将存储空间在逻辑上变成环状
    return true;
}
//出队操作(循环队列)
bool DeQueue(SqQueue &Q,int &x)
{
    if(Q.rear == Q.front)return false;//队列判空
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MAXSIZE;
    return true;
}
//查找操作
bool GetQueue(SqQueue Q,int &x)
{
    if(Q.rear == Q.front)return false;//队列判空
    x = Q.data[Q.front];
    return true;
}
//注:上述方法为方案1，在判满时浪费一个存储空间
//方案2引入成员变量size并初始化=0。入队++出队--,判断size?=0为空或size?=MAXSIZE为满即可
//方案3引入成员变量tag并初始化=0。tag=0表示最近进行删除操作tag=1表示最近进行插入操作。
//队满条件:Q.rear=Q.front && tag=1;队空条件:Q.rear=Q.front && tag=0;