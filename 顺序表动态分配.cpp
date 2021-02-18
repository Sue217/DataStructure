#include<stdio.h>
#include<stdlib.h>
#define InitSize 10//默认最大长度
typedef struct
{
    int *elem;
    int length;//顺序表当前长度
    int Maxsize;//顺序表最大容量
}SqList;
void InitList(SqList &L)
{
    L.elem = (int *)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.Maxsize = InitSize;
}
void IncreaseList(SqList &L,int len)
{
    int *q = L.elem;
    L.elem = (int *)malloc((L.Maxsize+InitSize)*sizeof(int));//多开辟InitMaxSize空间
    for(int i=0;i<L.length;i++)
    {//将元素复制到新的区域
        L.elem[i] = q[i];
    }
    L.Maxsize += len;
    free(q);
}
int main()
{
    SqList L;
    InitList (L);
    //increase elements
    IncreaseList(L,5);
    return 0;
}