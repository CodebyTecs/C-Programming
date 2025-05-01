#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define N 2500

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct matrix {
    int **A;
    int **B;
    int **C;
    int n;
    int start;
    int end;
};

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

void feel_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 1;
        }
    }
}

void print_matrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void* thread_func(void* arg) {
    struct matrix matrixs = *(struct matrix*)arg;
    int n = matrixs.n;

    for(int i = matrixs.start; i < matrixs.end; i++) {
        for(int j = 0; j < n; j++) {
            matrixs.C[i][j] = 0;
            for(int k = 0; k < n; k++)
                matrixs.C[i][j] += matrixs.A[i][k] * matrixs.B[k][j];
        }
    }

    return NULL;
}

int main() {
    struct matrix matrixs;
    matrixs.A = make_matrix(N);
    matrixs.B = make_matrix(N);
    matrixs.C = make_matrix(N);

    feel_matrix(matrixs.A, N);
    feel_matrix(matrixs.B, N);

    int threads;
    printf("Введите кол-во потоков: ");
    scanf("%d", &threads);

    pthread_t thread[threads];
    struct matrix matrix_args[threads];
    int n = N / threads;

    time_t t0 = time(0);
    for (int i = 0; i < threads; i++) {
        matrix_args[i].A = matrixs.A;
        matrix_args[i].B = matrixs.B;
        matrix_args[i].C = matrixs.C;
        matrix_args[i].n = N;
        matrix_args[i].start = i * n;
        matrix_args[i].end = (i == threads - 1) ? N : (i + 1) * n;

        pthread_create(&thread[i], NULL, thread_func, &matrix_args[i]);
    }

    for (int i = 0; i < threads; i++) {
        pthread_join(thread[i], NULL);
    }
    time_t t1 = time(0);

    if (N < 5) {
        print_matrix(matrixs.A, N);
        print_matrix(matrixs.B, N);
        print_matrix(matrixs.C, N);
    }
    double time_in_seconds = difftime(t1, t0);
    printf("%lf", time_in_seconds * 1000);

    free_matrix(matrixs.A, N);
    free_matrix(matrixs.B, N);
    free_matrix(matrixs.C, N);

    return 0;
}