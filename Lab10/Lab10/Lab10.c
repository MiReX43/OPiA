#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>


double sin_x(double x)
{
	return sin(x);
}

double sin_n(double x, int N)
{

}

double sin_eps(double x, double eps)
{

}

double Fa(double x)
{
	double y;
	if (x <= 3) y = pow(x, 2) - 3 * x + 9;
	else y = 1 / (pow(x,3) + 3);
	return y;
}

double Fb(double x)
{
	double y;
	y = x * exp(sin(pow(x,2)));
	return y;
}

int main()
{
	setlocale(LC_CTYPE, "RUS");

	//Задание 2



	//Задание 1

	double x;

	printf("Введите занчане x: ");
	scanf("%lf", &x);


	printf("fa(x)=%lf \nfb(x)=%lf\n",Fa(x), Fb(x));

	printf("Произведение: %lf\nРазность квадратов: %lf\nУдвоенная сумма: %lf\n", Fa(x) * Fb(x), pow(Fa(x), 2) - pow(Fb(x), 2), 2 * (Fa(x) + Fb(x)));

}