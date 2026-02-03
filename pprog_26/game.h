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

Id game_get_player_location(Game *game);

Status game_set_player_location(Game *game, Id id);

Id game_get_object_location(Game *game);

Status game_set_object_location(Game *game, Id space_id);

Command* game_get_last_command(Game *game);

Status game_set_last_command(Game *game, Command *command);

Bool game_get_finished(Game *game);

Status game_set_finished(Game *game, Bool finished);

void game_print(Game *game);

#endif
