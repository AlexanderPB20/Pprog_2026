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

#define MAX_SPACES 100

typedef struct _Game {
  Object* object;
  Player* player;
  Space *spaces[MAX_SPACES];
  int n_spaces;
  Command *last_cmd;
  Bool finished;
} Game;

/**
 * @brief It creates a new game, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param game the identification number for the new game
 * @return a new game, initialized
 */
Status game_create(Game *game);

Status game_create_from_file(Game *game, char *filename);

/**
 * @brief It destroys a game, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param game a pointer to the game that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_destroy(Game *game);

/**
 * @brief It gets the space from
 * @author Profesores PPROG
 *
 * @param game a pointer to the game that must be destroyed
 * @param space_id the id of the space
 * @return the space where the space_id coincide
 */
Space *game_get_space(Game *game, Id space_id);
/**
 * @brief It gets the current location of the player
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return the ID of the space where the player is located
 */
Id game_get_player_location(Game *game);

/**
 * @brief It sets the current location of the player
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param id the ID of the space for the player's new location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_player_location(Game *game, Id id);

/**
 * @brief It gets the current location of the object
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @return the ID of the space where the object is located
 */
Id game_get_object_location(Game *game);

/**
 * @brief It sets the location of the object
 * @author Profesores PPROG
 *
 * @param game a pointer to the game
 * @param space_id the ID of the space for the object's new location
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_set_object_location(Game *game, Id space_id);

/**
 * @brief It gets the last command executed in the game
 * @author Profesores PPROG
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
 * @author Profesores PPROG
 *
 * @param game a pointer to the game to be printed
 */
void game_print(Game *game);

#endif

