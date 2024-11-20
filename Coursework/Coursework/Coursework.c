#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define SIZE 100
#define TABLE_WIDTH 92

// Структура для описания фильма
struct Movie {
    char title[50];
    char genre[30];
    double cost;
    char director[50];
    int year;
};

typedef struct Movie movie_t;

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void random_string(char* str, const char* arr[], int arr_size) {
    int index = rand() % arr_size;
    strcpy(str, arr[index]);
    return 1;
}

// Заполнение массива
void fill_array(movie_t* movies, int size) {
    const char* titles[] = { "Inception", "Titanic", "The_Matrix", "Avatar", "Gladiator" };
    const char* genres[] = { "Action", "Drama", "Sci-Fi", "Romance", "Adventure" };
    const char* directors[] = { "Spielberg", "Cameron", "Nolan", "Tarantino", "Scorsese" };

    for (int i = 0; i < size; i++) {
        random_string(movies[i].title, titles, sizeof(titles) / sizeof(titles[0]));
        random_string(movies[i].genre, genres, sizeof(genres) / sizeof(genres[0]));
        movies[i].cost = getRandomNumber(100, 20000);
        random_string(movies[i].director, directors, sizeof(directors) / sizeof(directors[0]));
        movies[i].year = getRandomNumber(1950, 2024);
    }
    return 1;
}


void print_line(int width) {
    for (int i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");
}

void print_tab() {
    char index[50] = "Индекс";
    char title[50] = "Название";
    char genre[50] = "Жанр";
    char cost[50] = "Стоимость";
    char director[50] = "Режиссер";
    char year[50] = "Год выпуска";

    printf("\n");
    print_line(TABLE_WIDTH);

    printf("* %-6s * %-13s * %-13s * %-15s * %-13s * %-13s *\n", index, title, genre, cost, director, year);

    print_line(TABLE_WIDTH);
}

// Функция для вывода одной записи
void print_movie(movie_t movie, int index) {
    printf("* %-6d * %-13s * %-13s * %-14.2f$ * %-13s * %-13d *\n",
        index, movie.title, movie.genre, movie.cost, movie.director, movie.year);
}

// Функция для вывода всех записей
void print_all_movies(movie_t* movies, int size) {
    print_tab();
    for (int i = 0; i < size; i++) {
        print_movie(movies[i], i);
    }
    print_line(TABLE_WIDTH);
}

// Функция для поиска фильма по режиссеру
void search_by_director(movie_t* movies, int size, const char* director) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].director, director) == 0) {
            print_movie(movies[i], i);
            found = 1;
        }
    }
    if (!found) {
        printf("Фильмы с режиссером %s не найдены.\n", director);
    }
    return found;
}

// Функция для сортировки фильмов по стоимости
int compare_cost(const void* a, const void* b) {
    return ((movie_t*)a)->cost > ((movie_t*)b)->cost ? 1 : -1;
}

// Функция для сортировки по году выпуска с учетом жанра
int compare_year_and_genre(const void* a, const void* b) {
    movie_t* movieA = (movie_t*)a;
    movie_t* movieB = (movie_t*)b;
    int genre_cmp = strcmp(movieA->genre, movieB->genre);

    if (genre_cmp == 0) {
        return movieA->year - movieB->year;
    }
    return genre_cmp;
}

// Функция для записи базы данных в файл
int save_to_file(movie_t* movies, int size)
{
    char filename[50];
    printf("Введите имя файла для сохранения данных: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка при открытии файла для записи.\n");
        return 0;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %.2f %s %d\n", movies[i].title, movies[i].genre, movies[i].cost, movies[i].director, movies[i].year);
    }

    fclose(file);
    return 1;
}


// Функция для добавления записи фильма
void add_movie(movie_t* movies, int* size)
{
    if (*size >= SIZE) {
        printf("Достигнут лимит записей.\n");
        return;
    }
    printf("Введите название фильма: ");
    scanf("%s", movies[*size].title);
    printf("Введите жанр: ");
    scanf("%s", movies[*size].genre);
    printf("Введите стоимость: ");
    scanf("%lf", &movies[*size].cost);
    printf("Введите режиссера: ");
    scanf("%s", movies[*size].director);
    printf("Введите год выпуска: ");
    scanf("%d", &movies[*size].year);
    (*size)++;
}

// Функция для чтения базы данных из файла
int load_from_file(char* filename, movie_t* movies, int* size)
{
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Ошибка при открытии файла для чтения.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%s %s %lf %s %d", movies[i].title, movies[i].genre, &movies[i].cost, movies[i].director, &movies[i].year) != EOF) {
        i++;
    }
    *size = i;

    fclose(file);
    return 1;
}

void modify_record(movie_t* movies) {
    printf("Введите новые данные для фильма:\n");
    printf("Введите название фильма: ");
    scanf("%s", movies->title);
    printf("Введите жанр: ");
    scanf("%s", movies->genre);
    printf("Введите стоимость: ");
    scanf("%lf", &movies->cost);
    printf("Введите режиссера: ");
    scanf("%s", movies->director);
    printf("Введите год выпуска: ");
    scanf("%d", &movies->year);
}

void delete_record(movie_t* movies, int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("Некорректный индекс записи.\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        movies[i] = movies[i + 1];
    }
    (*size)--;
    printf("Запись успешно удалена.\n");
}

void create_new_file(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка при создании файла.\n");
        return;
    }

    fprintf(file, "");
    fclose(file);
    printf("Файл '%s' успешно создан.\n", filename);
}

int main()
{
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    movie_t movies[SIZE];
    int size = SIZE;
    int choice;
    int main_choice, sub_choice;
    int ch;

    while (1) {
        printf("\n========== ГЛАВНОЕ МЕНЮ ==========\n");
        printf("1. Создать файл\n");
        printf("2. Редактировать файл -->\n");
        printf("3. Вывод данных из файла\n");
        printf("4. Сортировка -->\n");
        printf("5. Поиск\n");
        printf("6. Выход\n");
        printf("==================================\n");
        printf("Выберите действие: ");
        scanf("%d", &main_choice);

        switch (main_choice) {
        case 1:
            printf("Создание нового файла...\n");
            printf("Введите имя нового файла: ");
            char new_filename[50];
            scanf("%s", new_filename);
            create_new_file(new_filename);
            break;

        case 2:
            while (1) {
                int auto_size;
                int ch;
                char saves;

                printf("\n==== РЕДАКТИРОВАНИЕ ФАЙЛА ====\n");
                printf("1. Заполнить файл автоматически\n");
                printf("2. Добавить запись вручную\n");
                printf("3. Изменить запись\n");
                printf("4. Удалить запись\n");
                printf("5. Назад <--\n");
                printf("==============================\n");
                printf("Выберите действие: ");
                if (scanf("%d", &sub_choice) != 1) {
                    printf("Ошибка ввода. Попробуйте снова.\n");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    continue;
                }

                if (sub_choice == 5) {
                    printf("Возврат в главное меню...\n");
                    break;
                }

                switch (sub_choice) {
                case 1:
                    printf("Автоматическое заполнение файла...\n");
                    printf("Укажите количество записей: ");
                    if (scanf("%d", &auto_size) != 1 || auto_size <= 0 || auto_size > SIZE) {
                        printf("Некорректное количество записей. Попробуйте снова.\n");
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        continue;
                    }

                    fill_array(movies, auto_size);
                    printf("Массив успешно заполнен!\n");

                    if (save_to_file(movies, auto_size)) {
                        printf("Данные успешно сохранены в файл.\n");
                    }
                    else {
                        printf("Ошибка при сохранении данных в файл.\n");
                    }
                    break;

                case 2:
                    printf("Добавление записи вручную...\n");
                    add_movie(movies, &size);

                    printf("Сохранить изменения (y / n): ");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    scanf("%c", &saves);

                    if (saves == 'y') {
                        if (save_to_file(movies, size)) {
                            printf("Данные успешно сохранены в файл.\n");
                        }
                        else {
                            printf("Ошибка при сохранении данных в файл.\n");
                        }
                    }
                    break;

                case 3:
                    printf("Изменение записи...\n");
                    print_all_movies(movies, size);
                    printf("Введите индекс записи для изменения (от 0 до %d): ", size - 1);
                    int index;
                    if (scanf("%d", &index) != 1 || index < 0 || index >= size) {
                        printf("Некорректный индекс. Попробуйте снова.\n");
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        continue;
                    }
                    modify_record(&movies[index]);
                    printf("Запись успешно изменена.\n");

                    printf("Сохранить изменения (y / n): ");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    scanf("%c", &saves);

                    if (saves == 'y') {
                        if (save_to_file(movies, size)) {
                            printf("Данные успешно сохранены в файл.\n");
                        }
                        else {
                            printf("Ошибка при сохранении данных в файл.\n");
                        }
                    }
                    break;

                case 4:
                    printf("Удаление записи...\n");
                    print_all_movies(movies, size);
                    printf("Введите индекс записи для удаления (от 0 до %d): ", size - 1);
                    int delete_index;
                    if (scanf("%d", &delete_index) != 1 || delete_index < 0 || delete_index >= size) {
                        printf("Некорректный индекс. Попробуйте снова.\n");
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        continue;
                    }
                    delete_record(movies, &size, delete_index);
                    printf("Запись успешно удалена.\n");

                    printf("Сохранить изменения (y / n): ");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    scanf("%c", &saves);

                    if (saves == 'y') {
                        if (save_to_file(movies, size)) {
                            printf("Данные успешно сохранены в файл.\n");
                        }
                        else {
                            printf("Ошибка при сохранении данных в файл.\n");
                        }
                    }
                    break;

                default:
                    printf("Ошибка: Неверный выбор. Попробуйте снова.\n");
                }
            }

            break;

        case 3:
            printf("Вывод данных из файла...\n");
            char filename[50];
            printf("Введите имя файла для загрузки данных: ");
            scanf("%s", filename);
            if (load_from_file(filename, movies, &size)) {
                printf("Данные успешно загружены из файла.\n");
                print_all_movies(movies, size);
            }
            else {
                printf("Не удалось загрузить данные из файла.\n");
            }
            break;

        case 4:
            while (1) {
                // Подменю сортировки
                printf("\n====== СОРТИРОВКА ЗАПИСЕЙ ======\n");
                printf("1. По стоимости\n");
                printf("2. По году выпуска с учетом жанра\n");
                printf("3. Назад <--\n");
                printf("================================\n");
                printf("Выберите действие: ");
                scanf("%d", &sub_choice);

                if (sub_choice == 1) {
                    qsort(movies, size, sizeof(movie_t), compare_cost);
                    printf("Фильмы отсортированы по стоимости.\n");
                }
                else if (sub_choice == 2) {
                    qsort(movies, size, sizeof(movie_t), compare_year_and_genre);
                    printf("Фильмы отсортированы по году выпуска с учетом жанра.\n");
                }
                else if (sub_choice == 3) {
                    printf("Возврат в главное меню...\n");
                    break; // Возврат в главное меню
                }
                else {
                    printf("Неверный выбор.\n");
                }
                print_all_movies(movies, size);
                break;
            }
            break;
        case 5:
            printf("Поиск записи...\n");
            char director[50];
            printf("Введите имя режиссера для поиска: ");
            scanf("%s", director);
            print_tab();
            search_by_director(movies, size, director);
            print_line(TABLE_WIDTH);
            break;

        case 6:
            printf("Выход из программы. До свидания!\n");
            return 0;

        default:
            printf("Ошибка: Неверный выбор! Попробуйте снова.\n");
        }
    }
    return 0;
}

//1. Создать файл
//2. Редактировать файл -->
//    1. Заполнить файл автоматически
//    2. Добавть запись в ручную
//    3. Изменть запись
//    4. Удалить записть
//    5. Назад <--
//3. Вывод данных из файла
//4. Соритирвка -->
//    1. По стоимости
//    2. По году выпуска с учетом жанра
//    3. Назад <--
//5. Поиск

//Разработка файловой базы данных "Видеотека"
//Поля: название фильма, жанр, стоимость, режиссер, год выпуска.
//Признак поиска: фильм по одному режиссеру, фильм по одному жанру.
//Вариант сортировки: фильм по возрастанию стоимости, фильм по году выпуска с учетом жанра.