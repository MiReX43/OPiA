#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define SIZE 5

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

const char* titles[] = { "Inception", "Titanic", "The Matrix", "Avatar", "Gladiator" };
const char* genres[] = { "Action", "Drama", "Sci-Fi", "Romance", "Adventure" };
const char* directors[] = { "Spielberg", "Cameron", "Nolan", "Tarantino", "Scorsese" };

void random_string(char* str, const char* arr[], int arr_size) {
    int index = rand() % arr_size;
    strcpy(str, arr[index]);
}

// Заполнение массива
void fill_array(movie_t* movies, int size) 
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) 
    {
        random_string(movies[i].title, titles, sizeof(titles) / sizeof(titles[0]));
        random_string(movies[i].genre, genres, sizeof(genres) / sizeof(genres[0]));
        movies[i].cost = getRandomNumber(100, 20000);
        random_string(movies[i].director, directors, sizeof(directors) / sizeof(directors[0]));
        movies[i].year = getRandomNumber(1950, 2024);
    }
}

// Функция для вывода одной записи
void print_movie(movie_t movie) {
    printf("| %-20s | %-10s | %-8.2f | %-15s | %-4d |\n", movie.title, movie.genre, movie.cost, movie.director, movie.year);
}

// Функция для вывода всех записей
void print_all_movies(movie_t* movies, int size) {
    for (int i = 0; i < size; i++) {
        print_movie(movies[i]);
    }
}

// Функция для поиска фильма по режиссеру
void search_by_director(movie_t* movies, int size, char* director) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].director, director) == 0) {
            print_movie(movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Фильмы с режиссером %s не найдены.\n", director);
    }
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
int save_to_file(char* filename, movie_t* movies, int size) {
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
void add_movie(movie_t* movies, int* size) {
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
int load_from_file(char* filename, movie_t* movies, int* size) {
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

// Главное меню
void menu() {
    printf("\nМеню:\n");
    printf("1. Загрузить данные из файла\n");
    printf("2. Добавить запись\n");
    printf("3. Поиск по режиссеру\n");
    printf("4. Сортировать записи\n");
    printf("5. Сохранить данные в файл\n");
    printf("6. Выход\n");
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    movie_t movies[SIZE];
    int size = SIZE;
    int choice;

    fill_array(movies, SIZE);

    while (1) {
        menu();
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
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
        }

        case 2:
            add_movie(movies, &size);
            break;

        case 3: {
            char director[50];
            printf("Введите имя режиссера для поиска: ");
            scanf("%s", director);
            search_by_director(movies, size, director);
            break;
        }

        case 4: {
            int sort_choice;
            printf("Выберите поле для сортировки:\n");
            printf("1. По стоимости\n");
            printf("2. По году выпуска с учетом жанра\n");
            printf("Ваш выбор: ");
            scanf("%d", &sort_choice);

            if (sort_choice == 1) {
                qsort(movies, size, sizeof(movie_t), compare_cost);
                printf("Фильмы отсортированы по стоимости.\n");
            }
            else if (sort_choice == 2) {
                qsort(movies, size, sizeof(movie_t), compare_year_and_genre);
                printf("Фильмы отсортированы по году выпуска с учетом жанра.\n");
            }
            else {
                printf("Неверный выбор.\n");
            }
            print_all_movies(movies, size);
            break;
        }

        case 5: {
            char filename[50];
            printf("Введите имя файла для сохранения данных: ");
            scanf("%s", filename);
            if (save_to_file(filename, movies, size)) {
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



//Разработка файловой базы данных "Видеотека"
//Поля: название фильма, жанр, стоимость, режиссер, год выпуска.
//Признак поиска: фильм по одному режиссеру, фильм по одному жанру.
//Вариант сортировки: фильм по возрастанию стоимости, фильм по году выпуска с учетом жанра.