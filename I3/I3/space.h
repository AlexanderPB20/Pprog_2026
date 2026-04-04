/**
 * @brief It defines the space module interface
 *
 * @file space.h
 * @author Samuel Manzorro, Paula de la Fuente
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#define GDESC_SIZE1 5
#define GDESC_SIZE2 10

#include "types.h"
#include "object.h"
#include "set.h"
#include "character.h"

typedef struct _Space Space;

/**
 * @brief It creates a new space, allocating memory and initializing its members
 * @author Samuel Manzorro
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space* space_create(Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_destroy(Space* space);

/**
 * @brief It gets the id of a space
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(Space* space);

/**
 * @brief It sets the name of a space
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_name(Space* space, char* name);

/**
 * @brief It gets the name of a space
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char* space_get_name(Space* space);

/**
 * @brief It sets the graphic description of the space
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @param line the line where the description will be set
 * @param desc the graphic description to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_gdesc(Space *space, int line, char *desc);

/**
 * @brief It gets the graphic description of the space depending on its line 
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @param line the line of the graphic description wanted
 * @return the graphic description of the space depending on its line
 */
char *space_get_gdesc(Space *space, int line);

/**
 * @brief It sets the id of the space located at the north
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the north
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_north(Space* space, Id id);

/**
 * @brief It gets the id of the space located at the north
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the north
 */
Id space_get_north(Space* space);

/**
 * @brief It sets the id of the space located at the south
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the south
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_south(Space* space, Id id);

/**
 * @brief It gets the id of the space located at the south
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the south
 */
Id space_get_south(Space* space);

/**
 * @brief It sets the id of the space located at the east
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the east
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_east(Space* space, Id id);

/**
 * @brief It gets the id of the space located at the east
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the east
 */
Id space_get_east(Space* space);

/**
 * @brief It sets the id of the space located at the west
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the west
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_west(Space* space, Id id);

/**
 * @brief It gets the id of the space located at the west
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the west
 */
Id space_get_west(Space* space);

/**
 * @brief It tells if the space has an object or not
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @param object_id the id of the object to be found
 * @return TRUE, if the object is in the space, FALSE in other cases
 */
Bool space_has_object(Space* space, Id object_id);

/**
 * @brief It adds an object to the space
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @param object_id the id of the object to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_add_object(Space* space, Id object_id);

/**
 * @brief It deletes an object from the space
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @param object_id the id of the object to be deleted
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_del_object(Space* space, Id object_id);

/**
 * @brief It gets the character in the space
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @return the character in the space
 */
Id space_get_character(Space *space);

/**
 * @brief It sets the character in the space
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @param character_id the id of the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_character(Space *space, Id character_id);

/**
 * @brief It tells if the space has a character or not
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @param character_id the id of the character to be found
 * @return TRUE, if the character is in the space, FALSE in other cases
 */
Bool space_has_character(Space *space, Id character_id);

/**
 * @brief It gets the set of objects in the space
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @return the set of objects in the space
 */
Set *space_get_objects(Space *space);

/**
 * @brief It sets a space to be discovered or not
 * @author Paula de la Fuente
 *
 * @param space a pointer to the space
 * @param discovered whether the space is discovered or not
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_discovered(Space* space, Bool discovered);

/**
 * @brief It gets whether a space is discovered or not
 * @author Paula de la Fuente
 *
 * @param space a pointer to the space
 * @return TRUE if the space is discovered, FALSE if not
 */
Bool space_is_discovered(Space* space);

/**
 * @brief It prints the space information
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_print(Space* space);

#endif
