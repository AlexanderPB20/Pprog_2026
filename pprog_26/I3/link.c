/**
 * @brief It implements the link module
 *
 * @file link.c
 * @author Marta López
 * @version 0
 * @date 19-03-2026
 * @copyright GNU Public License
 */


#include "link.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _Link {
    Id id;                    /*!< Id number of the link, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the link */
    Id origin;                /*!< Id number of the origin link */
    Id destination;           /*!< Id number of the destination link */
    Direction direction;      /*!< Direction of the link */
    Bool open;                /*!< State of the link, open or closed */
};



Link *link_create(Id id) {
    
    Link *link = NULL;

    if (id == NO_ID)  return NULL;

    link = (Link*)malloc(sizeof(Link));

    if (link == NULL) return NULL;
    
    link->id = id;
    link->name[0] = '\0';
    link->origin = NO_ID;
    link->destination = NO_ID;
    link->direction  = NO_DIRECTION;
    link->open = FALSE;

    return link;
}


Status link_destroy(Link* link) {

  if (!link)
  {
    return ERROR;
  }

  free(link);
  return OK;
}


Status link_set_id(Link *link, Id id){
    
    if(!link || id == NO_ID)
    {
      return NO_ID;
    }
    
    link->id = id;
    
    return OK;
}


Id link_get_id(Link* link) {

  if (!link)
  {
    return NO_ID;
  }

  return link->id;
}


Status link_set_name(Link* link, const char* name) {

  if (!link || !name)
  {
    return ERROR;
  }

  if (!strcpy(link->name, name)) return ERROR;
  
  return OK;
}


const char* link_get_name(Link* link) {
  if (!link)
  {
    return NULL;
  }

  return link->name;
}


Status link_set_origin(Link* link, Id id) {
  if (!link)
  {
    return ERROR;
  }

  link->origin = id;
  return OK;
}


Id link_get_origin(Link* link) {
  if (!link)
  {
    return NO_ID;
  }

  return link->origin;
}


Status link_set_destination(Link* link, Id id) {
  if (!link)
  {
    return ERROR;
  }
  
  link->destination = id;
  return OK;
}


Id link_get_destination(Link* link) {
  if (!link)
  {
    return NO_ID;
  }

  return link->destination;
}


Status link_set_direction(Link *link, Direction direction){
    if(!link || direction == NO_DIRECTION)
    {
      return ERROR;
    }

    link->direction = direction;
    return OK;
}


Id link_get_direction(Link* link) {
  if (!link)
  {
    return NO_DIRECTION;
  }
  
  return link->direction;
}


Status link_set_open(Link *link, Bool open){
    if(!link)
    {
      return ERROR;
    }

    link->open = open;
    return OK;
}


Bool link_get_open(Link* link) {
  if (!link)
  {
    return FALSE;
  }

  return link->open;
}


Status link_print(Link *link){
    if(!link)
    {
      return ERROR;
    }

    fprintf(stdout, "Link (Id: %ld, Name: %s, Origin: %ld, Destination: %ld, Direction: %c, Open: %d)\n", link->id, link->name, link->origin, link->destination, link->direction, link->open);    
    return OK;
}