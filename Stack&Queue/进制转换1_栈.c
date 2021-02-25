#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct 
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)//栈初始化
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));//内存分配
    if(!s->base) exit(0);//分配失败
    
    s->top=s->base;
    s->stackSize=STACK_INIT_SIZE;
}

void Push(sqStack *s,ElemType e)//进栈
{//插入e为新的栈顶元素
    if(s->top - s->base >= s->stackSize)
    {//栈当前容量
        s->base =(ElemType *)realloc(s->base,(s->stackSize + STACKINCREMENT) * sizeof(ElemType));//重新分配
        if(!s->base) exit(0);//分配失败
        *(s->top) = e;   //s->top = s->base+s->stackSize;
        s->top ++;       //s->stackSize += STACKINCREMENT;
    }
    //s->top ++ = e;
}

void Pop(sqStack *s,ElemType *e)//出栈
{
    if(s->top == s->base) return;
    *e = * --(s->top);
}

int StackLen(sqStack s)//操作中会做出改变的变量加*，不做出改变的不加
{
    return (s.top - s.base);//加*用->表示指针，不加*用.引用成员函数
}


int main()
{
    ElemType c;
    sqStack s;
    int len,sum = 0;

    printf("请输入二进制数，输入#表示结束\n");
    scanf("%c",&c);
    while(c !='#')
    {
        Push(&s,c);
        scanf("%c",&c);
    }
    getchar();//把‘\n‘从缓冲区去掉

    len = StackLen(s);
    printf("栈的容量是:%d\n",len);

    for(int i=0;i<len;i++)
    {   
        Pop(&s,&c);
        sum += (c-48) * pow(2,i);//ASCII Table:48==0;49==1;仅对向二进制转换成立
        //进制转换原理如此:N=(N/d)*d+(N%d)
        //while(N) Push(s,N % d);N /= d;
    }
        
    printf("转换为十进制数是:%d",sum);

    return 0;
}
