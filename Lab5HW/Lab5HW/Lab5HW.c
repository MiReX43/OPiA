#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	setlocale(LC_CTYPE, "RUS");

	double x, y, z, a;

	//Ввод данных
	printf("Введите значение 'x': ");
	scanf("%lf", &x);
	printf("Введите значение 'y': ");
	scanf("%lf", &y);
	printf("Введите значение 'z': ");
	scanf("%lf", &z);

	//Вычисления
	a = log(pow(y, -sqrt(fabs(x)))) * (x - y / 2) + pow(sin(atan(z)), 2);

	//Разложение на просты выражеия
	double res1 = fabs(x);
	double res2 = pow(y, -sqrt(res1));
	double res3 = log(res2);
	double res4 = (x - y / 2);
	double res5 = atan(z);
	double res6 = pow(sin(res5), 2);
	double result = res3 * res4 + res6;

	//Вывод результата
	printf("a =: %.3lf\n", result);
	printf("a =: %.3lf\n", a);

	system("pause");
}