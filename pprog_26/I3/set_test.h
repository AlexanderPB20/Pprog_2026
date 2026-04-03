/** * @brief It declares the tests for the set module
 * * @file set_test.h
 * @author Samuel Manzorro
 * @version 0.0 
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Test set creation
 * @pre none
 * @post Non NULL pointer to set
 */
void test1_set_create();

/**
 * @test Test set creation
 * @pre none
 * @post Number of elements == 0
 */
void test2_set_create();

/**
 * @test Test function for adding an element to a set
 * @pre Valid pointer to set
 * @post Output == OK 
 */
void test1_set_add_element_to_set();

/**
 * @test Test function for adding an element to a set
 * @pre Pointer to set = NULL 
 * @post Output == ERROR
 */
void test2_set_add_element_to_set();

/**
 * @test Test function for deleting an element from a set
 * @pre Valid pointer to set and existing element id
 * @post Output == OK
 */
void test1_set_del_element_to_set();

/**
 * @test Test function for deleting an element from a set
 * @pre Valid pointer to set and non-existing element id
 * @post Output == ERROR
 */
void test2_set_del_element_to_set();

/**
 * @test Test function for checking if an element exists in a set
 * @pre Valid pointer to set and existing element id
 * @post Output == TRUE
 */
void test1_set_find();

/**
 * @test Test function for checking if an element exists in a set
 * @pre Valid pointer to set and non-existing element id
 * @post Output == FALSE
 */
void test2_set_find();

/**
 * @test Test function for getting an element from a set by index
 * @pre Valid pointer to set and valid index
 * @post Output == Supplied element id
 */
void test1_set_get_element();

/**
 * @test Test function for getting an element from a set by index
 * @pre Valid pointer to set and out-of-range index
 * @post Output == NO_ID
 */
void test2_set_get_element();

/**
 * @test Test function for getting the number of elements in a set
 * @pre Valid pointer to set with added elements
 * @post Output == Correct number of elements (2)
 */
void test1_set_get_n_elements();

/**
 * @test Test function for getting the number of elements in a set
 * @pre Pointer to set = NULL
 * @post Output == ERROR (-1)
 */
void test2_set_get_n_elements();

#endif