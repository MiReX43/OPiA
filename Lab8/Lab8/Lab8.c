#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>



void main()
{
	setlocale(LC_CTYPE, "RUS");

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