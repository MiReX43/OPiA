#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define ROW 5
#define COL 8


void fill_arr(int arr[][COL]) 
{
    for (int i = 0; i < ROW; i++) 
    {
        for (int j = 0; j < COL; j++) 
        {
            arr[i][j] = rand() % (30 - 20 + 1) + 20;
        }
    }
}

// Печать массива в виде таблицы
void print_arr_tab(int arr[][COL]) 
{
    printf("Курс                  Группа\n");
    printf("    \n");
    printf("    ");
    for (int j = 0; j < COL; j++)
    {
        printf("%5d",j+1);
    }
    printf("    \n");
    printf("    \n");
    for (int i = 0; i < ROW; i++) 
    {
        printf("%3d  ", i+1);
        for (int j = 0; j < COL; j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

void calc(int array[][COL])
{
    for (int i = 0; i < ROW; i++) {
        int total = 0;
        for (int j = 0; j < COL; j++) {
            total += array[i][j];
        }
        printf("Общее количество студентов на курсе %d: %d\n", i + 1, total);
    }
}

int main()
{
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    int array[ROW][COL];

    fill_arr(array);
    print_arr_tab(array);
    printf("\n");
    calc(array);

}
