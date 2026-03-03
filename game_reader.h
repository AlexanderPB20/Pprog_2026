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
 * @brief It creates a new game from filename
 * @author Samuel Manzorro
 *
 * @param game the identification number for the new game
 * @param filename a pointer to charfilename with spaceloaded
 * @return a new game, initialized
 */
Status game_reader_create_from_file(Game *game, char *filename);

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
Status game_reader_load_spaces(Game *game, char *filename);

#endif
