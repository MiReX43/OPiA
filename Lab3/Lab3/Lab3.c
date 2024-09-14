#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define D 2.54
#define ID 2.32166
#define SD 2.7076
#define mor 1.852
#define suh 1.609
#define rim 1475
#define starrus 7.468
#define geo 7412.6



void main()
{
	setlocale(LC_CTYPE, "RUS");

	int a;
	int b;

	printf("Введите чило (a): ");
	scanf("%d", &a);
	printf("Введите чило (b): ");
	scanf("%d", &b);

	printf("_________________________\n");
	printf("|%7s|%7s|%7s|\n","a * b", "a + b", "a - b");

	printf("-------------------------\n");
	printf("|%3.d*%3.d|%3.d+%3.d|%3.d-%3.d|\n",a,b,a,b,a,b);
	printf("-------------------------\n");

	printf("|%7.d|%7.d|%7.d|\n",a * b,a + b,a - b);
	printf("-------------------------\n");


	//return 0;

	int mil;
	float result21;
	float result22;
	float result23;
	float result24;
	float result25;

	printf("\nВведите колличество миль: ");
	scanf("%d", &mil);

	result21 = mor * mil;
	result22 = suh * mil;
	result23 = rim * mil;
	result24 = starrus * mil;
	result25 = geo * mil;


	printf("\n%d морских милей - это %.2f м\n", mil, result21);
	printf("%d сухопутных милей - это %.2f км\n", mil, result22);
	printf("%d римских милей - это %.2f м\n", mil, result23);
	printf("%d старорусских милей - это %.2f км\n", mil, result24);
	printf("%d географических милей - это %.2f км\n", mil, result25);


	//return 0;

	int dym;
	float result;
	float result2;
	float result3;


	printf("\nВведите колличество дюймов: ");
	scanf("%d", &dym);

	result = D * dym;
	result2 = ID * dym;
	result3 = SD * dym;


	printf("\n%d дюймов - это %.2f см\n", dym, result);
	printf("%d испанских дюймов - это %.2f см\n", dym, result2);
	printf("%d старолитовских дюймов - это %.2f см\n", dym, result3);


	//return 0;

	int num;
	int num2;
	printf("\nВведите первое число: ");
	scanf("%d", &num);
	printf("Введите второе число: ");
	scanf("%d", &num2);
	printf("\nСумма: %d \nРазность: %d \nПроизведение: %d \nЧаcтное: %.2f \nОстаток: %d\n", num+num2, num-num2, num*num2, (double)num/num2, num % num2);
	
	return 0;
}