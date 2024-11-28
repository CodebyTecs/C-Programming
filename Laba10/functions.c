#include "functions.h"

void take_points(struct Point *p, int a, int b, int n) {
    for (int i = 0; i < n; i++) {
        printf("Введите значения X и Y для точки %d (уравнение y = %dx + %d): ", i + 1, a, b);
        scanf("%d %d", &p[i].x, &p[i].y);
    }
}

int check_points(struct Point *p, int a, int b, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int r = a * p[i].x + b;
        if (p[i].y == r) {
            k++;
        }
    }
    return k;
}