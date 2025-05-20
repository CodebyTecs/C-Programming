#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

static void test_make_node(void **state) {

    word_frequency *node = create_word_node("cat");

    assert_non_null(node);
    assert_string_equal(node->word, "cat");
    assert_int_equal(node->frequency, 1);
    assert_null(node->next);

    free(node->word);
    free(node);
}

static void test_add_word(void **state) {

    word_frequency *list = NULL;

    add_word(&list, "dog");
    assert_non_null(list);
    assert_string_equal(list->word, "dog");
    assert_int_equal(list->frequency, 1);

    add_word(&list, "dog");
    assert_int_equal(list->frequency, 2);

    add_word(&list, "cat");
    assert_non_null(list->next);
    assert_string_equal(list->next->word, "cat");
    assert_int_equal(list->next->frequency, 1);

    free_list(list);
}

static void test_sort_words(void **state) {

    word_frequency *list = NULL;

    add_word(&list, "dog");
    add_word(&list, "dog");
    add_word(&list, "cat");
    add_word(&list, "cat");
    add_word(&list, "cat");
    add_word(&list, "bird");

    sort_words(&list);

    assert_string_equal(list->word, "cat");
    assert_int_equal(list->frequency, 3);
    assert_string_equal(list->next->word, "dog");
    assert_int_equal(list->next->frequency, 2);
    assert_string_equal(list->next->next->word, "bird");
    assert_int_equal(list->next->next->frequency, 1);

    free_list(list);
}

static void test_count_words(void **state) {

    FILE *file = fopen("test.txt", "w");

    fprintf(file, "hi world");
    fclose(file);

    int chars = 0, words = 0;
    count_chars_and_words("test.txt", &chars, &words);
    assert_int_equal(chars, 8);
    assert_int_equal(words, 2);

    remove("test.txt");
}

static void test_process_file(void **state) {

    FILE *input = fopen("input.txt", "w");

    fprintf(input, "hi hi world");
    fclose(input);

    process_text_file("input.txt", "output.txt");
    FILE *output = fopen("output.txt", "r");
    char line[100];

    fgets(line, 100, output);
    assert_string_equal(line, "hi: 2\n");

    fgets(line, 100, output);
    assert_string_equal(line, "world: 1\n");
    
    fclose(output);
    remove("input.txt");
    remove("output.txt");
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_make_node),
        cmocka_unit_test(test_add_word),
        cmocka_unit_test(test_sort_words),
        cmocka_unit_test(test_count_words),
        cmocka_unit_test(test_process_file),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}