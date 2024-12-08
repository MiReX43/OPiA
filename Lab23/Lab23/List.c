#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

void initlist(List* lst) {
    *lst = NULL;
}

void insertfront_int(List* lst, int val) {
    List newNode = (List)malloc(sizeof(struct listitem));
    newNode->number = val;
    newNode->name[0] = '\0'; // пустое имя
    newNode->next = *lst;
    *lst = newNode;
}

void insertback_int(List* lst, int val) {
    List newNode = (List)malloc(sizeof(struct listitem));
    newNode->number = val;
    newNode->name[0] = '\0'; // пустое имя
    newNode->next = NULL;

    if (*lst == NULL) {
        *lst = newNode;
    }
    else {
        List current = *lst;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertfront_str(List* lst, char* str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    newNode->number = 0; // пустое число
    strncpy(newNode->name, str, 80);
    newNode->name[79] = '\0'; // защищаем от переполнения
    newNode->next = *lst;
    *lst = newNode;
}

void insertback_str(List* lst, char* str) {
    List newNode = (List)malloc(sizeof(struct listitem));
    newNode->number = 0; // пустое число
    strncpy(newNode->name, str, 80);
    newNode->name[79] = '\0'; // защищаем от переполнения
    newNode->next = NULL;

    if (*lst == NULL) {
        *lst = newNode;
    }
    else {
        List current = *lst;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool isempty(List* lst) {
    return *lst == NULL;
}

int length(List lst) {
    int count = 0;
    while (lst != NULL) {
        count++;
        lst = lst->next;
    }
    return count;
}

void destroyItem(List* lst, List node) {
    if (*lst == NULL || node == NULL) return;

    if (*lst == node) {
        *lst = (*lst)->next;
        free(node);
        return;
    }

    List current = *lst;
    while (current->next != NULL && current->next != node) {
        current = current->next;
    }

    if (current->next == node) {
        current->next = node->next;
        free(node);
    }
}

List getitem_name(List lst, char* str) {
    while (lst != NULL) {
        if (strcmp(lst->name, str) == 0) {
            return lst;
        }
        lst = lst->next;
    }
    return NULL;
}

List getitem_num(List lst, int n) {
    while (lst != NULL) {
        if (lst->number == n) {
            return lst;
        }
        lst = lst->next;
    }
    return NULL;
}


void printlist(List lst) {
    while (lst != NULL) {
        printf("%d ", lst->number);
        lst = lst->next;
    }
    printf("\n");
}

// Функция для вставки числа 10 после каждого отрицательного числа
void insert_after_negative(List* lst) {
    List current = *lst;
    while (current != NULL) {
        if (current->number < 0) {
            List newNode = (List)malloc(sizeof(struct listitem));
            newNode->number = 10;
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;  // Переходим к следующему элементу после вставленного
        }
        else {
            current = current->next;
        }
    }
}