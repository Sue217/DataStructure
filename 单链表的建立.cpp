/*单链表建立使用方法:
Initlist(&L)
while{
    Elemtype e;
    InsertNextNode(L,e);
}*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*Linklist;
bool InsertNextNode(LNode *p,int e)
{
    if(p == NULL)return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//尾插法建立单链表
//在尾节点后插入新元素
Linklist ListTailInsert(Linklist &L)
{
    int e;
    L = (Linklist)malloc(sizeof(LNode));//建立头节点,初始化空表
    LNode *p = L;//p为表尾指针
    scanf("%d",&e);
    while(e != 9999)//输入9999表示结束
    {//在p后插入s
        LNode *s;
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = p->next;
        p = s;//永远保持p指向最后一个节点
        scanf("%d",&e);
    }
    p->next = NULL;//尾节点指针置空
    return L;
}
//头插法建立单链表
//在头节点后插入新元素
Linklist ListHeadInsert(Linklist &L)
{
    int e;
    L = (Linklist)malloc(sizeof(LNode));//建立头节点,初始化空表
    L->next = NULL;//初始化为空表，防止脏数据!!!
    scanf("%d",&e);
    while(e != 9999)//输入9999表示结束
    {//在p后插入s
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L->next;
        L->next = s;
        scanf("%d",&e);
    }
    return L;
}
/*重要应用:单链表逆置
Linklist ListInversion(Linklist &L)
{
    Initlist(&L)
    while{
        Elemtype e;
        InsertNextNode(L,e);
    }
    LNode *p = L->next;
    while(p != NULL){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = p->data;
        L->next = s;
        p = p->next;
    }
    return L;
}*/