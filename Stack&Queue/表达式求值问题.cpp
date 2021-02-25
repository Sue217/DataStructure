#include<stdio.h>
#define MAXSIZE 10
typedef struct
{
    int data[MAXSIZE];
    int top;
}SqStack;
//函数接口
void InitStack(SqStack &S)
{
    S.top = -1;
}
bool Push(SqStack &S,int x)
{
    if(S.top == MAXSIZE-1)return false;
    S.data[++S.top] = x;
    return true;
}
bool Pop(SqStack &S,int &x)
{
    if(S.top == -1)return false;
    x = S.data[S.top--];
    return true;
}
int StackLen(SqStack S)
{
    return (S.top + 1);
}
//加法函数
void PlusElem(SqStack S)
{
    if(S.top == 0)return;
    int Topelem;
    Pop(S,Topelem);
    Pop(S,Topelem);
    S.data[S.top] = S.data[S.top-1] - S.data[S.top];
    Push(S,S.data[S.top]);
}
//减法函数
void MinusElem(SqStack S)
{
    if(S.top == 0)return;
    int Topelem;
    Pop(S,Topelem);
    Pop(S,Topelem);
    S.data[S.top] = S.data[S.top-1] - S.data[S.top];
    Push(S,S.data[S.top]);
}
//乘法函数
void MultElem(SqStack S)
{
    if(S.top == 0)return;
    int Topelem;
    Pop(S,Topelem);
    Pop(S,Topelem);
    S.data[S.top] = S.data[S.top-1] * S.data[S.top];
    Push(S,S.data[S.top]);
}
//除法函数
void DivElem(SqStack S)
{
    if(S.top == 0)return;
    int Topelem;
    Pop(S,Topelem);
    Pop(S,Topelem);
    if(S.data[S.top] == 0)return;
    S.data[S.top] = S.data[S.top-1] / S.data[S.top];
    Push(S,S.data[S.top]);
}
//操作函数
int Transform(char str[],int length)
{
    SqStack S;
    //Input
    length = StackLen(S);
    for(int i=0;i<length;i++)
    {
        switch(str[i])
        {
            case '+' : PlusElem(S);
            case '-' : MinusElem(S);
            case '*' : MultElem(S);
            case '/' : DivElem(S);
        }
    }
    return S.data[S.top];
}