/**
 * @brief It defines the game interface
 *
 * @file set.h
 * @author Samuel Manzorro
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H

typedef struct _Set Set;


#include "types.h"

/**
 * @brief It creates a new object, allocating memory and initializing its members
 * @author Samuel Manzorro
 *
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Set *set_create();

/**
 * @brief It destroys a object, freeing the allocated memory
 * @author Samuel Manzorro
 *
 * @param object a pointer to the object that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_destroy(Set *set);

Status add_element_to_set(Set *set, Id id);

Status set_print(Set* set);


#endif
