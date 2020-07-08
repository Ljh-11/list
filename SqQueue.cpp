//
// Created by 李金豪 on 2020/7/3.
//
#include <iostream>

#define MaxSize 10

//定义顺序队列结构体类型
typedef struct {
    int data[MaxSize];
    int front, rear;
}SqQueue;

//初始化队列
void InitQueue(SqQueue & Q) {
    Q.front = Q.rear = 0;
}

//队列判空
bool QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    }
    return false;
}

//进队
bool EnQueue(SqQueue & Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front) { //判断队满，牺牲一个单元来区分队满与队空
        return false;
    }

    Q.data[Q.rear] = x; //先进队，指针再加1
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

//出队
bool DeQueue(SqQueue & Q, int & X) {
    if (Q.front == Q.rear) { //判断队空
        return false;
    }

    X = Q.data[Q.front]; //先出队，指针再加1
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

//读队头元素
bool GetHead(SqQueue Q, int & X) {
    if (Q.front == Q.rear) { //判空
        return false;
    }

    X = Q.data[Q.front];
    printf("%d\n", X);
    return true;
}

//求队列长度
int LengthQueue(SqQueue Q) {
    int len;
    len = (Q.rear + MaxSize - Q.front) % MaxSize;
    printf("%d\n", len);

    return len;
}

int main() {
    SqQueue Q;
    InitQueue(Q);
    int X, Y;

    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    DeQueue(Q, Y);
    printf("%d\n", Y);
    GetHead(Q, X);
    LengthQueue(Q);

    return 0;
}

