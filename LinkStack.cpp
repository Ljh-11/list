//
// Created by 李金豪 on 2020/7/3.
//
#include <iostream>

//定义链栈结构体类型
typedef struct Linknode {
    int data;
    struct Linknode * next;
}Linknode, * LinkStack;

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
    Lhead->next = s; //Lhead始终指向栈顶元素

    return Lhead;
}

//链栈出栈（带头结点）
bool LinkPop(LinkStack & Lhead, int & Y) {
    if (Lhead->next == nullptr)
        return false;

    Linknode * s = Lhead->next;
    Y = s->data;
    Lhead->next = s->next;
    free(s);

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
