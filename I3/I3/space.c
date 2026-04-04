/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Samuel Manzorro, Paula de la Fuente
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include "space.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Space {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  char gdesc[GDESC_SIZE1][GDESC_SIZE2]; /*!< Description of the space */
  Id north;                 /*!< Id of the space at the north */
  Id south;                 /*!< Id of the space at the south */
  Id east;                  /*!< Id of the space at the east */
  Id west;                  /*!< Id of the space at the west */
  Set *objects;             /*!< Set of objects in the space */
  Id character;             /*!< Character in the space */
  Bool discovered;          /*!< Whether the space is discovered or not*/
};



Space* space_create(Id id) {
  Space* newSpace = NULL;

  if (id == NO_ID) 
  {
    return NULL;
  }

  newSpace = (Space*)calloc(1, sizeof(Space));
  if (newSpace == NULL) {
    return NULL;
  }
  
  newSpace->id = id;
  newSpace->name[0] = '\0';

  for (int i = 0; i < GDESC_SIZE1; i++)
  {
    strcpy(newSpace->gdesc[i], "       ");
  }

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->objects=set_create();
  if (newSpace->objects == NULL)
  {
    free(newSpace);
    return NULL;
  }

  newSpace->character = NO_ID;
  newSpace->discovered = FALSE;

  return newSpace;
}

Status space_destroy(Space* space) {
  if (!space)
  {
    return ERROR;
  }

  set_destroy(space->objects);
  free(space);

  return OK;
}

Id space_get_id(Space* space) {
  if (!space)
  {
    return NO_ID;
  }

  return space->id;
}

Status space_set_name(Space* space, char* name) {
  if (!space || !name)
  {
    return ERROR;
  }

  if (!strcpy(space->name, name))
  {
    return ERROR;
  }
  
  return OK;
}

const char* space_get_name(Space* space) {
  if (!space)
  {
    return NULL;
  }
  
  return space->name;
}

Status space_set_gdesc(Space *space, int line, char* desc) {

  if (!space || !desc || line < 0 || line >= GDESC_SIZE1)
  {
    return ERROR;
  }
  
  strncpy(space->gdesc[line], desc, GDESC_SIZE2 - 1);
  space->gdesc[line][GDESC_SIZE2 - 1] = '\0';

  
  return OK;
}


char *space_get_gdesc(Space *space, int line) {
  if (!space || line < 0 || line >= GDESC_SIZE1)
  {
    return NULL;
  }

  return space->gdesc[line];
}

Status space_set_north(Space* space, Id id) {
  if (!space)
  {
    return ERROR;
  }

  space->north = id;
  return OK;
}

Id space_get_north(Space* space) {
  if (!space)
  {
    return NO_ID;
  }
  
  return space->north;
}

Status space_set_south(Space* space, Id id) {
  if (!space)
  {
    return ERROR;
  }

  space->south = id;
  return OK;
}

Id space_get_south(Space* space) {
  if (!space)
  {
    return NO_ID;
  }
  
  return space->south;
}

Status space_set_east(Space* space, Id id) {
  if (!space)
  {
    return ERROR;
  }
  
  space->east = id;
  return OK;
}

Id space_get_east(Space* space) {
  if (!space)
  {
    return NO_ID;
  }
  
  return space->east;
}

Status space_set_west(Space* space, Id id) {
  if (!space)
  {
    return ERROR;
  }
  
  space->west = id;
  return OK;
}

Id space_get_west(Space* space) {
  if (!space)
  {
    return NO_ID;
  }
  
  return space->west;
}

Bool space_has_object(Space* space, Id object_id) {
  if (!space ||object_id == NO_ID)
  {
    return FALSE;
  }

  return set_find(space->objects, object_id);
}

Status space_add_object(Space* space, Id object_id) {

  if (!space || object_id == NO_ID)
  {
    return ERROR;
  }

  /* Verifica si el objeto existe ya en el espacio para evitar duplicados */
  if (space_has_object(space, object_id))
  {
    return ERROR;
  }

  return set_add_element_to_set(space->objects, object_id);
}

Status space_del_object(Space* space, Id object_id) {

  if (!space ||object_id == NO_ID)
  {
    return ERROR;
  }

  if (space_has_object(space, object_id))
  {
    return set_del_element_to_set(space->objects, object_id);
  }

  return ERROR;
}

Id space_get_character(Space *space) {
  if (!space)
  {
    return NO_ID;
  }

  return space->character;
}

Status space_set_character(Space *space, Id character_id)
{
  if (!space)
  {
    return ERROR;
  }

  space->character = character_id;
  return OK;
}

Bool space_has_character(Space *space, Id character_id) {
  if (!space || character_id == NO_ID)
  {
    return FALSE;
  }

  if (space->character == character_id)
  {
    return TRUE;
  }

  return FALSE;
}

Set *space_get_objects(Space *space) {
  if (!space)
  {
    return NULL;
  }
  
  return space->objects;
}

Status space_set_discovered(Space* space, Bool discovered) {
  if(!space){
    return ERROR;
  }

  space->discovered = discovered;

  return OK;
}

Bool space_is_discovered(Space* space) {
  if(!space){
    return FALSE;  /*si falla da false??*/
  }

  return space->discovered;
}

Status space_print(Space* space) {
  Id idaux = NO_ID;

  if (!space)
  {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (idaux != NO_ID)
  {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (idaux != NO_ID)
  {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = space_get_east(space);
  if (idaux != NO_ID)
  {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (idaux != NO_ID)
  {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  fprintf(stdout, "---> Graphic description:\n");
  for (int i = 0; i < GDESC_SIZE1; i++)
  {
    fprintf(stdout, "   [%s]\n", space->gdesc[i]);
  }

  if (space->character != NO_ID)
  {
    fprintf(stdout, "---> Character in the space: %ld.\n", space->character);
  } else {
    fprintf(stdout, "---> No character in the space.\n");
  }

  if (set_get_n_elements(space->objects) > 0)
  {
    fprintf(stdout, "---> Object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  idaux = space_is_discovered(space);
  if (idaux == TRUE) {
    fprintf(stdout, "---> Space is discovered.\n");
  } else {
    fprintf (stdout, "---> Space is not discovered.\n");
  }

  return OK;
}



  return OK;
}

