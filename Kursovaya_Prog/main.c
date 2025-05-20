#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "functions.h"
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Использование: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    if (strlen(argv[1]) == 0 || strlen(argv[2]) == 0) {
        printf("Ошибка: имена файлов не могут быть пустыми\n");
        return 1;
    }
    if (access(argv[1], F_OK | R_OK) != 0) {
        printf("Ошибка: входной файл '%s' не существует или недоступен\n", argv[1]);
        return 1;
    }
    const char* input_filename = argv[1];
    const char* output_filename = argv[2];
    int char_count, word_count;
    count_chars_and_words(input_filename, &char_count, &word_count);
    printf("Результат:\n");
    printf("Количество символов: %d\n", char_count);
    printf("Количество слов: %d\n", word_count);
    process_text_file(input_filename, output_filename);
    printf("Готово! Результат записан в %s\n", output_filename);
    return 0;
}

