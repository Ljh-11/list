//
// Created by ���� on 2020/7/4.
//
#include <iostream>
#define MaxSize 10

//��ֱ��ʹ��˳��ջ�Ļ���������ʵ������ƥ��
int main() {
    char data[MaxSize];
    char str[] = {'(', '[', '{', '}', ']', '{', '}', ')'};
    int len = sizeof(str);

    int top = -1; //��ʼ��top��ָ�롱

    for (int i = 0; i < len; ++i) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') { //ɨ�赽�����ţ���ѹ��ջ
            data[++top] = str[i];
        }
        else {
            if (top == -1) { //ɨ�赽�����ţ���ջΪ�գ���ƥ��ʧ��
                printf("ƥ��ʧ�ܣ�\n");
                return 0;
            }

            char x;
            x = data[top--]; //ջ��Ԫ�س�ջ

            if (str[i] == ')' && x != '(') {
                printf("ƥ��ʧ�ܣ�\n");
                return 0;
            }

            if (str[i] == ']' && x != '[') {
                printf("ƥ��ʧ�ܣ�\n");
                return 0;
            }

            if (str[i] == '}' && x != '{') {
                printf("ƥ��ʧ�ܣ�\n");
                return 0;
            }
        }
    }

    if (top != -1) { //��Ӧջ�ǿյ��������������ƥ���꣬ջ�л���������
        printf("ƥ��ʧ�ܣ�\n");
        return 0;
    } else {
        printf("ƥ��ɹ���\n");
    }

}