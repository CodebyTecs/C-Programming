#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct spravka {
    char start[100];
    char end[100];
    int number;
};

int writeSpravka(char *filename, struct spravka spravki[], int N) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }
    fwrite(spravki, sizeof(struct spravka), N, file);
    fclose(file);
    return 0;
}

int findStart(char *filename, char choice_str[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    struct spravka temp;
    int i = 0;
    while (fread(&temp, sizeof(struct spravka), 1, file) == 1) {
        if (strcmp(temp.start, choice_str) == 0) {
            printf("Маршрут: %s -> %s, Номер: %d\n", temp.start, temp.end, temp.number);
            i += 1;
        }
    }

    if (i == 0) printf("Справка не найдена\n");

    fclose(file);
    return 0;
}

int findEnd(char *filename, char choice_str[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    struct spravka temp;
    int i = 0;
    while (fread(&temp, sizeof(struct spravka), 1, file) == 1) {
        if (strcmp(temp.end, choice_str) == 0) {
            printf("Маршрут: %s -> %s, Номер: %d\n", temp.start, temp.end, temp.number);
        }
    }

    if (i == 0) printf("Справка не найдена\n");

    fclose(file);
    return 0;
}

int findNumber(char *filename, int choice_num) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Ошибка открытия файла");
        return 1;
    }

    struct spravka temp;
    int i = 0;
    while (fread(&temp, sizeof(struct spravka), 1, file) == 1) {
        if (temp.number == choice_num) {
            printf("Маршрут: %s -> %s, Номер: %d\n", temp.start, temp.end, temp.number);
        }
    }

    if (i == 0) printf("Справка не найдена\n");

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Ошибка: укажите имя файла в аргументах командной строки!\n");
        return 1;
    }

    int N;
    printf("Введите кол-во структур: ");
    scanf("%d", &N);

    char *filename = argv[1];
    struct spravka spravki[N];

    for (int i = 0; i < N; i++) {
        printf("Введите данные для справки %d\n", i + 1);
        printf("Введите название начального пункта: ");
        scanf("%s", spravki[i].start);
        printf("Введите название конечного пункта: ");
        scanf("%s", spravki[i].end);
        printf("Введите номер маршрута: ");
        scanf("%d", &spravki[i].number);
    }

    writeSpravka(filename, spravki, N);

    char choice[10];
    while (1) {
        printf("Введите поле для поиска (start | end | number): ");
        scanf("%s", choice);

        if (strcmp(choice, "start") == 0) {
            char choice_str[100];
            printf("Введите название пункта: ");
            scanf("%s", choice_str);
            findStart(filename, choice_str);
            break;
        } else if (strcmp(choice, "end") == 0) {
            char choice_str[100];
            printf("Введите название пункта: ");
            scanf("%s", choice_str);
            findEnd(filename, choice_str);
            break;
        } else if (strcmp(choice, "number") == 0) {
            int choice_num;
            printf("Введите номер маршрута для поиска: ");
            scanf("%d", &choice_num);
            findNumber(filename, choice_num);
            break;
        } else {
            printf("Ошибка, введите поле ещё раз\n");
        }
    }
    return 0;
}