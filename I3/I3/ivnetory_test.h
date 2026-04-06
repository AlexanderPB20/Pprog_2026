/** * @brief It declares the tests for the inventory module
 * * @file inventory_test.h
 * @author Alexander Preciado
 * @version 1.0 
 * @date 04-04-2026
 * @copyright GNU Public License
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

/**
 * @test Test creation of an inventory
 * @pre Normal conditions
 * @post Non NULL pointer to inventory
 */
void test1_inventory_create();

/**
 * @test Test setting the max objects of an inventory
 * @pre Valid inventory and valid max_objs
 * @post Output == OK
 */
void test1_inventory_set_max_objs();

/**
 * @test Test setting the max objects of an inventory
 * @pre Inventory == NULL
 * @post Output == ERROR
 */
void test2_inventory_set_max_objs();

/**
 * @test Test setting the max objects of an inventory
 * @pre Valid inventory, invalid max_objs (negative)
 * @post Output == ERROR
 */
void test3_inventory_set_max_objs();

/**
 * @test Test getting the max objects of an inventory
 * @pre Valid inventory with max_objs set
 * @post Output == max_objs set previously
 */
void test1_inventory_get_max_objs();

/**
 * @test Test getting the max objects of an inventory
 * @pre Inventory == NULL
 * @post Output == -1
 */
void test2_inventory_get_max_objs();

/**
 * @test Test adding an object to the inventory
 * @pre Valid inventory and valid object id
 * @post Output == OK
 */
void test1_inventory_add_object();

/**
 * @test Test adding an object to the inventory
 * @pre Inventory == NULL
 * @post Output == ERROR
 */
void test2_inventory_add_object();

/**
 * @test Test adding an object to a full inventory
 * @pre Valid inventory filled to maximum capacity
 * @post Output == ERROR
 */
void test3_inventory_add_object();

/**
 * @test Test removing an object from the inventory
 * @pre Valid inventory with the object inside
 * @post Output == OK
 */
void test1_inventory_remove_object();

/**
 * @test Test removing an object from the inventory
 * @pre Valid inventory, object not inside
 * @post Output == ERROR
 */
void test2_inventory_remove_object();

/**
 * @test Test checking if an inventory has a specific object
 * @pre Valid inventory with the object inside
 * @post Output == TRUE
 */
void test1_inventory_has_object();

/**
 * @test Test checking if an inventory has a specific object
 * @pre Valid inventory without the object inside
 * @post Output == FALSE
 */
void test2_inventory_has_object();

/**
 * @test Test checking if an inventory has a specific object
 * @pre Inventory == NULL
 * @post Output == ERROR / FALSE
 */
void test3_inventory_has_object();

/**
 * @test Test getting the number of objects currently in the inventory
 * @pre Valid inventory with 2 objects
 * @post Output == 2
 */
void test1_inventory_get_n_objects();

/**
 * @test Test getting the number of objects currently in the inventory
 * @pre Inventory == NULL
 * @post Output == -1
 */
void test2_inventory_get_n_objects();

/**
 * @test Test getting the object id at a specific position
 * @pre Valid inventory with an object at position 0
 * @post Output == The ID of the inserted object
 */
void test1_inventory_get_object_id();

/**
 * @test Test getting the object id at a specific position
 * @pre Inventory == NULL
 * @post Output == NO_ID
 */
void test2_inventory_get_object_id();

#endif
