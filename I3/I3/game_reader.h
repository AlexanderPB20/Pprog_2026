/**
 * @brief It defines the game interface
 *
 * @file game_reader.h
 * @author Samuel Manzorro
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
 * @param game a pointer to the new game
 * @param filename a string with the name of the file to be loaded
 * @return OK if everything goes well, or ERROR if there was some mistake
 */
Status game_reader_create_from_file(Game *game, char *filename);

/**
 * @brief It loads the players in the game from the filename
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param filename a string with the name of the file to be loaded
 * @return OK if the players are correctly loaded, ERROR if there was some mistake
 */
Status game_reader_load_players(Game *game, char *filename);

/**
 * @brief It loads the spaces in the game from the filename
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param filename a string with the name of the file to be loaded
 * @return OK if the spaces are correctly loaded, ERROR if there was some mistake
 */
Status game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief It loads the objects in the game from the filename
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param filename a string with the name of the file to be loaded
 * @return OK if the objects are correctly loaded, ERROR if there was some mistake
 */
Status game_reader_load_objects(Game *game, char *filename);

/**
 * @brief It loads the characters in the game from the filename
 * @author Samuel Manzorro
 *
 * @param game a pointer to the game
 * @param filename a string with the name of the file to be loaded
 * @return OK if the characters are correctly loaded, ERROR if there was some mistake
 */
Status game_reader_load_characters(Game *game, char *filename);

#endif
