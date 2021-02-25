#include<stdio.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;//LNode *等价于Linklist
//前者强调返回的是一个节点,而后者强调这是一个单链表
bool Initlist(Linklist &L)
{//L会被改变
    L = NULL;//空表,防止脏数据
    return true;
}
/*
bool IfEmpty(Linklist L)//判空函数
{
    if(L == NULL)
        return true;
        return false;
}*/
bool IfEmpty(Linklist L)//判空函数
{
    return (L == NULL);//L->NULL
}
void test()
{
    Linklist L;
    Initlist(L);
    /*Code*/
}