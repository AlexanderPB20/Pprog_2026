/**
 * @brief It defines the game interface
 *
 * @file object.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

typedef struct _Object Object;


#include "types.h"

/**
 * @brief It creates a new object, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Object* object_create(Id id);

/**
 * @brief It destroys a object, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param object a pointer to the object that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_destroy(Object* object);

/**
 * @brief It gets the id of a object
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return the id of object
 */
Id object_get_id(Object* object);

/**
 * @brief It gets the name of a object
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return  a string with the name of the object
 */
const char* object_get_name(Object* object);

/**
 * @brief It sets the name of a object
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_name(Object* object, char* name);

/**
 * @brief It prints the object information
 * @author Profesores PPROG
 *
 * This fucntion shows the id and name of the object
 * @param object a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_print(Object* object);

#endif