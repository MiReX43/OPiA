#include <stdbool.h>
#ifndef _LIST_H
#define _LIST_H

struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

void initlist(List*); /* инициализация списка пустым содержимым */
void insertfront_int(List*, int val); /* вставка в список перед узлом со значением поля number=val */
void insertback_int(List*, int val); /* вставка в список в конец списка со значением поля number=val */
void insertfront_str(List*, char* str); /* вставка в список перед узлом со значением str в поле name */
void insertback_str(List*, char* str); /* вставка в список в конец списка со значением str в поле name */
bool isempty(List*); /* проверяет, является ли список пустым */
int length(List); /* определение длины списка */
void destroyItem(List*, List node); /* удаление заданного узла node из списка */
List getitem_name(List lst, char* str); /* нахождение узла со значением str в поле name */
List getitem_num(List lst, int n); /* нахождение узла со значением n в поле number */

#endif /* _LIST_H */

