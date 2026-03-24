/**
 * @brief It implements the player module
 *
 * @file object.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _Player{
    Id id;                  /*!< The id of the player */
    char name[WORD_SIZE+1]; /*!< The name of the player */
    Id location;            /*!< The location of the player */
    Inventory *backpack;    /*!< The inventor containing all of the player objects */
    int health;             /*!< The health of the player */
    char gdesc[7];          /*!< The description of the player */
};

Player* player_create(Id id) {

    Player* newplayer = NULL;

    if (id == NO_ID)
    {
        return NULL;
    }

    newplayer = (Player*)calloc(1, sizeof(Player));
    if (newplayer == NULL)
    {
        return NULL;
    }

    newplayer->id = id;
    newplayer->name[0] = '\0';
    newplayer->location = NO_ID;
    newplayer->backpack = inventory_create();
    newplayer->health = 10;
    newplayer->gdesc[0] = '\0'; 

    return newplayer;
}

Status player_destroy(Player* player) {

    if (!player)
    {
        return ERROR;
    }

    inventory_destroy(player->backpack);

    free(player);
    return OK;
}

Id player_get_id(Player* player) {
    
    if (!player)
    {
        return NO_ID;
    }

    return player->id;
}

const char* player_get_name(Player* player) {
    
    if (!player)
    {
        return NULL;
    }

    return player->name;
}

Status player_set_name(Player* player, char* name) {
    
    if (!player || !name)
    {
        return ERROR;
    }

    if (!strcpy(player->name, name))
    {
        return ERROR;
    }

    return OK;
}

Status player_set_location(Player* player, Id location) {
    
    if (!player || location == NO_ID)
    {
        return ERROR;
    }

    player->location = location;
    return OK;
}

Id player_get_location(Player* player) {
  
    if (!player)
    {
        return NO_ID;
    }

    return player->location;
}

Inventory *player_get_backpack(Player *player) {
    if (!player)
    {
        return NULL;
    }

    return player->backpack;
}

Status player_set_backpack(Player *player, Inventory *inv) {
    if (!player || !inv)
    {
        return ERROR;
    }

    player->backpack = inv;
    return OK;
}

Id player_get_object_from_backpack(Player *player, int position) {
    if (!player || position < 0)
    {
        return NO_ID;
    }

    return inventory_get_object_id(player_get_backpack(player), position);
}

Status player_add_object_to_backpack(Player *player, Id obj) {
    if (!player || obj == NO_ID)
    {
        return ERROR;
    }

    return inventory_add_object(player->backpack, obj);
}

Status player_remove_object_of_backpack(Player *player, Id obj) {
    if (!player || obj == NO_ID)
    {
        return ERROR;
    }

    return inventory_remove_object(player->backpack, obj);
}

Bool player_has_object(Player *player, Id obj) {
    if (!player || obj == NO_ID)
    {
        return FALSE;
    }

    return inventory_has_object(player->backpack, obj);
}

Bool player_backpack_is_full(Player *player) {
    if (!player)
    {
        return FALSE;
    }

    if (inventory_get_n_objects(player->backpack) == MAX_OBJS)
    {
        return TRUE;
    }
    return FALSE;
}

Status player_set_health(Player *player, int health) {
    if (!player || health < 0)
    {
        return ERROR;
    }

    player->health = health;
    return OK;
}

int player_get_health(Player *player) {
    if (!player)
    {
        return -1;
    }

    return player->health;
}

Status player_set_gdesc(Player *player, char *gdesc) {
    if (!player || !gdesc)
    {
        return ERROR;
    }

    strcpy(player->gdesc, gdesc);
    return OK;
}

char *player_get_gdesc(Player *player) {
    if (!player)
    {
        return NULL;
    }

    return player->gdesc;
}

Status player_set_max_objs(Player *player, int max_objs) {
    if (!player || max_objs > MAX_OBJS)
    {
        return ERROR;
    }

    return inventory_set_max_objs(player->backpack, max_objs);
}

Status player_print(Player* player) {

    if (!player)
    {
        return ERROR;
    }

    fprintf(stdout,"--> Player (Id: %ld; Name: %s; Location: %ld; Health: %d; Description: %s)\n", player->id, player->name, player->location, player->health, player->gdesc);
    inventory_print(player->backpack);

    return OK;
}
