/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Samuel Manzorro
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "object.h"
#include "player.h"
#include "character.h"
#include "link.h"

#define MAX_SPACES 100 /*!< The maximum number of spaces in the game */
#define MAX_OBJECTS 100 /*!< The maximum number of objects in the game */
#define MAX_PLAYERS 100 /*!< The maximum number of players in the game */
#define MAX_CHARACTERS 100 /*!< The maximum number of characters in the game */

typedef struct _Game Game;

/**
 * @brief It creates a new game, allocating memory and initializing its members
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Game *game_create();

/**
 * @brief It destroys a game, freeing the allocated memory
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_destroy(Game *game);

/**
 * @brief It gets the space with the specified space id
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param space_id the id of the space
 * @return the space where the space id coincide
 */
Space *game_get_space(Game *game, Id space_id);

/**
 * @brief It gets the number of spaces in the game
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @return the number of spaces in the game
 *  */
int game_get_n_spaces(Game *game);

/**
 * @brief It gets the object where the object id coincides
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param object_id the id of the object
 * @return the object where the object id coincides
 */
Object *game_get_object(Game *game, Id object_id);

/**
 * @brief It gets the object id in the position indicated
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param position the position of the id in the set
 * @return the object id in the position indicated
 */
Id game_get_object_id_at(Game *game, int position) ;

/**
 * @brief It gets the number of objects in the game
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @return the number of objects in the game
 *  */
int game_get_n_objects(Game *game);

/**
 * @brief It adds a new objects to the game structure
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @param object a pointer to the object to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_object(Game *game, Object *object);

/**
 * @brief It gets the player of the game
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @return the player of the game
 */
Player *game_get_player(Game *game);

/**
 * @brief It sets the player of the game
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param player the player to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player(Game *game, Player *player);

/**
 * @brief It gets the character where the character id coincides
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param character_id the id of the character
 * @return the character where the character id coincides
 */
Character *game_get_character(Game *game, Id character_id);

/**
 * @brief It gets the number of characters in the game
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @return the number of characters in the game
 *  */
int game_get_n_characters(Game *game);

/**
 * @brief It adds a new character to the game structure
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @param character a pointer to the character to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_character(Game *game, Character *character);

/**
 * @brief It gets the character location
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @param character_id the id of the character
 * @return the space id of the character location
*/
Id game_get_character_location(Game *game, Id character_id);

/**
 * @brief It sets the character location
 * @author Samuel Manzorro
 * 
 * @param space a pointer to the space
 * @param character_id the character id
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_character_location(Space *space, Id character_id);

/**
 * @brief It gets the character id in the position indicated
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param position the position of the id in the set
 * @return the character id in the position indicated
 */
Id game_get_character_id_at(Game *game, int position);

/**
 * @brief It adds a new space to the game structure
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @param space a pointer to the space to be added
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief It gets the space id in the position indicated
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param position the position of the id in the set
 * @return the space id in the position indicated
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief It gets the current location of the player
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @return the ID of the space where the player is located
 */
Id game_get_player_location(Game *game);

/**
 * @brief It sets the current location of the player
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param space_id the ID of the space for the player's new location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player_location(Game *game, Id space_id);

/**
 * @brief It gets the current location of the object
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param object_id the id of the object
 * @return the ID of the space where the object is located
 */
Id game_get_object_location(Game *game, Id object_id);

/**
 * @brief It sets the location of the object
 * @author Samuel Manzorro
 *
 * @param space a pointer to the space
 * @param object_id the ID of the object for the object's new location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_object_location(Space* space, Id object_id);

/**
 * @brief It gets the connection between spaces
 * @author Marta López
 *
 * @param game a pointer to the game
 * @param origin the id of the current space
 * @param direction the direction of the space
 * @return the ID of the connection
 */
Id game_get_connection(Game *game, Id origin, Direction direction);

/**
 * @brief It adds a new link to the game
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @param link a pointer to the link to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 * */
Status game_add_link(Game *game, Link *link);

/**
 * @brief It gets the number of links in the game
 * @author Marta López
 * 
 * @param game a pointer to the game
 * @return the number of links in the game
 *  */
int game_get_n_links(Game *game);

/**
 * @brief It checks if the connection is open
 * @author Marta López
 *
 * @param game a pointer to the game
 * @return TRUE if the connecton is open, FALSE otherwise
 */
Bool game_connection_is_open(Game *game, Id origin, Direction direction);

/**
 * @brief It gets the last command executed in the game
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @return a pointer to the last command structure
 */
Command* game_get_last_command(Game *game);

/**
 * @brief It sets the last command executed in the game
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param command a pointer to the command structure to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief It checks if the game is finished
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @return TRUE if the game is over, FALSE otherwise
 */
Bool game_get_finished(Game *game);

/**
 * @brief It sets the finished state of the game
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param finished the new state of the finished flag
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief It gets the game message
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @return the game message
 */
char *game_get_message(Game *game);

/**
 * @brief It sets the fgaem message
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param msg the new message to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_message(Game *game, const char *msg);

/**
 * @brief It prints the game information for debugging
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game to be printed
 */
void game_print(Game *game);

#endif

