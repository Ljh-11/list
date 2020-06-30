//
// Created by 李金豪 on 2020/6/21.
//
#include <iostream>

#define MaxSize 50 //定义线性表的最大长度
#define InitSize 10 //线性表的初始长度

//定义顺序表结构体类型（静态）
typedef struct {
    int data[MaxSize];
    int length;
}SqList;

//定义顺序表结构体类型（动态）
typedef  struct {
    int * data;
    int maxSize, length;
}SeqList;

//动态分配创建顺序表
void InitList(SeqList & L) {
    L.data = (int *) malloc (sizeof(int) * InitSize);
    L.length = 0;
    L.maxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList & L, int len) {
    int * p = L.data;
    L.data = (int *) malloc(sizeof(int) * (L.maxSize + len));

    for (int i = 0; i < L.length; ++i) {
        L.data[i] = p[i];
    }

    L.maxSize = InitSize + len;
    free(p);
}

//插入操作
bool ListInsert(SeqList & L, int i, int e) {
    if (i < 1 || i > L.length + 1) { //对i进行合法性判断
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

//删除第i个元素
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

//按值查找，返回其位序
int LocateElem(SeqList L, int e) {

    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }

    return -1;
}

//按位序查找
int GetElem(SeqList L, int i) {
    if (i < 1 || i > L.length) {
        return -1;
    }

    return L.data[i - 1];
}

//遍历输出顺序表的值
void print_List(SeqList L) {
    for (int i = 0; i < L.length; ++i) {
        printf("%d\t", L.data[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;
    int e; //用于删除时返回被删除的元素的值

    SeqList L; //创建一个存放信息的结点
    InitList(L); //初始化，使得L结点的data指针指向动态分配的连续存储空间的首地址
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    print_List(L);
    ListInsert(L, 1, 22);
    print_List(L);

    printf("位于：%d\n",LocateElem(L, 22));
    printf("值是：%d\n",GetElem(L, 2));
    ListDelete(L, 1, e);
    printf("%d\n", e);
    print_List(L);

    return 0;
}
