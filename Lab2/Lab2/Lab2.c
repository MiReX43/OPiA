#include <stdio.h>
#include <locale.h>


int main()
{
	int N = 14;
	int K = 5;

	setlocale(LC_CTYPE, "RUS");
	printf("123\n");
	printf("1\n2\n3\n");
	printf("1,\n\t2,\n\t\t3.\n");
	printf("%d,\n%3d,\n%5d.\n", 1, 2, 3);
	printf("%10.3f\n ", 12.234657);
	printf("%10.5f\n ", 12.234657);
	printf("Остаток от деления %d на %d равен %d\n", 5, 2, 5 % 2);
	printf("Остаток от деления %d на %d равен %d\n", 7, 5, 7 % 5);
	printf("Остаток от деления %d на %d равен %d\n", 2000, 4, 2000 % 4);
	printf("%g разделить %e равно %f\n ", 5., 2., 5. / 2);

	printf("%d разделить %d равно %d\n ", 5., 2., 5. / 2);
	printf("%f разделить %f равно %f\n ", 5., 2., 5. / 2);
	printf("%g разделить %g равно %g\n ", 5., 2., 5. / 2);
	printf("%e разделить %e равно %e\n ", 5., 2., 5. / 2);

	printf("Сейчас %d часов %d минут 00 секунд\n", N, K);
	printf("Идет %d минута суток\n", N * 60 + K);
	printf("До полуночи осталось %d часов и %d минут\n", 23 - N, 60 - K);
	printf("С 8.00 прошло %d секунд\n", (N - 8) * 60 * 60);
	float h = 14;
	float t = 5;
	printf("Текущий час = %.2f суток и текущая минута = %.2f часа\n", h / 24, t / 60);

	float n = 3;
	float L = 313;

	printf("Дано:\n\t%4.f\n\t%4.f\n\t_________\nОтвет:\n\t%+08.2f",n, L, n / L);

	return 0;
}
