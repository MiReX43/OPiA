#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>


void main()
{
	setlocale(LC_CTYPE, "RUS");

    double a, x, res;

    int b = 133;  
    int c = 75;  

    printf("¬ведите заработок на первых 75 газетах: ");
    scanf("%lf", &a);
    printf("¬ведите заработок на каждой из остальных газет: ");
    scanf("%lf", &x);

    res = a + (b - c) * x;

    printf("ќбщий заработок мальчика за продажу %d газет: %.2f руб.\n", b, res);

    system("pause");
}