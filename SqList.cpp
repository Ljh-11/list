//
// Created by ���� on 2020/6/21.
//
#include <iostream>

#define MaxSize 50 //�������Ա����󳤶�
#define InitSize 10 //���Ա�ĳ�ʼ����

//����˳���ṹ�����ͣ���̬��
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

//����˳���ṹ�����ͣ���̬��
typedef  struct {
    int * data;
    int maxSize, length;
}SeqList;

//��̬���䴴��˳���
void InitList(SeqList & L) {
    L.data = (int *) malloc (sizeof(int) * InitSize);
    L.length = 0;
    L.maxSize = InitSize;
}

//���Ӷ�̬����ĳ���
void IncreaseSize(SeqList & L, int len) {
    int * p = L.data;
    L.data = (int *) malloc(sizeof(int) * (L.maxSize + len));

    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }

    L.maxSize = InitSize + len;
    free(p);
}

//�������
bool ListInsert(SeqList & L, int i, int e) {
    if (i < 1 || i > L.length + 1) { //��i���кϷ����ж�
        return false;
    }

    if (L.length >= L.maxSize) {
        return false;
    }

    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;

    return true;
}

//ɾ����i��Ԫ��
bool ListDelete(SeqList & L, int i, int & e) {
    if (i < 1 || i > L.length) {
        return false;
    }

    e = L.data[i - 1];

    for (int j = i; j < L.length; ++j) {
        L.data[j - 1] = L.data[j];
    }

    L.length--;
    return true;
}

//��ֵ���ң�������λ��
int LocateElem(SeqList L, int e) {

    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }

    return -1;
}

//��λ�����
int GetElem(SeqList L, int i) {
    if (i < 1 || i > L.length) {
        return -1;
    }

    return L.data[i - 1];
}

//�������˳����ֵ
void print_List(SeqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%d\t", L.data[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;
    int e; //����ɾ��ʱ���ر�ɾ����Ԫ�ص�ֵ

    SeqList L; //����һ�������Ϣ�Ľ��
    InitList(L); //��ʼ����ʹ��L����dataָ��ָ��̬����������洢�ռ���׵�ַ
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    print_List(L);
    ListInsert(L, 1, 22);
    print_List(L);

    printf("λ�ڣ�%d\n",LocateElem(L, 22));
    printf("ֵ�ǣ�%d\n",GetElem(L, 2));
    ListDelete(L, 1, e);
    printf("%d\n", e);
    print_List(L);

    return 0;
}
