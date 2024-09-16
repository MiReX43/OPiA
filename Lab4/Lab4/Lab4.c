#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>


int main()	
{
	setlocale(LC_CTYPE, "RUS");

	//Заадание 3

	int N;

	printf("Ведите целое трехзначное число: ");
	scanf("%d", &N);

	printf("\n Последняя цифра чиcла: %d\n Первая цифра чиcла : %d\n Сумма цифр числа: %d\n Число наоборот: %d%d%d\n", N % 10, N / 100, (N/100)+(N/10)%10+(N%10), N % 10, (N / 10) % 10, N / 100);


	//return 0;

	//Задание 2
	//При делении целых чисел (a / b) результат всегда целочисленный, 
	//поэтому даже при присваивании этого результата переменным 
	//типа float и double результат будет округлен до целого значения.

	int a = 11;
	int b = 3;
	
	printf(" Результат деления a/b с преобразованием в float: %.2f\n Результат деления a/b с преобразованием в duble: %lf\n", (float)a/b, (double)a/b);

	//Задание 1в
	//Вывод десятичного числа, соотвествующее 1 / i

	int i;
	double result;

	printf("Введите целое число: ");
	scanf("%d", &i);

	result = 1.0 / i;

	printf("Десятичное число, соотвествующее 1/%d = %lf", i, result);


	//Задание 1б
	//Вывод шестнадцатеричного и десятичного кода введенного символа.

	char s;

	printf("Введите символ: ");
	scanf("%c", &s);

	printf("Дсятичный код символа: %d\n", s);
	printf("Шестнадцатеричный код символа: %x\n", s);


	//Задание 1а
	//Вывод целой и дробной части отбельно
	double num;

	printf("Введите вещественнео число: ");
	scanf("%lf", &num);

	printf("Целая часть: %d\n", (int)num);
	printf("Дробная часть: %.3lf\n", num-(int)num);


	//Задание 1
	//Вывод различных типов данных

	char c;
	int in;
	float f;
	double d;

	printf("Введите занчение типа cahar:");
	scanf(" %c", &c);
	printf("Введите занчение типа int:");
	scanf("%d", &in);
	printf("Введите занчение типа float:");
	scanf("%f", &f);
	printf("Введите занчение типа double:");
	scanf("%lf", &d);

	printf("\nТип данных char: %c \nТип данных int: %d \nТип данных float: %f \nТип данных double: %g", c, in, f,d);

	return 0;
}