#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>

//Вычисление площади круга
float area_round(float r)
{
	return M_PI * pow(r,2);
}

//Вычисление площади прямоугольника
float area_rectangle(float a, float b)
{
	return a * b;
}

//Вычисление площади треугольника
float area_triangle(float a, float b, float c)
{
	float s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

//Рисование круга
void draw_round(char symb, int r)
{
    int diameter = 2 * r;
    for (int y = 0; y <= diameter; y++) {
        for (int x = 0; x <= diameter; x++) {
            // Условие окружности с центрированием
            float distance = sqrt((x - r) * (x - r) + (y - r) * (y - r));
            if (distance > r - 0.5 && distance < r + 0.5) {
                printf("%c ", symb);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

//Рисование прямоугольника
void draw_rectangle(int a, int b,char symb)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (i == 0 || i == a - 1 || j == 0 || j == b -1)
            {
                printf("%c ", symb);
            }
            else
            {
                printf("  ");
            }
            
        }
        printf("\n");
    }
}

//Рисоавание треугольника
void draw_triangle(int a, char symb)
{
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i || i == a)
            {
                printf("%c ", symb);
            }
            else
            {
                printf("  ");
            } 
        }
        printf("\n");
    }
}

void name(int a)
{
    if (a == 1)
    {
        printf("Это круг\n");
    }
    else if (a == 3)
    {
        printf("Это треугольник\n");
    }
    else if (a == 4)
    {
        printf("Это прямоугольник\n");
    }
    else
    {
        printf("Неизвестная фигура\n");
    }
}

int main()
{
	setlocale(LC_CTYPE, "RUS");

    int choice;
    float a, b, c, r;
    char symb;

    printf("\nМеню выбора:\n");
    printf("1. Рассчитать площадь\n");
    printf("2. Вывести определение фигуры\n");
    printf("3. Нарисовать фигуру\n");
    printf("4. Выход\n");
    printf("Выберите действие : ");
    scanf(" %d", &choice);

    switch (choice)
    {
    case 1:
        printf("Выберите фигуру для расчета площади:\n");
        printf("1. Круг\n");
        printf("2. Прямоугольник\n");
        printf("3. Треугольник\n");
        printf("Выбор: ");
        int fig;
        scanf("%d", &fig);
        if (fig == 1) {
            printf("Введите радиус круга: ");
            scanf("%f", &r);
            printf("Площадь круга: %.2f\n", area_round(r));
        }
        else if (fig == 2) {
            printf("Введите длины сторон прямоугольника (a и b): ");
            scanf("%f", &a);
            scanf("%f", &b);
            printf("Площадь прямоугольника: %.2f\n", area_rectangle(a, b));
        }
        else if (fig == 3) {
            printf("Введите длины сторон треугольника (a, b, c): ");
            scanf("%f", &a);
            scanf("%f", &b);
            scanf("%f", &c);
            printf("Площадь треугольника: %.2f\n", area_triangle(a, b, c));
        }
        break;

    case 2:

        printf("Введите количество сторон фигуры: ");
        int sides;
        scanf("%d", &sides);
        name(sides);
        break;

    case 3:

        printf("Выберите фигуру для рисования:\n");
        printf("1. Круг\n");
        printf("2. Прямоугольник\n");
        printf("3. Треугольник\n");
        printf("Выбор: ");
        scanf("%d", &fig);

        printf("Введите символ для рисования фигуры: ");
        scanf(" %c", &symb);  // Обратите внимание на пробел перед %c

        if (fig == 1) {
            int r;
            printf("Введите радиус круга: ");
            scanf("%d", &r);
            draw_round(symb,r);
        }
        else if (fig == 2) {
            printf("Введите длины сторон прямоугольника (a и b): ");
            int ia, ib;
            scanf("%d", &ia);
            scanf("%d", &ib);
            draw_rectangle(ia, ib, symb);
        }
        else if (fig == 3) {
            printf("Введите высоту треугольника: ");
            int height;
            scanf("%d", &height);
            draw_triangle(height, symb);
        }
        break;
    case 4:
        system("pause");
    }
}
