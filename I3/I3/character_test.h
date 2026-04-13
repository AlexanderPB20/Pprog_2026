/**
 * @brief It declares the tests for the character module
 * @file character_test.h
 * @author Olger Alexander Preciado Bolaños
 * @version 0.0 
 * @date 10-03-2025
 * @copyright GNU Public License
 */

#ifndef CHARACTER_TEST_H
#define CHARACTER_TEST_H

/**
 * @test Test character creation
 * @pre Valid character ID 
 * @post Non NULL pointer to character 
 */
void test1_character_create();

/**
 * @test Test character creation
 * @pre Character ID = NO_ID
 * @post NULL pointer to character
 */
void test2_character_create();

/**
 * @test Test function for character_name setting
 * @pre Valid pointer to character and valid string
 * @post Output == OK 
 */
void test1_character_set_name();

/**
 * @test Test function for character_name setting
 * @pre Pointer to character = NULL 
 * @post Output == ERROR
 */
void test2_character_set_name();

/**
 * @test Test function for character_name getting
 * @pre Valid pointer to character with a name set
 * @post Output == 0 (strcmp matches the string)
 */
void test1_character_get_name();

/**
 * @test Test function for character_name getting
 * @pre Pointer to character = NULL
 * @post Output == NULL
 */
void test2_character_get_name();

/**
 * @test Test function for character_gdesc setting
 * @pre Valid pointer to character and valid string
 * @post Output == OK
 */
void test1_character_set_gdesc();

/**
 * @test Test function for character_gdesc setting
 * @pre Pointer to character = NULL
 * @post Output == ERROR
 */
void test2_character_set_gdesc();

/**
 * @test Test function for character_gdesc getting
 * @pre Valid pointer to character with a gdesc set
 * @post Output == 0 (strcmp matches the string)
 */
void test1_character_get_gdesc();

/**
 * @test Test function for character_gdesc getting
 * @pre Pointer to character = NULL
 * @post Output == NULL
 */
void test2_character_get_gdesc();

/**
 * @test Test function for character_health setting
 * @pre Valid pointer to character and positive health value
 * @post Output == OK
 */
void test1_character_set_health();

/**
 * @test Test function for character_health setting
 * @pre Valid pointer to character and negative health value
 * @post Output == ERROR
 */
void test2_character_set_health();

/**
 * @test Test function for character_health getting
 * @pre Valid pointer to character with health = 10
 * @post Output == 10
 */
void test1_character_get_health();

/**
 * @test Test function for character_health getting
 * @pre Pointer to character = NULL
 * @post Output == -1
 */
void test2_character_get_health();

/**
 * @test Test function for character_friendly setting
 * @pre Valid pointer to character
 * @post Output == OK
 */
void test1_character_set_friendly();

/**
 * @test Test function for character_friendly setting
 * @pre Pointer to character = NULL
 * @post Output == ERROR
 */
void test2_character_set_friendly();

/**
 * @test Test function for checking if character is friendly
 * @pre Valid pointer to character set as friendly
 * @post Output == TRUE
 */
void test1_character_is_friendly();

/**
 * @test Test function for checking if character is friendly
 * @pre Pointer to character = NULL
 * @post Output == FALSE
 */
void test2_character_is_friendly();

/**
 * @test Test function for character_message setting
 * @pre Valid pointer to character and valid string
 * @post Output == OK
 */
void test1_character_set_message();

/**
 * @test Test function for character_message setting
 * @pre Pointer to character = NULL
 * @post Output == ERROR
 */
void test2_character_set_message();

/**
 * @test Test function for character_message getting
 * @pre Valid pointer to character with a message set
 * @post Output == 0 (strcmp matches the string)
 */
void test1_character_get_message();

/**
 * @test Test function for character_message getting
 * @pre Pointer to character = NULL
 * @post Output == NULL
 */
void test2_character_get_message();

#endif
