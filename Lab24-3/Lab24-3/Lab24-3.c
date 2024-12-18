#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define NMAX 100

typedef struct {
    int top;
    int data[NMAX];
} IntStack;

typedef struct {
    int top;
    char data[NMAX];
} CharStack;

// Инициализация стеков
void initIntStack(IntStack* stack) {
    stack->top = -1;
}

void initCharStack(CharStack* stack) {
    stack->top = -1;
}

// Операции с целочисленным стеком
int isIntStackEmpty(IntStack* stack) {
    return stack->top == -1;
}

int isIntStackFull(IntStack* stack) {
    return stack->top == NMAX - 1;
}

void pushInt(IntStack* stack, int value) {
    if (!isIntStackFull(stack)) {
        stack->data[++stack->top] = value;
    }
    else {
        printf("Ошибка: стек операндов переполнен.\n");
    }
}

int popInt(IntStack* stack) {
    if (!isIntStackEmpty(stack)) {
        return stack->data[stack->top--];
    }
    printf("Ошибка: стек операндов пуст.\n");
    return 0;
}

// Операции со стеком символов
int isCharStackEmpty(CharStack* stack) {
    return stack->top == -1;
}

int isCharStackFull(CharStack* stack) {
    return stack->top == NMAX - 1;
}

void pushChar(CharStack* stack, char value) {
    if (!isCharStackFull(stack)) {
        stack->data[++stack->top] = value;
    }
    else {
        printf("Ошибка: стек операций переполнен.\n");
    }
}

char popChar(CharStack* stack) {
    if (!isCharStackEmpty(stack)) {
        return stack->data[stack->top--];
    }
    printf("Ошибка: стек операций пуст.\n");
    return '\0';
}

// Функция вычисления
int evaluateExpression(const char* expression) {
    IntStack operandStack;
    CharStack operatorStack;
    initIntStack(&operandStack);
    initCharStack(&operatorStack);

    int i = 0;
    while (expression[i] != '\0') {
        char ch = expression[i];

        if (isdigit(ch)) {
            // Если цифра, добавляем в стек операндов
            pushInt(&operandStack, ch - '0');
        }
        else if (ch == '+' || ch == '-') {
            // Если оператор, добавляем в стек операций
            pushChar(&operatorStack, ch);
        }
        else if (ch == '=') {
            // При встрече '=', начинаем вычисление
            while (!isCharStackEmpty(&operatorStack)) {
                int operand2 = popInt(&operandStack);
                int operand1 = popInt(&operandStack);
                char operator = popChar(&operatorStack);

                int result = 0;
                if (operator == '+') {
                    result = operand1 + operand2;
                }
                else if (operator == '-') {
                    result = operand1 - operand2;
                }
                pushInt(&operandStack, result);
            }
        }

        i++;
    }

    // Верхний элемент стека операндов — результат
    return popInt(&operandStack);
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    char expression[NMAX];
    printf("Введите арифметическое выражение (например, 5+3-9=): ");
    fgets(expression, NMAX, stdin);

    // Удалить символ новой строки, если есть
    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    int result = evaluateExpression(expression);
    printf("Результат выражения: %d\n", result);

    system("pause");
}