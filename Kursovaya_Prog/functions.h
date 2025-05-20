#ifndef FREQUENCY_H
#define FREQUENCY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct word_frequency
{
    char *word;
    int frequency;
    struct word_frequency *next;
} word_frequency;

word_frequency *create_word_node(const char *word);
void add_word(word_frequency **head, const char *word);
void free_list(word_frequency *head);
void sort_words(word_frequency **head);
void process_text_file(const char *input_filename, const char *output_filename);
void count_chars_and_words(const char *filename, int *char_count, int *word_count);

#endif