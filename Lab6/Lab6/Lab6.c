#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>



void main()
{
	setlocale(LC_CTYPE, "RUS");

	//Задание 3

	double X,square, squareR, max, mid, min;

	printf("Введите значение X: ");
	scanf("%lf", &X);


    // Вычисление квадрата и квадратного корня
	square = X * X;
    squareR = sqrt(X);

    //Сравнение значений и вывод в порядке убывания
	max = (square >= X && square >= squareR) ? square : (X >= squareR ? X : squareR);
	min = (square <= X && square <= squareR) ? square : (X <= squareR ? X : squareR);
	mid = (square != max && square != min) ? square : (X != max && X != min ? X : squareR);

	//Вывод в порядкне убывания
	printf("%.2f\n", max);
	printf("%.2f\n", mid);
	printf("%.2f\n", min);

	//Задание 2

	double x, F, contrl;

	printf("Введите значение x: ");
	scanf("%lf", &x);

	if (x <= 7) contrl = -3 * x + 9;
	else contrl = 1 / (x - 7);

	F = (x <= 7) ? (-3 * x + 9) : (1 / (x - 7));

	printf("\nЗначение для проверки результата: %.2f\n",contrl);
	printf("F(%.2f) = %.2f\n", x, F);

	//Задание 1

	int year;

	printf("\nВведите год: ");
	scanf("%d", &year);


	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 
		printf("\n%d год высокостный\n", year);

	else printf("%d год НЕ высокостный\n", year);

	system("pause");
}