//
// Created by 李金豪 on 2020/6/19.
//
#include <iostream>

//创建单链表结点结构体类型
typedef struct LNode {
    int data;
    struct LNode * next;
}LNode, * LinkList;

//函数声明
int List_Length(LinkList L);

//头插法建立单链表
LinkList List_HeadInsert(LinkList & L, int a[], int len) {
    LNode * s;
    L = (LNode *) malloc (sizeof(LNode));
    L->next = nullptr;

    for (int i = 0; i < len; ++i) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }

    return L;
}

//不带头结点头插法建立单链表
LinkList List_HeadInsertWithoutHead(LinkList & L, int a[], int len) {
    LNode * s;
    L = nullptr;

    for (int i = 0; i < len; ++i) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        s->next = L;
        L = s;
    }

    return L;
}

//尾插法建立单链表
LNode * List_TailInsert(LinkList & L, int a[], int len) {
    L = (LNode *) malloc(sizeof(LNode));
    L->next = nullptr; //这里可以不用置空
    LNode * r = L; //r为表尾指针，始终指向最后一个结点
    LNode * s;

    for (int i = 0; i < len; ++i) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }

    r->next = nullptr; //当链表创建完成后，尾指针置空
    return L;
}

//不带头结点的尾插法建立单链表
LNode * List_TailInsertWithoutHead(LinkList & L, int a[], int len) {
    //先把第一个结点单独拿出来考虑
    L = (LNode *) malloc(sizeof(LNode));
    L->data = a[0];
    L->next = nullptr;

    LNode * r = L;
    LNode * s;

    for (int i = 1; i < len; ++i) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }

    r->next = nullptr;//让最后一个结点指向NULL，便于遍历整个链表时的循环条件判断
    return L;
}

//尾插法建立循环单链表（带头结点）
LNode * CircleList_TailInsert(LinkList & CL, int a[], int len) {
    CL = (LNode *) malloc(sizeof(LNode));
    CL->next = nullptr; //这里可以不用置空
    LNode *r = CL, *s;

    for (int i = 0; i < len; ++i) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        s->next = r->next;
        r->next = s;
        r = r->next;
    }

    r->next = CL;
    return CL;
}

//按位查找（仅实现带头结点，下同）
LNode * GetElem(LinkList L, int i) {
    int j = 1; //计数，当前p指针指向的是第一个结点
    LNode * p = L->next;

    if (i == 0) {
        return L;
    }

    if (i < 1) {
        return nullptr;
    }

    while (p != nullptr && j < i) {
        p = p->next;
        j++;
    }

    return p;
}

//按值查找
LNode * LocateElem(LinkList L, int e) {
    LNode * p = L->next;

    while (p != nullptr && p->data != e) {
        p = p->next;
    }

    return p;
}

//在指定位置处插入新结点
bool InsertNode(LinkList & L, int i, int e) {
    int len = List_Length(L);

    //对i进行合法性判断
    if (i < 1 || i > len + 1) {
        return false;
    }

    LNode * p = GetElem(L, i - 1); //找到要插入位置的前一个结点
    LNode * s;

    s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

//扩展：对某一结点进行前插操作
bool InsertPriorNode(LNode * p, int e) {
    if (p == nullptr) {
        return false;
    }

    LNode * s;
    s = (LNode *) malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;

    return true;
}

//按位删除结点
int DeleteNodeByLocation(LinkList & L, int i) {
    int e;
    int len = List_Length(L);

    //对i进行合法性判断
    if (i < 1 || i > len) {
        return -1;
    }

    LNode * p = GetElem(L, i - 1); //查找删除位置的前驱结点
    LNode * q = p->next; //让q指向被删除结点
    e = q->data;
    p->next = q->next;
    free(q);

    return e;
}


//删除节点*p
bool DeleteNode(LNode * p) {
    if (p == nullptr) {
        return false;
    }

    LNode * q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
}

//遍历输出带头结点单链表
void print_List(LinkList L) {
    LNode * s = L->next;

    while (s != nullptr) {
        printf("%d\t", s->data);
        s = s->next;
    }

    printf("\n");
}

//遍历输出带头结点的循环单链表
void print_CircleList(LinkList CL) {
    LNode * s = CL->next;

    while (s != CL) {
        printf("%d\t", s->data);
        s = s->next;
    }

    printf("\n");
}

//遍历输出不带头结点单链表
void print_ListWithoutHead(LinkList L) {
    LNode * s = L;

    while (s != nullptr) {
        printf("%d\t", s->data);
        s = s->next;
    }

    printf("\n");
}

//求单链表长度(带头结点)
int List_Length(LinkList L) {
    int len = 0;
    LNode * p = L->next; //让p初始时指向第一个结点

    while (p != nullptr) {
        len++;
        p = p->next;
    }

    return len;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;
    LinkList L;

    //以带头结点的尾插法为例进行其他操作
    L = List_TailInsert(L, a, len);
    print_List(L);

    LinkList CL;
    CircleList_TailInsert(CL, a, len);
    print_CircleList(CL);


    return 0;
}
