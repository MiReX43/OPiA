#include <stdbool.h>
#ifndef _LIST_H
#define _LIST_H

struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

void initlist(List*); /* ������������� ������ ������ ���������� */
void insertfront_int(List*, int val); /* ������� � ������ ����� ����� �� ��������� ���� number=val */
void insertback_int(List*, int val); /* ������� � ������ � ����� ������ �� ��������� ���� number=val */
void insertfront_str(List*, char* str); /* ������� � ������ ����� ����� �� ��������� str � ���� name */
void insertback_str(List*, char* str); /* ������� � ������ � ����� ������ �� ��������� str � ���� name */
bool isempty(List*); /* ���������, �������� �� ������ ������ */
int length(List); /* ����������� ����� ������ */
void destroyItem(List*, List node); /* �������� ��������� ���� node �� ������ */
List getitem_name(List lst, char* str); /* ���������� ���� �� ��������� str � ���� name */
List getitem_num(List lst, int n); /* ���������� ���� �� ��������� n � ���� number */

#endif /* _LIST_H */

