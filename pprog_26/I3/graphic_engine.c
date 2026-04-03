/**
 * @brief It implements a textual graphic engine
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include "graphic_engine.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "libscreen.h"
#include "space.h"
#include "types.h"

#define WIDTH_MAP 60  /*!< Width of the map area */
#define WIDTH_DES 29  /*!< Width of the description area */
#define WIDTH_BAN 45  /*!< Width of the banner area */
#define HEIGHT_MAP 30 /*!< Height of the map area */
#define HEIGHT_BAN 1  /*!< Height of the banner area */
#define HEIGHT_HLP 2  /*!< Height of the help area */
#define HEIGHT_FDB 3  /*!< Height of the feedback area */

#define MAX_O 1

struct _Graphic_engine {
  Area *map;      /*!< Pointer to the map area */
  Area *descript; /*!< Pointer to the description area */
  Area *banner;   /*!< Pointer to the banner area */
  Area *help;     /*!< Pointer to the help area */
  Area *feedback; /*!< Pointer to the feedback area */
};

Graphic_engine *graphic_engine_create() {
  static Graphic_engine *ge = NULL;

  if (ge) {
    return ge;
  }

  screen_init(HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + HEIGHT_FDB + 4, WIDTH_MAP + WIDTH_DES + 3);
  ge = (Graphic_engine *)calloc(1, sizeof(Graphic_engine));
  if (ge == NULL) {
    return NULL;
  }

  ge->map = screen_area_init(1, 1, WIDTH_MAP, HEIGHT_MAP);
  ge->descript = screen_area_init(WIDTH_MAP + 2, 1, WIDTH_DES, HEIGHT_MAP);
  ge->banner = screen_area_init((int)((WIDTH_MAP + WIDTH_DES + 1 - WIDTH_BAN) / 2), HEIGHT_MAP + 2, WIDTH_BAN, HEIGHT_BAN);
  ge->help = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + 2, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_HLP);
  ge->feedback = screen_area_init(1, HEIGHT_MAP + HEIGHT_BAN + HEIGHT_HLP + 3, WIDTH_MAP + WIDTH_DES + 1, HEIGHT_FDB);

  return ge;
}

void graphic_engine_destroy(Graphic_engine *ge) {
  if (!ge) return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, id_left = NO_ID, id_right = NO_ID, obj_loc = NO_ID, obj_id = NO_ID, chr_loc = NO_ID, character_id = NO_ID;
  Space *space_act = NULL;
  char obj_act[WORD_SIZE] = {'\0'};
  char obj_back[WORD_SIZE] = {'\0'};
  char obj_next[WORD_SIZE] = {'\0'};
  char obj_left[WORD_SIZE] = {'\0'};
  char obj_right[WORD_SIZE] = {'\0'};
  char chr_act[WORD_SIZE] = {'\0'};
  char chr_back[WORD_SIZE] = {'\0'};
  char chr_next[WORD_SIZE] = {'\0'};
  char chr_left[WORD_SIZE] = {'\0'};
  char chr_right[WORD_SIZE] = {'\0'};

  char str[WORD_SIZE * 10];
  CommandCode last_cmd = UNKNOWN;
  Status last_command_status = OK;
  extern char *cmd_to_str[N_CMD][N_CMDT];
  int i, n;
  Object *obj = NULL;
  Character *chr = NULL;

  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID) {
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    id_left = space_get_west(space_act);
    id_right = space_get_east(space_act);

    for (i=0; i < game_get_n_objects(game); i++)
    {
      obj_id = game_get_object_id_at(game, i);
      obj = game_get_object(game, obj_id);

      if (obj != NULL)
      {
        if (game_get_object_location(game, obj_id) == NO_ID)
        {
          continue;

        } else if (game_get_object_location(game, obj_id) == id_act)
        {
          strncat(obj_act, object_get_name(obj), strlen(object_get_name(obj)));
          strncat(obj_act, " ", WORD_SIZE - strlen(obj_act) - 1);

        } else if (game_get_object_location(game, obj_id) == id_back)
        {
          strncat(obj_back, object_get_name(obj), strlen(object_get_name(obj)));
          strncat(obj_back, " ", WORD_SIZE - strlen(obj_back) - 1);

        } else if (game_get_object_location(game, obj_id) == id_next)
        {
          strncat(obj_next, object_get_name(obj), strlen(object_get_name(obj)));
          strncat(obj_next, " ", WORD_SIZE - strlen(obj_next) - 1);

        } else if (game_get_object_location(game, obj_id) == id_left)
        {
          strncat(obj_left, object_get_name(obj), strlen(object_get_name(obj)));
          strncat(obj_left, " ", WORD_SIZE - strlen(obj_left) - 1);

        } else if (game_get_object_location(game, obj_id) == id_right)
        {
          strncat(obj_right, object_get_name(obj), strlen(object_get_name(obj)));
          strncat(obj_right, " ", WORD_SIZE - strlen(obj_right) - 1);
        }
      }
    }

    for (int k = 0; k < game_get_n_characters(game); k++)
    {
      character_id = game_get_character_id_at(game, k);
      chr = game_get_character(game, character_id);

      if (chr != NULL && character_get_health(chr) > 0)
      {
        if (game_get_character_location(game, character_id) == id_act)
        {
          strncat(chr_act, character_get_gdesc(chr), strlen(character_get_gdesc(chr)));
          strncat(chr_act, " ", WORD_SIZE - strlen(chr_act) - 1);

        } else if (game_get_character_location(game, character_id) == id_back)
        {
          strncat(chr_back, character_get_gdesc(chr), strlen(character_get_gdesc(chr)));
          strncat(chr_back, " ", WORD_SIZE - strlen(chr_back) - 1);

        } else if (game_get_character_location(game, character_id) == id_next)
        {
          strncat(chr_next, character_get_gdesc(chr), strlen(character_get_gdesc(chr)));
          strncat(chr_next, " ", WORD_SIZE - strlen(obj_next) - 1);

        } else if (game_get_character_location(game, character_id) == id_left)
        {
          strncat(chr_left, character_get_gdesc(chr), strlen(character_get_gdesc(chr)));
          strncat(chr_left, " ", WORD_SIZE - strlen(chr_left) - 1);

        } else if (game_get_character_location(game, character_id) == id_right)
        {
          strncat(chr_right, character_get_gdesc(chr), strlen(character_get_gdesc(chr)));
          strncat(chr_right, " ", WORD_SIZE - strlen(chr_right) - 1);
        }
      }

    }

    if (id_back != NO_ID) {
      sprintf(str, "                   +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                   | %-12.12s%2d|", chr_back, (int)id_back);
      screen_area_puts(ge->map, str);

      if (space_get_gdesc(game_get_space(game, id_back), 0) != NULL)
      {
        for (n = 0; n < GDESC_SIZE1; n++)
        {
          sprintf(str, "                   |   %-9.9s   |", space_get_gdesc(game_get_space(game, id_back), n));
          screen_area_puts(ge->map, str);
        }
      } else {
        for (n = 0; n < GDESC_SIZE1; n++)
        {
          sprintf(str, "                   |               |");
          screen_area_puts(ge->map, str);
        }
      }
      sprintf(str, "                   |%-15.15s|", obj_back);
      screen_area_puts(ge->map, str);
      sprintf(str, "                   +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                            ^       ");
      screen_area_puts(ge->map, str);
    } else {
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                                    ");
      screen_area_puts(ge->map, str);
    }


    if (id_act != NO_ID ) {
      if (id_left != NO_ID && id_right != NO_ID)
      {
        sprintf(str, "+---------------+  +---------------+  +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "|%-12.12s%3d|  | ^C>%-8.8s%3d|  |%-12.12s%3d|", chr_left, (int)id_left, chr_act, (int)id_act, chr_right, (int)id_right);
        screen_area_puts(ge->map, str);
        if (space_get_gdesc(game_get_space(game, id_left), 0) != NULL)
        {
          if (space_get_gdesc(game_get_space(game, id_left), 0) != NULL && space_get_gdesc(game_get_space(game, id_right), 0) != NULL )
          {
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "|   %-9.9s   |  |   %-9.9s   |  |   %-9.9s   |", space_get_gdesc(game_get_space(game, id_left), n), space_get_gdesc(game_get_space(game, id_act), n), space_get_gdesc(game_get_space(game, id_right), n));
              screen_area_puts(ge->map, str);
            }
          } else if (space_get_gdesc(game_get_space(game, id_left), 0) != NULL && space_get_gdesc(game_get_space(game, id_right), 0) == NULL )
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "|   %-9.9s   |  |   %-9.9s   |  |               |", space_get_gdesc(game_get_space(game, id_left), n), space_get_gdesc(game_get_space(game, id_act), n));
              screen_area_puts(ge->map, str);
            }else if (space_get_gdesc(game_get_space(game, id_left), 0) == NULL && space_get_gdesc(game_get_space(game, id_right), 0) != NULL )
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "|               |  |   %-9.9s   |  |   %-9.9s   |", space_get_gdesc(game_get_space(game, id_act), n), space_get_gdesc(game_get_space(game, id_right), n));
              screen_area_puts(ge->map, str);
            } else if (space_get_gdesc(game_get_space(game, id_left), 0) == NULL && space_get_gdesc(game_get_space(game, id_right), 0) == NULL ) {
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "|               |  |   %-9.9s   |  |               |", space_get_gdesc(game_get_space(game, id_act), n));
              screen_area_puts(ge->map, str);
            }
            } else {
              for (n = 0; n < GDESC_SIZE1; n++)
              {
              sprintf(str, "|               |  |               |  |               |");
              screen_area_puts(ge->map, str);
            }
            }
          sprintf(str, "|%-15.15s| <|%-15.15s|> |%-15.15s|", obj_left, obj_act, obj_right);
          screen_area_puts(ge->map, str);
          sprintf(str, "+---------------+  +---------------+  +---------------+");
          screen_area_puts(ge->map, str);
        }
      } else if (id_left != NO_ID && id_right == NO_ID)
      {
        sprintf(str, "+---------------+  +---------------+ ");
        screen_area_puts(ge->map, str);
        sprintf(str, "|%-12.12s%3d|  | ^C>%-8.8s%3d|", chr_left, (int)id_left, chr_act, (int)id_act);
        screen_area_puts(ge->map, str);
        if (space_get_gdesc(game_get_space(game, id_left), 0) != NULL && space_get_gdesc(game_get_space(game, id_act), 0) != NULL )
          {
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "|   %-9.9s   |  |   %-9.9s   |", space_get_gdesc(game_get_space(game, id_left), n), space_get_gdesc(game_get_space(game, id_act), n));
              screen_area_puts(ge->map, str);
            }
          } else if (space_get_gdesc(game_get_space(game, id_left), 0) == NULL && space_get_gdesc(game_get_space(game, id_act), 0) == NULL )
          {
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "|               |  |   %-9.9s   |", space_get_gdesc(game_get_space(game, id_act), n));
              screen_area_puts(ge->map, str);
            }
          } else {
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "|               |  |               |");
              screen_area_puts(ge->map, str);
            }
          }
        sprintf(str, "|%-15.15s| <|%-15.15s|", obj_right, obj_act);
        screen_area_puts(ge->map, str);
        sprintf(str, "+---------------+  +---------------+ ");
        screen_area_puts(ge->map, str);
      } else if (id_left == NO_ID && id_right != NO_ID)
      {
        sprintf(str, "                   +---------------+  +---------------+ ");
        screen_area_puts(ge->map, str);
        sprintf(str, "                   | ^C>%-8.8s%3d|  |%-12.12s%3d|", chr_act, (int)id_act, chr_right, (int)id_right);
        screen_area_puts(ge->map, str);
        if (space_get_gdesc(game_get_space(game, id_act), 0) != NULL && space_get_gdesc(game_get_space(game, id_right), 0) != NULL )
          {
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "                   |   %-9.9s   |  |   %-9.9s   |", space_get_gdesc(game_get_space(game, id_act), n), space_get_gdesc(game_get_space(game, id_right), n));
              screen_area_puts(ge->map, str);
            }
          } else if (space_get_gdesc(game_get_space(game, id_act), 0) == NULL && space_get_gdesc(game_get_space(game, id_right), 0) == NULL )
          {
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "                   |   %-9.9s   |  |               |", space_get_gdesc(game_get_space(game, id_act), n));
              screen_area_puts(ge->map, str);
            }
          } else {
            for (n = 0; n < GDESC_SIZE1; n++)
            {
              sprintf(str, "                   |               |  |               |");
              screen_area_puts(ge->map, str);
            }
          }
        sprintf(str, "                   |%-15.15s|> |%-15.15s|", obj_act, obj_right);
        screen_area_puts(ge->map, str);
        sprintf(str, "                   +---------------+  +---------------+ ");
        screen_area_puts(ge->map, str);
      } else {
        sprintf(str, "                   +---------------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "                   | ^C>%-8.8s%3d|", chr_act, (int)id_act);
        screen_area_puts(ge->map, str);

        if (space_get_gdesc(game_get_space(game, id_act), 0) != NULL)
        {
          for (n = 0; n < GDESC_SIZE1; n++)
          {
            sprintf(str, "                   |   %-9.9s   |", space_get_gdesc(game_get_space(game, id_act), n));
           screen_area_puts(ge->map, str);
          }
        } else {
          for (n = 0; n < GDESC_SIZE1; n++)
          {
            sprintf(str, "                   |               |");
            screen_area_puts(ge->map, str);
          }
        }
        sprintf(str, "                   |%-15.15s|", obj_act);
        screen_area_puts(ge->map, str);
        sprintf(str, "                   +---------------+");
        screen_area_puts(ge->map, str);
      }
    }

    if (id_next != NO_ID) {
      sprintf(str, "                           v        ");
      screen_area_puts(ge->map, str);
      sprintf(str, "                   +---------------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "                   | %-12.12s%2d|", chr_next, (int)id_next);
      screen_area_puts(ge->map, str);

      if (space_get_gdesc(game_get_space(game, id_next), 0) != NULL)
      {
        for (n = 0; n < GDESC_SIZE1; n++)
        {
          sprintf(str, "                   |   %-9.9s   |", space_get_gdesc(game_get_space(game, id_next), n));
          screen_area_puts(ge->map, str);
        }
      } else {
        for (n = 0; n < GDESC_SIZE1; n++)
        {
          sprintf(str, "                   |               |");
          screen_area_puts(ge->map, str);
        }
      }
      sprintf(str, "                   |%-15.15s|", obj_next);
      screen_area_puts(ge->map, str);
      sprintf(str, "                   +---------------+");
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);
  sprintf(str, "  Objects:");
  screen_area_puts(ge->descript, str);
  for (int j = 0; j < game_get_n_objects(game); j++)
  {
    obj_id = game_get_object_id_at(game, j);
    obj = game_get_object(game, obj_id);
    if (obj != NULL)
    {
      obj_loc = game_get_object_location(game, obj_id);
      sprintf(str, "   %s: %d", object_get_name(obj), (int)obj_loc);
      screen_area_puts(ge->descript, str);
    }
  }
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Characters:");
  screen_area_puts(ge->descript, str);
  for (int n = 0; n < game_get_n_characters(game); n++)
  {
    character_id = game_get_character_id_at(game, n);
    chr = game_get_character(game, character_id);
    if (chr != NULL)
    {
      chr_loc = game_get_character_location(game, character_id);
      sprintf(str, "    %s -->  %s: %d (%d)", character_get_name(chr), character_get_gdesc(chr), (int)chr_loc, character_get_health(chr));
      screen_area_puts(ge->descript, str);
      if (command_get_status(game_get_last_command(game)) == OK && strcmp(game_get_message(game), character_get_message(chr)) == 0)
      {
        sprintf(str, "    %s", game_get_message(game));
        screen_area_puts(ge->descript, str);
      } else {
        sprintf(str, "      ");
        screen_area_puts(ge->descript, str);
      }
    }
  }
  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Player location: %ld (%d)", game_get_player_location(game), player_get_health(game_get_player(game)));
  screen_area_puts(ge->descript, str);
  sprintf(str, "  Player objects: ");
  screen_area_puts(ge->descript, str);
  for (int l = 0; l < inventory_get_max_objs(player_get_backpack(game_get_player(game))); l++)
  {
    if (player_get_object_from_backpack(game_get_player(game), l) != NO_ID)
    {
      sprintf(str, "  -%s ", object_get_name(game_get_object(game, inventory_get_object_id(player_get_backpack(game_get_player(game)), l))));
      screen_area_puts(ge->descript, str);
    }
  }

  sprintf(str, " ");
  screen_area_puts(ge->descript, str);

  /* Paint in the banner area */
  screen_area_puts(ge->banner, " The haunted castle game ");

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     next or n, back or b, left or l, right or r, exit or e, take or t, drop or d, attack or a, chat or c");
  screen_area_puts(ge->help, str);

  /* Paint in the feedback area */
  last_cmd = command_get_code(game_get_last_command(game));
  last_command_status = command_get_status(game_get_last_command(game));
  if (last_command_status == OK)
  {
    sprintf(str, " %s (%s) : OK", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  } else {
    sprintf(str, " %s (%s) : ERROR", cmd_to_str[last_cmd - NO_CMD][CMDL], cmd_to_str[last_cmd - NO_CMD][CMDS]);
    screen_area_puts(ge->feedback, str);
  }

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}