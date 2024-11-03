#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

double* full_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        double x = i + 1;
        ptr_array[i] = pow(x, 2) - pow(cos(x + 1), 2);
    }
    return ptr_array;
}

double* calc_elements(double* ptr_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        ptr_array[i] /= 10;
    }
    return ptr_array;
}

void put_elements(double* ptr_array, int n)
{
    printf("Вывод элементов массива:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %.2f ", ptr_array[i]);
    }
    printf("\n");
}

fill_rand_elements(double *ptr_array,int n) 
{
    for (int i = 0; i < n; i++)
    {
        ptr_array[i] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
    }
}

int find_max(double* ptr_array, int size)
{
    int max = 0;
    for (int i = 1; i < size; i++)
    {
        if (ptr_array[i] > ptr_array[max])
        {
            max = i;
        }
    }
    return max;
}

double* insert(double* ptr_array, int* size, int index, double num)
{
    *size += 1;
    ptr_array = (double*)realloc(ptr_array, (*size) * sizeof(double));

    for (int i = *size - 1; i > index; i--)
    {
        ptr_array[i] = ptr_array[i - 1];
    }

    ptr_array[index] = num;
    return ptr_array;
}

int del_max(double *ptr_array, int size)
{
    if (size < 2) {
        return size;
    }

    int max1 = find_max(ptr_array, size);
    size = delete_k(ptr_array, size, max1);

    int max2 = find_max(ptr_array,size);
    size = delete_k(ptr_array, size, max2);

    return size;
}

int delete_k(double* ptr_array, int size, int k)
{
    for (int i = k; i < (size - 1); i++)
    {
        ptr_array[i] = ptr_array[i + 1];
    }
    return size - 1;
}

int main()
{
    setlocale(LC_CTYPE, "RUS");

    //Задание 1
    double* ptr_array = NULL;
    int size;
    
    printf("Введите размер массива: ");
    scanf("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("Ошибка выделения памяти");
        return -1;
    }

    full_elements(ptr_array, size);
    put_elements(ptr_array, size);
    puts("\n");
    calc_elements(ptr_array, size);
    put_elements(ptr_array, size);
    puts("\n");

    //Задание 2

    fill_rand_elements(ptr_array, size);
    put_elements(ptr_array, size);
    puts("\n");

    //Задание 2.1

    size = del_max(ptr_array, size);
    put_elements(ptr_array, size);
    puts("\n");
    //Задание 2.2

    int max = find_max(ptr_array, size);
    ptr_array = insert(ptr_array, &size, max, -999);
    put_elements(ptr_array, size);
 

    free(ptr_array);
    return 0;
}
