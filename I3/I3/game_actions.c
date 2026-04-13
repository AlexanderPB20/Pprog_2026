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

void game_actions_move(Game *game);

void game_actions_take(Game *game);

void game_actions_drop(Game* game);

void game_actions_attack(Game *game);

void game_actions_chat(Game *game);

void game_actions_inspect(Game *game);

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

    case MOVE:
      game_actions_move(game);
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

void game_actions_move(Game *game) {
  Id destination_id = NO_ID;
  Id space_id = NO_ID;
  char *space_input = NULL;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  space_input = command_get_arg(game_get_last_command(game), 0);
  if (!space_input)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  if (strcmp(space_input, "north") == 0 || strcmp(space_input, "n") == 0)
  {
    destination_id = game_get_connection(game, space_id, N);
    if (destination_id != NO_ID && game_connection_is_open(game, space_id, N))
    {
      game_set_player_location(game, destination_id);
      space_set_discovered(game_get_space(game, space_id), TRUE);
      command_set_status(game_get_last_command(game), OK);
      return;
    }
  } else if (strcmp(space_input, "south") == 0 || strcmp(space_input, "s") == 0)
  {
    destination_id = game_get_connection(game, space_id, S);
    if (destination_id != NO_ID && game_connection_is_open(game, space_id, S))
    {
      game_set_player_location(game, destination_id);
      space_set_discovered(game_get_space(game, space_id), TRUE);
      command_set_status(game_get_last_command(game), OK);
      return;
    }
  } else if (strcmp(space_input, "east") == 0 || strcmp(space_input, "e") == 0)
  {
    destination_id = game_get_connection(game, space_id, E);
    if (destination_id != NO_ID && game_connection_is_open(game, space_id, E))
    {
      game_set_player_location(game, destination_id);
      space_set_discovered(game_get_space(game, space_id), TRUE);
      command_set_status(game_get_last_command(game), OK);
      return;
    }
  } else if (strcmp(space_input, "west") == 0 || strcmp(space_input, "w") == 0)
  {
    destination_id = game_get_connection(game, space_id, W);
    if (destination_id != NO_ID && game_connection_is_open(game, space_id, W))
    {
      game_set_player_location(game, destination_id);
      space_set_discovered(game_get_space(game, space_id), TRUE);
      command_set_status(game_get_last_command(game), OK);
      return;
    }
  }

  command_set_status(game_get_last_command(game), ERROR);
  return;
}

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

    if ((game_get_object_location(game, object_id) == space_id) && !player_has_object(player, object_id)) /* The object is in the space and the player doesn't have an object. */
    {
      if (strcmp(object_input, object_get_name(obj)) == 0) /* Compares if the argument and name are equals. */
      {
        player_add_object_to_backpack(player, object_id); /* Player takes the object. */
        space_del_object(game_get_space(game, space_id), object_get_id(obj)); /* Remove the object from the space. */
        game_set_object_location(game_get_space(game, space_id), NO_ID); /* Modifies the location of the object to NO_ID. */
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
  char *object_input = NULL;

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

  for (i = 0; i < player_get_n_objects(player); i++)
  {
    object_id = player_get_object_from_backpack(player, i);
    if (object_id == NO_ID)
    {
      continue;
    }

    if (player_has_object(player, object_id) && strcmp(object_input, object_get_name(game_get_object(game, object_id))) == 0) /* The player has the object. */
    {
      space_add_object(game_get_space(game, space_id), object_id); /* Adds the object to the space. */
      player_remove_object_from_backpack(player, object_id); /* The player leaves the object. */
      game_set_object_location(game_get_space(game, space_id), object_id); /* Modifies the location of the object. */
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
        /* The verification of life already exists in graphic_engine.c. */
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

void game_actions_inspect(Game *game) {
  
  Id player_location = NO_ID;
  char *object_input = NULL;
  Object *obj = NULL;

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

  object_input = command_get_arg(game_get_last_command(game), 0);
  if (!object_input)
  {
    command_set_status(game_get_last_command(game), ERROR);
    return;
  }

  for (int i = 0; i < set_get_n_elements(space_get_objects(game_get_space(game, player_location))); i++)
  {
    obj = game_get_object(game, set_get_element(space_get_objects(game_get_space(game, player_location)), i));

    if (strcmp(object_input, object_get_name(obj)) == 0)
    {
      game_set_message(game, object_get_desc(obj));
      command_set_status(game_get_last_command(game), OK);
      return;
    }
  }

  for (int j = 0; j < inventory_get_n_objects(player_get_backpack(game_get_player(game))); j++)
  {
    obj = game_get_object(game, inventory_get_object_id(player_get_backpack(game_get_player(game)), j));

    if (strcmp(object_input, object_get_name(obj)) == 0)
    {
      game_set_message(game, object_get_desc(obj));
      command_set_status(game_get_last_command(game), OK);
      return;
    }
  }

  command_set_status(game_get_last_command(game), ERROR);
  return;
}
