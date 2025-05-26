#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

struct Student addStudent(char *name, int math, int phy, int inf) {
    struct Student newStudent;
    strcpy(newStudent.name, name);
    newStudent.math = math;
    newStudent.phy = phy;
    newStudent.inf = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

void printStudentInfo(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Имя: %s, математика: %d, физика: %d, информатика: %d, сумма: %d\n", 
                students[i].name, students[i].math, students[i].phy, students[i].inf, students[i].total);
    }
}

void SelectSort(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) { 
            if (students[j].total < students[minIndex].total) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            struct Student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
}

void CountingSort(struct Student students[], int n) {
    int max_total = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].total > max_total) {
            max_total = students[i].total;
        }
    }

    int* C = (int*)calloc(max_total + 1, sizeof(int));
    struct Student* sorted = (struct Student*)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        C[students[i].total]++;
    }

    for (int i = 1; i <= max_total; i++) {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        sorted[C[students[i].total] - 1] = students[i];
        C[students[i].total]--;
    }

    for (int i = 0; i < n; i++) {
        students[i] = sorted[i];
    }

    free(C);
    free(sorted);
}

int partition(struct Student students[], int l, int r) {
    int v = students[(l + r) / 2].total;
    int i = l;
    int j = r;

    while (i <= j) {
        while (students[i].total < v) {
            i++;
        }
        while (students[j].total > v) {
            j--;
        }

        if (i >= j) {
            break;
        }

        struct Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
        i++;
        j--;
    }

    return j;
}

void QuickSort(struct Student students[], int l, int r) {
    if (l < r) {
        int q = partition(students, l, r);
        QuickSort(students, l, q);
        QuickSort(students, q + 1, r);
    }
}

