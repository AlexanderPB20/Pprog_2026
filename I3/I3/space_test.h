/** * @brief It declares the tests for the space module
 * * @file space_test.h
 * @author Profesores Pprog
 * @author Samuel Manzorro
 * @version 0.0 
 * @date 17-02-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Output == OK 
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output == ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (pointer to space = NON NULL) 
 * @post Output == ERROR
 */
void test3_space_set_name();

/**
 * @test Test function for space_north setting
 * @pre Valid pointer to space
 * @post Output == OK
 */
void test1_space_set_north();

/**
 * @test Test function for space_north setting
 * @pre Pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_set_north();

/**
 * @test Test function for space_south setting
 * @pre Valid pointer to space
 * @post Output == OK
 */
void test1_space_set_south();

/**
 * @test Test function for space_south setting
 * @pre Pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_set_south();

/**
 * @test Test function for space_east setting
 * @pre Valid pointer to space
 * @post Output == OK
 */
void test1_space_set_east();

/**
 * @test Test function for space_east setting
 * @pre Pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_set_east();

/**
 * @test Test function for space_west setting
 * @pre Valid pointer to space
 * @post Output == OK
 */
void test1_space_set_west();

/**
 * @test Test function for space_west setting
 * @pre Pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_set_west();

/**
 * @test Test function for space_id getting
 * @pre Valid pointer to space
 * @post Output == Supplied Space Id
 */
void test1_space_get_id();

/**
 * @test Test function for space_id getting
 * @pre Pointer to space = NULL
 * @post Output == NO_ID
 */
void test2_space_get_id();

/**
 * @test Test function for space_name getting
 * @pre Valid pointer to space
 * @post Output == String with space name
 */
void test1_space_get_name();

/**
 * @test Test function for space_name getting
 * @pre Pointer to space = NULL
 * @post Output == NULL
 */
void test2_space_get_name();

/**
 * @test Test function for space_north getting
 * @pre Valid pointer to space
 * @post Output == Supplied North Link Id
 */
void test1_space_get_north();

/**
 * @test Test function for space_north getting
 * @pre Pointer to space = NULL
 * @post Output == NO_ID
 */
void test2_space_get_north();

/**
 * @test Test function for space_south getting
 * @pre Valid pointer to space
 * @post Output == Supplied South Link Id
 */
void test1_space_get_south();

/**
 * @test Test function for space_south getting
 * @pre Pointer to space = NULL
 * @post Output == NO_ID
 */
void test2_space_get_south();

/**
 * @test Test function for space_east getting
 * @pre Valid pointer to space
 * @post Output == Supplied East Link Id
 */
void test1_space_get_east();

/**
 * @test Test function for space_east getting
 * @pre Pointer to space = NULL
 * @post Output == NO_ID
 */
void test2_space_get_east();

/**
 * @test Test function for space_west getting
 * @pre Valid pointer to space
 * @post Output == Supplied West Link Id
 */
void test1_space_get_west();

/**
 * @test Test function for space_west getting
 * @pre Pointer to space = NULL
 * @post Output == NO_ID
 */
void test2_space_get_west();

/**
 * @test Test function for object adding
 * @pre Valid pointer to space and valid object id
 * @post Output == OK
 */
void test1_space_add_object();

/**
 * @test Test function for object adding
 * @pre Pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_add_object();

/**
 * @test Test function for object deleting
 * @pre Valid pointer to space and existing object id
 * @post Output == OK
 */
void test1_space_del_object();

/**
 * @test Test function for object deleting
 * @pre Valid pointer to space and non-existing object id
 * @post Output == ERROR
 */
void test2_space_del_object();

/**
 * @test Test function for checking object presence
 * @pre Valid pointer to space and existing object id
 * @post Output == TRUE
 */
void test1_space_has_object();

/**
 * @test Test function for checking object presence
 * @pre Valid pointer to space and non-existing object id
 * @post Output == FALSE
 */
void test2_space_has_object();

/**
 * @test Test function for character setting
 * @pre Valid pointer to space
 * @post Output == OK
 */
void test1_space_set_character();

/**
 * @test Test function for character setting
 * @pre Pointer to space = NULL
 * @post Output == ERROR
 */
void test2_space_set_character();

/**
 * @test Test function for character getting
 * @pre Valid pointer to space with a character
 * @post Output == Supplied Character Id
 */
void test1_space_get_character();

/**
 * @test Test function for character getting
 * @pre Pointer to space = NULL
 * @post Output == NO_ID
 */
void test2_space_get_character();

/**
 * @test Test function for gdesc setting
 * @pre Valid pointer to space and valid line number
 * @post Output == OK
 */
void test1_space_set_gdesc();

/**
 * @test Test function for gdesc setting
 * @pre Valid pointer to space and out-of-range line number
 * @post Output == ERROR
 */
void test2_space_set_gdesc();

#endif