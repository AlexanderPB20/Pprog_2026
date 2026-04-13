/**
 * @brief It implements the inventory module
 *
 * @file inventory.c
 * @author Alexander Preciado
 * @version 0
 * @date 23-03-2026
 * @copyright GNU Public License
 */

 #include "inventory.h"

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

struct _Inventory {
    Set* objs; /*!< The set of objects contained in the backpack */       
    int max_objs; /*!< The maximum number of objects a player can take */
};


Inventory * inventory_create(){

    Inventory * newinv = NULL;

    newinv = (Inventory*)malloc(sizeof(Inventory));
    if (!newinv)
    {
       return NULL;
    }

    newinv->max_objs = MAX_OBJS;

    newinv->objs = set_create();
    if (newinv->objs == NULL)
    {
        return NULL;
    }
    
    return newinv;
}


Status inventory_destroy(Inventory* inv){

    if (!inv)
    {
        return ERROR;
    }

    if (set_destroy(inv->objs) == ERROR)
    {
        return ERROR;
    }

    free(inv);
    inv = NULL;
    return OK;
}

Id inventory_get_object_id(Inventory *inventory, int i) {
    Id element = NO_ID;
    
    if (!inventory || i<0){
        return NO_ID;
    }

    element = set_get_element(inventory->objs, i);

    return element;
}

Status inventory_set_max_objs(Inventory* inv, int max_objs){

    if (!inv || max_objs < 0)
    {
        return ERROR;
    }
    
    inv->max_objs = max_objs;
    return OK;
}

Status inventory_set_setofobjs(Inventory* inv, Set* objs){

    if (!inv || objs == NULL)
    {
        return ERROR;
    }

    inv->objs = objs;
    return OK;
}

int inventory_get_max_objs(Inventory* inv){

    if (!inv || inv->max_objs < 0)
    {
        return -1;
    }

    return inv->max_objs;
}

Set* inventory_get_set_of_objs(Inventory* inv){

    if (!inv || inv->objs == NULL)
    {
        return NULL;
    }
    
    return inv->objs;
}

Status inventory_remove_object(Inventory* inv, Id obj){
    if (!inv || obj < 0)
    {
        return ERROR;
    }
    
    return set_del_element_to_set(inv->objs, obj);
}

Bool inventory_has_object(Inventory* inv, Id obj){

    if (!inv || obj < 0)
    {
        return FALSE;
    }

    return set_find(inv->objs, obj);
}

Status inventory_add_object(Inventory* inv, Id obj){

    if (!inv || inventory_get_n_objects(inv) >= inv->max_objs)
    {
        return ERROR;
    }

    return set_add_element_to_set(inv->objs, obj);

}

int inventory_get_n_objects(Inventory *inv) {
    int count, i;
    
    if (!inv)
    {
        return -1;
    }

    for (i = count = 0; i < inv->max_objs; i++)
    {
        if (set_get_element(inv->objs, i) != NO_ID)
        {
            count ++;
        }
    }

    return count;
}

Status inventory_print(Inventory* inv){

    if (!inv || inv->objs == NULL || inv->max_objs < 0)
    {
        return ERROR;
    }
    
    if (set_print(inv->objs)==ERROR)
    {
        return ERROR;
    }

    if(fprintf(stdout,"--> Max objects:\n   %d",inv->max_objs) < 0)
    {
        return ERROR;
    }

    return OK;
}
