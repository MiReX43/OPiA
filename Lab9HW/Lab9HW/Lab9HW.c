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

	//¬вод символа
	printf("¬ведите символ из которого будет строитьс€ фигура: ");
	scanf(" %c", &c);

	//¬вод высоты фигуры
	printf("¬ведите высоту: ");
	scanf(" %d", &a);

	//–исование контура треугольника
	for (int row = 1; row <= a; row++)
	{
		for (int col = 1; col <= row; col++)
		{	
			// ѕечатаем символ только на границах: первый и последний столбцы, а также на диагонали
			if (col == 1 || col == row || row == a)
			{
				printf("%c ", c); // √раницы треугольника
			}
			else
			{
				printf("  "); // ¬нутренние пустые пространства
			}
		}
		printf("\n");
	}
}