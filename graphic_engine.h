/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
 * @brief It creates a new graphic engine, initializing the screen and areas
 * @author Profesores PPROG
 * * This function allocates memory for the engine and initializes the screen
 * layout, including the dimensions for the map and command feedback areas.
 * * @return a pointer to the new graphic engine, or NULL if an error occurs
 */
Graphic_engine *graphic_engine_create();

/**
 * @brief It destroys a graphic engine and frees its allocated memory
 * @author Profesores PPROG
 * * This function destroys the individual screen areas, stops the screen 
 * management system, and frees the engine structure.
 * * @param ge a pointer to the graphic engine to be destroyed
 */
void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It paints the current game state on the screen
 * @author Profesores PPROG
 * * This function updates all screen areas based on the current state of the 
 * game, including the player's location, the object's position, the map 
 * connections, and the last command executed.
 * * @param ge a pointer to the graphic engine
 * @param game a pointer to the game structure containing the information to paint
 */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif

