//
// Created by 李金豪 on 2020/7/3.
//
#include <iostream>

//定义链队列结点结构体类型
typedef struct LinkNode{
    int data;
    struct LinkNode * next;
}LinkNode;

//定义队头指针和队尾指针结构体类型
typedef struct {
    LinkNode * front; //队头指针
    LinkNode * rear; //队尾指针
    int length; //增加一个length变量以便于求队列长度
}LinkQueue;

//初始化链队列(带头结点)
void InitQueue(LinkQueue & Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
    Q.length = 0;
}

//初始化链队列(不带头结点)
void InitQueueWithoutHead(LinkQueue & Q) {
    Q.front = Q.rear = nullptr;
    Q.length = 0;
}

//链队列判空（带头结点）
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    }

    return false;
}

//链队列判空（不带头结点）
bool IsEmptyWithoutHead(LinkQueue Q) {
    if (Q.front == nullptr) { //无结点
        return true;
    }

    return false;
}

//入队（带头结点）
void EnQueue(LinkQueue & Q, int x) {
    LinkNode * s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr; //新入队结点一定指向null
    Q.rear->next = s;
    Q.rear = s;
    Q.length++;
}

//入队（不带头结点）
void EnQueueWithoutHead(LinkQueue & Q, int x) {
    LinkNode * s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;

    if (Q.front == nullptr) { //第一个结点入队时特殊操作
        Q.front = s;
        Q.rear = s;
    } else {
        Q.rear->next = s;
        Q.rear = s;
    }

    Q.length++;
}

//出队（带头结点）
bool DeQueue(LinkQueue & Q, int & X) {
    if (Q.front == Q.rear) { //判空
        return false;
    }

    LinkNode * p = Q.front->next;
    X = p->data;
    Q.front->next = p->next;

    if (p == Q.rear) { //如果删除的是最后一个结点，则删除后链表置空
        Q.rear = Q.front;
    }

    free(p);
    Q.length--;

    return true;
}

//出队（不带头结点）
bool DeQueueWithoutHead(LinkQueue & Q, int & X) {
    if (Q.front == nullptr) { //判空
        return false;
    }

    LinkNode * p = Q.front;
    X = p->data;
    Q.front = p->next;

    if (p == Q.rear) { //如果删除的是最后一个结点，则删除后链表置空
        Q.rear = Q.front;
    }

    free(p);
    Q.length--;

    return true;
}

//读队
bool GetQueue(LinkQueue Q) {
    if (Q.front->next == nullptr) {
        return false;
    }

    int x = Q.front->next->data;
    printf("%d\n", x);

    return true;
}


int main() {
    LinkQueue Q; //创建一个含有队头指针和队尾指针的结点变量
    int X;

    InitQueueWithoutHead(Q);
    EnQueueWithoutHead(Q, 1);
    EnQueueWithoutHead(Q, 2);
    DeQueueWithoutHead(Q, X);

    printf("%d\n", Q.front->data);



    return 0;
}