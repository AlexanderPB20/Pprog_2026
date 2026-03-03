/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
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

#define MAX_SPACES 100
#define MAX_OBJECTS 100
#define MAX_PLAYERS 100
#define MAX_CHARACTERS 100

typedef struct _Game {
  Object* objects[MAX_OBJECTS]; // array of objects that contains the game
  int n_objects; // number of objects the game has
  Player* players[MAX_PLAYERS]; // array of players that play the game
  int n_players; // number of players the game has
  Space *spaces[MAX_SPACES]; // array of spaces that contains all the spaces of the game
  int n_spaces; // number of valid spaces the game map has
  Character *characters[MAX_SPACES]; // array of characters that contains the game
  int n_characters; // number of characters the game has
  Command *last_cmd; // last command typed by the user
  Bool finished; // true if the game us finished, false if not
} Game;

/**
 * @brief It creates a new game, allocating memory and initializing its members
 * @author Samuel Manzorro
 *
 * @param game the identification number for the new game
 * @return a new game, initialized
 */
Game *game_create();

/**
 * @brief It destroys a game, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param game a pointer to the game that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_destroy(Game *game);

/**
 * @brief It gets the space where the object id space
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param space_id the id of the space
 * @return the space where the space_id coincide
 */
Space *game_get_space(Game *game, Id space_id);

/**
 * @brief it gets the number of spaces in the game
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
 * @brief it gets the number of objects in the game
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @return the number of objects in the game
 *  */
int game_get_n_objects(Game *game);

/**
 * @brief It gets the player where the player id coincides
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param player_id the id of the player
 * @return the player where the player id coincides
 */
Player *game_get_player(Game *game, Id player_id);

/**
 * @brief it gets the number of players in the game
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @return the number of players in the game
 *  */
int game_get_n_players(Game *game);

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
 * @brief it gets the number of characters in the game
 * @author Samuel Manzorro
 * 
 * @param game a pointer to the game
 * @return the number of characters in the game
 *  */
int game_get_n_characters(Game *game);



/**
 * @brief Añade un espacio a la estructura del juego
 * @author Alexander Preciado
 *
 * Comprueba que el espacio no sea nulo y que no se haya superado el límite
 * máximo antes de añadirlo al array de espacios del juego.
 *
 * @param game Puntero a la estructura del juego.
 * @param space Puntero al espacio que se desea añadir.
 * @return OK si se añade con éxito, ERROR si hay fallo o el juego está lleno.
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief Obtiene el ID del espacio en una posición determinada
 * @author Alexander Preciado
 *
 * Permite acceder al identificador de un espacio basándose en su posición
 * dentro del array interno del juego.
 *
 * @param game Puntero a la estructura del juego.
 * @param position Índice del espacio en el array de espacios del juego.
 * @return Id del espacio si la posición es válida, NO_ID en caso contrario.
 */
Id game_get_space_id_at(Game *game, int position);

/**
 * @brief It gets the current location of the player
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param player a pointer to the player
 * @return the ID of the space where the player is located
 */
Id game_get_player_location(Game *game, Player *player);

/**
 * @brief It sets the current location of the player
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param player a pointer to the player
 * @param id the ID of the space for the player's new location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player_location(Game *game, Player *player, Id id);

/**
 * @brief It gets the current location of the object
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param object a pointer to the object
 * @return the ID of the space where the object is located
 */
Id game_get_object_location(Game *game, Object* object);

/**
 * @brief It sets the location of the object
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param object a pointer to the object
 * @param space_id the ID of the space for the object's new location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_object_location(Game *game, Object* object, Id space_id);
/**
 * @brief It adds the object in the game
 * @author Olger ALexander Preciado
 *
 * @param game a pointer to the game
 * @return a pointer to the last command structure
 */

Status game_add_object(Game *game, Object *object);
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
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param command a pointer to the command structure to be set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief It checks if the game is finished
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return TRUE if the game is over, FALSE otherwise
 */
Bool game_get_finished(Game *game);

/**
 * @brief It sets the finished state of the game
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param finished the new state of the finished flag
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief It prints the game information for debugging
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game to be printed
 */
void game_print(Game *game);

#endif



