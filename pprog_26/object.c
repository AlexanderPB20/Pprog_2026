/**
 * @brief It implements the game structure
 *
 * @file object.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _Object{
    Id id;
    char name[WORD_SIZE+1];
};

Object* object_create(Id id) {

    Object* newobject = NULL;

    if (id == NO_ID)
    {
        return NULL;
    }

    newobject = (Object*)calloc(1, sizeof(Object));
    if (newobject == NULL)
    {
        return NULL;
    }

    newobject->id=id;
    newobject->name[0]='\0';

    return newobject;
}

Status object_destroy(Object* object) {

    if (!object)
    {
        return ERROR;
    }

    free(object);
    return OK;
}

Id object_get_id(Object* object) {
    
    if (!object)
    {
        return NO_ID;
    }

    return object->id;
}

const char* object_get_name(Object* object) {
    
    if (!object)
    {
        return NULL;
    }

    return object->name;
}

Status object_set_name(Object* object, char* name) {
    
    if (!object || !name)
    {
        return ERROR;
    }

    if (!strcpy(object->name, name))
    {
        return ERROR;
    }

    return OK;
}

Status object_print(Object* object) {

    if (!object)
    {
        return ERROR;
    }

    fprintf(stdout,"--> Object (Id: %ld; Name: %s)\n", object->id, object->name);

    return OK;
}