/**
 * @brief It defines the game interface
 *
 * @file game_reader.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
#include "types.h"


/**
 * @brief Carga los espacios de un juego desde un fichero
 * @author Alexander Preciado
 *
 * Abre el fichero indicado y lee los datos de los espacios para crearlos
 * y añadirlos a la estructura del juego[cite: 21, 92].
 *
 * @param game Puntero a la estructura del juego donde se cargarán los espacios.
 * @param filename Nombre del fichero que contiene los datos de los espacios.
 * @return OK si se cargan los espacios correctamente, ERROR en caso contrario.
 */
Status game_load_spaces(Game *game, char *filename);

/**
 * @brief Añade un espacio a la estructura del juego
 * @author Alexander Preciado
 *
 * Comprueba que el espacio no sea nulo y que no se haya superado el límite
 * máximo antes de añadirlo al array de espacios del juego.
 *
 * @param game Puntero a la estructura del juego.
 * @param space Puntero al espacio que se desea añadir.
 * @return OK si se añade con éxito, ERROR si hay fallo o el juego está lleno.
 */
Status game_add_space(Game *game, Space *space);

/**
 * @brief Obtiene el ID del espacio en una posición determinada
 * @author Alexander Preciado
 *
 * Permite acceder al identificador de un espacio basándose en su posición
 * dentro del array interno del juego.
 *
 * @param game Puntero a la estructura del juego.
 * @param position Índice del espacio en el array de espacios del juego.
 * @return Id del espacio si la posición es válida, NO_ID en caso contrario.
 */
Id game_get_space_id_at(Game *game, int position);


#endif
