//
// Created by 李金豪 on 2020/6/25.
//
#include <iostream>
#define MaxSize 10

//定义双链表结点结构体类型
typedef struct DNode {
    int data;
    struct DNode * prior, * next;
}DNode, * DLinklist;

//定义静态链表结构体结点类型
typedef struct {
    int data;
    int next;
}SLinkList[MaxSize];

//初始化双链表
bool InitDLinkList(DLinklist & L) {
    L = (DNode *) malloc(sizeof(DNode)); //若内存不足，会导致内存动态分配失败

    if (L == nullptr) {
        return false;
    }

    L->prior = nullptr; //头结点的prior指针永远指向NULL
    L->next = nullptr;

    return true;
}

bool InitCircleDLinkList(DLinklist & CL) {
    CL = (DNode *) malloc(sizeof(DNode)); //若内存不足，会导致内存动态分配失败

    if (CL == nullptr) {
        return false;
    }

    CL->prior = CL;
    CL->next = CL;

    return true;
}

//头插法建立双链表（带头结点）
DNode * List_HeardInsert(DLinklist & L, int a[], int len) {
    DLinklist s;

    for (int i = 0; i < len; ++i) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = a[i];
        s->next = L->next;

        if (L->next != nullptr) //当插入第一个结点时，考虑L->next指向NULL
            L->next->prior = s;

        L->next = s;
        s->prior = L;
    }

    return L;
}

//尾插法建立双链表（带头结点）
DNode * List_TailInsert(DLinklist & L, int a[], int len) {
    DNode *r = L, *s;

    for (int i = 0; i < len; ++i) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = a[i];
        s->next = r->next;
        s->prior = r;
        r->next = s;
        r = r->next;
    }

    return L;
}

//尾插法建立带头结点的循环双链表
DNode * CircleList_TailInsert(DLinklist & CL, int a[], int len) {
    DNode *r = CL, *s;

    for (int i = 0; i < len; ++i) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = a[i];
        s->next = r->next;
        s->prior = r;
        r->next = s;
        r = r->next;
    }

    r->next = CL;
    CL->prior = r;
    return CL;
}

//初始化静态链表
void InitSLinkList(SLinkList SL) {
    for (int i = 0; i < MaxSize; ++i) {
        SL[i].next = -2; //-2表示该结点为空
    }
}

//判断双链表是否为空（带头结点）
bool Empty(DLinklist L) {
    if (L->next == nullptr) { //该if语句可以直接简化为 return L->next == nullptr;
        return true;
    } else {
        return false;
    }
}

//在结点*p之后插入结点*s
bool InsertNextDNode(DNode * p, DNode * s) {
    if (p == nullptr || s == nullptr) {
        return false;
    }

    s->next = p->next;
    if (p->next != nullptr) //当往最后一个结点后插入时，考虑p->next指向NULL
        p->next->prior = s;
    p->next = s;
    s->prior = p;

    return true;
}

//在结点*p之前插入结点*s
bool InsertFrontDNode(DNode * p, DNode * s) {
    if (p == nullptr || s == nullptr) {
        return false;
    }

    p->prior->next = s;//首先应保证*p的前一个结点要指链接到已知的*s结点
    s->prior = p->prior;
    s->next = p;
    p->prior = s;

    return true;
}

//删除结点*p的后继结点*q
bool DeleteNextInsert(DNode * p) {
    if (p == nullptr) {
        return false;
    }

    DNode * q = p->next; //让p指向要被删除的结点

    if (q == nullptr) //如果删除的是最后一个结点的后继结点，而此时无后继结点
        return false;

    p->next = q->next;

    if (q->next != nullptr) //如果删除的是倒数第二个结点的后继结点，操作有些许不同
        q->next->prior = p;

    free(q); //释放结点空间

    return true;
}

//删除结点*p的前驱结点*q
bool DeleteFrontInsert(DNode * p) {
    if (p == nullptr) {
        return false;
    }

    DNode * q = p->prior; //让p指向要被删除的结点
    q->prior->next = p;
    p->prior = q->prior;
    free(q);

    return true;
}

//遍历输出带头结点的双链表
void print_List(DLinklist L) {
    DNode * s = L->next;
    if (Empty(L)) {
        printf("该链表为空！");
    } else {
        while (s != nullptr) {
            printf("%d\t", s->data);
            s = s->next;
        }
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;

    DLinklist L;//创建一个头指针
    InitDLinkList(L);//初始化双链表
    //List_HeardInsert(L, a, len);
    List_TailInsert(L, a, len);
    print_List(L);

    //DeleteNextInsert(L->next->next);//这里的L->next->next指向第二个结点，应删除第三个结点
    //DeleteFrontInsert(L->next->next);//这里的L->next->next指向第二个结点，应删除第一个个结点

    DLinklist CL;//创建一个头指针
    InitCircleDLinkList(CL);//初始化循环双链表




    return 0;
}
