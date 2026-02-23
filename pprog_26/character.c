/* @brief Player module implementation
*
* @file player.c
* @author Olger Alexander Preciado Bolaños
* @version 1.0

* @date 20-02 2024
*/

#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _Character {
    Id id;                      /* Id numero del personaje */
    char name[WORD_SIZE + 1];    /*Name of the Character*/
    char gdesc[7];               /* Descripcion grafica con un caracter extra de null*/
    int health;                  /*Salud del personaje*/
    Bool friendly;               /* Si el personaje es amigo*/
    char message[WORD_SIZE + 1]; /* Mensaje del personaje*/
};

/* Implementacion */
Character *character_create(Id id) {
    Character *newCharacter = NULL;

    if (id == NO_ID)
        return NULL;

    newCharacter = (Character *)malloc(sizeof(Character));
    if (!newCharacter)
        return NULL;

    newCharacter->id = id;
    newCharacter->name[0] = '\0';
    newCharacter->gdesc[0] = '\0';
    newCharacter->health = 100;
    newCharacter->friendly = FALSE;
    newCharacter->message[0] = '\0';

    return newCharacter;
}

Status character_destroy(Character *character) {
    if (!character)
        return ERROR;

    free(character);
    return OK;
}

Status character_set_id(Character *character,Id id){
    if (!character || id<0) {
        return ERROR;
    }
      
    character->id=id;
    return OK;
}

const char *character_get_name(const Character *character) {
    if (!character)
        return NULL;
    return character->name;
}

Id character_get_id(const Character *character) {
    if (!character)
        return NO_ID;
    return character->id;
}

int character_get_health(const Character *character) {
    if (!character)
        return -1;
    return character->health;
}

Bool character_is_friendly(const Character *character) {
    if (!character){
        return FALSE;
    }
    return character->friendly;
}

const char *character_get_message(const Character *character) {
    if (!character)
        return NULL;
    return character->message;
}

const char *character_get_gdesc(const Character *character) {
    if (!character)
        return NULL;
    return character->gdesc;
}

Status character_set_name(Character *character, const char *name) {
    if (!character || !name)
        return ERROR;

    if(!strcpy(character->name, name)){
        return ERROR;
    }
    return OK;
}

Status character_set_health(Character *character, int health) {
    if (!character || health < 0)
        return ERROR;

    if(health < 0){
        return ERROR;
    }

    character->health = health;
    return OK;
}

Status character_set_friendly(Character *character, Bool friendly) {
    if (!character)
        return ERROR;

    character->friendly = friendly;
    return OK;
}

Status character_set_message(Character *character, const char *message) {
    if (!character || !message)
        return ERROR;

    if(!strcpy(character->message, message)){
        return ERROR;
    }
    return OK;
}

Status character_set_gdesc(Character *character, const char *gdesc) {
    if (!character || !gdesc)
        return ERROR;

    if(!(strcpy(character->gdesc, gdesc))){
        return ERROR;
    }
    return OK;
}

Status character_print(const Character *character) {
    if (!character)
        return ERROR;

    fprintf(stdout, "Character (Id: %ld, Name: %s, Health: %d, Friendly: %s, Message: %s, Gdesc: %s)\n", 
            character_get_id(character), character_get_name(character), character_get_health(character), 
            character_is_friendly(character) ? "Yes" : "No", character_get_message(character), character_get_gdesc(character));
    return OK;
}

