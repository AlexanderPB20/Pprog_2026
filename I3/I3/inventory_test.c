/** * @brief It tests inventory module
 * * @file inventory_test.c
 * @author Alexander Preciado
 * @version 1.0 
 * @date 04-04-2026
 * @copyright GNU Public License
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "inventory.h"
#include "inventory_test.h"
#include "test.h"

#define MAX_TESTS 18

/** * @brief Main function for INVENTORY unit tests. 
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Inventory:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test1_inventory_set_max_objs();
  if (all || test == 3) test2_inventory_set_max_objs();
  if (all || test == 4) test3_inventory_set_max_objs();
  if (all || test == 5) test1_inventory_get_max_objs();
  if (all || test == 6) test2_inventory_get_max_objs();
  if (all || test == 7) test1_inventory_add_object();
  if (all || test == 8) test2_inventory_add_object();
  if (all || test == 9) test3_inventory_add_object();
  if (all || test == 10) test1_inventory_remove_object();
  if (all || test == 11) test2_inventory_remove_object();
  if (all || test == 12) test1_inventory_has_object();
  if (all || test == 13) test2_inventory_has_object();
  if (all || test == 14) test3_inventory_has_object();
  if (all || test == 15) test1_inventory_get_n_objects();
  if (all || test == 16) test2_inventory_get_n_objects();
  if (all || test == 17) test1_inventory_get_object_id();
  if (all || test == 18) test2_inventory_get_object_id();

  PRINT_PASSED_PERCENTAGE;

  return 0;
}

void test1_inventory_create() {
  Inventory *inv = inventory_create();
  PRINT_TEST_RESULT(inv != NULL);
  inventory_destroy(inv);
}

void test1_inventory_set_max_objs() {
  Inventory *inv = inventory_create();
  PRINT_TEST_RESULT(inventory_set_max_objs(inv, 10) == OK);
  inventory_destroy(inv);
}

void test2_inventory_set_max_objs() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_set_max_objs(inv, 10) == ERROR);
}

void test3_inventory_set_max_objs() {
  Inventory *inv = inventory_create();
  PRINT_TEST_RESULT(inventory_set_max_objs(inv, -5) == ERROR);
  inventory_destroy(inv);
}

void test1_inventory_get_max_objs() {
  Inventory *inv = inventory_create();
  inventory_set_max_objs(inv, 8);
  PRINT_TEST_RESULT(inventory_get_max_objs(inv) == 8);
  inventory_destroy(inv);
}

void test2_inventory_get_max_objs() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_get_max_objs(inv) == -1);
}

void test1_inventory_add_object() {
  Inventory *inv = inventory_create();
  PRINT_TEST_RESULT(inventory_add_object(inv, 5) == OK);
  inventory_destroy(inv);
}

void test2_inventory_add_object() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_add_object(inv, 5) == ERROR);
}

void test3_inventory_add_object() {
  Inventory *inv = inventory_create();
  /* Llenamos el inventario hasta el máximo por defecto (MAX_OBJS = 5) */
  inventory_add_object(inv, 1);
  inventory_add_object(inv, 2);
  inventory_add_object(inv, 3);
  inventory_add_object(inv, 4);
  inventory_add_object(inv, 5);
  /* Intentamos añadir un sexto objeto */
  PRINT_TEST_RESULT(inventory_add_object(inv, 6) == ERROR);
  inventory_destroy(inv);
}

void test1_inventory_remove_object() {
  Inventory *inv = inventory_create();
  inventory_add_object(inv, 5);
  PRINT_TEST_RESULT(inventory_remove_object(inv, 5) == OK);
  inventory_destroy(inv);
}

void test2_inventory_remove_object() {
  Inventory *inv = inventory_create();
  /* Intentar borrar un objeto que no está en el inventario */
  PRINT_TEST_RESULT(inventory_remove_object(inv, 5) == ERROR);
  inventory_destroy(inv);
}

void test1_inventory_has_object() {
  Inventory *inv = inventory_create();
  inventory_add_object(inv, 5);
  PRINT_TEST_RESULT(inventory_has_object(inv, 5) == TRUE);
  inventory_destroy(inv);
}

void test2_inventory_has_object() {
  Inventory *inv = inventory_create();
  PRINT_TEST_RESULT(inventory_has_object(inv, 5) == FALSE);
  inventory_destroy(inv);
}

void test3_inventory_has_object() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_has_object(inv, 5) == FALSE); 
}

void test1_inventory_get_n_objects() {
  Inventory *inv = inventory_create();
  inventory_add_object(inv, 5);
  inventory_add_object(inv, 7);
  PRINT_TEST_RESULT(inventory_get_n_objects(inv) == 2);
  inventory_destroy(inv);
}

void test2_inventory_get_n_objects() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_get_n_objects(inv) == -1);
}

void test1_inventory_get_object_id() {
  Inventory *inv = inventory_create();
  inventory_add_object(inv, 5);
  PRINT_TEST_RESULT(inventory_get_object_id(inv, 0) == 5);
  inventory_destroy(inv);
}

void test2_inventory_get_object_id() {
  Inventory *inv = NULL;
  PRINT_TEST_RESULT(inventory_get_object_id(inv, 0) == NO_ID);
}
