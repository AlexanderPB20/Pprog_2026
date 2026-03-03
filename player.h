/**
 * @brief It defines the game interface
 *
 * @file object.h
 * @author Alexander Preciado
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

typedef struct _Player Player;


#include "types.h"

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
 * @param location a string with the name to store
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
 * @brief It sets the id of the object the player has
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @param object_id an Id with the id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_object(Player* player, Id object_id);

/**
 * @brief It gets the id of the object the player has
 * @author Alexander Preciado
 *
 * @param player a pointer to the player
 * @return the id of the object the player has
 */
Id player_get_object(Player* player);


/**
 * @brief It prints the player information
 * @author Alexander Preciado
 *
 * This function shows the id, the name, the localization and the id of the object of the player
 * @param player a pointer to the player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(Player* player);


#endif
