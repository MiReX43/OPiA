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
    printf("������ ����� �����: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_double_array(double* arr, int n)
{
    printf("������ ������������ �����: \n");
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

    printf("����������� ������������� ������:\n");
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

    // ���� "������ �����"
    int m = 1 + rand() % 10;
    int k;

    printf("�������� ����� �� 1 �� 10: ");
    scanf("%d", &k);

    if (k == m)
    {
        printf("�� ������� ����� %d! �����������!\n", k);
    }
    else
    {
        printf("�� �� �������. ���������� ����� ���� %d.\n", m);
    }

    system("pause");

    // ���� "������, �������, ������"
    int player, comp;
    const char* options[] = { "������", "�������", "������" };

    comp = rand() % 3;

    printf("��������: 0 - ������, 1 - �������, 2 - ������: ");
    scanf("%d", &player);

    printf("�� �������: %s\n", options[player]);
    printf("��������� ������: %s\n", options[comp]);

    if (player == comp)
    {
        printf("�����\n");
    }
    else if ((player == 0 && comp == 1) ||
        (player == 1 && comp == 2) ||
        (player == 2 && comp == 0))
    {
        printf("�� �������� :)\n");
    }
    else
    {
        printf("�� ��������� :(\n");
    }

    system("pause");

    int sing_int = rand10(10);
    double sing_double = rand_double(1.0, 5.0);

    printf("��������� ����� ����� �� 1 �� 10: %d\n", sing_int);
    printf("��������� ������������ ����� �� 1.0 �� 5.0: %.2f\n", sing_double);

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
    printf("������� ����������� �������� ���������: ");
    scanf("%d", &min);
    printf("������� ������������ �������� ���������: ");
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
