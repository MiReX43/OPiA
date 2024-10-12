#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");

	int N;
	double sum = 0.0, sign = 1.0; //Переменная для чередования знаков(+1 или - 1)

	// Ввод значения N
	printf("Введите значение < 10: ");
	scanf("%d", &N);

	// Цикл для вычисления знакопеременного выражения
	for (int i = 1; i <= N; i++)
	{	
		sum = sum + sign * (1.0 + i / 10.0); // Вычисляем значение 1.1, 1.2, 1.3, ...
		sign = -sign; // Меняем знак на противоположный
	}
	// Вывод результата
	printf("Результат: %.2f\n", sum);
}