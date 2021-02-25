#include<stdio.h>
#define MAXSIZE 10
typedef struct
{
    int elem[MAXSIZE];
    int length;
}SqList;
void InitList(SqList &L)
{
    for(int i=0;i<MAXSIZE;i++)
    {
        L.elem[i] = 0;
        L.length = 0;
    }
}
bool ListInsert(SqList &L,int i,int e)//i是位续,e是插入值
{
    if(i < 1 || i > L.length+1)return false;
    if(L.length >= MAXSIZE)return false;//空间已满或溢出
    for(int j=L.length;j>=i;j--)
    {//从后向前遍历
        L.elem[j] = L.elem[j-1];
    }
    L.elem[i-1] = e;//插入元素值为e
    L.length++;
    return true;
}
bool ListDelete(SqList &L,int i,int &e)//用e把删除元素带回
{//如果不加&且在main中设e的局部变量和删除函数e不同;加上&能让L,e值变化
    if(i < 1 || i > L.length+1)return false;
    if(L.length > MAXSIZE)return false;
    e = L.elem[i-1];//将删除的值赋给e
    for(int j=i;j<L.length;j++)
    {//从前向后遍历
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
    return true;
}
int main()
{
    SqList L;
    InitList(L);
    //此处插入几个元素
    for(int i=0;i<3;i++)
    {
        ListInsert(L,i+1,i+1);
    }
    int e = -1;//局部变量，如果ListDelete函数&e的值一直为-1
    if(ListDelete(L,1,e))
    {
        printf("已删除第三个元素值为%d\n",e);
    }
    else
    {
        printf("输入非法，删除失败\n");
    }
    return 0;
}