#include "functions.h"

word_frequency *create_word_node(const char *word) {

    word_frequency *new_node = (word_frequency *)malloc(sizeof(word_frequency));

    if (new_node == NULL) {

        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    new_node->word = strdup(word);
    if (new_node->word == NULL) {

        free(new_node);
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    new_node->frequency = 1;
    new_node->next = NULL;
    return new_node;
}

void add_word(word_frequency **head, const char *word) {
    if (*head == NULL) {

        *head = create_word_node(word);
        return;
    }

    word_frequency *current = *head;
    word_frequency *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->frequency++;
            return;
        }

        prev = current;
        current = current->next;
    }

    prev->next = create_word_node(word);
}

void free_list(word_frequency *head) {

    word_frequency *current = head;
    while (current != NULL) {

        word_frequency *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
}

void sort_words(word_frequency **head) {

    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    bool swapped;
    word_frequency *ptr1;
    word_frequency *lptr = NULL;

    do {
        swapped = false;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->frequency < ptr1->next->frequency) {
                char *temp_word = ptr1->word;
                int temp_freq = ptr1->frequency;

                ptr1->word = ptr1->next->word;
                ptr1->frequency = ptr1->next->frequency;

                ptr1->next->word = temp_word;
                ptr1->next->frequency = temp_freq;

                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void count_chars_and_words(const char *filename, int *char_count, int *word_count) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {

        perror("Файл не открылся");
        exit(1);
    }

    *char_count = 0;
    *word_count = 0;
    int c;
    bool in_word = false;

    while ((c = fgetc(file)) != EOF) {

        (*char_count)++;

        if (isspace(c) || c == ',' || c == '.' || c == '!' || c == '?' || c == ';' || c == ':') {
            if (in_word) {
                (*word_count)++;
                in_word = false;
            }
        }
        else {
            in_word = true;
        }
    }

    if (in_word) {
        (*word_count)++;
    }

    fclose(file);
}

void process_text_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {

        perror("Файл не открылся");
        exit(1);
    }

    word_frequency *word_list = NULL;
    char buffer[256];
    int index = 0;
    int c;

    do {
        c = fgetc(input_file);

        if (isalpha(c) || c == '\'') {
            buffer[index++] = tolower(c);
        }
        else if (index > 0) {
            buffer[index] = '\0';
            add_word(&word_list, buffer);
            index = 0;
        }

        if (c == EOF) {
            break;
        }

    } while (c != 0);

    fclose(input_file);

    sort_words(&word_list);

    FILE *output_file = fopen(output_filename, "w");

    if (output_file == NULL) {

        perror("Файл не открылся");
        free_list(word_list);
        exit(1);
    }

    word_frequency *current = word_list;
    while (current != NULL) {

        fprintf(output_file, "%s: %d\n", current->word, current->frequency);
        current = current->next;
    }

    fclose(output_file);
    free_list(word_list);
}