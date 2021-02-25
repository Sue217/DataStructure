#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int *elem;//指向起始地址
    int length;
}SqList;
int GetElem1(SqList L,int i)//静态存储
{//顺序表的按位查找
    if(i>0 && i<=L.length)return L.data[i-1];
    else printf("Wrong\n");
}
int GetElem2(SqList L,int i)//动态分配
{
    if(i>0 && i<=L.length)return L.elem[i-1];
    else printf("Wrong\n");
}