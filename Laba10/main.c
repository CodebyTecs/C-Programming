#include "functions.h"

int main() {
    int n;
    int a, b;

    printf("Введите значения a и b в функции y = ax + b: ");
    scanf("%d %d", &a, &b);

    struct Straight s;
    s.a = a;
    s.b = b;

    printf("Введите количество точек: ");
    scanf("%d", &n);

    struct Point p[n];

    take_points(p, a, b, n);

    int k = check_points(p, a, b, n);

    printf("Количество точек, принадлежащих прямой y = %dx + %d: %d\n", a, b, k);

    return 0;
}