/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Samuel Manzorro
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _Set{
    Id *ids;   /*!< Array of ids */
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

    if (!set || id == NO_ID) {
        return ERROR;
    }

    /* Verifica si ya existe el id en el set */
    for (i = 0; i < set->n_ids; i++) {
        if (set->ids[i] == id) {
        return OK;
        }
    }

    set->n_ids++; /* Suma 1 a set->n_ids */
    set->ids = (Id *)realloc(set->ids, sizeof(Id) * set->n_ids); /* Vuelve a reservar memoria */

    if (!set->ids)
    {
        return ERROR;
    }

    set->ids[set->n_ids - 1] = id; /* Incluye el id en el conjunto set */

    return OK;
}

Status set_del_element_to_set(Set *set, Id id) {
    int i, j;

    if (set== NULL || id == NO_ID)
    {
        return ERROR;
    }

    for (i=0;i<set->n_ids;i++)
    {
        if (set->ids[i] == id)
        {
            /* Cambia todos los ids una posicion atras para rellenar el hueco */
            for (j = i;j < set->n_ids - 1;j++)
            {
                set->ids[j] = set->ids[j+1];
            }
            set->n_ids--;

            /* En caso de que no quede ningun id */
            if (set->n_ids == 0) {
                free(set->ids);
                set->ids = NULL;
                return OK;
            }

            /* Nueva reserva de memoria con control de errores */
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
        return FALSE;
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

Id set_get_element(Set *set, int i) {
  if (set == NULL || i < 0 || i >= set->n_ids)
  {
    return NO_ID;
  }

  return set->ids[i];
}

int set_get_n_elements(Set *set) {
    if (set == NULL)
    {
        return -1;
    }

    return set->n_ids;
}


Status set_print(Set *set) {
  int i;

  if (set == NULL)
  {
    return ERROR;
  }

  printf("Set has %d elements:\n", set->n_ids);
  for (i = 0; i < set->n_ids; i++) {
    printf("%ld\n", set->ids[i]);
  }

  return OK;
}