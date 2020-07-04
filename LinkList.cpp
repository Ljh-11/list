//
// Created by ���� on 2020/6/19.
//
#include <iostream>

//������������ṹ������
typedef struct LNode {
    int data;
    struct LNode * next;
}LNode, * LinkList;

//��������
int List_Length(LinkList L);

//ͷ�巨����������
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

//����ͷ���ͷ�巨����������
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

//β�巨����������
LNode * List_TailInsert(LinkList & L, int a[], int len) {
    L = (LNode *) malloc(sizeof(LNode));
    L->next = nullptr; //������Բ����ÿ�
    LNode * r = L; //rΪ��βָ�룬ʼ��ָ�����һ�����
    LNode * s;

    for (int i = 0; i < len; ++i) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }

    r->next = nullptr; //����������ɺ�βָ���ÿ�
    return L;
}

//����ͷ����β�巨����������
LNode * List_TailInsertWithoutHead(LinkList & L, int a[], int len) {
    //�Ȱѵ�һ����㵥���ó�������
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

    r->next = nullptr;//�����һ�����ָ��NULL�����ڱ�����������ʱ��ѭ�������ж�
    return L;
}

//β�巨����ѭ����������ͷ��㣩
LNode * CircleList_TailInsert(LinkList & CL, int a[], int len) {
    CL = (LNode *) malloc(sizeof(LNode));
    CL->next = nullptr; //������Բ����ÿ�
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

//��λ���ң���ʵ�ִ�ͷ��㣬��ͬ��
LNode * GetElem(LinkList L, int i) {
    int j = 1; //��������ǰpָ��ָ����ǵ�һ�����
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

//��ֵ����
LNode * LocateElem(LinkList L, int e) {
    LNode * p = L->next;

    while (p != nullptr && p->data != e) {
        p = p->next;
    }

    return p;
}

//��ָ��λ�ô������½��
bool InsertNode(LinkList & L, int i, int e) {
    int len = List_Length(L);

    //��i���кϷ����ж�
    if (i < 1 || i > len + 1) {
        return false;
    }

    LNode * p = GetElem(L, i - 1); //�ҵ�Ҫ����λ�õ�ǰһ�����
    LNode * s;

    s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return true;
}

//��չ����ĳһ������ǰ�����
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

//��λɾ�����
int DeleteNodeByLocation(LinkList & L, int i) {
    int e;
    int len = List_Length(L);

    //��i���кϷ����ж�
    if (i < 1 || i > len) {
        return -1;
    }

    LNode * p = GetElem(L, i - 1); //����ɾ��λ�õ�ǰ�����
    LNode * q = p->next; //��qָ��ɾ�����
    e = q->data;
    p->next = q->next;
    free(q);

    return e;
}


//ɾ���ڵ�*p
bool DeleteNode(LNode * p) {
    if (p == nullptr) {
        return false;
    }

    LNode * q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
}

//���������ͷ��㵥����
void print_List(LinkList L) {
    LNode * s = L->next;

    while (s != nullptr) {
        printf("%d\t", s->data);
        s = s->next;
    }

    printf("\n");
}

//���������ͷ����ѭ��������
void print_CircleList(LinkList CL) {
    LNode * s = CL->next;

    while (s != CL) {
        printf("%d\t", s->data);
        s = s->next;
    }

    printf("\n");
}

//�����������ͷ��㵥����
void print_ListWithoutHead(LinkList L) {
    LNode * s = L;

    while (s != nullptr) {
        printf("%d\t", s->data);
        s = s->next;
    }

    printf("\n");
}

//��������(��ͷ���)
int List_Length(LinkList L) {
    int len = 0;
    LNode * p = L->next; //��p��ʼʱָ���һ�����

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

    //�Դ�ͷ����β�巨Ϊ��������������
    L = List_TailInsert(L, a, len);
    print_List(L);

    LinkList CL;
    CircleList_TailInsert(CL, a, len);
    print_CircleList(CL);


    return 0;
}
