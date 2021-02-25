#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;
bool Initlist(Linklist &L)
{
    L = (LNode *)malloc(sizeof(LNode));//头节点L不存放数据
    if(L == NULL)return false;//内存不足,分配失败
    L->next = NULL;
    return true;
}
void test()
{
    Linklist L;
    Initlist(L);
    /*Code*/
}