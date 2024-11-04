#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define max_size 50
#define min_size 10

void fill_rand_elements(double *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() / (double)RAND_MAX) * 20.0 - 10.0;
    }
}

void put_elements(const double *arr, int n, const char *name)
{
    printf("Вывод элементов массива %s:\n", name);
    for (int i = 0; i < n; i++)
    {
        printf(" %.2f ", arr[i]);
    }
    printf("\n");
}

double* new_arr(double* a, int n, double* b, int m, int* new_size)
{
    int last_neg = -1;
    for (int i = 0; i < m; i++)
    {
        if (b[i] < 0) {
            last_neg = i;
        }
    }

    int b_count = (last_neg == -1) ? m : m - last_neg - 1;
    int a_count = (n >= 5) ? 5 : n;

    *new_size = b_count + a_count;
    double* d = (double*)malloc(*new_size * sizeof(double));
    if (d == NULL)
    {
        printf("Ошибка выделениея памяти!\n");
    }

    for (int i = 0; i < b_count; i++)
    {
        d[i] = b[last_neg + 1 + i];
    }
    for (int i = 0; i < a_count; i++)
    {
        d[b_count + i] = a[i];
    }

    return d;
}


int main()
{
    setlocale(LC_CTYPE, "RUS");

    int n = rand() % (max_size - min_size + 1) + min_size;
    int m = rand() % (max_size - min_size + 1) + min_size;
    int l = rand() % (max_size - min_size + 1) + min_size;

    double* a = (double*)malloc(n * sizeof(double));
    double* b = (double*)malloc(m * sizeof(double));
    double* c = (double*)malloc(l * sizeof(double));

    if (a == NULL || b == NULL || c == NULL)
    {
        printf("Ошибка выделения памяти\n");
        return -1;
    }

    fill_rand_elements(a,n);
    fill_rand_elements(b, m);
    fill_rand_elements(c, l);

    put_elements(a, n, "Массив a");
    put_elements(b, m, "Массив b");
    put_elements(c, l, "Массив c");

    int new_size;
    double* d = new_arr(a, n, b, m, &new_size);
    put_elements(d, new_size, "Массив d");

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}