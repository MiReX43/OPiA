#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>

//--------------------------------------------------------
// result - ���������� ������ ���������
// ����: 
//      b - ���������� ���� �����
//      c - ���������� ����� � ������������� �����
//      a - ��������� �� ������ c �������
//      x - ��������� �� ������ �� ���������� �����
// �����: 
//      res - ����� ���������
//--------------------------------------------------------

double result(int b, int c, int a, int x )
{
    double res;
    res = a + (b - c) * x;
    return res;
}


void main()
{
	setlocale(LC_CTYPE, "RUS");

    int a, x, res;

    int b = 133;
    int c = 75;

    //���� ������
    printf("������� ��������� �� ������ 75 �������: ");
    scanf("%d", &a);
    printf("������� ��������� �� ������ �� ��������� �����: ");
    scanf("%d", &x);

    //����������
    res = result(b,c,a,x);

    //����� ����������
    printf("����� ��������� �������� �� ������� %d �����: %d ���.\n", b, res);

    system("pause");
}