#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#define M_PI 3.14159265358979323846



void main()
{
	setlocale(LC_CTYPE, "RUS");

	//Задание 1
	double gr, rad, res;


	printf("Введите градус угал: ");
	scanf("%lf",&gr);
	rad = gr * M_PI / 180.0;
	res = sin(rad);
	printf("Раезультат: %.6lf",res );

	//Задание 2;
	
	//double y, a, b, x, t;
	 
	//printf("\nВведите значение:a ");
	//scanf("%lf", &a);
	//printf("Введите занчение b: ");
	//scanf("%lf", &b);

	//double res1 = 
	//Пример
	//double x, y, result;

	//printf("\nВведите значение x: ");
	//scanf("%lf", &x);
	//printf("Введите занчение Y: ");
	//scanf("%lf", &y);

	//double Res1 = 0.5 * y;
	//double Res2 = pow(x,Res1);
	//double Res3 = sin(Res2);
	//double Res4 = y + 8e-4;
	//double Res5 = pow(Res4, 1/5.f);
	//result = Res3 + Res5;

	//printf("\nОтвет: % .3f\n",result);
	//printf("Ответ: %.3f", sin(pow(x, 0.5 * y)) + pow(y + 8e-4, 1 / 5.f));
}