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
  Player *player = NULL;

  if (game_create(game) == ERROR) {
    return ERROR;
  }

  if (game_reader_load_spaces(game, filename) == ERROR) {
    return ERROR;
  }

  if (game_reader_load_objects(game, filename) == ERROR) {
    return ERROR;
  }

  player = game_get_player(game, 1);
  if (player != NULL) {
    /* le pasamos el puntero al jugador como segundo argumento */
    game_set_player_location(game, player, game_get_space_id_at(game, 0));
  }


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
  Id id = NO_ID, space_id = NO_ID;
  Object *obj = NULL;

  if (!filename || !game) return ERROR;

  file = fopen(filename, "r");
  if (!file) return ERROR;

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      /* Extraer ID */
      toks = strtok(line + 3, "|");
      if (!toks) continue;
      id = atol(toks);

      /* Extraer Nombre */
      toks = strtok(NULL, "|");
      if (!toks) continue;
      strcpy(name, toks);

      /* Extraer ID del espacio */
      toks = strtok(NULL, "|");
      if (!toks) continue;
      space_id = atol(toks);

      /* Crear el objeto y añadirlo al juego */
      obj = object_create(id);
      if (obj != NULL) {
        object_set_name(obj, name);
        game_add_object(game, obj);
        game_set_object_location(game, obj, space_id);
      }
    }
  }

  fclose(file);
  return OK;
}

  return status;

}
