/**
 * @brief It implements the game structure
 *
 * @file game_reader.c
 * @author Profesores PPROG
 * @version 0
 * @date 23-03-2026
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

  if (game_reader_load_spaces(game, filename) == ERROR || game_reader_load_objects(game, filename) == ERROR || game_reader_load_characters(game, filename) == ERROR || game_reader_load_links(game, filename) == ERROR || game_reader_load_player(game, filename) == ERROR) {
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));

  return OK;
}


/**
   Implementation of private functions
*/

Status game_reader_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID;
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

#ifdef DEBUG
      printf("Leido: s:%ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);

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

Status game_reader_load_links(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, origin = NO_ID, destination = NO_ID;
  Link *link = NULL;
  Direction direction;
  Bool open;

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
    if (strncmp("#l:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);

      toks = strtok(NULL, "|");
      strcpy(name, toks);

      toks = strtok(NULL, "|");
      origin = atol(toks);

      toks = strtok(NULL, "|");
      destination = atol(toks);

      toks = strtok(NULL, "|");
      if (strcmp(toks, "N") == 0) {
        direction = N;

      } else if (strcmp(toks, "S") == 0) {
        direction = S;

      } else if (strcmp(toks, "E") == 0) {
        direction = E;

      } else if (strcmp(toks, "W") == 0) {
        direction = W;
      } else {
        direction = NO_DIRECTION;
      }


      toks = strtok(NULL, "|");
      open = atol(toks);

      link = link_create(id);

      link_set_name(link, name);
      link_set_origin(link, origin);
      link_set_destination(link, destination);
      link_set_direction(link, direction);
      link_set_open(link, open);

    }
  }

  fclose(file);
  return OK;
}

Status game_reader_load_player(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "", name[WORD_SIZE] = "", gdesc[WORD_SIZE] = "", *toks = NULL;
  Id location = NO_ID;
  int health = 0, max_objs = 0;
  Player *player = NULL;

  if (!filename || !game) return ERROR;
  file = fopen(filename, "r");
  if (!file) return ERROR;

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#p:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      strcpy(gdesc, toks);
      toks = strtok(NULL, "|");
      location = atol(toks);
      toks = strtok(NULL, "|");
      health = atoi(toks);
      toks = strtok(NULL, "|");
      max_objs = atoi(toks);

      player = game_get_player(game);
      if (player != NULL) {
        player_set_name(player, name);
        player_set_gdesc(player, gdesc);
        game_set_player_location(game, location);
        player_set_health(player, health);
        player_set_max_objs(player, max_objs);
      }
    }
  }
  fclose(file);
  return OK;
}