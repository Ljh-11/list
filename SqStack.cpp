//
// Created by 李金豪 on 2020/7/1.
//
#include <iostream>

#define MaxSize 10

//定义顺序栈结构体类型
typedef struct {
    int data[MaxSize];
    int top; //栈顶指针
}SqStack;

//定义链栈结构体类型
typedef struct Linknode {
    int data;
    struct Linknode * next;
}Linknode, * LinkStack;

//初始化顺序栈
void InitStack(SqStack & S) {
    S.top = -1;
}

//顺序栈判空
bool StackEmpty(SqStack S) {
    if (S.top == -1) //判空条件
        return true;
    else
        return false;
}

//顺序栈进栈
bool Push(SqStack & S, int x) {
    if (S.top == MaxSize - 1) //判断是否栈满
        return false;

    S.top = S.top + 1; //指针先加1，再入栈
    S.data[S.top] = x;

    return true;
}

//顺序栈出栈
bool Pop(SqStack & S, int & Y) {
    if (S.top == -1) //判断是否为空栈
        return false;

    Y = S.data[S.top--]; //先出栈，指针再减1
    return true;
}

//顺序栈读栈
bool GetTop(SqStack S,int & X) {
    if (S.top == -1)
        return false;

    X = S.data[S.top];
    return true;
}

//初始化链栈（带头结点）
void InitLinkStack(LinkStack & Lhead) {
    Lhead = (Linknode *) malloc(sizeof(Linknode));//栈顶指针指向头结点
    Lhead->next = nullptr;
}

//链栈判空（带头结点）
bool LinkStackEmpty(LinkStack Lhead) {
    if (Lhead->next == nullptr)
        return true;

    return false;
}

//链栈进栈（带头结点）
Linknode  * LinkPush(LinkStack & Lhead, int x) {
    Linknode * s;
    s = (Linknode *) malloc(sizeof(Linknode));
    s->data = x;
    s->next = Lhead->next;
    Lhead->next = s;

    return Lhead;
}

//链栈出栈（带头结点）
bool LinkPop(LinkStack & Lhead, int & Y) {
    if (Lhead ->next == nullptr)
        return false;

    Y = Lhead->next->data;
    Lhead->next = Lhead->next->next;
    return true;
}

//链栈读栈（带头结点）
bool GetLinkTop(LinkStack & Lhead, int & X) {
    if (Lhead ->next == nullptr) //判断链栈是否为空
        return false;

    X = Lhead->next->data;
    printf("%d\n", X);
    return true;
}


int main() {
    LinkStack Lhead; // 创建栈顶指针
    int X, Y;

    InitLinkStack(Lhead);
    LinkPush(Lhead, 1);
    LinkPush(Lhead, 2);
    LinkPush(Lhead, 3);
    LinkPop(Lhead, Y);
    printf("%d\n", Y);

    GetLinkTop(Lhead, X);

    return 0;
}