#include<stdio.h>

#define MAXSIZE 10
//定义栈
typedef struct 
{
    int data[MAXSIZE];
    int top;
}SqStack;
//初始化栈
void InitStack(SqStack S)
{
    S.top = -1;//初始化栈顶指针
}
bool IfEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
        return false;
}
//进栈操作Push
bool Push(SqStack &S,int x)
{
    if(S.top == MAXSIZE-1)return false;//栈满报错 若初始化S.top=0此处判满S.top?=MAXSIZE
    S.data[++S.top] = x;//注:先+1后入栈 若初始化S.top=0此处S.data[S.top++] = x;
    return true;
}
bool Pop(SqStack &S,int &x)
{
    if(S.top == -1)return false;//栈空报错
    x = S.data[S.top--];//注:先出栈后-1 若初始化S.top=0此处x = S.data[--S.top];
    return true;
}
bool GetStack(SqStack S,int &x)
{
    if(S.top == -1)return false;
    x = S.data[S.top];
    return true;
}