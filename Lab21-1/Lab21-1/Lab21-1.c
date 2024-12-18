#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define NMAX 100
#define TYPE char
#define FTYPE "%3c,"

typedef struct Stack {
    int top;
    TYPE data[NMAX];
} stack;

int isempty(stack* s) {
    return s->top == 0;
}

int isfull(stack* s) {
    return s->top == NMAX - 1;
}

int push(stack* s, TYPE a) {
    if (!isfull(s)) {
        s->data[++s->top] = a;
        return 1; // ������� ���������
    }
    return 0; // ���� �����
}

TYPE pop(stack* s) {
    if (!isempty(s)) {
        return s->data[s->top--];
    }
    return '\0'; // ������: ���� ����
}

TYPE top(stack* s) {
    if (!isempty(s)) {
        return s->data[s->top];
    }
    return '\0'; // ������: ���� ����
}

void display(stack* s) {
    int i = s->top;
    while (i > 0)
        printf(FTYPE, s->data[i--]);
    printf("\n");
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    stack s;
    s.top = 0; // ������������� �����

    char input[NMAX];
    printf("������� ������: ");
    fgets(input, NMAX, stdin);

    // ������� ������ ����� ������
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // ��������� ���� ��������� ������
    for (size_t i = 0; i < strlen(input); i++) {
        if (!push(&s, input[i])) {
            printf("���� �����, ������ '%c' �� ����� ���� ��������.\n", input[i]);
            break;
        }
    }

    // ������� ���������� �����
    printf("���������� �����: ");
    display(&s);

    return 0;
}
