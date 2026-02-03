/**
 * @brief It implements the game structure
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game.h"
#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
   Game interface implementation
*/

Status game_create(Game *game) {
  int i;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->n_spaces = 0;
  game->player = player_create(1);
  game->object = object_create(1);
  game->last_cmd = command_create();
  game->finished = FALSE;

  return OK;
}

Status game_create_from_file(Game *game, char *filename) {
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_load_spaces(game, filename) == ERROR) {
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

Status game_destroy(Game *game) {
  int i = 0;

  for (i = 0; i < game->n_spaces; i++) {
    space_destroy(game->spaces[i]);
  }

  command_destroy(game->last_cmd);
  player_destroy(game->player);
  object_destroy(game->object);

  return OK;
}

Space *game_get_space(Game *game, Id space_id) {
  int i = 0;

  if (space_id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_spaces; i++) {
    if (space_id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}

Id game_get_player_location(Game *game) {

  return player_get_location(game->player);

}

Status game_set_player_location(Game *game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;
}

Id game_get_object_location(Game *game) {
  
  int i=0;
  
  if (!game)
  {
    return NO_ID;
  }

  for (i=0;i<game->n_spaces;i++)
  {
    if (space_get_object(game->spaces[i]) == object_get_id(game->object))
    {
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

Status game_set_object_location(Game *game, Id space_id) {

  int i = 0;

  if (!game || space_id == NO_ID) {
    return ERROR;
  }

  for (i=0;i<game->n_spaces;i++)
  {
    if (space_get_object(game->spaces[i]) == object_get_id(game->object))
    {
      space_set_object(game->spaces[i], NO_ID);
      break;
    }
  }

  space_set_object(game_get_space(game, space_id), object_get_id(game->object));

  return OK;
}

Command* game_get_last_command(Game *game) { return game->last_cmd; }

Status game_set_last_command(Game *game, Command *command) {
  game->last_cmd = command;

  return OK;
}

Bool game_get_finished(Game *game) { return game->finished; }

Status game_set_finished(Game *game, Bool finished) {
  game->finished = finished;

  return OK;
}

void game_print(Game *game) {
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < game->n_spaces; i++) {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game_get_object_location(game));
  printf("=> Player location: %d\n", (int)player_get_location(game->player));
}
