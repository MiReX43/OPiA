#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shift_right(int* array, int size, int n) {
    // Проверка на корректность сдвига
    if (n < 0 || size <= 0 || n >= size) {
        printf("Ошибка: неверный параметр сдвига.\n");
        return;
    }

    // Сдвиг вправо на n позиций
    for (int i = size - 1; i >= n; i--) {
        array[i] = array[i - n];
    }

    // Заполнение первых n позиций нулями
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

    // Ввод количества позиций для сдвига
    printf("Введите количество позиций для сдвига: ");
    scanf("%d", &n);

    // Печать исходного массива
    printf("Исходный массив:\n");
    print_array(array, size);

    // Выполнение сдвига
    shift_right(array, size, n);

    // Печать измененного массива
    printf("Массив после сдвига вправо на %d позиций:\n", n);
    print_array(array, size);

    return 0;

}