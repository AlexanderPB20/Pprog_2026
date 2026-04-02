/**
 * @brief It defines the backpack module interface
 *
 * @file inventory.h
 * @author Alexander Preciado
 * @version 0
 * @date 23-03-2026
 * 
 * This file declares the functions and data structures needed to manage
 * a Backpack. A Backpack contains a set of objects (`Set`) and
 * a maximum capacity for the number of objects.
 */

 #ifndef INVENTORY_H
 #define INVENTORY_H
 
 #include "types.h"  /**< For Status, Bool, Id, etc. */
 #include "set.h"    /**< For Set type */
 
 #define MAX_OBJS 5 /*!< The maximum number of objects a backpack can hold */
 /**
  * @brief Backpack opaque data structure
  *
  * The internal definition (struct _Backpack) resides in inventory.c,
  * making this an opaque type for external modules.
  */
 typedef struct _Inventory Inventory;
 
 /**
  * @brief It creates a new backpack, allocating memory and initializing its members
  *
  * @return a pointer to the newly allocated Backpack, or NULL if an error occurs
  */
 Inventory* inventory_create();
 
 /**
  * @brief It destroys a backpack, freeing the allocated memory
  *
  * @param[in] bp a pointer to the backpack that must be destroyed
  * @return 
  *    - OK, if the backpack was successfully destroyed
  *    - ERROR, if bp is NULL or if an internal error occurred
  */
 Status inventory_destroy(Inventory* inv);
  /**
  * @brief It removes an object from a backpack by its Id
  *
  * @param[in] bp   a pointer to the backpack
  * @param[in] obj  the Id of the object to remove
  * @return 
  *    - OK, if the object was successfully removed
  *    - ERROR, if bp is NULL, obj is invalid, or the object was not present
  */
 Status inventory_remove_object(Inventory* inv, Id obj);
 
/*******************************************************************************
 *                               GETTERS
 ******************************************************************************/

 
 Id inventory_get_object_id(Inventory *inventory, int i);
 
 /**
  * @brief It gets the maximum number of objects a backpack can hold
  *
  * @param[in] bp a pointer to the backpack
  * @return the maximum number of objects, or -1 if an error occurs
  */
 int inventory_get_max_objs(Inventory* inv);
 
 /**
  * @brief It gets the internal set of objects in a backpack
  *
  * @param[in] bp a pointer to the backpack
  * @return the pointer to the Set of objects, or NULL if an error occurs
  */
 Set* inventory_get_set_of_objs(Inventory* inv);
 
 
/*******************************************************************************
 *                               SETTERS
 ******************************************************************************/

 /**
  * @brief It sets the maximum number of objects allowed in a backpack
  *
  * @param[in] bp        a pointer to the backpack
  * @param[in] max_objs  the new maximum number of objects
  * @return 
  *    - OK, if everything goes well
  *    - ERROR, if bp is NULL or max_objs < 0
  */
 Status inventory_set_max_objs(Inventory* inv, int max_objs);
 
 /**
  * @brief It replaces the internal set of objects with the specified one
  *
  * @param[in] bp   a pointer to the backpack
  * @param[in] objs a pointer to a Set that will be stored inside the backpack
  * @return 
  *    - OK, if the internal set was successfully replaced
  *    - ERROR, if bp or objs is NULL
  */
 Status inventory_set_setofobjs(Inventory* inv, Set* objs);
 


 
 /**
  * @brief It checks if a backpack contains an object by its Id
  *
  * @param[in] bp   a pointer to the backpack
  * @param[in] obj  the Id of the object to check
  * @return 
  *    - TRUE, if the object is found
  *    - FALSE, otherwise (or if bp is NULL/obj is invalid)
  */
 Bool inventory_has_object(Inventory* inv, Id obj);
 
 /**
  * @brief It adds an object to a backpack by its Id
  *
  * @param[in] bp   a pointer to the backpack
  * @param[in] obj  the Id of the object to add
  * @return 
  *    - OK, if the object was successfully added
  *    - ERROR, if bp is NULL or if an internal error occurs
  */
 Status inventory_add_object(Inventory* inv, Id obj);
 
 /**
  * @brief It prints the backpack information
  *
  * This function shows the objects contained in the backpack and the maximum
  * number of objects allowed.
  *
  * @param[in] bp a pointer to the backpack
  * @return 
  *    - OK, if the backpack was successfully printed
  *    - ERROR, if bp is NULL or if an internal error occurs
  */
 Status inventory_print(Inventory* inv);
 
 #endif /* INVENTORY_H */
 