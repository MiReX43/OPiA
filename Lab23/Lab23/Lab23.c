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

    printf("����� ������: %d\n", length(myList));

    // ����� �� �����
    List node = getitem_name(myList, "Hello");
    if (node != NULL) {
        printf("������ ������� � ������: %s\n", node->name);
    }

    // ����� �� �����
    node = getitem_num(myList, 42);
    if (node != NULL) {
        printf("������ ������� � ������: %d\n", node->number);
    }

    destroyItem(&myList, node);
    printf("����� ��������, ����� ������: %d\n", length(myList));

    //������� 2

    insertback_int(&myList, 5);
    insertback_int(&myList, -3);
    insertback_int(&myList, 7);
    insertback_int(&myList, -2);
    insertback_int(&myList, 8);
    insertback_int(&myList, -1);
    insertback_int(&myList, 4);

    printf("�������� ������: \n");
    printlist(myList);

    // ������� ����� 10 ����� ������� �������������� ��������
    insert_after_negative(&myList);

    printf("������ ����� ������� 10 ����� ������������� �����: \n");
    printlist(myList);

    return 0;
}
