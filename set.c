/**
 * @brief It implements the game structure
 *
 * @file set.c
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _Set{
    Id *ids; /*!< Array of ids */
    int n_ids; /*!< Number of ids in the set */
};

Set *set_create() {
    Set *set = NULL;
    
    set = (Set*)malloc(sizeof(Set));
    if (set == NULL)
    {
        return NULL;
    }

    set->ids = NULL;
    set->n_ids = 0;

    return set;
}

Status set_destroy(Set *set) {

    if (!set)
    {
        return ERROR;
    }

    free(set->ids);
    free(set);

    return OK;
}

Status set_add_element_to_set(Set *set, Id id) {
    int i;

    /* Error control*/
    if (!set || id == NO_ID) {
        return ERROR;
    }

    // Verifica si ya existe el id en el set
    for (i = 0; i < set->n_ids; i++) {
        if (set->ids[i] == id) {
        return OK;
        }
    }

    set->n_ids++; // suma 1 a set->n_ids
    set->ids = (Id *)realloc(set->ids, sizeof(Id) * set->n_ids); // vuelve a reservar memoria

    /* Error control*/
    if (!set->ids) {
        return ERROR;
    }

    set->ids[set->n_ids - 1] = id; // incluye el id en el conjunto set

    return OK;
}

Status set_del_element_to_set(Set *set, Id id) {
    int i, j;

    /* Error control*/
    if (set== NULL || id == NO_ID)
    {
        return ERROR;
    }

    for (i=0;i<set->n_ids;i++)
    {
        if (set->ids[i] == id)
        {
            // cambia todos los ids una posicion atras para rellenar el hueco
            for (j = i;j < set->n_ids - 1;j++)
            {
                set->ids[j] = set->ids[j+1];
            }
            set->n_ids--;

            // en caso de que no quede ningun id
            if (set->n_ids == 0) {
                free(set->ids);
                set->ids = NULL;
                return OK;
            }

            // rereserva de memoria con control de errores
            set->ids = (Id *)realloc(set->ids, sizeof(Id) * set->n_ids);
            if (set->ids == NULL) {
                return ERROR;
            }            
            return OK;
        }
    }

    return ERROR;
}

Bool set_find(Set* set, Id id) {
    
    int i;

    if (set == NULL || id == NO_ID)
    {
        return NO_ID;
    }

    for (i=0;i<set->n_ids; i++)
    {
        if (set->ids[i] == id)
        {
            return TRUE;
        }
    }
    
    return FALSE;
}

/**
 * @brief Gets an element from the set by its position
 */
Id set_get_element(Set *set, int i) {
  if (set == NULL || i < 0 || i >= set->n_ids) {
    return NO_ID;
  }

  return set->ids[i];
}

int set_get_n_elements(Set *set) {
    if (set == NULL)
    {
        return ERROR;
    }

    return set->n_ids;
}


Status set_print(Set *set) {
  int i;

  if (set == NULL) {
    return ERROR;
  }

  printf("Set has %d elements:\n", set->n_ids);
  for (i = 0; i < set->n_ids; i++) {
    printf("%ld\n", set->ids[i]);
  }
  return OK;
}