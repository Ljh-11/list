//
// Created by ���� on 2020/7/3.
//
#include <iostream>

//���������н��ṹ������
typedef struct LinkNode{
    int data;
    struct LinkNode * next;
}LinkNode;

//�����ͷָ��Ͷ�βָ��ṹ������
typedef struct {
    LinkNode * front; //��ͷָ��
    LinkNode * rear; //��βָ��
    int length; //����һ��length�����Ա�������г���
}LinkQueue;

//��ʼ��������(��ͷ���)
void InitQueue(LinkQueue & Q) {
    Q.front = Q.rear = (LinkNode *) malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
    Q.length = 0;
}

//��ʼ��������(����ͷ���)
void InitQueueWithoutHead(LinkQueue & Q) {
    Q.front = Q.rear = nullptr;
    Q.length = 0;
}

//�������пգ���ͷ��㣩
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return true;
    }

    return false;
}

//�������пգ�����ͷ��㣩
bool IsEmptyWithoutHead(LinkQueue Q) {
    if (Q.front == nullptr) { //�޽��
        return true;
    }

    return false;
}

//��ӣ���ͷ��㣩
void EnQueue(LinkQueue & Q, int x) {
    LinkNode * s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr; //����ӽ��һ��ָ��null
    Q.rear->next = s;
    Q.rear = s;
    Q.length++;
}

//��ӣ�����ͷ��㣩
void EnQueueWithoutHead(LinkQueue & Q, int x) {
    LinkNode * s = (LinkNode *) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;

    if (Q.front == nullptr) { //��һ��������ʱ�������
        Q.front = s;
        Q.rear = s;
    } else {
        Q.rear->next = s;
        Q.rear = s;
    }

    Q.length++;
}

//���ӣ���ͷ��㣩
bool DeQueue(LinkQueue & Q, int & X) {
    if (Q.front == Q.rear) { //�п�
        return false;
    }

    LinkNode * p = Q.front->next;
    X = p->data;
    Q.front->next = p->next;

    if (p == Q.rear) { //���ɾ���������һ����㣬��ɾ���������ÿ�
        Q.rear = Q.front;
    }

    free(p);
    Q.length--;

    return true;
}

//���ӣ�����ͷ��㣩
bool DeQueueWithoutHead(LinkQueue & Q, int & X) {
    if (Q.front == nullptr) { //�п�
        return false;
    }

    LinkNode * p = Q.front;
    X = p->data;
    Q.front = p->next;

    if (p == Q.rear) { //���ɾ���������һ����㣬��ɾ���������ÿ�
        Q.rear = Q.front;
    }

    free(p);
    Q.length--;

    return true;
}

//����
bool GetQueue(LinkQueue Q) {
    if (Q.front->next == nullptr) {
        return false;
    }

    int x = Q.front->next->data;
    printf("%d\n", x);

    return true;
}


int main() {
    LinkQueue Q; //����һ�����ж�ͷָ��Ͷ�βָ��Ľ�����
    int X;

    InitQueueWithoutHead(Q);
    EnQueueWithoutHead(Q, 1);
    EnQueueWithoutHead(Q, 2);
    DeQueueWithoutHead(Q, X);

    printf("%d\n", Q.front->data);



    return 0;
}