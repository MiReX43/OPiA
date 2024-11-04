#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_CARS 10

struct ����������
{
    char �����[50];
    char �������������[50];
    char ���[50];
    int ���_�������;
    int ���_�����������;
};

void ����_����������(struct ����������* ����������) {
    printf("������� ����� ����������: ");
    scanf("%49s", ����������->�����);
    printf("������� ������������� ����������: ");
    scanf("%49s", ����������->�������������);
    printf("������� ��� ����������: ");
    scanf("%49s", ����������->���);
    printf("������� ��� ������� ����������: ");
    scanf("%d", &����������->���_�������);
    printf("������� ��� ����������� ����������: ");
    scanf("%d", &����������->���_�����������);
}

void �����_����������(struct ���������� ����������) {
    printf("�����: %s\n", ����������.�����);
    printf("�������������: %s\n", ����������.�������������);
    printf("���: %s\n", ����������.���);
    printf("��� �������: %d\n", ����������.���_�������);
    printf("��� �����������: %d\n", ����������.���_�����������);
    printf("\n");
}

int main()
{
    setlocale(LC_CTYPE, "RUS");

    struct ���������� ����������[MAX_CARS];
    int n;

    // ���� ���������� �����������
    printf("������� ���������� ����������� (�� 5 �� 10): ");
    scanf("%d", &n);
    if (n < 5 || n > 10) {
        printf("������: ������� ���������� �� 5 �� 10.\n");
        return 1;
    }

    // ���� ������ ��� ������� ����������
    for (int i = 0; i < n; i++) {
        printf("\n���������� %d:\n", i + 1);
        ����_����������(&����������[i]);
    }

    // ����� � ����� ����������� ����� "Toyota" � ����� ����������� �� 2007
    printf("\n���������� ����� 'Toyota', ������������������ �� 2007 ����:\n");
    int ������� = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(����������[i].�����, "Toyota") == 0 && ����������[i].���_����������� < 2007) {
            �����_����������(����������[i]);
            ������� = 1;
        }
    }

    if (!�������) {
        printf("��� �����������, ��������������� ���������.\n");
    }

    return 0;

}