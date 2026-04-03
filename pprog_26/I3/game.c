/**
 * @brief It implements the game structure
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 0
 * @date 23-03-2026
 * @copyright GNU Public License
 */

#include "game.h"
#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct _Game {
  Object* objects[MAX_OBJECTS]; /*!< The array of objects that contains the game */
  int n_objects; /*!< The number of objects the game has */
  Player *player; /*!< The player playing the game */
  Space *spaces[MAX_SPACES]; /*!< The array of spaces that contains all the spaces of the game */
  int n_spaces; /*!< The number of valid spaces the game map has */
  Character *characters[MAX_SPACES]; /*!< An array of characters that contains the game */
  int n_characters; /*!< The number of characters the game has */
  Command *last_cmd; /*!< The last command typed by the user */
  Bool finished; /*!< True if the game is finished, false if not */
  char msg[WORD_SIZE]; /*!< Message printed by the game*/
  Link* link[4*(MAX_OBJECTS)]; /*!< The array of links that contains all the link of the game */
  int n_links; /*!< The number of links the game has */
};

/**
   Game interface implementation
*/

Game* game_create() {
  Game *game = NULL;
  int i;

  /* Pedimos memoria dinámica para el juego opaco */
  game = (Game*)calloc(1, sizeof(Game));
  if (game == NULL) {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }

  game->n_objects = 0;

  game->player = player_create(1);
  if (!game->player)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->n_spaces = 0;

  for (i = 0; i < MAX_CHARACTERS; i++) {
    game->characters[i] = NULL;
  }

  game->n_characters = 0;

  for (i = 0; i < (4*MAX_SPACES); i++) {
    game->link[i] = NULL;
  }

  game->n_links = 0;
  
  game->last_cmd = command_create();
  game->finished = FALSE;
  game->msg[0] = '\0';

  return game;
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
  free(game);
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
  if (space_id == NO_ID) {
    return ERROR;
  }

  return player_set_location(game->player, space_id);
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

Id game_get_connection(Game *game, Id current_space, Direction direction){
  int i = 0;

  /* CORRECCIÓN: Usamos NO_DIRECTION en lugar de !direction */
  if (!game || current_space == NO_ID || direction == NO_DIRECTION) {
    return NO_ID; 
  }

  /* CORRECCIÓN: Buscamos solo hasta game->n_links para que no crashee */
  for (i = 0; i < game->n_links; i++) { 
    if (current_space == link_get_origin(game->link[i]) && direction == link_get_direction(game->link[i])) {
      return link_get_destination(game->link[i]);
    }
  }

  return NO_ID;
}

int game_get_n_links(Game *game) {
  if (game == NULL)
  {
    return 0;
  }

  return game->n_links;
}

Bool game_connection_is_open(Game *game, Id origin, Direction direction){
  int i = 0;

  if(!game || origin == NO_ID || direction == NO_DIRECTION){
    return FALSE;
  }

  for(i = 0; i < game->n_links; i++){
    if(link_get_origin(game->link[i]) == origin && link_get_direction(game->link[i]) == direction){
      return link_get_open(game->link[i]);
    }
  }

  return FALSE;
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

Status game_add_link(Game *game, Link *link) {
  if (game == NULL || link == NULL || game->n_links >= (4*MAX_SPACES)) {
    return ERROR;
  }
  game->link[game->n_links] = link;
  game->n_links++;
  return OK;
}