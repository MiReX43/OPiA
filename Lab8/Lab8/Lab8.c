#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>

double res(double x)
{
	return pow(x, 2) - pow(cos(x + 1), 2);
}


int main()
{
	setlocale(LC_CTYPE, "RUS");


	//Задание 2

	double step, start, end, fx;

	printf("Функция: f(x) = x^2 - cos^2(x + 1)\n");

	printf("Введите начала интервала: ");
	scanf(" %lf", &start);

	printf("Введите введите конец интервала: ");
	scanf(" %lf", &end);

	printf("Введите шаг табуляции: ");
	scanf(" %lf", &step);

	printf("______________________\n");
	printf("|   x   |     f(x)   |\n");
	printf("______________________\n");

	for (double x = start; x <= end; x += step)
	{
		fx = res(x);

		printf("| %5.2lf | %10.6lf |\n", x, fx);
	}

	printf("______________________\n");

	//Задание 1А

	int degr, N;
	double res;

	printf("Введите максимальную степень: ");
	scanf("%d", &degr);

	for (N = 0; N <= degr; N++)
	{
		res = pow(2,N);
		if (res >= 1024)
		{
			printf("2^%d = %.1fK\n", degr, res / 1024);
		}
		else
		{
			printf("2^%d = %.0f\n", degr, res);
		}
	}
	

	//Залание 1

	int n, m,s = 0, k = 0;

	printf("Введите перове занчение: ");
	scanf(" %d", &n);
	printf("Введите второе занчение: ");
	scanf(" %d", &m);

	for (int i = m; i >= n; i--) {
		s += i;
		printf("Выполнено %d раз\n", k++);
	}
	printf("Результат: %d\n", s);

	//Задание 0

	char c1, c2;
	int num;

	printf("Введите кол-во символов: ");
	scanf(" %d", &num);

	printf("Введите первый символ: ");
	scanf(" %c", &c1);

	printf("Введите второй символ: ");
	scanf(" %c", &c2);

	putchar('+');
	for (int start = 1; start <= num; start++) {
		if (start <= num / 2) {
			putchar(c1);
		}
		else {
			putchar(c2);
		}
		putchar('!');
	}
	putchar('+');

	return 0;
}