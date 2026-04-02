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
    Id id;                  /*!< id of the player */
    char name[WORD_SIZE+1]; /*!< name of the player */
    Id location;            /*!< location of the player */
    Inventory* backpack;     /*!< Inventory of the player (backpack with all objects) */
    int health;             /*!< health of the player */
    char gdesc[7];          /*!< description of the player */
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
    newplayer->backpack= inventory_create();
    newplayer->health = 10;
    newplayer->gdesc[0] = '\0'; 

    return newplayer;
}

Status player_destroy(Player* player) {

    if (!player)
    {
        return ERROR;
    }

    if(inventory_destroy(player->backpack)==ERROR) {
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

Status player_add_object(Player* player, Id obj_id) {
    if(!player || obj_id==NO_ID) {
        return ERROR;
    }
    /*Make sure that there's space in the backpack*/
    if(inventory_get_num_objects(player->backpack)==MAX_OBJS) {
        return ERROR;
    }
    /*Make sure that the object is not already in the backpack*/
    if(inventory_has_object(player->backpack, obj_id)==TRUE){
        return ERROR;
    }

    if(inventory_add_object(player->backpack, obj_id)==ERROR) {
        return ERROR;
    }

    return OK;
}

Status player_del_object(Player* player, Id obj_id) {
    Set* objs_set=NULL;

    if(!player || obj_id==NO_ID) {
        return ERROR;
    }
    
    /*Make sure that the object is already in the backpack*/
    if(inventory_has_object(player->backpack, obj_id)==FALSE){
        return ERROR;
    }

    objs_set=inventory_get_set_of_objs(player->backpack);
    if(!objs_set){
        return ERROR;
    }

    return set_del_element_to_set(objs_set, obj_id);
}


Inventory* player_get_inventory(Player* player) {
    if(!player) {
        return NULL;
    }

    return player->backpack;
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

Status player_print(Player* player) {

    if (!player)
    {
        return ERROR;
    }

    fprintf(stdout,"--> Player (Id: %ld; Name: %s; Location: %ld; Health: %d; Description: %s)\n", player->id, player->name, player->location, player->health, player->gdesc);
    if(inventory_print(player->backpack)==ERROR){
        return ERROR;
    }

    return OK;
}
