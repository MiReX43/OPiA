#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define SIZE 5

// ��������� ��� �������� ������
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

// ���������� �������
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

// ������� ��� ������ ����� ������
void print_movie(movie_t movie) {
    printf("| %-20s | %-10s | %-8.2f | %-15s | %-4d |\n", movie.title, movie.genre, movie.cost, movie.director, movie.year);
}

// ������� ��� ������ ���� �������
void print_all_movies(movie_t* movies, int size) {
    for (int i = 0; i < size; i++) {
        print_movie(movies[i]);
    }
}

// ������� ��� ������ ������ �� ���������
void search_by_director(movie_t* movies, int size, char* director) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].director, director) == 0) {
            print_movie(movies[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("������ � ���������� %s �� �������.\n", director);
    }
}

// ������� ��� ���������� ������� �� ���������
int compare_cost(const void* a, const void* b) {
    return ((movie_t*)a)->cost > ((movie_t*)b)->cost ? 1 : -1;
}

// ������� ��� ���������� �� ���� ������� � ������ �����
int compare_year_and_genre(const void* a, const void* b) {
    movie_t* movieA = (movie_t*)a;
    movie_t* movieB = (movie_t*)b;
    int genre_cmp = strcmp(movieA->genre, movieB->genre);

    if (genre_cmp == 0) {
        return movieA->year - movieB->year;
    }
    return genre_cmp;
}

// ������� ��� ������ ���� ������ � ����
int save_to_file(char* filename, movie_t* movies, int size) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("������ ��� �������� ����� ��� ������.\n");
        return 0;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %.2f %s %d\n", movies[i].title, movies[i].genre, movies[i].cost, movies[i].director, movies[i].year);
    }

    fclose(file);
    return 1;
}


// ������� ��� ���������� ������ ������
void add_movie(movie_t* movies, int* size) {
    if (*size >= SIZE) {
        printf("��������� ����� �������.\n");
        return;
    }

    printf("������� �������� ������: ");
    scanf("%s", movies[*size].title);
    printf("������� ����: ");
    scanf("%s", movies[*size].genre);
    printf("������� ���������: ");
    scanf("%lf", &movies[*size].cost);
    printf("������� ���������: ");
    scanf("%s", movies[*size].director);
    printf("������� ��� �������: ");
    scanf("%d", &movies[*size].year);

    (*size)++;
}

// ������� ��� ������ ���� ������ �� �����
int load_from_file(char* filename, movie_t* movies, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("������ ��� �������� ����� ��� ������.\n");
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

// ������� ����
void menu() {
    printf("\n����:\n");
    printf("1. ��������� ������ �� �����\n");
    printf("2. �������� ������\n");
    printf("3. ����� �� ���������\n");
    printf("4. ����������� ������\n");
    printf("5. ��������� ������ � ����\n");
    printf("6. �����\n");
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    movie_t movies[SIZE];
    int size = SIZE;
    int choice;

    fill_array(movies, SIZE);

    while (1) {
        menu();
        printf("�������� ��������: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            char filename[50];
            printf("������� ��� ����� ��� �������� ������: ");
            scanf("%s", filename);
            if (load_from_file(filename, movies, &size)) {
                printf("������ ������� ��������� �� �����.\n");
                print_all_movies(movies, size);
            }
            else {
                printf("�� ������� ��������� ������ �� �����.\n");
            }
            break;
        }

        case 2:
            add_movie(movies, &size);
            break;

        case 3: {
            char director[50];
            printf("������� ��� ��������� ��� ������: ");
            scanf("%s", director);
            search_by_director(movies, size, director);
            break;
        }

        case 4: {
            int sort_choice;
            printf("�������� ���� ��� ����������:\n");
            printf("1. �� ���������\n");
            printf("2. �� ���� ������� � ������ �����\n");
            printf("��� �����: ");
            scanf("%d", &sort_choice);

            if (sort_choice == 1) {
                qsort(movies, size, sizeof(movie_t), compare_cost);
                printf("������ ������������� �� ���������.\n");
            }
            else if (sort_choice == 2) {
                qsort(movies, size, sizeof(movie_t), compare_year_and_genre);
                printf("������ ������������� �� ���� ������� � ������ �����.\n");
            }
            else {
                printf("�������� �����.\n");
            }
            print_all_movies(movies, size);
            break;
        }

        case 5: {
            char filename[50];
            printf("������� ��� ����� ��� ���������� ������: ");
            scanf("%s", filename);
            if (save_to_file(filename, movies, size)) {
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



//���������� �������� ���� ������ "���������"
//����: �������� ������, ����, ���������, ��������, ��� �������.
//������� ������: ����� �� ������ ���������, ����� �� ������ �����.
//������� ����������: ����� �� ����������� ���������, ����� �� ���� ������� � ������ �����.