/**
 * @brief It implements the game structure
 *
 * @file game_reader.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game_reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Implementation of public functions
*/

Status game_reader_create_from_file(Game *game, char *filename) {
  if (game == NULL || filename == NULL) {
    return ERROR;
  }

  if (game_reader_load_spaces(game, filename) == ERROR || game_reader_load_objects(game, filename) == ERROR || game_reader_load_characters(game, filename) == ERROR) {
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));

  return OK;
}


/**
   Implementation of private functions
*/
Status game_reader_load_players(Game *game, char* filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char gdesc[WORD_SIZE] = "";
  int health, max_objs;
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Player *ply = NULL;
  Status status = OK;

  if (!filename || !game)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (!file)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#p:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      strcpy(gdesc, toks);

      toks = strtok(NULL, "|");
      location = atol(toks);

      toks = strtok(NULL, "|");
      health = atol(toks);

      toks = strtok(NULL, "|");
      max_objs = atol(toks);

      ply = player_create(id);
      if (!ply)
      {
        fclose(file);
        return ERROR;
      }

      if (player_set_name(ply, name) == ERROR || player_set_gdesc(ply, gdesc) || game_set_player_location(game, location) || player_set_health(ply, health) || player_set_max_objs(ply, max_objs))
      {
        player_destroy(ply);
        fclose(file);
        status = ERROR;
      }

      if (game_set_player(game, ply) == ERROR)
      {
        player_destroy(ply);
        fclose(file);
        status = ERROR;
      }

      if (ferror(file))
      {
        fclose(file);
        status = ERROR;
      }      
    }
  }

  fclose(file);
  return status;

}

Status game_reader_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Space *space = NULL;
  Status status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    line[strcspn(line, "\r\n")] = '\0';
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: s:%ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);

        for (int i = 0; i < GDESC_SIZE1; i++)
        {
          toks = strtok(NULL, "|");
          if (toks != NULL)
          {
            space_set_gdesc(space, i, toks);
          }
        }

        game_add_space(game, space);
      }
    }
  }

  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;
}

Status game_reader_load_objects(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object *obj = NULL;
  Status status = OK;

  if (!filename || !game)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (!file)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      location = atol(toks);

      obj = object_create(id);
      if (!obj)
      {
        fclose(file);
        return ERROR;
      }

      if (object_set_name(obj, name) == ERROR || game_set_object_location(game_get_space(game, location), id) == ERROR)
      {
        object_destroy(obj);
        fclose(file);
        status = ERROR;
      }

      if (game_add_object(game, obj) == ERROR)
      {
        object_destroy(obj);
        fclose(file);
        status = ERROR;
      }

      if (ferror(file))
      {
        fclose(file);
        status = ERROR;
      }      
    }
  }

  fclose(file);
  return status;
}

Status game_reader_load_characters(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char gdesc[WORD_SIZE] = "";
  char message[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Character *character = NULL;
  Bool friendly;

  if (!filename || !game)
  {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (!file)
  {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#c:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      strcpy(gdesc, toks);

      toks = strtok(NULL, "|");
      location = atol(toks);

      toks = strtok(NULL, "|");
      friendly = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(message, toks);

      character = character_create(id);
      if (!character)
      {
        fclose(file);
        return ERROR;
      }

      if (game_add_character(game, character) == ERROR)
      {
        fclose(file);
        return ERROR;
      }

      character_set_name(character, name);
      character_set_gdesc(character, gdesc);
      game_set_character_location(game_get_space(game, location), id);
      character_set_friendly(character, friendly);
      character_set_message(character, message);  
    }
  }

  fclose(file);
  return OK;
}