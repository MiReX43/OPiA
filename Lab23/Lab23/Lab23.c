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

    return 0;
}
