#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
	setlocale(LC_CTYPE, "RUS");

	double x, y, z, a;
	x = -15.246;
	y = 4.642 * pow(10,-2);
	z = 20.001 * pow(10, 2);


	a = log(pow(y, -sqrt(fabs(x)))) * (x - y / 2) + pow(sin(atan(z)), 2);

	//Разложение на просты выражеия
	double res1 = fabs(x);
	double res2 = pow(y, -sqrt(res1));
	double res3 = log(res2);
	double res4 = (x - y / 2);
	double res5 = atan(z);
	double res6 = pow(sin(res5), 2);
	double result = res3 * res4 + res6;

	printf("a =: %.3f\n", result);
	printf("a =: %.3f\n", a);

	system("pause");
}