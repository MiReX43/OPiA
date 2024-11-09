#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void del_first_letter(char* str)
{
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isspace((unsigned)str[i]))
        {
            in_word = 0;
            putchar(str[i]);
        }
        else
        {
            if (in_word == 0)
            {
                in_word = 1;
            }
            else
            {
                putchar(str[i]);
            }
        }
    }
}

int main()
{
    char input[100];

    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);

    printf("Результат: ");
    del_first_letter(input);

}
