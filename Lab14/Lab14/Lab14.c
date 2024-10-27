#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#define N 1000

double *full_elements(double *ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		double x = i + 1;
		ptr_array[i] = pow(x, 2) - pow(cos(x + 1), 2);
	}
	return ptr_array;
}

int put_elements(double *ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %.2f ", ptr_array[i]);
	}
	printf("\n");
}

double* calc_elements(double *ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] /= 10;
	}
	return ptr_array;
}

double sum_elements(double* ptr_array, int begin, int end)
{
	double sum = 0.0;
	for (int i = begin; i <= end; i++)
	{
		sum += ptr_array[i];
	}
	return sum;
}

int find_elements(double* ptr_array, int n,double element)
{
	double eps = 0.01;
	for (int i = 0; i < n; i++)
	{
		if (fabs(ptr_array[i] - element) < eps)
			return i;
	}
	return -1;
}

int function(double* ptr_array, int n, int type)
{
	for (int i = 0; i < n; i++)
	{
		if (type == 1 && ptr_array[i] > 0)
		{
			return i;
		}
		else if(type == -1 && ptr_array[i] < 0)
		{
			return i;
		}
		else if(type == 0 && ptr_array[i] == 0)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	setlocale(LC_CTYPE, "RUS");

	//������� 1

	double array[N];
	int size;

	printf("������� ������ ������ > ");
	scanf("%d", &size);

	full_elements(array, size);
	printf("������ ����� ����������:\n");
	put_elements(array, size);

	calc_elements(array, size);
	printf("������ ����� ���������:\n");
	put_elements(array, size);

	system("pause");

	//������� 2

	int begin, end;
	printf("������� ��������� ������: ");
	scanf("%d", &begin);
	printf("������� �������� ������: ");
	scanf("%d", &end);

	printf("����� ��������� ������� �� ������� %d �� %d: %.2f\n", begin, end, sum_elements(array,begin,end));
	
	system("pause");

	double element;
	printf("������� ������� ������� ������ �����: ");
	scanf("%lf", &element);

	int index = (find_elements(array, size, element));

	if (index != -1)
	{
		printf("%.2lf ����������� �������� � �������� %d\n", element, index);
	}
	else
	{
		printf("%.2lf �� ������� � �������\n",element);
	}

	//������� 3

	int type;
	printf("������� ��� �������� ��� ������ (1 - �������������, -1 - �������������, 0 - �������): ");
	scanf("%d", &type);

	int ind = function(array, size, type);
	if (ind != -1)
	{
		printf("������ ������� � ����� %d ������ �� �������: %d\n",type, ind);
	}
	else
	{
		printf("������� � ����� %d �� ������ � �������\n",type);
	}
}
