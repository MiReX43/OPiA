#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>



void main()
{
	setlocale(LC_CTYPE, "RUS");

	//������� 3

	double X,square, squareR, max, mid, min;

	printf("������� �������� X: ");
	scanf("%lf", &X);


    // ���������� �������� � ����������� �����
	square = X * X;
    squareR = sqrt(X);

    //��������� �������� � ����� � ������� ��������
	max = (square >= X && square >= squareR) ? square : (X >= squareR ? X : squareR);
	min = (square <= X && square <= squareR) ? square : (X <= squareR ? X : squareR);
	mid = (square != max && square != min) ? square : (X != max && X != min ? X : squareR);

	//����� � �������� ��������
	printf("%.2f\n", max);
	printf("%.2f\n", mid);
	printf("%.2f\n", min);

	//������� 2

	double x, F, contrl;

	printf("������� �������� x: ");
	scanf("%lf", &x);

	if (x <= 7) contrl = -3 * x + 9;
	else contrl = 1 / (x - 7);

	F = (x <= 7) ? (-3 * x + 9) : (1 / (x - 7));

	printf("\n�������� ��� �������� ����������: %.2f\n",contrl);
	printf("F(%.2f) = %.2f\n", x, F);

	//������� 1

	int year;

	printf("\n������� ���: ");
	scanf("%d", &year);


	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 
		printf("\n%d ��� �����������\n", year);

	else printf("%d ��� �� �����������\n", year);

	system("pause");
}