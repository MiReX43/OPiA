#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>

//���������� ������� �����
float area_round(float r)
{
	return M_PI * pow(r,2);
}

//���������� ������� ��������������
float area_rectangle(float a, float b)
{
	return a * b;
}

//���������� ������� ������������
float area_triangle(float a, float b, float c)
{
	float s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

//��������� �����
void draw_round(char symb, int r)
{
    int diameter = 2 * r;
    for (int y = 0; y <= diameter; y++) {
        for (int x = 0; x <= diameter; x++) {
            // ������� ���������� � ��������������
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

//��������� ��������������
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

//���������� ������������
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
        printf("��� ����\n");
    }
    else if (a == 3)
    {
        printf("��� �����������\n");
    }
    else if (a == 4)
    {
        printf("��� �������������\n");
    }
    else
    {
        printf("����������� ������\n");
    }
}

int main()
{
	setlocale(LC_CTYPE, "RUS");

    int choice;
    float a, b, c, r;
    char symb;

    printf("\n���� ������:\n");
    printf("1. ���������� �������\n");
    printf("2. ������� ����������� ������\n");
    printf("3. ���������� ������\n");
    printf("4. �����\n");
    printf("�������� �������� : ");
    scanf(" %d", &choice);

    switch (choice)
    {
    case 1:
        printf("�������� ������ ��� ������� �������:\n");
        printf("1. ����\n");
        printf("2. �������������\n");
        printf("3. �����������\n");
        printf("�����: ");
        int fig;
        scanf("%d", &fig);
        if (fig == 1) {
            printf("������� ������ �����: ");
            scanf("%f", &r);
            printf("������� �����: %.2f\n", area_round(r));
        }
        else if (fig == 2) {
            printf("������� ����� ������ �������������� (a � b): ");
            scanf("%f", &a);
            scanf("%f", &b);
            printf("������� ��������������: %.2f\n", area_rectangle(a, b));
        }
        else if (fig == 3) {
            printf("������� ����� ������ ������������ (a, b, c): ");
            scanf("%f", &a);
            scanf("%f", &b);
            scanf("%f", &c);
            printf("������� ������������: %.2f\n", area_triangle(a, b, c));
        }
        break;

    case 2:

        printf("������� ���������� ������ ������: ");
        int sides;
        scanf("%d", &sides);
        name(sides);
        break;

    case 3:

        printf("�������� ������ ��� ���������:\n");
        printf("1. ����\n");
        printf("2. �������������\n");
        printf("3. �����������\n");
        printf("�����: ");
        scanf("%d", &fig);

        printf("������� ������ ��� ��������� ������: ");
        scanf(" %c", &symb);  // �������� �������� �� ������ ����� %c

        if (fig == 1) {
            int r;
            printf("������� ������ �����: ");
            scanf("%d", &r);
            draw_round(symb,r);
        }
        else if (fig == 2) {
            printf("������� ����� ������ �������������� (a � b): ");
            int ia, ib;
            scanf("%d", &ia);
            scanf("%d", &ib);
            draw_rectangle(ia, ib, symb);
        }
        else if (fig == 3) {
            printf("������� ������ ������������: ");
            int height;
            scanf("%d", &height);
            draw_triangle(height, symb);
        }
        break;
    case 4:
        system("pause");
    }
}
