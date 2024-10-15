#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#define N 10
#define size 100

double res(double x)
{
	return pow(x, 2) - pow(cos(x + 1), 2);
}

void array(double start, double end, double step, float B[size], int *index)
{
	for (double x = start; x <= end && *index < size; x += step)
	{
		B[*index] = res(x);
		(*index)++;
	}
}

int main()
{
	setlocale(LC_CTYPE, "RUS");

	//Задание 2
	
	float B[size];

	double step, start, end;
	int index = 0;
	double sum_pos = 0.0, sum_neg = 0.0;
	int count_pos = 0, count_neg = 0;

	printf("Функция: f(x) = x^2 - cos^2(x + 1)\n");

	printf("Введите начала интервала: ");
	scanf(" %lf", &start);

	printf("Введите введите конец интервала: ");
	scanf(" %lf", &end);

	printf("Введите шаг табуляции: ");
	scanf(" %lf", &step);

	array(start, end, step, B, &index);//Заполнение массива

	for (int i = 0; i < index; i++)
	{
		if (B[i] > 0)
		{
			sum_pos += B[i];
			count_pos++;
		}
		else if (B[i] < 0)
		{
			sum_neg += B[i];
			count_neg++;
		}
	}

	double mid_pos = (count_pos > 0) ? (sum_pos / count_pos) : 0;
	double mid_neg = (count_neg > 0) ? (sum_neg / count_neg) : 0;

	printf("Имя массива: B\n");
	printf("Накопленное значение положительных элементов: %.6lf\n", sum_pos);
	printf("Кол-во положительных элементов: %d\n", count_pos);
	printf("Среднее значение положительных элементов: %.6lf\n", mid_pos);
	
	printf("Накопленное значение отрицательных элементов: %.6lf\n", sum_neg);
	printf("Кол-во отрицательных элементов: %d\n", count_neg);
	printf("Среднее значение отрицательных элементов: %.6lf\n", mid_neg);

	system("pause");

	/*for (double x = start; x <= end && index < size ; x += step)
	{
		B[index] = res(x);
		index++;
	}*/

	/*for (int i = 0; i < index; i ++)
	{
		printf("B[%d] = %f\n", i + 1, B[i]);
	}*/

	//Задание 1

	float A[N], temp, sum = 0.0;
	
	for (int i = 0; i < N; i++)
	{
		printf("a[%d]= ", i + 1);
		scanf("%f", &temp);
		A[i] = temp;
		sum += A[i];
	}

	printf("\n_________________________________________________\n");
	printf("\n|  индекс  | исходное занчение | новое значение |\n");
	for (int i = 0; i < N; i++)
	{
		printf("|  a[%2.d]   |      a[%4.1f]      |     a[%3.1f]     |\n", i + 1, A[i], A[i]/10);
	}
	printf("_________________________________________________\n");

	printf("\nсредне арефметическое элементов массива = %.1f\n", sum / N);

}
