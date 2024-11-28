// 1. Заполнение матрицы (с клавиатуры и рандомными числами)
// 2. Поиск строки, сумма элементов которой меньше 15
// 3. Увеличение элементов строки на элемент побочной диагонали
// 4. Определение строки с наибольшим количеством отрицательных элементов

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int **make_matrix(int n) {
    int **matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int feel_matrix_keyboard(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int success = 0;
            while (success == 0) {
                int data;
                printf("Введите элемент на %d строчке на %d позиции: ", i, j);
                if (scanf("%d", &data) == 1) {
                    matrix[i][j] = data;
                    success = 1;
                } else {
                    printf("Ошибка, введите целое число\n");
                    while (getchar() != '\n');
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int feel_matrix_random(int **matrix, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100 - 50;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int find_sum(int **matrix, int *strs, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += matrix[i][j];
        }
        if (s < 15) {
            strs[k++] = i;
        }
    }
    printf("Количество строк с суммой элементов больше 15: %d\n", k);
    printf("\n");
    return k;
}

int up(int **matrix, int *strs, int num_strs, int n) {
    for (int k = 0; k < num_strs; k++) { 
        int i = strs[k]; 
        int elem = matrix[i][n - 1 - i]; 
        for (int j = 0; j < n; j++) {
            matrix[i][j] += elem; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int find_str(int **matrix, int n) {
    int lstr = 0;
    int max = -1; 
    for (int i = 0; i < n; i++) {
        int l = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0)
                l++;
        }
        if (l > max) {
            max = l;
            lstr = i;
        }
    }
    printf("Строка с наибольшим количеством отрицательных элементов: %d\n", lstr);
    return lstr;
}

int main() {
    int keyboard = 0;
    int random = 1;
    int anw;
    int n;

    printf("Как вы хотите заполнить матрицу (введите '0 = keyboard' или '1 = random')?\n");
    scanf("%d", &anw);

    printf("Введите значение n для матрицы nxn: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Ошибка, введите положительное целое число для n\n");
        return 1;
    }

    int **matrix = make_matrix(n);
    int *strs = (int*)malloc(n * sizeof(int));

    if (anw == keyboard) {
        feel_matrix_keyboard(matrix, n);
    } else if (anw == random) {
        feel_matrix_random(matrix, n);
    } else {
        printf("Неизвестный тип заполнения\n");
        free_matrix(matrix, n);
        free(strs);
        return 1;
    }

    int num_strs = find_sum(matrix, strs, n);
    up(matrix, strs, num_strs, n);
    find_str(matrix, n);

    free_matrix(matrix, n);
    free(strs);
    return 0;
}