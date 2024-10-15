#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#define max 100

int main()
{
	setlocale(LC_CTYPE, "RUS");

	int n;

	printf("Введите размер массива: ");
	scanf("%d", &n);

	float A[max];

	for (int i = 0; i < n; i++)
	{
		printf("A[%d] = ", i + 1);
		scanf("%f",&A[i]);
	}
	
	int one = -1, two = -1, found = 0;
	double prod = 1;

	for (int i = 0; i < n; i++)
	{
		if (A[i] == 0)
		{
			if (one == -1)
			{
				one = i;
			}
			else
			{

				two = i;
				break;
			}
		}
	
	}

	if (one != -1 && two != -1)
	{

		for (int i = one + 1; i < two; i++)
		{
			prod *= A[i];
			found = 1;
		}

		if (found) {
			printf("Произведение элементов между первым и вторым нулевыми элементами: %.2lf\n", prod);
		}
		else
		{
			printf("Между первым и вторым нулевыми элементами нет чисел.\n");
		}
	}
		else {
			printf("Не удалось найти два нуля в массиве.\n");
		}
}
