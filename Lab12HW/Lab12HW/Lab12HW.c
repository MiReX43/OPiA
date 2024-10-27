#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>

int size_char()
{
	char array[2];               
	char* start = (char*)&array; 
	return (char*)(&array[1]) - start; 
}

int size_short_int()
{
	short int array[2];
	char* start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_unsigned_short_int()
{
	unsigned short array[2];
	char *start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_int()
{
	int array[2];
	char* start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_unsigned_char()
{
	unsigned char array[2];
	char *start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_wchar_t()
{
	wchar_t array[2];
	char* start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_long_long_int()
{
	long long int array[2];
	char* start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_size_t()
{
	size_t array[2];
	char* start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_float()
{
	float array[2];
	char* start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_double()
{
	double array[2];
	char* start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int size_signed_int()
{
	signed int array[2];
	char* start = (char*)&array;
	return (char*)(&array[1]) - start;
}

int main()
{
	setlocale(LC_CTYPE, "RUS");

	printf("Размер char: %d байт\n", size_char());
	printf("Размер short int: %d байт\n", size_short_int());
	printf("Размер unsigned short int: %d байт\n", size_unsigned_short_int());
	printf("Размер int: %d байт\n", size_int());
	printf("Размер unsigned char: %d байт\n", size_unsigned_char());
	printf("Размер wchar_t: %d байт\n", size_wchar_t());
	printf("Размер long long int: %d байт\n", size_long_long_int());
	printf("Размер size_t: %d байт\n", size_size_t());
	printf("Размер float: %d байт\n", size_float());
	printf("Размер double: %d байт\n", size_double());
	printf("Размер signed int: %d байт\n", size_signed_int());

	system("pause");

}