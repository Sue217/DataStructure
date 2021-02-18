#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;
//ListDelete(&L,i,&e) 删除第i个节点返回元素的值为e
//有头节点的删除操作
//L->a1->a2->a3->a4     L->a1->a2->a3->a4     L->a1->a2->a4
//       ^p  ^q=p->next          |___|
bool ListDelete(Linklist &L,int i,int &e)
{
    LNode *p;
    if(i < 1)return false;
    for(int j=0;j<i-1 && p!=NULL;j++)p = p->next;
    if(p == NULL || p->next == NULL)return false;//i不合法或第i个位置无元素(i-1节点之后无节点)
    LNode *q = p->next;//令q指向被删除节点i
    e = q->data;//e返回节点i的值
    p->next = q->next;//将*q节点从链中断开
    free(q);
    return true;
}
/*O(1)bug:对于删除最后一个节点不适用
bool DeleteNode(LNode *p)
{
    if(p == NULL)return false;
    LNode *q = p->next;
    p->data = q->data;/p->data = p->next->data;/和后继节点交换数据域
    q = q->next;/p->next = q->next;/将*q从链中断开
    free(q);
    return true;
}
*/