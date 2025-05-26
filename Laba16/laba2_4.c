#include <stdio.h>
#include <string.h>

void makeStrings(FILE *file) {
    fprintf(file, "Hello world\n");
    fprintf(file, "This is a test string\n");
    fprintf(file, "File handling in C is useful\n");
    fprintf(file, "Short\n");
    fprintf(file, "Reading and writing files  \n");
    fprintf(file, "A longer sentence with multiple words for testing purposes\n");
    fprintf(file, "Experimenting with file operations such as opening reading writing and closing\n");
    fprintf(file, "C programming allows low-level file manipulation, which is powerful and efficient\n");
    fprintf(file, "Testing different string lengths for file input and output\n");
    fprintf(file, "Handling text files requires understanding of functions like fopen fclose fread and fwrite\n");
}

void printStrings(FILE *file) {
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "w+");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    makeStrings(file);
    
    rewind(file);
    printf("Исходный файл:\n");
    printStrings(file);
    
    rewind(file);
    char buffer[1000], longest[1000] = "";
    int max_len = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        int len = strlen(buffer);
        if (len > max_len) {
            max_len = len;
            strcpy(longest, buffer);
        }
    }

    char *words[1000];
    int i = 0;
    char *word = strtok(longest, " ");
    while (word != NULL) {
        words[i] = word;
        word = strtok(NULL, " ");
        i++;
    }

    if (i > 1) {
        char *temp = words[0];
        words[0] = words[i - 1];
        words[i - 1] = temp;
    }

    printf("Новая строка: \n");
    for (int j = 0; j < i; j++) {
        printf("%s ", words[j]);
    }
    printf("\n");

    fclose(file);
}