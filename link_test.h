/**
 * @brief It declares the tests for the link module
 * @file link_test.h
 * @author Marta López
 * @version 0.0 
 * @date 31-03-2026
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Test link creation
 * @pre Link ID 
 * @post Non NULL pointer to link 
 */
void test1_link_create();

/**
 * @test Test link creation with NO_ID
 * @pre NO_ID
 * @post NULL pointer to link 
 */
void test2_link_create_no_id();

/**
 * @test Test link set id
 * @pre Link and ID 
 * @post Output == OK
 */
void test3_link_set_id();

/**
 * @test Test link get id
 * @pre Link ID 
 * @post Output == ID
 */
void test4_link_get_id();

/**
 * @test Test link set name
 * @pre Link and name
 * @post Output == OK 
 */
void test5_set_name();

/**
 * @test Test link get name
 * @pre Link name 
 * @post Output == name
 */
void test6_link_get_name();

/**
 * @test Test link set origin
 * @pre Link and origin 
 * @post Output == OK
 */
void test7_link_set_origin();

/**
 * @test Test link get origin
 * @pre Link and origin
 * @post Output == ID
 */
void test8_link_get_origin();

/**
 * @test Test link set direction
 * @pre Link and direction
 * @post Output == OK
 */
void test9_link_set_direction();

/**
 * @test Test link get direction
 * @pre Link direction
 * @post Output == direction
 */
void test10_link_get_direction();

#endif