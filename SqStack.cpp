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


int main() {
    SqStack S;


    return 0;
}