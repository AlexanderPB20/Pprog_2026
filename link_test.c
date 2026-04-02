/** 
 * @brief It tests link module
 * 
 * @file link_test.c
 * @author Marta López
 * @version 0.0 
 * @date 31-03-2026
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#include "link.h"
#include "link_test.h"
#include "test.h"

#define MAX_TESTS 10

/** 
 * @brief Main function for LINK unit tests.
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Link:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_link_create();
  if (all || test == 2) test2_link_create_no_id();
  if (all || test == 3) test3_link_set_id();
  if (all || test == 4) test4_link_get_id();
  if (all || test == 5) test5_link_set_name();
  if (all || test == 6) test6_link_get_name();
  if (all || test == 7) test7_link_set_origin();
  if (all || test == 8) test8_link_get_origin();
  if (all || test == 9) test9_link_set_direction();
  if (all || test == 10) test10_link_get_direction();


  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_link_create() {
  int result;
  Link *l;
  l = link_create(5);
  result=l!=NULL ;
  PRINT_TEST_RESULT(result);
  link_destroy(l);
}

void test2_link_create_no_id() {
    Link *l;
    l = link_create(NO_ID);
    PRINT_TEST_RESULT(l == NULL);
}

void test3_link_set_id() {
    Link *l;
    l = link_create(1);
    Status result = link_set_id(l, 2);
    PRINT_TEST_RESULT(result == OK);
    link_destroy(l);
}

void test4_link_get_id() {
    Link *l;
    l = link_create(10);
    Id result = link_get_id(l);
    PRINT_TEST_RESULT(result == 10);
    link_destroy(l);
}

void test5_set_name(){
  Link *l;
  l = link_create(1);
  Status result = link_set_name(l, "door");
  PRINT_TEST_RESULT(result == OK);
  link_destroy(l);
}

void test6_link_get_name() {
  Link *l;
  l = link_create(1);
  link_set_name(l, "door");
  PRINT_TEST_RESULT(strcmp(link_get_name(l), "door") == 0);
  link_destroy(l);
}

void test7_link_set_origin() {
  Link *l;
  l = link_create(1);
  Status result = link_set_origin(l, 100);
  PRINT_TEST_RESULT(result == OK);
  link_destroy(l);
}

void test8_link_get_origin() {
  Link *l;
  l = link_create(1);
  link_set_origin(l, 100);
  Id result = link_get_origin(l);
  PRINT_TEST_RESULT(result == 100);
  link_destroy(l);
}

void test9_link_set_direction() {
  Link *l;
  l = link_create(1);
  Status result = link_set_direction(l, N);
  PRINT_TEST_RESULT(result == OK);
  link_destroy(l);
}

void test10_link_get_direction() {
  Link *l;
  l = link_create(1);
  link_set_direction(l, N);
  Id result = link_get_direction(l);
  PRINT_TEST_RESULT(result == N);
  link_destroy(l);
}