#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#define M_PI 3.14159265358979323846
#define p 3



void main()
{
	setlocale(LC_CTYPE, "RUS");

	//������� 2

	double y, a, b, x;


	printf("\n������� �������� x: ");
	scanf("%lf", &x);
	
	a = sqrt(p*x);
	b = p*pow(x,2) + sqrt(a);
	y = pow(log(pow(b, 2)), 3) + a * x;

	printf("y ��� x=%.1f �����: %.1f\n", x,y);

	//������� 3

	int chet = ((int)a % 2 == 0) ^ ((int)b % 2 == 0);
	int krat = ((int)a % 3 == 0) && ((int)b % 3 == 0) && ((int)y % 3 == 0);

	printf("\n�������(������ ���� �� ����� � � � �����) ���������(1 - ��, 0 - ���): %d\n",chet);
	printf("�������(������ �� ����� �,�,� ������ ����) ���������(1 - ��, 0 - ���): %d\n",krat);


	//������� 1

	double gr, rad, res;

	printf("������� ������ ����: ");
	scanf("%lf",&gr);
	rad = gr * M_PI / 180.0;
	res = sin(rad);
	printf("����������: %.6lf",res );

	//������� 0;
	
	//double y, a, b, x, t;
	 
	//printf("\n������� ��������:a ");
	//scanf("%lf", &a);
	//printf("������� �������� b: ");
	//scanf("%lf", &b);

	//double res1 = 
	//������
	//double x, y, result;

	//printf("\n������� �������� x: ");
	//scanf("%lf", &x);
	//printf("������� �������� Y: ");
	//scanf("%lf", &y);

	//double Res1 = 0.5 * y;
	//double Res2 = pow(x,Res1);
	//double Res3 = sin(Res2);
	//double Res4 = y + 8e-4;
	//double Res5 = pow(Res4, 1/5.f);
	//result = Res3 + Res5;

	//printf("\n�����: % .3f\n",result);
	//printf("�����: %.3f", sin(pow(x, 0.5 * y)) + pow(y + 8e-4, 1 / 5.f));
}