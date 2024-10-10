#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>



void main()
{
	setlocale(LC_CTYPE, "RUS");

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