#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>



void main()
{
	setlocale(LC_CTYPE, "RUS");

	//Задание 3///////////
	int m;

	printf("Введите номер месяца: ");
	scanf("%d", &m);

	switch (m)
	{
	case 12:
	case 1:
	case 2:
		printf("Зима\n");
		break;
	case 3:
	case 4:
	case 5:
		printf("Весна\n");
		break;
	case 6:
	case 7:
	case 8:
		printf("Лето\n");
		break;
	case 9:
	case 10:
	case 11:
		printf("Осень\n");
		break;
		default:
			printf("Такого месяца нет!\n");
			break;
	}

	return 0;

	//Задание 2

	float x, y;
	char C;

	printf("Введите пример: \n");
	scanf("%f%c%f",&x,&C,&y);

	switch (C)
	{
	case '+':
		printf("=%f", x + y);
		break;
	case '-':
		printf("=%f", x - y);
		break;
	case '/':
		printf("=%f", x / y);
		break;
	case '*':
		printf("=%f", x * y);
		break;
	case '^':
		printf("=%f", pow(x,y));
		break;
	}

	//Задание 1

	char c;

	printf("\nВведите символ: ");
	scanf("%c", &c);//считывание с консоли

	switch (c)
	{
	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
	case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
	case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
	case 's': case 't': case 'u': case 'v': case 'w': case 'x':
	case 'y': case 'z':
		printf("Это буква\n");
		break;
	case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
		printf("Это цифра\n");
		break;
	default:
		printf("Неизвестный символ");
	}
	return 0;
}