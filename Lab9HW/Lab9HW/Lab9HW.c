#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>


int main()
{
	setlocale(LC_CTYPE, "RUS");

	char c;
	int a, b;

	//���� �������
	printf("������� ������ �� �������� ����� ��������� ������: ");
	scanf(" %c", &c);

	//���� ������ ������
	printf("������� ������: ");
	scanf(" %d", &a);

	//��������� ������� ������������
	for (int row = 1; row <= a; row++)
	{
		for (int col = 1; col <= row; col++)
		{	
			// �������� ������ ������ �� ��������: ������ � ��������� �������, � ����� �� ���������
			if (col == 1 || col == row || row == a)
			{
				printf("%c ", c); // ������� ������������
			}
			else
			{
				printf("  "); // ���������� ������ ������������
			}
		}
		printf("\n");
	}
}