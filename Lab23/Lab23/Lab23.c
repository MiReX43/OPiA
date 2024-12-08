#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "List.h"

int main() {
    setlocale(LC_CTYPE, "RUS");
    List myList;
    initlist(&myList);

    insertfront_int(&myList, 42);
    insertback_str(&myList, "Hello");
    insertfront_int(&myList, -7);

    printf("Длина списка: %d\n", length(myList));

    // Поиск по имени
    List node = getitem_name(myList, "Hello");
    if (node != NULL) {
        printf("Найден элемент с именем: %s\n", node->name);
    }

    // Поиск по числу
    node = getitem_num(myList, 42);
    if (node != NULL) {
        printf("Найден элемент с числом: %d\n", node->number);
    }

    destroyItem(&myList, node);
    printf("После удаления, длина списка: %d\n", length(myList));

    //Задание 2

    insertback_int(&myList, 5);
    insertback_int(&myList, -3);
    insertback_int(&myList, 7);
    insertback_int(&myList, -2);
    insertback_int(&myList, 8);
    insertback_int(&myList, -1);
    insertback_int(&myList, 4);

    printf("Исходный список: \n");
    printlist(myList);

    // Вставка числа 10 после каждого отрицательного элемента
    insert_after_negative(&myList);

    printf("Список после вставки 10 после отрицательных чисел: \n");
    printlist(myList);

    return 0;
}
