// sort.c
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Student addStudent(const char* name, int math, int phy, int inf) {
    struct Student newStudent;
    strncpy(newStudent.name, name, 63);
    newStudent.name[63] = '\0';
    newStudent.math = math;
    newStudent.phy = phy;
    newStudent.inf = inf;
    newStudent.total = math + phy + inf;
    return newStudent;
}

void CountingSort(int n, struct Student *students) {
    if (n <= 0) return;

    int* count = (int*)calloc(MAX + 1, sizeof(int));
    struct Student* output = (struct Student*)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++) {
        count[students[i].total]++;
    }

    for (int i = MAX - 1; i >= 0; i--) {
        count[i] += count[i + 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[students[i].total] - 1] = students[i];
        count[students[i].total]--;
    }

    for (int i = 0; i < n; i++) {
        students[i] = output[i];
    }

    free(count);
    free(output);
}

void SelectionSort(struct Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].total > arr[maxIndex].total) {
                maxIndex = j;
            }
        }
        struct Student temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

void swapStudents(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct Student arr[], int low, int high) {
    int pivot = arr[high].total;
    int i = low;
    
    for (int j = low; j < high; j++) {
        if (arr[j].total >= pivot) {
            swapStudents(&arr[i], &arr[j]);
            i++;
        }
    }
    swapStudents(&arr[i], &arr[high]);
    return i;
}

void quicksort(struct Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void printPerson(struct Student p) {
    printf("name: %s; ", p.name);
    printf("math: %d; ", p.math);
    printf("phy: %d; ", p.phy);
    printf("inf: %d; ", p.inf);
    printf("total: %d; \n", p.total);
}

void CpuInfo() {
    system("grep 'model name' /proc/cpuinfo | uniq");
    system("grep 'cpu MHz' /proc/cpuinfo | uniq");
}
