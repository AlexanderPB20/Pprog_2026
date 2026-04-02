/**
 * @brief It defines the player module interface
 *
 * @file player.h
 * @author Alexander Preciado, Paula de la Fuente
 * @version 1
 * @date 23-03-2025
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
 * @brief It gets the inventory(backpack) of a player
 * @author Paula de la Fuente
 *
 * @param player a pointer to the player
 * @return  a pointer to the inventory of the player
 */
Inventory* player_get_inventory(Player* player);


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
 * @brief It adds an object to a player (in the backpack)
 * @author Paula de la Fuente
 * 
 * @param player a pointer to the player
 * @param obj_id the id of the object to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_add_object(Player* player, Id obj_id);

/**
 * @brief It deletes an object from a player (from the backpack)
 * @author Paula de la Fuente
 * 
 * @param player a pointer to the player
 * @param obj_id the id of the object to be deleted
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_del_object(Player* player, Id obj_id);

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
 * @brief It prints the player information
 * @author Alexander Preciado
 *
 * This function shows the id, the name, the location and the id of the object of the player
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(Player* player);

#endif
