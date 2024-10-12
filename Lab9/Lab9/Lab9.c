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