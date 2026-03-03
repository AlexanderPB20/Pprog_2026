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
 * @brief It loads the spaces of a game from a filename
 * @author Alexander Preciado
 *
 * @param game a pointer to the structure of the game where the spaces are loaded
 * @param filename a pointer to char with the name of the file that contains the spaces data
 * @return OK if the spaces are loaded correctly, ERROR otherwise.
 */
Status game_reader_load_spaces(Game *game, char *filename);
/**
 * @brief It loads the objects of a game from a filename
 * @author Alexander Preciado
 *
 * @param game a pointer to the structure of the game where the objects are loaded
 * @param filename a pointer to char with the name of the file that contains the objects data
 * @return OK if the objects are loaded correctly, ERROR otherwise.
 */

Status game_reader_load_objects(Game *game, char *filename);

#endif


