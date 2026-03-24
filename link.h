/**
 * @brief It manages the links between spaces.
 *
 * @file link.h
 * @author Marta Lopez
 * @version 0
 * @date 19-03-2026
 * @copyright GNU Public License
 */

#ifndef LINK_H
#define LINK_H


#include "types.h"

typedef struct _Link Link;


/**
 * @brief It creates a link, allocating memory and initializing its members
 * @author Marta Lopez
 * 
 * @param id the new id of the link created
 * @return a new link, initialized
 */
Link *link_create(Id id);

/**
 * @brief It destroys a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_destroy(Link* link);

/**
 * @brief It sets the id of a link
 * @author Marta Lopez
 * ´
 * @param link a pointer to the link
 * @param id the new id to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_id(Link *link, Id id);

/**
 * @brief It gets the id of a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @return the id of the link
 */
Id link_get_id(Link* link);

/**
 * @brief It sets the name of a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @param name the name to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_name(Link* link, const char* name);

/**
 * @brief It gets the name of a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @return the name of the link
 */
const char* link_get_name(Link* link);

/**
 * @brief It sets the origin of the link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @param id the id to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_origin(Link* link, Id id);

/**
 * @brief It gets the origin of a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @return the id of the origin of the link
 */
Id link_get_origin(Link* link);

/**
 * @brief It sets the destination of the link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @param id the id to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_destination(Link* link, Id id);

/**
 * @brief It gets the destination of a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @return the id of the destination of the link
 */
Id link_get_destination(Link* link);

/**
 * @brief It sets the direction of the link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @param direction the direction to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_direction(Link *link, Direction direction);

/**
 * @brief It gets the direction of a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @return the id of the direction of the link
 */
Id link_get_direction(Link* link);

/**
 * @brief It sets the open of a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @param open the value of open to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_set_open(Link *link, Bool open);

/**
 * @brief It gets the open of a link
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @return the open of the link
 */
Bool link_get_open(Link* link);

/**
 * @brief It prints a link information
 * @author Marta Lopez
 * 
 * @param link a pointer to the link
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status link_print(Link *link);

#endif