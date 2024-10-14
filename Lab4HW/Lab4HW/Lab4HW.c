#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>

//--------------------------------------------------------
// result - вычисление общего заработка
// Вход: 
//      b - количество всех газет
//      c - количество газет с фиксированной ценой
//      a - заработок на первых c газетах
//      x - заработок на каждой из оставшихся газет
// Выход: 
//      res - общий заработок
//--------------------------------------------------------

double result(int b, int c, int a, int x )
{
    double res;
    res = a + (b - c) * x;
    return res;
}


void main()
{
	setlocale(LC_CTYPE, "RUS");

    int a, x, res;

    int b = 133;
    int c = 75;

    //Ввод данных
    printf("Введите заработок на первых 75 газетах: ");
    scanf("%d", &a);
    printf("Введите заработок на каждой из остальных газет: ");
    scanf("%d", &x);

    //вычисления
    res = result(b,c,a,x);

    //Вывод результата
    printf("Общий заработок мальчика за продажу %d газет: %d руб.\n", b, res);

    system("pause");
}