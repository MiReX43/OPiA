#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void to_uppercase(char* str) 
{
    while (*str) 
    {
        *str = toupper((unsigned char)*str);
        str++;
    }
    return str;
}

void marks(char* str, int total_length) 
{
    int length = strlen(str);
    while (length < total_length - 1) 
    {
        str[length++] = '!';
    }
    str[length] = '\0';
}

void reverse(char* str) 
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main()
{
    srand(time(NULL));

    //Ex.1-2

    char Snew[40] = "Hi, "; 
    char Name[20];

    printf("Enter your name: ");

    scanf("%s", Name);

    reverse(Name);

    strcat(Snew, Name);

    to_uppercase(Snew);

    marks(Snew, 40);

    printf("%s!\n", Snew);

    system("pause");
}
