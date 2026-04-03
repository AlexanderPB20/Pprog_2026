#include <stdio.h> 
#include <stdlib.h> 
#include "set.h"
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 12

int main(int argc, char** argv) {
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  if (all || test == 3) test1_set_add_element_to_set();
  if (all || test == 4) test2_set_add_element_to_set();
  if (all || test == 5) test1_set_del_element_to_set();
  if (all || test == 6) test2_set_del_element_to_set();
  if (all || test == 7) test1_set_find();
  if (all || test == 8) test2_set_find();
  if (all || test == 9) test1_set_get_element();
  if (all || test == 10) test2_set_get_element();
  if (all || test == 11) test1_set_get_n_elements();
  if (all || test == 12) test2_set_get_n_elements();

  PRINT_PASSED_PERCENTAGE;
  return 0;
}

void test1_set_create() {
  Set *s = set_create();
  PRINT_TEST_RESULT(s != NULL);
  set_destroy(s);
}
void test2_set_create() {
  Set *s = set_create();
  PRINT_TEST_RESULT(set_get_n_elements(s) == 0);
  set_destroy(s);
}

void test1_set_add_element_to_set() {
  Set *s = set_create();
  PRINT_TEST_RESULT(set_add_element_to_set(s, 5) == OK);
  set_destroy(s);
}
void test2_set_add_element_to_set() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_add_element_to_set(s, 5) == ERROR);
}

void test1_set_del_element_to_set() {
  Set *s = set_create();
  set_add_element_to_set(s, 5);
  PRINT_TEST_RESULT(set_del_element_to_set(s, 5) == OK);
  set_destroy(s);
}
void test2_set_del_element_to_set() {
  Set *s = set_create();
  PRINT_TEST_RESULT(set_del_element_to_set(s, 5) == ERROR); /* Elemento que no existe */
  set_destroy(s);
}

void test1_set_find() {
  Set *s = set_create();
  set_add_element_to_set(s, 10);
  PRINT_TEST_RESULT(set_find(s, 10) == TRUE);
  set_destroy(s);
}
void test2_set_find() {
  Set *s = set_create();
  set_add_element_to_set(s, 10);
  PRINT_TEST_RESULT(set_find(s, 5) == FALSE);
  set_destroy(s);
}

void test1_set_get_element() {
  Set *s = set_create();
  set_add_element_to_set(s, 10);
  PRINT_TEST_RESULT(set_get_element(s, 0) == 10);
  set_destroy(s);
}
void test2_set_get_element() {
  Set *s = set_create();
  PRINT_TEST_RESULT(set_get_element(s, 0) == NO_ID); /* Índice fuera de rango */
  set_destroy(s);
}

void test1_set_get_n_elements() {
  Set *s = set_create();
  set_add_element_to_set(s, 1);
  set_add_element_to_set(s, 2);
  PRINT_TEST_RESULT(set_get_n_elements(s) == 2);
  set_destroy(s);
}
void test2_set_get_n_elements() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_get_n_elements(s) == -1);
}