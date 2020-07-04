//
// Created by 李金豪 on 2020/7/4.
//
#include <iostream>
#define MaxSize 10

//不直接使用顺序栈的基本操作，实现括号匹配
int main() {
    char data[MaxSize];
    char str[] = {'(', '[', '{', '}', ']', '{', '}', ')'};
    int len = sizeof(str);

    int top = -1; //初始化top“指针”

    for (int i = 0; i < len; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') { //扫描到左括号，则压入栈
            data[++top] = str[i];
        }
        else {
            if (top == -1) { //扫描到右括号，且栈为空，则匹配失败
                printf("匹配失败！\n");
                return 0;
            }

            char x;
            x = data[top--]; //栈顶元素出栈

            if (str[i] == ')' && x != '(') {
                printf("匹配失败！\n");
                return 0;
            }

            if (str[i] == ']' && x != '[') {
                printf("匹配失败！\n");
                return 0;
            }

            if (str[i] == '}' && x != '{') {
                printf("匹配失败！\n");
                return 0;
            }
        }
    }

    if (top != -1) { //对应栈非空的情况：所有括号匹配完，栈中还有左括号
        printf("匹配失败！\n");
        return 0;
    } else {
        printf("匹配成功！\n");
    }

}