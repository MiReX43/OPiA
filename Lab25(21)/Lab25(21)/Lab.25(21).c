#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define SIZE 5

// ��������� Car
struct Car {
    char brand[50];
    char manufacturer[50];
    char type[50];
    int year_of_manufacture;
    int year_of_registration;
};

typedef struct Car car_t;

// ��������� ��������� �����
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

const char* brands[] = { "Toyota", "Ford", "BMW", "Honda", "Chevrolet" };
const char* manufacturers[] = { "Japan", "USA", "Germany", "Italy", "South Korea" };
const char* types[] = { "Sedan", "SUV", "Truck", "Hatchback", "Coupe" };

void random_string(char* str, const char* arr[], int arr_size) {
    int index = rand() % arr_size;
    strcpy(str, arr[index]);
}

// ���������� �������
void fill_array(car_t* cars, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        random_string(cars[i].brand, brands, sizeof(brands) / sizeof(brands[0]));
        random_string(cars[i].manufacturer, manufacturers, sizeof(manufacturers) / sizeof(manufacturers[0]));
        random_string(cars[i].type, types, sizeof(types) / sizeof(types[0]));
        cars[i].year_of_manufacture = getRandomNumber(2000, 2024);
        cars[i].year_of_registration = getRandomNumber(2000, 2024);
    }
}

// ������ ����� ������
void print_car(car_t car) {
    printf("| %-15s || %-15s || %-15s || %-4d || %-4d |\n", car.brand, car.manufacturer, car.type, car.year_of_manufacture, car.year_of_registration);
}

// ������ ���� �������
void print_array(car_t* cars, int size) {
    for (int i = 0; i < size; i++) {
        print_car(cars[i]);
    }
}

// ����� �� ����� ����������
car_t* search_car_by_brand(car_t* cars, int size, char* brand) {
    for (int i = 0; i < size; i++) {
        if (strcmp(cars[i].brand, brand) == 0) {
            return &cars[i];
        }
    }
    return NULL;
}

// ��������� �� ���� �������
int compare(const void* a, const void* b) {
    const car_t* carA = (const car_t*)a;
    const car_t* carB = (const car_t*)b;

    if (carA->year_of_manufacture < carB->year_of_manufacture) {
        return -1;
    }
    else if (carA->year_of_manufacture > carB->year_of_manufacture) {
        return 1;
    }
    return 0;
}

int compare1(const void* a, const void* b) {
    const car_t* carA = (const car_t*)a;
    const car_t* carB = (const car_t*)b;

    if (carA->year_of_registration < carB->year_of_registration) {
        return -1;
    }
    else if (carA->year_of_registration > carB->year_of_registration) {
        return 1;
    }
    return 0;
}


// ������ � ����
int output_file(char* filename, car_t* cars, int n) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("������ ��� �������� ����� ��� ������.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s %s %d %d\n", cars[i].brand, cars[i].manufacturer, cars[i].type, cars[i].year_of_manufacture, cars[i].year_of_registration);
    }

    fclose(file);
    return 1;
}

// ������ �� �����
int input_file(char* filename, car_t* cars) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("������ ��� �������� ����� ��� ������.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%s %s %s %d %d", cars[i].brand, cars[i].manufacturer, cars[i].type, &cars[i].year_of_manufacture, &cars[i].year_of_registration) != EOF) {
        i++;
    }

    fclose(file);
    return 1;
}

// ��������� ������ �� �������
void modify_car_record(car_t* car) {
    printf("������� ����� ������ ��� ����������:\n");
    printf("�����: ");
    scanf("%s", car->brand);
    printf("�������������: ");
    scanf("%s", car->manufacturer);
    printf("���: ");
    scanf("%s", car->type);
    printf("��� �������: ");
    scanf("%d", &car->year_of_manufacture);
    printf("��� �����������: ");
    scanf("%d", &car->year_of_registration);
}

// ������� ����
void menu() {
    printf("\n����:\n");
    printf("1. ��������� ������ �� �����\n");
    printf("2. �������� ������\n");
    printf("3. ����� ������\n");
    printf("4. ����������� ������\n");
    printf("5. ��������� ������ � ����\n");
    printf("6. �����\n");
}

int main() 
{
    setlocale(LC_CTYPE, "RUS");

    car_t cars[SIZE];
    int size = SIZE;
    int choice;
    char brand[50];

    fill_array(cars, SIZE);

    while (1) {
        menu();
        printf("�������� ��������: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char filename[50];
            printf("������� ��� ����� ��� �������� ������: ");
            scanf("%s", filename);
            if (input_file(filename, cars)) {
                printf("������ ������� ��������� �� �����.\n");
                print_array(cars, size);
            }
            else {
                printf("�� ������� ��������� ������ �� �����.\n");
            }
            break;
        }

        case 2: {
            printf("������� ������ ������ ��� ��������� (�� 0 �� %d): ", size - 1);
            int index;
            scanf("%d", &index);
            if (index >= 0 && index < size) {
                modify_car_record(&cars[index]);
                printf("������ ������� ��������.\n");
            }
            else {
                printf("������������ ������.\n");
            }
            break;
        }

        case 3: {
            printf("������� ����� ���������� ��� ������: ");
            scanf("%s", brand);
            car_t* found_car = search_car_by_brand(cars, size, brand);
            if (found_car) {
                printf("������ �������: ");
                print_car(*found_car);
            }
            else {
                printf("���������� � ������ %s �� ������.\n", brand);
            }
            break;
        }

        case 4: {
            int sort_choice;
            printf("�������� ���� ��� ����������:\n");
            printf("1. ��� �������\n");
            printf("2. ��� �����������\n");
            printf("��� �����: ");
            scanf("%d", &sort_choice);

            if (sort_choice == 1) {
                qsort(cars, size, sizeof(car_t), compare);
                printf("���������� ������������� �� ���� �������.\n");
                print_array(cars, size);
            }
            else if (sort_choice == 2) {
                // ��� ���������� �� ���� ����������� ���������� ��������������� ������� compare
                qsort(cars, size, sizeof(car_t), compare1); // ����� �������� compare, ���� ����� ������ ��������
                printf("���������� ������������� �� ���� �����������.\n");
                print_array(cars, size);
            }
            else {
                printf("�������� �����.\n");
            }
            break;
        }

        case 5: {
            char filename[50];
            printf("������� ��� ����� ��� ���������� ������: ");
            scanf("%s", filename);
            if (output_file(filename, cars, size)) {
                printf("������ ������� ��������� � ����.\n");
            }
            else {
                printf("������ ��� ���������� ������ � ����.\n");
            }
            break;
        }

        case 6:
            printf("����� �� ���������.\n");
            exit(0);

        default:
            printf("�������� �����! ���������� �����.\n");
        }
    }

    return 0;
}
