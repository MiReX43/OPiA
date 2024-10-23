#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_CTYPE, "RUS");

	//Задание 5

	int X = 123456;
	float Y = 12345.0f;
	double Z = 12345.0;

	unsigned char *a1, *a2, *a3, *a4;
	unsigned char *a = (unsigned char*)&X;

	a1 = a + 3;
	a2 = a + 2;
	a3 = a + 1;
	a4 = a;

	printf("Побайтовый вывод чила: 12345\n");
	printf("Тип данных int:\n%.2d\n%.2d\n%.2d\n%.2d\n", *a1, *a2, *a3, *a4);

	unsigned char* b1, * b2, * b3, * b4;
	unsigned char* b = (unsigned char*)&Y;

	b1 = b + 3;
	b2 = b + 2;
	b3 = b + 1;
	b4 = b;

	printf("\nТип даных float:\n%.2x\n%.2x\n%.2x\n%.2x\n", *b1, *b2, *b3, *b4);

	unsigned char *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
	unsigned char *c = (unsigned char*)&Z;

	c1 = c + 7;
	c2 = c + 6;
	c3 = c + 5;
	c4 = c + 4;
	c5 = c + 3;
	c6 = c + 2;
	c7 = c + 1;
	c8 = c;

	printf("\nТип даных double:\n%.2x\n%.2x\n%.2x\n%.2x\n%.2x\n%.2x\n%.2x\n%.2x\n", *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8);

	system("pause");

	//Задание 4

	float array[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
	float *ptr_a = array;

	printf(" array: %p\n &array[0]: %p\n &array: %p\n", array, &array[0], &array);

	printf("\n");

	printf(" ptr_a = %p \n *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a++;

	printf(" ptr_a++ = %p \n *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a = ptr_a+4;

	printf(" ptr_a+4 = %p \n *ptr_a = %.1f\n", ptr_a, *ptr_a);

	ptr_a = ptr_a - 2;

	printf(" ptr_a-2 = %p \n *ptr_a = %.1f\n", ptr_a, *ptr_a);

	printf("\n");

	float *ptr_a2 = &array;

	for (int i = 0; i < 10; i += 2)
	{
		printf(" ptr_a = %p \n *ptr_a = %.1f\n", ptr_a2, *ptr_a2);
		ptr_a2 += 2;
	}

	printf("\n");

	float *ptr_a3 = &array[9];

	for (int i = 9; i >= 0; i -= 2)
	{
		printf(" ptr_a = %p \n *ptr_a = %.1f\n", ptr_a3, *ptr_a3);
		ptr_a3 -= 2;
	}
	system("pause");	

	//Задание 3

	//При выполнении pa++, указатель смещается на количество байт, равное размеру типа данных.

	//При инкременте указателя на тип _Bool, указатель смещается на 1 байт.

	_Bool *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);

	//При инкременте указателя на short unsigned int, указатель смещается на 2 байта.

	/*short unsigned int *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);*/

	//При инкременте указателя на long double, указатель смещается на 16 байт.

	/*long double *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);*/

	//При инкременте указателя на char, указатель смещается на 1 байт.

	/*char *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);*/

	//При инкременте указателя на double, указатель смещается на 8 байт.

	/*double *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);*/


	//При инкременте указателя на int, указатель смещается на 4 байта.

	/*int *pa, x = 5;
	pa = &x;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa++;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);
	pa--;
	printf("По адресу %p хранится *ptr=%g\n", pa, *pa);*/

	//Задание 2

	float PI = 3.14159, *p1, *p2;
	p1 = p2 = &PI;
	printf("По адресу p1=%p хранится *p1=%g\n", p1, *p1);
	printf("По адресу p2=%p хранится *p2=%g\n", p2, *p2);

	//Объяснения
	/*Указатели p1 и p2 указывают на одни и тот же адрес переменной PI.
	Соответсветнно оба указателя возращают одно и то же значние. Соответсвенно и объем выделеннйо памяти будет одинаковый.
	Адрес выведенный с помощью %p будте одинаковый в обоих указателях.*/

	system("pause");

	//Задание 1
	int *pi, i = 5;
	float *pf, f = 2.1f;
	printf("%lu\n", sizeof(pi));
	printf("%lu\n", sizeof(pf));

}