/*带头节点(一般):
L->Head->a1->a2->a3->a4->NULL
^p ->
可见此时i最大为5*/
/*不带头节点:
L->a1->a2->a3->a4->a5->NULL
^p ->
需添加在头节点插入的情况*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;
//ListInsert(&L,i,e) 在第i个位置插入值为e
//有头节点的插入操作
bool ListInsert(Linklist &L,int i,int e)
{
    if(i < 1)return false;
    /*如果无头节点加上:
    if(i == 1)
    LNode *s;
    LNode *s= (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L;
    L = s;
    return true;*/
    LNode *p;
    p = L;
    for(int j=0;p!=NULL && j<i-1;j++)p = p->next;//如果无头节点j的初始值为1
    if(p == NULL)return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//封装函数后插操作 - 在p节点之后插入e
bool InsertNextNode(Linklist &L,int e)
{
    LNode *p;
    if(p == NULL)return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)return false;//分配节点失败
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//指定节点的前插操作-在p节点之前插入e O(1)
//x->y x->[]->y e->[x]->y copy x's data
bool InsertPriorNode(Linklist &L,int e)
{
    LNode *p;
    if(p == NULL)return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;//elements in p cover e
    return true;
}
/*前插操作(一般)
bool InsertPriorNode(Lnode *p,LNode *s)
{
    if(p==NULL||s==NULL)return false;
    s->next = p->next;
    p->next = s;
    Elemtype temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}*/