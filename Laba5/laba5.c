#include <stdio.h>

int main()
{
    int a[]= {1, 2, 2, 1, 2, 3, 3, 2};
    int b[] = {3, 4, 4, 3, 4, 5, 5, 4};
    int c[16] = {};
    int j = 0;
    int k = 0;
    int n = 8;
    int s = 0;
    int tmp;
    for (int i = 0, j, k; i < (2 * n) - 1; i++) {
        if (i <= 7)
        {
            c[i] = a[k];
            k++;
        }
        else
        {
            c[i] = b[j];
            j++;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (j % 2 == 0) {
                if (a[j] > a[j + 1]) {
                    int tmp = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = tmp;
                }
            else continue;
            }
        }
        printf("%d", tmp);

    }
    for (int i = 0, k = 0; i < n; i++){
        if (k % 2 != 0) {
            if (b[k] < 0){
                s++;
            }
        }
        k++;
        printf("%d", s);
    }
}

