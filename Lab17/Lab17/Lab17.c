#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 10000

void sort_buble(int* ptrarr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ptrarr[j] > ptrarr[j + 1]) {
                int temp = ptrarr[j];
                ptrarr[j] = ptrarr[j + 1];
                ptrarr[j + 1] = temp;
            }
        }
    }
}

void sort_shaker(int *ptrarr,int n)
{
    int left = 0, right = n - 1;
    int flag = 1;

    while (left < right && flag) {
        flag = 0;

        for (int i = left; i < right; i++) {
            if (ptrarr[i] > ptrarr[i + 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = temp;
                flag = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (ptrarr[i - 1] > ptrarr[i]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = temp;
                flag = 1;
            }
        }
        left++;
    }
}

void sort_select(int* ptrarr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = ptrarr[i];
            ptrarr[i] = ptrarr[min_idx];
            ptrarr[min_idx] = temp;
        }
    }
}

void sort_insert(int *ptrarr, int n) {
    for (int i = 1; i < n; i++) {
        int key = ptrarr[i];
        int j = i - 1;
        while (j >= 0 && ptrarr[j] > key) {
            ptrarr[j + 1] = ptrarr[j];
            j--;
        }
        ptrarr[j + 1] = key;
    }
}

void fill_arr(int* ptrarr, int n){
    for (int i = 0; i < n; i++){
        ptrarr[i] = ((double)rand() / RAND_MAX) * 20 - 10;
    }
}

void print_arr(int *ptrarr, int n){
    for (int i = 0; i < n; i++) {
        printf("%d ", ptrarr[i]);
    }
    printf("\n");
}

void comb_sort(int* arr, int n, float shrink_factor) {
    int gap = n; // Начальное расстояние
    int sorted = 0; // Флаг, если массив отсортирован

    while (gap > 1 || !sorted) {
        // Уменьшаем расстояние
        gap = (int)(gap / shrink_factor);
        if (gap < 1) gap = 1;

        sorted = 1; // Предполагаем, что массив отсортирован

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                sorted = 0; // Найдена несортированная пара
            }
        }
    }
}

void copy_arr(int* src, int* dest, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

double measure_time(int* arr, int n, float shrink_factor) {
    clock_t start = clock();
    comb_sort(arr, n, shrink_factor);
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

int main(){
    setlocale(LC_CTYPE, "RUS");

    //Задание 1-2

    int ptrarr[SIZE];
    int size;
    float time;

    printf("Введите размер массива: ");
    scanf("%d", &size);

    fill_arr(ptrarr, size);
    print_arr(ptrarr, size);

    printf("\n");

    printf("Пузырьковая сортировка: ");
    fill_arr(ptrarr, size);
    clock_t t1 = clock();
    sort_buble(ptrarr, size);
    time = (float)(clock() - t1) / CLOCKS_PER_SEC;
    print_arr(ptrarr, size);
    printf("Время выполнения: %.6f секунд\n", time);

    printf("\n");

    printf("Шейкерная сортировка: ");
    fill_arr(ptrarr, size);
    clock_t t2 = clock();
    sort_shaker(ptrarr, size);
    time = (float)(clock() - t2) / CLOCKS_PER_SEC;
    print_arr(ptrarr, size);
    printf("Время выполнения: %.6f секунд\n", time);

    printf("\n");

    printf("Cортировка прстым выбором: ");
    fill_arr(ptrarr, size);
    clock_t t3 = clock();
    sort_select(ptrarr, size);
    time = (float)(clock() - t3) / CLOCKS_PER_SEC;
    print_arr(ptrarr, size);
    printf("Время выполнения: %.6f секунд\n", time);

    printf("\n");

    printf("Cортировка вставками: ");
    fill_arr(ptrarr, size);
    clock_t t4 = clock();
    sort_insert(ptrarr, size);
    time = (float)(clock() - t4) / CLOCKS_PER_SEC;
    print_arr(ptrarr, size);
    printf("Время выполнения: %.6f секунд\n", time);

    //Задание 3
    int n = 10000;
    int arr[SIZE], temp[SIZE];
    float shrink_factors[] = { 1.2, 1.3, 1.4, 1.5 };
    int num_factors = sizeof(shrink_factors) / sizeof(shrink_factors[0]);

    fill_arr(arr, n);

    printf("Оценка влияния shrink factor на скорость сортировки:\n");
    printf("Размер массива: %d\n", n);
    printf("Shrink Factor\tВремя (секунд)\n");

    for (int i = 0; i < num_factors; i++) {
        copy_arr(arr, temp, n);
        double time = measure_time(temp, n, shrink_factors[i]);
        printf("%.2f\t\t%.6f\n", shrink_factors[i], time);
    }
}