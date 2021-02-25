#include<stdio.h>
#define MAXSIZE 10
typedef struct
{
    char data[MAXSIZE];
    int top;
}SqStack;
//函数接口
void InitStack(SqStack &S)
{
    S.top = -1;
}
bool IfStackEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
        return false;
}
bool Push(SqStack &S,char x)
{
    if(S.top == MAXSIZE-1)return false;
    S.data[++S.top] = x;
    return true;
}
bool Pop(SqStack &S,char &x)
{
    if(S.top == -1)return false;
    x = S.data[S.top--];
    return true;
}
int StackLen(SqStack S)
{
    return (S.top + 1);
}
//匹配函数
bool CheckMatch(char str[],int length)
{
    SqStack S;
    length = StackLen(S);
    if(length == 0)return true;
    for(int i=0;i<length;i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{')Push(S,str[i]);
        else
        {
            if(IfStackEmpty(S))return false;//右括号单
            char TopElem;
            Pop(S,TopElem);//匹配
            if(str[i]==')' || TopElem!='(')return false;
            if(str[i]==']' || TopElem!='[')return false;
            if(str[i]=='}' || TopElem!='{')return false;
        }
    }
    return IfStackEmpty(S);//false==左括号单
}