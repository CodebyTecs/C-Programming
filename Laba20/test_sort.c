#include "sort.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>

static void initialize_student(struct Student *s, const char *name, int math, int phy, int inf) {
    memset(s, 0, sizeof(struct Student)); 
    strncpy(s->name, name, 63);
    s->math = math;
    s->phy = phy;
    s->inf = inf;
    s->total = math + phy + inf;
}

static void test_countingsort(void **state) {
    int n = 5;
    struct Student students[5];
    struct Student expected[5];
    
    initialize_student(&students[0], "A", 30, 30, 30);
    initialize_student(&students[1], "B", 40, 40, 40);
    initialize_student(&students[2], "C", 20, 20, 20);
    initialize_student(&students[3], "D", 50, 50, 50);
    initialize_student(&students[4], "E", 10, 10, 10);
    
    initialize_student(&expected[0], "D", 50, 50, 50);
    initialize_student(&expected[1], "B", 40, 40, 40);
    initialize_student(&expected[2], "A", 30, 30, 30);
    initialize_student(&expected[3], "C", 20, 20, 20);
    initialize_student(&expected[4], "E", 10, 10, 10);
    
    CountingSort(n, students);
    
    assert_memory_equal(students, expected, n * sizeof(struct Student));
}

static void test_selectionsort(void **state) {
    int n = 5;
    struct Student students[5];
    struct Student expected[5];
    
    initialize_student(&students[0], "A", 30, 30, 30);
    initialize_student(&students[1], "B", 40, 40, 40);
    initialize_student(&students[2], "C", 20, 20, 20);
    initialize_student(&students[3], "D", 50, 50, 50);
    initialize_student(&students[4], "E", 10, 10, 10);
    
    initialize_student(&expected[0], "D", 50, 50, 50);
    initialize_student(&expected[1], "B", 40, 40, 40);
    initialize_student(&expected[2], "A", 30, 30, 30);
    initialize_student(&expected[3], "C", 20, 20, 20);
    initialize_student(&expected[4], "E", 10, 10, 10);
    
    SelectionSort(students, n);
    
    assert_memory_equal(students, expected, n * sizeof(struct Student));
}

static void test_quicksort(void **state) {
    int n = 5;
    struct Student students[5];
    struct Student expected[5];
    
    initialize_student(&students[0], "A", 30, 30, 30);
    initialize_student(&students[1], "B", 40, 40, 40);
    initialize_student(&students[2], "C", 20, 20, 20);
    initialize_student(&students[3], "D", 50, 50, 50);
    initialize_student(&students[4], "E", 10, 10, 10);
    
    initialize_student(&expected[0], "D", 50, 50, 50);
    initialize_student(&expected[1], "B", 40, 40, 40);
    initialize_student(&expected[2], "A", 30, 30, 30);
    initialize_student(&expected[3], "C", 20, 20, 20);
    initialize_student(&expected[4], "E", 10, 10, 10);
    
    quicksort(students, 0, n-1);
    
    assert_memory_equal(students, expected, n * sizeof(struct Student));
}

static void test_empty_array(void **state) {
    struct Student students[1] = {0}; 
    struct Student expected[1] = {0};
    
    CountingSort(0, students);
    SelectionSort(students, 0);
    quicksort(students, 0, -1); 

    assert_memory_equal(students, expected, 0);
}

static void test_negative_size(void **state) {
    struct Student students[1];
    initialize_student(&students[0], "X", 0, 0, 0);
    struct Student original = students[0];
    
    CountingSort(-1, students);
    SelectionSort(students, -1);
    quicksort(students, 0, -2);
    
    assert_memory_equal(&students[0], &original, sizeof(struct Student));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_countingsort),
        cmocka_unit_test(test_selectionsort),
        cmocka_unit_test(test_quicksort),
        cmocka_unit_test(test_empty_array),
        cmocka_unit_test(test_negative_size),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}

