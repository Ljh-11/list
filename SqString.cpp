//
// Created by 李金豪 on 2020/7/8.
//
#include <iostream>
#define MAXLEN 255

//定义静态串结构体类型
typedef struct {
    char ch[MAXLEN];
    int length;
}SString;

//初始化串S
void InitString(SString & S, char s1[], int len) {
    for (int i = 1; i <= len; ++i) {
        S.ch[i] = s1[i];
    }

    S.length = len;
}

//求子串,用Sub返回S的第pos个字符起长度为len的子串
bool SubString(SString & Sub, SString S, int pos, int len) {
    if (pos + len - 1 > S.length) { //判断子串是否越界
        return false;
    }

    for (int i = pos; i < pos + len; ++i) {
        Sub.ch[i - pos + 1] = S.ch[i];
        Sub.length = len;
    }

    return true;
}

//比较两个串
int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; ++i) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }

    return S.length - T.length;
}

//定位操作
int Index(SString S, SString T) {
    int i = 1;
    int lenS = S.length, lenT = T.length;

    SString sub; //用于暂存子串

    while (i <= lenS - lenT + 1) {
        SubString(sub, S, i, lenT);

        if (StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;
        }
    }

    return 0;
}

//朴素模式匹配算法
int Index1(SString S, SString T) {
    int i = 1, j = 1;

    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            ++i, ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > T.length)
        return i - T.length;
    else
    return 0;
}

//遍历串
bool printString(SString S) {
    if (S.length == 0) {
        return false;
    }

    for (int i = 1; i <= S.length; ++i) {
        printf("%c\t", S.ch[i]);
    }

    printf("\n");
    return true;
}

int main() {
    char s1[] = {'#','w', 'a', 'n', 'g', 'd', 'a', 'o'};
    char s2[] = {'#', 'd', 'a', 'o'};
    SString S;
    SString T;
    InitString(S, s1, 7);
    InitString(T, s2, 3);

    SString Sub;
    SubString(Sub, S, 4, 4);

    printf("%d\n",Index(S, T));

    printString(S);
    printString(T);


    return 0;
}
