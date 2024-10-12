#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");

	int N;
	double sum = 0.0, sign = 1.0; //���������� ��� ����������� ������(+1 ��� - 1)

	// ���� �������� N
	printf("������� �������� < 10: ");
	scanf("%d", &N);

	// ���� ��� ���������� ���������������� ���������
	for (int i = 1; i <= N; i++)
	{	
		sum = sum + sign * (1.0 + i / 10.0); // ��������� �������� 1.1, 1.2, 1.3, ...
		sign = -sign; // ������ ���� �� ���������������
	}
	// ����� ����������
	printf("���������: %.2f\n", sum);
}