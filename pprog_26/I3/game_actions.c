/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

void game_actions_unknown(Game *game);

void game_actions_exit(Game *game);

void game_actions_take(Game *game);

void game_actions_drop(Game* game);

void game_actions_attack(Game *game);

void game_actions_chat(Game *game);

void game_actions_move(Game *game);

void game_actions_inspect(Game *game);
/**
   Game actions implementation
*/

Status game_actions_update(Game *game, Command *command) {
  CommandCode cmd;

  game_set_last_command(game, command);

  cmd = command_get_code(command);

  switch (cmd) {
    case UNKNOWN:
      game_actions_unknown(game);
      break;

    case EXIT:
      game_actions_exit(game);
      break;

    case TAKE:
      game_actions_take(game);
      break;

    case DROP:
      game_actions_drop(game);
      break;

    case ATTACK:
      game_actions_attack(game);
      break;

    case CHAT:
      game_actions_chat(game);
      break;

    case MOVE:
      game_actions_move(game);
      break;

    case INSPECT:
      game_actions_inspect(game);
      break;

    default:
      break;
  }

  return OK;
}

/**
   Calls implementation for each action
*/

void game_actions_unknown(Game *game) {}

void game_actions_exit(Game *game) {}


void game_actions_take(Game *game) {

  Id space_id = NO_ID;
  Id object_id = NO_ID;
  Player *player = NULL;
  Object *obj=NULL;
  char *object_input = NULL;
  int i;

  if (!game)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  player = game_get_player(game);
  if (!player)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  
  object_input = command_get_arg(game_get_last_command(game), 0);
  if (!object_input)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  for (i = 0; i < game_get_n_objects(game); i++)
  {
    object_id = game_get_object_id_at(game, i);
    if (object_id == NO_ID)
    {
      continue;
    }

    obj = game_get_object(game, object_id);
    if (!obj)
    {
      continue;
    }
    
    if ((game_get_object_location(game, object_id) == space_id) && !player_has_object(player, object_id) && !player_backpack_is_full(player)) // si el objeto esta en el espacio y el jugador no tiene objeto
    {
      if (strcasecmp(object_input, object_get_name(obj)) == 0) // compara si el argumento y el nombre del objeto son iguales
      {
        player_add_object_to_backpack(player, object_get_id(obj)); // jugador toma objeto
        space_del_object(game_get_space(game, space_id), object_get_id(obj)); // quita objeto del espacio
        game_set_object_location(game_get_space(game, space_id), NO_ID); // actualiza la localizacion del objeto a NO_ID
        command_set_status(game_get_last_command(game), OK);
        return;        
      }
    }
  }
  command_set_status(game_get_last_command(game), ERROR);
  return;
}

void game_actions_drop(Game* game) {

  Id space_id = NO_ID;
  Id object_id = NO_ID;
  Player *player = NULL;

  if (!game)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  player = game_get_player(game);
  if (!player)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }
  
  for (int i = 0; i < inventory_get_max_objs(player_get_backpack(player)); i++)
  {
    object_id = player_get_object_from_backpack(player, i);
    if (object_id == NO_ID)
    {
      command_set_status(game_get_last_command(game), ERROR);
      return;
    }

    if (!space_has_object(game_get_space(game, space_id), object_id)) // player tiene objeto
    {
      space_add_object(game_get_space(game, space_id), object_id); // añade el objeto a la sala
      player_remove_object_of_backpack(player, object_id); // jugador deja el objeto
      game_set_object_location(game_get_space(game, space_id), object_id); // actualiza  localizacion del objeto en el juego
      command_set_status(game_get_last_command(game), OK);
      return;
    }
  }

  command_set_status(game_get_last_command(game), ERROR);
  return;
}

void game_actions_attack(Game *game) {

  Id player_location = NO_ID, character_id = NO_ID;
  Character *character = NULL;
  int damage;
  char *object_input = NULL;

  if (!game)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  player_location = game_get_player_location(game);
  if (player_location == NO_ID)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  character_id = space_get_character(game_get_space(game, player_location));
  if (character_id == NO_ID)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  character = game_get_character(game, character_id);
  if (character == NULL)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  object_input = command_get_arg(game_get_last_command(game), 0);
  if (!object_input)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }


  if (character_id != NO_ID && !character_is_friendly(character) && player_get_health(game_get_player(game)) > 0 && strcmp(object_input, character_get_name(character)) == 0)
  {
    damage = rand() %10;
    if (damage < 5)
    {
      player_set_health(game_get_player(game), player_get_health(game_get_player(game))-1);
      if (player_get_health(game_get_player(game)) <= 0)
      {
        game_set_finished(game, TRUE);
      }
    } else {
      character_set_health(character, character_get_health(character)-1);
      if (character_get_health(character) <= 0)
      {
        // ya existe una verificacion de la vida en graphic_engine.c
      }
    }
    command_set_status(game_get_last_command(game), OK);
  }
  return;
}

void game_actions_chat(Game *game) {
  
  Id player_location = NO_ID, character_id = NO_ID, character_location = NO_ID;
  Character *character = NULL;


  if (!game)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  player_location = game_get_player_location(game);
  if (player_location == NO_ID)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  character_id = space_get_character(game_get_space(game, player_location));
  if (character_id == NO_ID)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  character = game_get_character(game, character_id);

  character_location = game_get_character_location(game, character_id);
  if (character_location == NO_ID)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }
  
  if (character_location == player_location && character_is_friendly(character) && character_get_message(character) != NULL && command_get_code(game_get_last_command(game)) == CHAT)
  {
    game_set_message(game, character_get_message(character));
    command_set_status(game_get_last_command(game), OK);
    return;
  }
  game_set_message(game, NULL);
  command_set_status(game_get_last_command(game), ERROR);
  return;
}

void game_actions_move(Game *game) {
  Id space_id = NO_ID, dest_id = NO_ID;
  Direction dir = NO_DIRECTION;
  char *dir_str = NULL;

  if (!game) return;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  /* El usuario escribe la direccion: move north, move s, etc... */
  dir_str = command_get_arg(game_get_last_command(game), 0);
  if (!dir_str) {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  if (strcasecmp(dir_str, "north") == 0 || strcasecmp(dir_str, "n") == 0) dir = N;
  else if (strcasecmp(dir_str, "south") == 0 || strcasecmp(dir_str, "s") == 0) dir = S;
  else if (strcasecmp(dir_str, "east") == 0 || strcasecmp(dir_str, "e") == 0) dir = E;
  else if (strcasecmp(dir_str, "west") == 0 || strcasecmp(dir_str, "w") == 0) dir = W;

  if (dir == NO_DIRECTION) {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  /* Si el enlace existe y está abierto, nos movemos */
  if (game_connection_is_open(game, space_id, dir) == TRUE) {
    dest_id = game_get_connection(game, space_id, dir);
    if (dest_id != NO_ID) {
      game_set_player_location(game, dest_id);
      command_set_status(game_get_last_command(game), OK);
      return;
    }
  }

  command_set_status(game_get_last_command(game), ERROR);
  return;
}

void game_actions_inspect(Game *game) {
  char *obj_name = NULL;
  Id space_id = NO_ID, obj_id = NO_ID;
  Object *obj = NULL;
  Player *player = NULL;
  int i;

  if (!game) return;

  game_set_message(game, ""); /* Limpiamos el mensaje anterior */

  obj_name = command_get_arg(game_get_last_command(game), 0);
  if (!obj_name || strcmp(obj_name, "") == 0) {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  space_id = game_get_player_location(game);
  player = game_get_player(game);

  /* Buscamos el objeto por nombre en todo el juego */
  for (i = 0; i < game_get_n_objects(game); i++) {
    obj_id = game_get_object_id_at(game, i);
    if (obj_id == NO_ID) continue;
    
    obj = game_get_object(game, obj_id);
    if (!obj) continue;

    if (strcasecmp(obj_name, object_get_name(obj)) == 0) {
      /* Comprobamos si está en la sala actual O si lo lleva el jugador en su MOCHILA */
      if (space_has_object(game_get_space(game, space_id), obj_id) || 
          player_has_object(player, obj_id)) {
          
          game_set_message(game, object_get_description(obj));
          command_set_status(game_get_last_command(game), OK);
          return;
      }
    }
  }

  /* Si llegamos aquí es porque no existe o no está a nuestro alcance */
  command_set_status(game_get_last_command(game), ERROR);
  return;
}