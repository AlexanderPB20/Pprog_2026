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
 * @brief It creates a new set, allocating memory and initializing its members
 * @author Samuel Manzorro
 *
 * @return a new set, initialized
 */
Set *set_create();

/**
 * @brief It destroys a set, freeing the allocated memory
 * @author Samuel Manzorro
 *
 * @param set a pointer to the set that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_destroy(Set *set);

/**
* @brief It adds the id parameter to the set
* @author Samuel Manzorro
*
* @param set a pointer to the set
* @param id the id of the element to be added to the set
* @return OK, if everything goes well or ERROR if there was some mistake
*/
Status add_element_to_set(Set *set, Id id);

/**
* @brief It deletes the id parameter to the set
* @author Samuel Manzorro
*
* @param set a pointer to the set
* @param id the id of the element to be deleted from the set
* @return OK, if everything goes well or ERROR if there was some mistake
*/
Status del_element_to_set(Set *set, Id id);

/**
 * @brief It gets the id from the position asked
 * @author Profesores PPROG
 *
 * @param set a pointer to the set
 * @param i the position of the id searched
 * @return the id asked
 */
Id set_get_element(Set *set, int i);

/**
 * @brief It gets the number of ids of the set
 * @author Profesores PPROG
 *
 * @param set a pointer to the set
 * @return the number of ids
 */
int set_get_n_elements(Set *set);

/**
 * @brief It prints the set information
 * @author Profesores PPROG
 *
 * This function shows the number of ids there is and the list of ids
 * @param set a pointer to the set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_print(Set* set);


#endif

