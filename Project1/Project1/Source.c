#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define a 7.1e-9

// ������� ��� ��������� ����� ������
double F(double x, double y)
{
    return (cos(pow(x, 3) + 6) - sin(y - a)) / (log(pow(x, 4)) - 2 * pow(sin(x), 5));
}

int main() {
    setlocale(LC_ALL, "RUS");

        double x, y;
        printf("������� �������� x: ");
        scanf("%lf", &x);
        printf("������� �������� y: ");
        scanf("%lf", &y);

        double result = F(x, y);

        printf("����������� ������:\n");

        printf("F(%.2lf, %.2lf) = %.6lf\n", x, y, result);

}