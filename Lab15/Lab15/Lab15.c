#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define COL 100
#define ROW 100

//Ex.1
//����������
double* fill_arr(int row, int col, double arr[][COL]) {
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            double min = i;
            double max = j + 1;
            arr[i][j] = min + (rand() / (double)RAND_MAX) * (max - min);
        }
    }
    return *arr;
}

//������ � �������� ���������
void print_arr_index(int row, int col, double arr[][COL])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("a[%d][%d] %.2f ",i, j, arr[i][j]);
        }
        printf("\n");
    }
}

//������ � ���� �������
void print_arr_tab(int row, int col, double arr[][COL])
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%.2f ", arr[i][j]);
        }
        printf("\n");
    }
}

double max_in_column(int row, int col, double arr[][COL], int target_col) 
{
    if (target_col < 0 || target_col >= col) 
    {
        printf("������: ����� ������� ��� ���������.\n");
        return -1;
    }

    double max_value = arr[0][target_col];
    for (int i = 1; i < row; i++) 
    {
        if (arr[i][target_col] > max_value) 
        {
            max_value = arr[i][target_col];
        }
    }
    return max_value;
}

//Ex.2
int fill_arr2(int row, int col, int array[][COL]) 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            array[i][j] = rand() % 21 - 10;
        }
    }
    return **array;
}

void print_arr_tab2(int row, int col, int array[][COL]) 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }
}

int transpose_arr(int row, int col, int array[][COL], int trans_arr[][ROW]) 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            trans_arr[j][i] = array[i][j];
        }
    }
}

double calc(int row, int array[][COL])
{
    int sum = 0;
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        if (array[i][2] % 2 == 0)
        {
            sum += array[i][2];
            count++;
        }
    }

    if (count > 0)
    {
        return(double)sum / count;
    } 
    else
    {
        printf("��� ������ ��������� � ������� ������. \n");
        return 0;
    }
}

int count_pairs(int row, int col, int array[][COL]) 
{
    int count = 0;

    // �� �������
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col - 1; j++) 
        {
            if (array[i][j] == array[i][j + 1]) 
            {
                count++;
            }
        }
    }

    // �� ��������
    for (int i = 0; i < row - 1; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            if (array[i][j] == array[i + 1][j]) 
            {
                count++;
            }
        }
    }

    // �� ���������� (������� � ��������)
    for (int i = 0; i < row - 1; i++) 
    {
        for (int j = 0; j < col - 1; j++) 
        {
            if (array[i][j] == array[i + 1][j + 1]) 
            {
                count++;
            }
        }
    }

    return count;
}

void find_max_coords(int row, int col, int array[][COL]) {
    int max_val = array[0][0];  // ��������� ������������ ��������
    int max_row = 0, max_col = 0;  // ��������� ���������� ������������� ��������

    // �������� �� ������� �������
    for (int j = 0; j < col; j++) {
        for (int i = 0; i < row; i++) {
            if (array[i][j] > max_val) {
                max_val = array[i][j];
                max_row = i;
                max_col = j;
            }
            else if (array[i][j] == max_val && i > max_row) {
                max_row = i;
                max_col = j;
            }
        }
    }

    // ������� ���������� ������������� ��������
    printf("������������ �������: %d\n", max_val);
    printf("����������: ������ %d, ������� %d\n", max_row + 1, max_col + 1);  // +1, ����� ���������� ���� � 1
}

int main()
{
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    //Ex.1

    int row, col;
    printf("������� ���������� �����: ");
    scanf("%d", &row);
    printf("������� ���������� ��������: ");
    scanf("%d", &col);

    double arr[ROW][COL];

    puts("\n");

    fill_arr(row, col, arr);
    print_arr_index(row, col, arr);
    puts("\n");
    print_arr_tab(row, col, arr);

    int selected_row, selected_col;
    printf("\n������� ����� ������ � ������� ��� ������ �������� (�� 0 �� %d � �� 0 �� %d): ", row - 1, col - 1);
    scanf("%d %d", &selected_row, &selected_col);

    if (selected_row >= 0 && selected_row < row && selected_col >= 0 && selected_col < col) {
        printf("������� a[%d][%d] = %.2f\n", selected_row, selected_col, arr[selected_row][selected_col]);
    }
    else {
        printf("������: �������� ������� ��������� �� ��������� �������.\n");
    }

    int target_col;
    printf("\n������� ����� ������� ��� ������ ������������� �������� (0-%d): ", col - 1);
    scanf("%d", &target_col);

    // ����� ������������� �������� � ��������� �������
    double max_value = max_in_column(row, col, arr, target_col);
    if (max_value != -1) {
        printf("������������ ������� � ������� %d: %.2f\n", target_col, max_value);
    }

    system("pause");

    //Ex.2

    int array[ROW][COL];
    int Col = 7, Row = 7;

    printf("�������� ������: \n");
    fill_arr2(Row, Col, array);
    print_arr_tab2(Row, Col, array);

    int trans_arr[COL][ROW];
    transpose_arr(Row, Col, array, trans_arr);
    printf("����������������� ������\n");
    print_arr_tab2(Col, Row, trans_arr);

    double calc_arr = calc(Row,trans_arr);

    if (calc_arr != 0)
    {
        printf("\n������� �������������� ������ ��������� �������� �������: %.2f\n",calc_arr);
    }

    int pairs_count = count_pairs(Row, Col, trans_arr);

    printf("\n���������� ��� ���������� �������� ���������: %d\n", pairs_count);


    find_max_coords(Row, Col, trans_arr);

    system("pause");
}