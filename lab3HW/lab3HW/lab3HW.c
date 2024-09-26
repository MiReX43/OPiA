#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>


double name(double U, double R)
{
	double I;
	I = U / R;
	return I;

}

void main()
{
	setlocale(LC_CTYPE, "RUS");

	double U, R, I;

	printf("Введите напряжение в электрической цепи (Вольт): ");
	scanf("%lf", &U);

	printf("Введите сопротивление в электрической цепи (Ом): ");
	scanf("%lf", &R);

	I = name(U, R);

	printf("Сила тока ровна: %lf A", I);
}
