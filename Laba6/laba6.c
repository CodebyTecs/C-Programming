#include <stdio.h>
/*
int main() {
    int A[] = {1, 2, 2, 1, 2, 3, 3, 2};
    int B[] = {3, 4, 4, 3, 4, 5, 5, 4};
    int C[8] = {};
    int max;
    int s = 0;
    int p = 0;
    int anw = 0;

    for (int i = 0; i < 8; i++) // складываем элементы массивов A и B, помещая их в массив C
        C[i] = A[i] + B[i];

    for (int i = 0; i < 8; i += 2) { // перебираем элементы массива, продвигая самый большой в конец
        max = C[i];
        if (C[i] > max) {
            max = C[i];
        }
    }
    printf("%d\n", max); // выводим самый большой элемент массива 

    for (int i = 1; i < 8; i += 2) { // находим элементы через условие
        if (B[i] < 0) {
            s++;
        }
    }
    printf("%d\n", s);

    for (int i = 0; i < 8; i++) { // складываем все значения элементов
        p += C[i];
    }
    anw = p/8;
    printf("%d\n", anw);
}


/*
int find(int n) { // функция для проверки чисел на "простоту"
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int Y[] = {10, 11, 12, 13, 14, 15, 16, 17, 19};  
    int size = 9;
    int sizenew = 0;  
    int s = 0;
    int max = 0;
    int maxnew = 0;
    
    max = Y[0]; // нахожу максимальный элемент 
    for (int i = 1; i < size; i++) {
        if (Y[i] > max) {
            max = Y[i];
        }
    }

    for (int i = 0; i < size; i++) { // считаю количество простых чисел
        if (Y[i] >= 10 && Y[i] < 100 && find(Y[i])) {
            s++;
        }
    }
    printf("%d\n", s);

    if (s > 2) { // выполняю условие, если чисел больше 2
        for (int i = 0; i < size; i++) {
            if (Y[i] >= 10 && Y[i] < 100 && find(Y[i])) { // записываю в массив все числа кроме простых
                continue;
            }
            else {
                Y[sizenew] = Y[i];
                sizenew++;
            }
        }
        size = sizenew;  
    }

    maxnew = Y[0]; // нахожу максимальный элемент нового массива
    for (int i = 1; i < size; i++) {
        if (Y[i] > maxnew) {
            maxnew = Y[i];
        }
    }

    if (max == maxnew) { // вывожу информацию об изменении максимального элемента
        printf("Not change\n");
    } else {
        printf("Changed\n");
    }

    for (int i = 0; i < size; i++){
        printf("%d ", Y[i]);
    }
}
*/