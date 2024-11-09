#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define SIZE 5

// Структура Car
struct Car {
    char brand[50];
    char manufacturer[50];
    char type[50];
    int year_of_manufacture;
    int year_of_registration;
};

typedef struct Car car_t;

// Генерация случайных чисел
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

// Заполнение массива
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

// Печать одной записи
void print_car(car_t car) {
    printf("| %-15s || %-15s || %-15s || %-4d || %-4d |\n", car.brand, car.manufacturer, car.type, car.year_of_manufacture, car.year_of_registration);
}

// Печать всех записей
void print_array(car_t* cars, int size) {
    for (int i = 0; i < size; i++) {
        print_car(cars[i]);
    }
}

// Поиск по марке автомобиля
car_t* search_car_by_brand(car_t* cars, int size, char* brand) {
    for (int i = 0; i < size; i++) {
        if (strcmp(cars[i].brand, brand) == 0) {
            return &cars[i];
        }
    }
    return NULL;
}

// Сравнение по году выпуска
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


// Запись в файл
int output_file(char* filename, car_t* cars, int n) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка при открытии файла для записи.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %s %s %d %d\n", cars[i].brand, cars[i].manufacturer, cars[i].type, cars[i].year_of_manufacture, cars[i].year_of_registration);
    }

    fclose(file);
    return 1;
}

// Чтение из файла
int input_file(char* filename, car_t* cars) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка при открытии файла для чтения.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%s %s %s %d %d", cars[i].brand, cars[i].manufacturer, cars[i].type, &cars[i].year_of_manufacture, &cars[i].year_of_registration) != EOF) {
        i++;
    }

    fclose(file);
    return 1;
}

// Изменение записи по индексу
void modify_car_record(car_t* car) {
    printf("Введите новые данные для автомобиля:\n");
    printf("Марка: ");
    scanf("%s", car->brand);
    printf("Производитель: ");
    scanf("%s", car->manufacturer);
    printf("Тип: ");
    scanf("%s", car->type);
    printf("Год выпуска: ");
    scanf("%d", &car->year_of_manufacture);
    printf("Год регистрации: ");
    scanf("%d", &car->year_of_registration);
}

// Главное меню
void menu() {
    printf("\nМеню:\n");
    printf("1. Загрузить данные из файла\n");
    printf("2. Изменить запись\n");
    printf("3. Поиск записи\n");
    printf("4. Сортировать записи\n");
    printf("5. Сохранить данные в файл\n");
    printf("6. Выход\n");
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
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char filename[50];
            printf("Введите имя файла для загрузки данных: ");
            scanf("%s", filename);
            if (input_file(filename, cars)) {
                printf("Данные успешно загружены из файла.\n");
                print_array(cars, size);
            }
            else {
                printf("Не удалось загрузить данные из файла.\n");
            }
            break;
        }

        case 2: {
            printf("Введите индекс записи для изменения (от 0 до %d): ", size - 1);
            int index;
            scanf("%d", &index);
            if (index >= 0 && index < size) {
                modify_car_record(&cars[index]);
                printf("Запись успешно изменена.\n");
            }
            else {
                printf("Некорректный индекс.\n");
            }
            break;
        }

        case 3: {
            printf("Введите марку автомобиля для поиска: ");
            scanf("%s", brand);
            car_t* found_car = search_car_by_brand(cars, size, brand);
            if (found_car) {
                printf("Запись найдена: ");
                print_car(*found_car);
            }
            else {
                printf("Автомобиль с маркой %s не найден.\n", brand);
            }
            break;
        }

        case 4: {
            int sort_choice;
            printf("Выберите поле для сортировки:\n");
            printf("1. Год выпуска\n");
            printf("2. Год регистрации\n");
            printf("Ваш выбор: ");
            scanf("%d", &sort_choice);

            if (sort_choice == 1) {
                qsort(cars, size, sizeof(car_t), compare);
                printf("Автомобили отсортированы по году выпуска.\n");
                print_array(cars, size);
            }
            else if (sort_choice == 2) {
                // Для сортировки по году регистрации используем соответствующую функцию compare
                qsort(cars, size, sizeof(car_t), compare1); // можно изменить compare, если нужен другой критерий
                printf("Автомобили отсортированы по году регистрации.\n");
                print_array(cars, size);
            }
            else {
                printf("Неверный выбор.\n");
            }
            break;
        }

        case 5: {
            char filename[50];
            printf("Введите имя файла для сохранения данных: ");
            scanf("%s", filename);
            if (output_file(filename, cars, size)) {
                printf("Данные успешно сохранены в файл.\n");
            }
            else {
                printf("Ошибка при сохранении данных в файл.\n");
            }
            break;
        }

        case 6:
            printf("Выход из программы.\n");
            exit(0);

        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }
    }

    return 0;
}
