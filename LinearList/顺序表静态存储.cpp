#include<stdio.h>
#define MAXSIZE 10

typedef struct
{
    int elem[MAXSIZE];//静态数组存储数据元素
    int length;//顺序表当前长度
}SqList;
//初始化线性表
void InitList(SqList &L)
{
    for(int i=0;i<MAXSIZE;i++)
    {
        L.elem[i] = 0;
        L.length = 0;
    }
}
int main()
{
    SqList L;
    InitList(L);
    for(int i=0;i<L.length;i++)//注意是i<L.length,防止脏数据
    {
        printf("elem[%d] = %d\n",i,L.elem[i]);
    }
    return 0;
}