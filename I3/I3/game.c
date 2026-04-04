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

  if (game == NULL)
  {
    return ERROR;
  }


  for (i = 0; i < MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }

  game->n_objects = 0;

  game->player = player_create(1);
  if (!game->player)
  {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->n_spaces = 0;

  for (i = 0; i < MAX_CHARACTERS; i++) {
    game->characters[i] = NULL;
  }

  game->n_characters = 0;
  
  game->last_cmd = command_create();
  game->finished = FALSE;
  game->msg[0] = '\0';

  return OK;
}

Status game_destroy(Game *game) {
  int i;

  for (i = 0; i < game->n_objects; i++) {
    if (game->objects[i] != NULL)
    {
      object_destroy(game->objects[i]);
      game->objects[i] = NULL;
    }
  }

  player_destroy(game->player);

  for (i = 0; i < game->n_spaces; i++) {
    if (game->spaces[i] != NULL)
    {
      space_destroy(game->spaces[i]);
      game->spaces[i] = NULL;
    }
  }

  for (i = 0; i < game->n_characters; i++) {
    if (game->characters[i] != NULL)
    {
      character_destroy(game->characters[i]);
      game->characters[i] = NULL;
    }
  }

  command_destroy(game->last_cmd);

  return OK;
}

Space *game_get_space(Game *game, Id space_id) {
  int i = 0;

  if (game == NULL || space_id == NO_ID) {
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

int game_get_n_spaces(Game *game) {
  if (game == NULL)
  {
    return 0;
  }

  return game->n_spaces;
}

Object *game_get_object(Game *game, Id object_id) {
  int i = 0;

  if (game == NULL || object_id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_objects; i++) {
    if (object_id == object_get_id(game->objects[i]))
    {
      return game->objects[i];
    }
  }

  return NULL;
}

Id game_get_object_id_at(Game *game, int position) {
  if (position < 0 || position >= game->n_objects) {
    return NO_ID;
  }

  return object_get_id(game->objects[position]);
}

int game_get_n_objects(Game *game) {
  if (game == NULL)
  {
    return 0;
  }

  return game->n_objects;
}

Status game_add_object(Game *game, Object *object) {
  if ((object == NULL) || (game->n_objects >= MAX_OBJECTS)) {
    return ERROR;
  }

  game->objects[game->n_objects] = object;
  game->n_objects++;
  
  return OK;
}

Player *game_get_player(Game *game) {
  if (!game)
  {
    return NULL;
  }

  return game->player;
}

Status game_set_player(Game *game, Player *player) {
  if (!game || !player)
  {
    return ERROR;
  }

  game->player = player;
  return OK;
}

Character *game_get_character(Game *game, Id character_id) {
  int i = 0;

  if (game == NULL || character_id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_characters; i++) {
    if (character_id == character_get_id(game->characters[i]))
    {
      return game->characters[i];
    }
  }

  return NULL;
}

int game_get_n_characters(Game *game) {
  if (game == NULL)
  {
    return 0;
  }
  return game->n_characters;
}

Status game_add_character(Game *game, Character *character) {
  if ((!character) || (game->n_characters >= MAX_CHARACTERS)) {
    return ERROR;
  }

  game->characters[game->n_characters] = character;
  game->n_characters++;
  
  return OK;
}

Id game_get_character_location(Game *game, Id character_id) {
  int i;

  if (game == NULL || character_id == NO_ID) {
    return NO_ID;
  }

  for (i = 0; i < game->n_spaces; i++) {
    if (space_has_character(game->spaces[i], character_id) == TRUE) {
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

Status game_set_character_location(Space *space, Id character_id) {
  
  if (!space || character_id == NO_ID)
  {
    return ERROR;
  }

  return space_set_character(space, character_id);
}

Id game_get_character_id_at(Game *game, int position) {

  if (!game || position < 0)
  {
    return NO_ID;
  }

  return character_get_id(game->characters[position]);
}

Status game_add_space(Game *game, Space *space) {
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES)) {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}

Id game_get_space_id_at(Game *game, int position) {
  if (position < 0 || position >= game->n_spaces) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Id game_get_player_location(Game *game) {

  if (!game)
  {
    return NO_ID;
  }

  return player_get_location(game->player);

}

Status game_set_player_location(Game *game, Id space_id) {
  Space* space;
  if (space_id == NO_ID) {
    return ERROR;
  }

  if(player_set_location(game->player, space_id)==ERROR) {
    return ERROR;
  }

  /*Set the space where the player is as discovered */
  space = game_get_space(game, space_id);
  if(!space){
    return ERROR;
  }

  if(space_is_discovered(space)==FALSE) {
    space_set_discovered(space, TRUE);
  }

  return OK;
}

Id game_get_object_location(Game *game, Id object_id) {
  
  int i=0;
  
  if (!game || !object_id)
  {
    return NO_ID;
  }

  for (i=0;i<game->n_spaces;i++)
  {
    if (space_has_object(game->spaces[i], object_id))
    {
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

Status game_set_object_location(Space* space, Id object_id) {
  if (!space || object_id == NO_ID) {
    return ERROR;
  }

  return space_add_object(space, object_id);
}

Command* game_get_last_command(Game *game) {
  return game->last_cmd;
}

Status game_set_last_command(Game *game, Command *command) {
  game->last_cmd = command;

  return OK;
}

Bool game_get_finished(Game *game) {
  return game->finished;
}

Status game_set_finished(Game *game, Bool finished) {
  game->finished = finished;

  return OK;
}

char *game_get_message(Game *game) {
  if (!game)
  {
    return NULL;
  }

  return game->msg;
}

Status game_set_message(Game *game, const char *msg) {

  if (!game || msg == NULL)
  {
    return ERROR;
  }

  strcpy(game->msg, msg);
  return OK;
}

void game_print(Game *game) {
  int i;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < game->n_spaces; i++) {
    space_print(game->spaces[i]);
  }

  player_print(game->player);

  for (i = 0; i < game->n_objects; i++) {
    object_print(game->objects[i]);
  }

  for (i = 0; i < game->n_characters; i++) {
    character_print(game->characters[i]);
  }
}
