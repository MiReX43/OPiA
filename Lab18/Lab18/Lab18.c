#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SCREEN_WIDTH 80
#define WINDOW_HEIGHT 10

struct point
{
    float x;
    float y;
    char name;
};

typedef struct point Point;

void put_point(Point z)
{
    printf("point %c (%.1f,%.1f)\n", z.name, z.x, z.y);
}

float dist(Point z, Point w)
{
    return sqrt(pow(w.x - z.x, 2) + pow(w.y - z.y, 2));
}

Point midpoint(Point z, Point w)
{
    Point mid;
    mid.x = (z.x + w.x) / 2;
    mid.y = (z.y + w.y) / 2;
    mid.name = 'M';
    return mid;
}

int det_quad(Point z)
{
    if (z.x > 0 && z.y > 0)
    return 1;
        else if (z.x < 0 && z.y > 0)
        return 2;
            else if (z.x < 0 && z.y < 0)
            return 3;
                else if (z.x > 0 && z.y < 0)
                return 4;
                    else
                    return 0;

}

void print(const char *message)
{
    int message_length = strlen(message);

    // Рассчитываем отступы для центрирования
    int padding = (SCREEN_WIDTH - message_length - 2) / 2; // 2 символа - по одному '*' по бокам

    // Верхняя граница окна
    for (int i = 0; i < SCREEN_WIDTH; i++) printf("*");
    printf("\n");

    // Пустое пространство сверху
    for (int i = 0; i < (WINDOW_HEIGHT - 3) / 2; i++) {
        printf("*%*s*\n", SCREEN_WIDTH - 2, "");
    }

    char formatted_message[SCREEN_WIDTH];
    snprintf(formatted_message, sizeof(formatted_message), "*%*s%s%*s*", padding, "", message, padding, "");
    printf("%s\n", formatted_message);

    // Пустое пространство снизу
    for (int i = 0; i < (WINDOW_HEIGHT - 3) / 2; i++) {
        printf("*%*s*\n", SCREEN_WIDTH - 2, "");
    }

    // Нижняя граница окна
    for (int i = 0; i < SCREEN_WIDTH; i++) printf("*");
    printf("\n");
}

int main()
{
    setlocale(LC_CTYPE, "RUS");
    
    //Задание 1

    Point b, a;

    a = (Point){ 1.0f,2.0f,'A' };
    b = (Point){ 5.0f,-3.0f,'B' };

    put_point(a);
    put_point(b);

    float distance = dist(a, b);
    printf("Расстояние между точками %c и %c: %.2f\n", a.name, b.name, distance);

    Point middle = midpoint(a, b);
    put_point(middle);

    int quadrantA = det_quad(a);
    int quadrantB = det_quad(b);

    printf("Точка %c находтся в %d-й четверти\n", a.name, quadrantA);
    printf("Точка %c находтся в %d-й четверти\n", b.name, quadrantB);

    //Задание 2

    struct tm *mytime;
    time_t t;
    t = time(NULL);
    mytime = localtime(&t);

    printf("Московское время %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

    //Задание 2.2 - 2.3

    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);

    int days_to_sunday = 7 - current_time->tm_wday;
    if (days_to_sunday == 0) {
        days_to_sunday = 7;
    }

    struct tm next_sunday = *current_time;
    next_sunday.tm_mday += days_to_sunday;
    next_sunday.tm_hour = 0;
    next_sunday.tm_min = 0;
    next_sunday.tm_sec = 0;

    double seconds_to_sunday = difftime(mktime(&next_sunday), now);

    int k_days = (int)(seconds_to_sunday / (60 * 60 * 24));
    int m_hours = (int)((seconds_to_sunday - (k_days * 60 * 60 * 24)) / (60 * 60));

    char message[100];
    snprintf(message, sizeof(message), "До воскресенья осталось %d дней и %d часов ", k_days, m_hours);

    print(message);

    return 0;
}
