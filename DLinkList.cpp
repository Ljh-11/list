//
// Created by ���� on 2020/6/25.
//
#include <iostream>
#define MaxSize 10

//����˫������ṹ������
typedef struct DNode {
    int data;
    struct DNode * prior, * next;
}DNode, * DLinklist;

//���徲̬����ṹ��������
typedef struct {
    int data;
    int next;
}SLinkList[MaxSize];

//��ʼ��˫����
bool InitDLinkList(DLinklist & L) {
    L = (DNode *) malloc(sizeof(DNode)); //���ڴ治�㣬�ᵼ���ڴ涯̬����ʧ��

    if (L == nullptr) {
        return false;
    }

    L->prior = nullptr; //ͷ����priorָ����Զָ��NULL
    L->next = nullptr;

    return true;
}

bool InitCircleDLinkList(DLinklist & CL) {
    CL = (DNode *) malloc(sizeof(DNode)); //���ڴ治�㣬�ᵼ���ڴ涯̬����ʧ��

    if (CL == nullptr) {
        return false;
    }

    CL->prior = CL;
    CL->next = CL;

    return true;
}

//ͷ�巨����˫������ͷ��㣩
DNode * List_HeardInsert(DLinklist & L, int a[], int len) {
    DLinklist s;

    for (int i = 0; i < len; ++i) {
        s = (DNode *) malloc(sizeof(DNode));
        s->data = a[i];
        s->next = L->next;

        if (L->next != nullptr) //�������һ�����ʱ������L->nextָ��NULL
            L->next->prior = s;

        L->next = s;
        s->prior = L;
    }

    return L;
}

//β�巨����˫������ͷ��㣩
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

//β�巨������ͷ����ѭ��˫����
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

//��ʼ����̬����
void InitSLinkList(SLinkList SL) {
    for (int i = 0; i < MaxSize; ++i) {
        SL[i].next = -2; //-2��ʾ�ý��Ϊ��
    }
}

//�ж�˫�����Ƿ�Ϊ�գ���ͷ��㣩
bool Empty(DLinklist L) {
    if (L->next == nullptr) { //��if������ֱ�Ӽ�Ϊ return L->next == nullptr;
        return true;
    } else {
        return false;
    }
}

//�ڽ��*p֮�������*s
bool InsertNextDNode(DNode * p, DNode * s) {
    if (p == nullptr || s == nullptr) {
        return false;
    }

    s->next = p->next;
    if (p->next != nullptr) //�������һ���������ʱ������p->nextָ��NULL
        p->next->prior = s;
    p->next = s;
    s->prior = p;

    return true;
}

//�ڽ��*p֮ǰ������*s
bool InsertFrontDNode(DNode * p, DNode * s) {
    if (p == nullptr || s == nullptr) {
        return false;
    }

    p->prior->next = s;//����Ӧ��֤*p��ǰһ�����Ҫָ���ӵ���֪��*s���
    s->prior = p->prior;
    s->next = p;
    p->prior = s;

    return true;
}

//ɾ�����*p�ĺ�̽��*q
bool DeleteNextInsert(DNode * p) {
    if (p == nullptr) {
        return false;
    }

    DNode * q = p->next; //��pָ��Ҫ��ɾ���Ľ��

    if (q == nullptr) //���ɾ���������һ�����ĺ�̽�㣬����ʱ�޺�̽��
        return false;

    p->next = q->next;

    if (q->next != nullptr) //���ɾ�����ǵ����ڶ������ĺ�̽�㣬������Щ��ͬ
        q->next->prior = p;

    free(q); //�ͷŽ��ռ�

    return true;
}

//ɾ�����*p��ǰ�����*q
bool DeleteFrontInsert(DNode * p) {
    if (p == nullptr) {
        return false;
    }

    DNode * q = p->prior; //��pָ��Ҫ��ɾ���Ľ��
    q->prior->next = p;
    p->prior = q->prior;
    free(q);

    return true;
}

//���������ͷ����˫����
void print_List(DLinklist L) {
    DNode * s = L->next;
    if (Empty(L)) {
        printf("������Ϊ�գ�");
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

    DLinklist L;//����һ��ͷָ��
    InitDLinkList(L);//��ʼ��˫����
    //List_HeardInsert(L, a, len);
    List_TailInsert(L, a, len);
    print_List(L);

    //DeleteNextInsert(L->next->next);//�����L->next->nextָ��ڶ�����㣬Ӧɾ�����������
    //DeleteFrontInsert(L->next->next);//�����L->next->nextָ��ڶ�����㣬Ӧɾ����һ�������

    DLinklist CL;//����һ��ͷָ��
    InitCircleDLinkList(CL);//��ʼ��ѭ��˫����




    return 0;
}
