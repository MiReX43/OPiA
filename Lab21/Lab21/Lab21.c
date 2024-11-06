#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define R 50
#define N 100

int rand10(int mmax)
{
    return 1 + rand() % mmax;
}

double rand_double(double dmin, double dmax)
{
    double scale = rand() / (double)RAND_MAX;
    return dmin + scale * (dmax - dmin);
}

int* rand10_arr(int n, int mmax)
{
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand10(mmax);
    }
    return arr;
}

double* rand_double_arr(int n, double dm)
{
    double* arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand_double(-dm, dm);
    }
    return arr;
}

void print_int_array(int* arr, int n)
{
    printf("Массив целых чисел: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_double_array(double* arr, int n)
{
    printf("Массив вещественных чисел: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void calc_k(int *array, int n, int * counter, int k)
{
    for (int i = 0; i < n; i++)
    {
        counter[array[i] - 1]++;
    }
}

void histog(int* counter, int k, int max_symbols)
{
    int max_count = 0;
    for (int i = 0; i < k; i++) {
        if (counter[i] > max_count) {
            max_count = counter[i];
        }
    }

    printf("Гистограмма распределения частот:\n");
    for (int i = 0; i < k; i++) {
        int normalized_length = (int)((double)counter[i] / max_count * max_symbols);
        printf("%2d | ", i + 1);
        for (int j = 0; j < normalized_length; j++) {
            printf("*");
        }
        printf(" (%d)\n", counter[i]);
    }
}

int rand_in_range(int mmin, int mmax) {
    return mmin + rand() % (mmax - mmin + 1);
}

int* rand_arr(int n, int mmin, int mmax)
{
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand_in_range(mmin,mmax);
    }
    return arr;
}

int main()
{
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    // Игра "Угадай число"
    int m = 1 + rand() % 10;
    int k;

    printf("Угадайте число от 1 до 10: ");
    scanf("%d", &k);

    if (k == m)
    {
        printf("Вы угадали число %d! Поздравляем!\n", k);
    }
    else
    {
        printf("Вы не угадали. Загаданное число было %d.\n", m);
    }

    system("pause");

    // Игра "Камень, ножницы, бумага"
    int player, comp;
    const char* options[] = { "Камень", "Ножницы", "Бумага" };

    comp = rand() % 3;

    printf("Выберите: 0 - Камень, 1 - Ножницы, 2 - Бумага: ");
    scanf("%d", &player);

    printf("Вы выбрали: %s\n", options[player]);
    printf("Противник выбрал: %s\n", options[comp]);

    if (player == comp)
    {
        printf("Ничья\n");
    }
    else if ((player == 0 && comp == 1) ||
        (player == 1 && comp == 2) ||
        (player == 2 && comp == 0))
    {
        printf("Вы победили :)\n");
    }
    else
    {
        printf("Вы проиграли :(\n");
    }

    system("pause");

    int sing_int = rand10(10);
    double sing_double = rand_double(1.0, 5.0);

    printf("Случайное целое число от 1 до 10: %d\n", sing_int);
    printf("Случайное вещественное число от 1.0 до 5.0: %.2f\n", sing_double);

    int n = 10;
    int* int_array = rand10_arr(n, 10);
    double* double_array = rand_double_arr(n, 5.0);

    print_int_array(int_array, n);
    print_double_array(double_array, n);

    free(int_array);
    free(double_array);

    system("pause");

    //Ex 3
    
    int min, max;
    printf("Введите минимальное значение диапазона: ");
    scanf("%d", &min);
    printf("Введите максимальное значение диапазона: ");
    scanf("%d", &max);

    int K = max - min + 1;
    int* array = rand_arr(N, min, max); 
    int* counter = (int*)calloc(K, sizeof(int));

    for (int i = 0; i < K; i++) {
        counter[i] = 0;
    }

    calc_k(array, N, counter, K, min, max);

    histog(counter, K, R);

    free(array);
    free(counter);

    return 0;

}
