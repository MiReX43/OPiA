#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shift_right(int* array, int size, int n) {
    // �������� �� ������������ ������
    if (n < 0 || size <= 0 || n >= size) {
        printf("������: �������� �������� ������.\n");
        return;
    }

    // ����� ������ �� n �������
    for (int i = size - 1; i >= n; i--) {
        array[i] = array[i - n];
    }

    // ���������� ������ n ������� ������
    for (int i = 0; i < n; i++) {
        array[i] = 0;
    }
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    setlocale(LC_CTYPE, "RUS");

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(array) / sizeof(array[0]);
    int n;

    // ���� ���������� ������� ��� ������
    printf("������� ���������� ������� ��� ������: ");
    scanf("%d", &n);

    // ������ ��������� �������
    printf("�������� ������:\n");
    print_array(array, size);

    // ���������� ������
    shift_right(array, size, n);

    // ������ ����������� �������
    printf("������ ����� ������ ������ �� %d �������:\n", n);
    print_array(array, size);

    return 0;

}