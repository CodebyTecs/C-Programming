#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#define N 10

int main() {
    srand(time(NULL));

    struct Student* students = (struct Student*)malloc(N * sizeof(struct Student)); 

    for (int i = 0; i < N; i++) {
        char name[64];
        sprintf(name, "Student_%d", i + 1);
        int math = rand() % 101;
        int phy = rand() % 101;
        int inf = rand() % 101;

        students[i] = addStudent(name, math, phy, inf);
    }

    printf("Исходные данные:\n");
    printStudentInfo(students, N);
    printf("\n");

    QuickSort(students, 0, N - 1);
    printf("После QuickSort:\n");
    printStudentInfo(students, N);
    printf("\n");

    free(students);
}