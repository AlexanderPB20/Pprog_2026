/**
 * @brief It defines the player module interface
 *
 * @file player.h
 * @author Alexander Preciado
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

typedef struct _Player Player;

#include "types.h"
#include "inventory.h"

/**
 * @brief It creates a new player, allocating memory and initializing its members
 * @author Alexander Preciado
 *
 * @param id the identification number for the new player
 * @return a new player, initialized
 */
Player* player_create(Id id);

/**
 * @brief It destroys a player, freeing the allocated memory
 * @author Alexander Preciado
 *
 * @param player a pointer to the player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_destroy(Player* player);

/**
 * @brief It gets the id of a player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @return the id of player
 */
Id player_get_id(Player* player);

/**
 * @brief It gets the name of a player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @return  a string with the name of the player
 */
const char* player_get_name(Player* player);

/**
 * @brief It sets the name of a player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name(Player* player, char* name);

/**
 * @brief It sets the location of a player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @param location the ID of the new location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_location(Player* player, Id location);

/**
 * @brief It gets the location of a player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @return the location of player
 */
Id player_get_location(Player* player);

/**
 * @brief It gets the player backpack
 * @author Samuel Manzorro
 * 
 * @param player a pointer to the player
 * @return the player backpack
 */
Inventory *player_get_backpack(Player *player);

/**
 * @brief It sets the player backpack
 * @author Samuel Manzorro
 * 
 * @param player a pointer to the player
 * @param inv a pointer to the inventory to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_backpack(Player *player, Inventory *inv);

/**
 * @brief It gets an object from the backpack and its position
 * @author Samuel Manzorro
 * 
 * @param player a pointer to the player
 * @param position the position to be searched
 * @return the id of the object searched
 */
Id player_get_object_from_backpack(Player *player, int position);

/**
 * @brief It adds an object to the player backpack
 * @author Samuel Manzorro
 * 
 * @param player a pointer to the player
 * @param obj the id of the object to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_add_object_to_backpack(Player *player, Id obj);

/**
 * @brief It removes an object of the player backpack
 * @author Samuel Manzorro
 * 
 * @param player a pointer to the player
 * @param obj the id of the object to be removed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_remove_object_of_backpack(Player *player, Id obj);

/**
 * @brief It checks if the player has an object or not
 * @author Samuel Manzorro
 * 
 * @param player a pointer to the player
 * @param obj the id of the object to be checked
 * @return TRUE, if everything goes well or FALSE if there was some mistake
 */
Bool player_has_object(Player *player, Id obj);

/**
 * @brief It checks if the backpack is full or not
 * @author Samuel Manzorro
 * 
 * @param player a pointer to the player
 * @return TRUE, if the backpack is full or FALSE if it is not
 */
Bool player_backpack_is_full(Player *player);

/**
 * @brief It sets the id of the object the player has
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @param object_id the id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_object_id(Player* player, Id object_id);

/**
 * @brief It gets the id of the object the player has
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @return the id of the object the player has
 */
Id player_get_object_id(Player* player);

/**
 * @brief It sets the health of the player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @param health the health to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_health(Player* player, int health);

/**
 * @brief It gets the health of the player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @return the health of the player
 */
int player_get_health(Player* player);

/**
 * @brief It sets the gdesc of the player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @param gdesc a pointer to the graphic description
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_gdesc(Player* player, char *gdesc);

/**
 * @brief It gets the gdesc of the player
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @return the graphic description of the player
 */
char *player_get_gdesc(Player* player);

/**
 * @brief It sets the maximum number of objects the player backpack can contain
 * @author Samuel Manzorro
 * 
 * @param player a pointer to the player
 * @param max_objs the maximum number of objects to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_max_objs(Player *player, int max_objs);

/**
 * @brief It prints the player information
 * @author Alexander Preciado
 *
 * This function shows the id, the name, the location and the id of the object of the player
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(Player* player);

#endif