#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>


double sin_x(double x)
{
	return sin(x);
}

double sin_N(double x, int N)
{
	double result = 0;
	double term = x;
	int sign = 1;
	for (int i = 1; i <= N; i++) {
		result += sign * term;
		term *= (x * x) / ((2 * i) * (2 * i + 1));  // следующий член ряда
		sign = -sign;  // смена знака
	}
	return result;
}

double sin_eps(double x, double eps)
{
	double result = 0;
	double term = x;
	int sign = 1;
	int i = 1;
	while (fabs(term) > eps) {
		result += sign * term;
		term *= (x * x) / ((2 * i) * (2 * i + 1));  // следующий член ряда
		sign = -sign;  // смена знака
		i++;
	}
	return result;
}

double Fa(double X)
{
	double y;
	if (X <= 3) y = pow(X, 2) - 3 * X + 9;
	else y = 1 / (pow(X,3) + 3);
	return y;
}

double Fb(double X)
{
	double y;
	y = X * exp(sin(pow(X,2)));
	return y;
}

int main()
{
	setlocale(LC_CTYPE, "RUS");

	//Задание 2

	double x;
	int N;
	double eps;

	printf("Введите значение x: ");
	scanf("%lf", &x);

	printf("Введите количество членов ряда N: ");
	scanf("%d", &N);

	printf("Введите точность eps: ");
	scanf("%lf", &eps);

	double std_result = sin_x(x);
	double series_result = sin_N(x, N);
	double eps_result = sin_eps(x, eps);

	printf("\nСтандартная функция sin(x): %lf\n", std_result);
	printf("sin(x) через разложение в ряд до N-го члена: %lf\n", series_result);
	printf("sin(x) через разложение в ряд до точности eps: %lf\n", eps_result);
	
	system("pause");

	//Задание 1

	double X;

	printf("Введите занчане x: ");
	scanf("%lf", &X);


	printf("fa(x)=%lf \nfb(x)=%lf \n",Fa(X), Fb(X));

	printf("Произведение: %lf\nРазность квадратов: %lf\nУдвоенная сумма: %lf\n", Fa(X) * Fb(X), pow(Fa(x), 2) - pow(Fb(x), 2), 2 * (Fa(x) + Fb(x)));

}