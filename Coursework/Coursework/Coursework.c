#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define SIZE 100
#define TABLE_WIDTH 92

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

void random_string(char* str, const char* arr[], int arr_size) {
    int index = rand() % arr_size;
    strcpy(str, arr[index]);
    return 1;
}

// ���������� �������
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
    char index[50] = "������";
    char title[50] = "��������";
    char genre[50] = "����";
    char cost[50] = "���������";
    char director[50] = "��������";
    char year[50] = "��� �������";

    printf("\n");
    print_line(TABLE_WIDTH);

    printf("* %-6s * %-13s * %-13s * %-15s * %-13s * %-13s *\n", index, title, genre, cost, director, year);

    print_line(TABLE_WIDTH);
}

// ������� ��� ������ ����� ������
void print_movie(movie_t movie, int index) {
    printf("* %-6d * %-13s * %-13s * %-14.2f$ * %-13s * %-13d *\n",
        index, movie.title, movie.genre, movie.cost, movie.director, movie.year);
}

// ������� ��� ������ ���� �������
void print_all_movies(movie_t* movies, int size) {
    print_tab();
    for (int i = 0; i < size; i++) {
        print_movie(movies[i], i);
    }
    print_line(TABLE_WIDTH);
}

// ������� ��� ������ ������ �� ���������
void search_by_director(movie_t* movies, int size, const char* director) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(movies[i].director, director) == 0) {
            print_movie(movies[i], i);
            found = 1;
        }
    }
    if (!found) {
        printf("������ � ���������� %s �� �������.\n", director);
    }
    return found;
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
int save_to_file(movie_t* movies, int size)
{
    char filename[50];
    printf("������� ��� ����� ��� ���������� ������: ");
    scanf("%s", filename);

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
void add_movie(movie_t* movies, int* size)
{
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
int load_from_file(char* filename, movie_t* movies, int* size)
{
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

void modify_record(movie_t* movies) {
    printf("������� ����� ������ ��� ������:\n");
    printf("������� �������� ������: ");
    scanf("%s", movies->title);
    printf("������� ����: ");
    scanf("%s", movies->genre);
    printf("������� ���������: ");
    scanf("%lf", &movies->cost);
    printf("������� ���������: ");
    scanf("%s", movies->director);
    printf("������� ��� �������: ");
    scanf("%d", &movies->year);
}

void delete_record(movie_t* movies, int* size, int index) {
    if (index < 0 || index >= *size) {
        printf("������������ ������ ������.\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        movies[i] = movies[i + 1];
    }
    (*size)--;
    printf("������ ������� �������.\n");
}

void create_new_file(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("������ ��� �������� �����.\n");
        return;
    }

    fprintf(file, "");
    fclose(file);
    printf("���� '%s' ������� ������.\n", filename);
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
        printf("\n========== ������� ���� ==========\n");
        printf("1. ������� ����\n");
        printf("2. ������������� ���� -->\n");
        printf("3. ����� ������ �� �����\n");
        printf("4. ���������� -->\n");
        printf("5. �����\n");
        printf("6. �����\n");
        printf("==================================\n");
        printf("�������� ��������: ");
        scanf("%d", &main_choice);

        switch (main_choice) {
        case 1:
            printf("�������� ������ �����...\n");
            printf("������� ��� ������ �����: ");
            char new_filename[50];
            scanf("%s", new_filename);
            create_new_file(new_filename);
            break;

        case 2:
            while (1) {
                int auto_size;
                int ch;
                char saves;

                printf("\n==== �������������� ����� ====\n");
                printf("1. ��������� ���� �������������\n");
                printf("2. �������� ������ �������\n");
                printf("3. �������� ������\n");
                printf("4. ������� ������\n");
                printf("5. ����� <--\n");
                printf("==============================\n");
                printf("�������� ��������: ");
                if (scanf("%d", &sub_choice) != 1) {
                    printf("������ �����. ���������� �����.\n");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    continue;
                }

                if (sub_choice == 5) {
                    printf("������� � ������� ����...\n");
                    break;
                }

                switch (sub_choice) {
                case 1:
                    printf("�������������� ���������� �����...\n");
                    printf("������� ���������� �������: ");
                    if (scanf("%d", &auto_size) != 1 || auto_size <= 0 || auto_size > SIZE) {
                        printf("������������ ���������� �������. ���������� �����.\n");
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        continue;
                    }

                    fill_array(movies, auto_size);
                    printf("������ ������� ��������!\n");

                    if (save_to_file(movies, auto_size)) {
                        printf("������ ������� ��������� � ����.\n");
                    }
                    else {
                        printf("������ ��� ���������� ������ � ����.\n");
                    }
                    break;

                case 2:
                    printf("���������� ������ �������...\n");
                    add_movie(movies, &size);

                    printf("��������� ��������� (y / n): ");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    scanf("%c", &saves);

                    if (saves == 'y') {
                        if (save_to_file(movies, size)) {
                            printf("������ ������� ��������� � ����.\n");
                        }
                        else {
                            printf("������ ��� ���������� ������ � ����.\n");
                        }
                    }
                    break;

                case 3:
                    printf("��������� ������...\n");
                    print_all_movies(movies, size);
                    printf("������� ������ ������ ��� ��������� (�� 0 �� %d): ", size - 1);
                    int index;
                    if (scanf("%d", &index) != 1 || index < 0 || index >= size) {
                        printf("������������ ������. ���������� �����.\n");
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        continue;
                    }
                    modify_record(&movies[index]);
                    printf("������ ������� ��������.\n");

                    printf("��������� ��������� (y / n): ");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    scanf("%c", &saves);

                    if (saves == 'y') {
                        if (save_to_file(movies, size)) {
                            printf("������ ������� ��������� � ����.\n");
                        }
                        else {
                            printf("������ ��� ���������� ������ � ����.\n");
                        }
                    }
                    break;

                case 4:
                    printf("�������� ������...\n");
                    print_all_movies(movies, size);
                    printf("������� ������ ������ ��� �������� (�� 0 �� %d): ", size - 1);
                    int delete_index;
                    if (scanf("%d", &delete_index) != 1 || delete_index < 0 || delete_index >= size) {
                        printf("������������ ������. ���������� �����.\n");
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        continue;
                    }
                    delete_record(movies, &size, delete_index);
                    printf("������ ������� �������.\n");

                    printf("��������� ��������� (y / n): ");
                    while ((ch = getchar()) != '\n' && ch != EOF);
                    scanf("%c", &saves);

                    if (saves == 'y') {
                        if (save_to_file(movies, size)) {
                            printf("������ ������� ��������� � ����.\n");
                        }
                        else {
                            printf("������ ��� ���������� ������ � ����.\n");
                        }
                    }
                    break;

                default:
                    printf("������: �������� �����. ���������� �����.\n");
                }
            }

            break;

        case 3:
            printf("����� ������ �� �����...\n");
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

        case 4:
            while (1) {
                // ������� ����������
                printf("\n====== ���������� ������� ======\n");
                printf("1. �� ���������\n");
                printf("2. �� ���� ������� � ������ �����\n");
                printf("3. ����� <--\n");
                printf("================================\n");
                printf("�������� ��������: ");
                scanf("%d", &sub_choice);

                if (sub_choice == 1) {
                    qsort(movies, size, sizeof(movie_t), compare_cost);
                    printf("������ ������������� �� ���������.\n");
                }
                else if (sub_choice == 2) {
                    qsort(movies, size, sizeof(movie_t), compare_year_and_genre);
                    printf("������ ������������� �� ���� ������� � ������ �����.\n");
                }
                else if (sub_choice == 3) {
                    printf("������� � ������� ����...\n");
                    break; // ������� � ������� ����
                }
                else {
                    printf("�������� �����.\n");
                }
                print_all_movies(movies, size);
                break;
            }
            break;
        case 5:
            printf("����� ������...\n");
            char director[50];
            printf("������� ��� ��������� ��� ������: ");
            scanf("%s", director);
            print_tab();
            search_by_director(movies, size, director);
            print_line(TABLE_WIDTH);
            break;

        case 6:
            printf("����� �� ���������. �� ��������!\n");
            return 0;

        default:
            printf("������: �������� �����! ���������� �����.\n");
        }
    }
    return 0;
}

//1. ������� ����
//2. ������������� ���� -->
//    1. ��������� ���� �������������
//    2. ������� ������ � ������
//    3. ������� ������
//    4. ������� �������
//    5. ����� <--
//3. ����� ������ �� �����
//4. ���������� -->
//    1. �� ���������
//    2. �� ���� ������� � ������ �����
//    3. ����� <--
//5. �����

//���������� �������� ���� ������ "���������"
//����: �������� ������, ����, ���������, ��������, ��� �������.
//������� ������: ����� �� ������ ���������, ����� �� ������ �����.
//������� ����������: ����� �� ����������� ���������, ����� �� ���� ������� � ������ �����.