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
    Id id;
    char name[WORD_SIZE+1];
    Id location;
    Id object;
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
    newplayer->object=FALSE;

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

Status player_print(Player* player) {

    if (!player)
    {
        return ERROR;
    }

    fprintf(stdout,"--> Object (Id: %ld; Name: %s; Location: %ld; Object: %ld)\n", player->id, player->name, player->location, player->object);

    return OK;
}