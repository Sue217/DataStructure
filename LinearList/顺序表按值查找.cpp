#include<stdio.h>
#include<stdlib.h>
#define InitSize 10//默认最大长度
typedef struct
{
    int *elem;
    int length;//顺序表当前长度
    int Maxsize;//顺序表最大容量
}SqList;
int LocateElem(SqList L,int e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i] == e)return i+1;
        else return 0;
    }
}