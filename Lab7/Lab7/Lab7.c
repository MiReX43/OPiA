#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>



void main()
{
	setlocale(LC_CTYPE, "RUS");

	//������� 3//
	int m;

	printf("������� ����� ������: ");
	scanf("%d", &m);

	// ���������� �������� switch ��� ����������� ������� ���� �� ������ ������ ������
	switch (m)
	{
	case 12:
	case 1:
	case 2:
		// ���� ����� - ������� (12), ������ (1) ��� ������� (2), ������� "����"
		printf("����\n");
		break;
	case 3:
	case 4:
	case 5:
		// ���� ����� - ���� (3), ������ (4) ��� ��� (5), ������� "�����"
		printf("�����\n");
		break;
	case 6:
	case 7:
	case 8:
		// ���� ����� - ���� (6), ���� (7) ��� ������ (8), ������� "����"
		printf("����\n");
		break;
	case 9:
	case 10:
	case 11:
		// ���� ����� - �������� (9), ������� (10) ��� ������ (11), ������� "�����"
		printf("�����\n");
		break;
		// ���� ������� ������������ �������� (�� �� 1 �� 12), ������� ��������� �� ������
		default:
			printf("������ ������ ���!\n");
			break;
	}

	//������� 2

	float x, y;
	char C;

	printf("������� ������: \n");
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

	//������� 1

	char c;

	printf("\n������� ������: ");
	scanf("%c", &c);//���������� � �������

	switch (c)
	{
	case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
	case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
	case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
	case 's': case 't': case 'u': case 'v': case 'w': case 'x':
	case 'y': case 'z':
		printf("��� �����\n");
		break;
	case '0': case '1': case '2': case '3': case '4': case '5':
	case '6': case '7': case '8': case '9':
		printf("��� �����\n");
		break;
	default:
		printf("����������� ������");
	}
	return 0;
}