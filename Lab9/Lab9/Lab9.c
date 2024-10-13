#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#define ROW 9
#define COL 9

int main()
{
	setlocale(LC_CTYPE, "RUS");

	//Задание 2

	while (1) {

		long long num;
		int sum = 0;
		char a;

		printf("Введите число: ");
		scanf("%lld", &num);

		while (num != 0)
		{
			int dig = num % 10;
			if (dig % 2 != 0)
			{
				sum += dig;
			}
			num /= 10;
		}

		printf("Сумма нечетных цифр: %d\n", sum);

		printf("Продолжить? (Да - y, Нет - n): ");

		getchar();

		a = getchar();

		if (a == 'n')
		{
			break;
		}
	}

	system("pause");
	//Задание 1

	int row, col;

	printf("\n");

	//Левый верхний единицами ИЗ

	for (row = 5; row >= 1; --row)
	{
		for (col = 1; col <= row; col++)
		printf(" 1 ");
		printf("\n");
	}

	system("pause");

	//Левый нижний угол ТБ
	printf("\n");
	for (row = 1; row <= ROW; ++row)
	{
		for (col = 1; col <= row; col++)
		printf("%5d", col*row);
		printf("\n");
	}

	system("pause");

	//Обычная ТБ
	printf("\n");
	for (row = 1; row <= ROW; ++row)
	{
		for (col = 1; col <= COL; col++)
			printf("%5d", col * row);
		printf("\n");
	}
}