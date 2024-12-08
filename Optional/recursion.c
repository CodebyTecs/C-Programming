#include <stdio.h>
#include <math.h>

double num_p(int n, double p, double E) {
    double new_p = pow(-1, n - 1) * 1 / (2 * n - 1); 
    if (fabs(new_p) < E) {
        return p;
    }
    return num_p(n + 1, p + new_p, E); 
}

int main() {
    double P = 0;
    double E = pow(10, -2); 

    P = num_p(1, 0, E) * 4; 
    printf("%lf\n", P);  

    return 0;
}