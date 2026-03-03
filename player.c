/**
 * @brief It implements the game structure
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
    Id id;                  // id of the player
    char name[WORD_SIZE+1]; // name of the player
    Id location;            // location of the player
    Id object;              // location of the object the player has
    int health;             // health of the player
    char gdesc[7];          // description of the player
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
    newplayer->object= NO_ID;
    newplayer->health = 10;
    newplayer->gdesc[0] = '\0';

    return newplayer;
}

Status player_destroy(Player* player) {

    if (!player)
    {
        return ERROR;
    }

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
    
    if (!player || !location)
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

Status player_set_object(Player* player, Id object_id) {
 
    if (!player || !object_id) {
    return ERROR;
    }
  
    player->object = object_id;
    return OK;
}

Id player_get_object(Player* player) {
  
    if (!player) {
        return NO_ID;
    }
  
    return player->object;
}

Status player_set_health(Player* player, int health) {
    if (!player) return ERROR;
    player->health = health;
    return OK;
}

int player_get_health(Player* player) {
    if (!player) return -1;
    return player->health;
}

Status player_set_gdesc(Player* player, char* gdesc) {
    if (!player || !gdesc) return ERROR;
    if (!strcpy(player->gdesc, gdesc)) return ERROR;
    return OK;
}

const char* player_get_gdesc(Player* player) {
    if (!player) return NULL;
    return player->gdesc;
}

Status player_print(Player* player) {

    if (!player)
    {
        return ERROR;
    }

    fprintf(stdout,"--> Player (Id: %ld; Name: %s; Location: %ld; Object: %ld; Health: %d; Graphic Description: %s)\n", player->id, player->name, player->location, player->object, player->health, player->gdesc);

    return OK;

}


