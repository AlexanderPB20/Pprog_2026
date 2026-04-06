/**
 * @brief It defines the inventory module interface
 *
 * @file inventory.h
 * @author Alexander Preciado
 * @version 2.0
 * @date 23-03-2026
 * @copyright GNU Public License
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_OBJS 5 /*!< The maximum number of objects an inventory can hold */

#include "types.h"  
#include "set.h"    

typedef struct _Inventory Inventory;

/**
 * @brief It creates a new inventory, allocating memory and initializing its members
 * @author Alexander Preciado
 *
 * @return a pointer to the newly allocated Inventory, or NULL if an error occurs
 */
Inventory* inventory_create();

/**
 * @brief It destroys an inventory, freeing the allocated memory
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory that must be destroyed
 * @return OK, if the inventory was successfully destroyed, or ERROR if inv is NULL
 */
Status inventory_destroy(Inventory* inv);

/**
 * @brief It removes an object from an inventory by its Id
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory
 * @param obj the Id of the object to remove
 * @return OK, if the object was successfully removed, or ERROR if inv is NULL or obj is invalid
 */
Status inventory_remove_object(Inventory* inv, Id obj);

/**
 * @brief It gets the id of an object from the inventory given its position
 * @author Alexander Preciado
 *
 * @param inventory a pointer to the inventory
 * @param i the position of the object in the set
 * @return the Id of the object, or NO_ID if there is an error
 */
Id inventory_get_object_id(Inventory *inventory, int i);

/**
 * @brief It gets the maximum number of objects an inventory can hold
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory
 * @return the maximum number of objects, or -1 if an error occurs
 */
int inventory_get_max_objs(Inventory* inv);

/**
 * @brief It gets the internal set of objects in an inventory
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory
 * @return the pointer to the Set of objects, or NULL if an error occurs
 */
Set* inventory_get_set_of_objs(Inventory* inv);

/**
 * @brief It gets the number of objects an inventory currently has
 * @author Samuel Manzorro
 *
 * @param inv a pointer to the inventory
 * @return the number of objects the inventory has, or -1 if an error occurs
 */
int inventory_get_n_objects(Inventory *inv);

/**
 * @brief It sets the maximum number of objects allowed in an inventory
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory
 * @param max_objs the new maximum number of objects
 * @return OK, if everything goes well, or ERROR if inv is NULL or max_objs < 0
 */
Status inventory_set_max_objs(Inventory* inv, int max_objs);

/**
 * @brief It replaces the internal set of objects with the specified one
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory
 * @param objs a pointer to a Set that will be stored inside the inventory
 * @return OK, if the internal set was successfully replaced, or ERROR if inv or objs is NULL
 */
Status inventory_set_setofobjs(Inventory* inv, Set* objs);

/**
 * @brief It checks if an inventory contains an object by its Id
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory
 * @param obj the Id of the object to check
 * @return TRUE, if the object is found, or FALSE otherwise
 */
Bool inventory_has_object(Inventory* inv, Id obj);

/**
 * @brief It adds an object to an inventory by its Id
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory
 * @param obj the Id of the object to add
 * @return OK, if the object was successfully added, or ERROR if inv is NULL or full
 */
Status inventory_add_object(Inventory* inv, Id obj);

/**
 * @brief It prints the inventory information
 * @author Alexander Preciado
 *
 * @param inv a pointer to the inventory
 * @return OK, if the inventory was successfully printed, or ERROR if an error occurs
 */
Status inventory_print(Inventory* inv);

#endif
