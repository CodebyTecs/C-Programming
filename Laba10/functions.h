#include <stdio.h>

struct Straight {
    int a;
    int b;
};

struct Point {
    int x;
    int y;
};

void take_points(struct Point *p, int a, int b, int n);
int check_points(struct Point *p, int a, int b, int n);