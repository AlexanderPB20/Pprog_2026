/**
 * @brief It defines the game update interface
 *
 * @file game.h
 * @author Samuel Manzorro
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "game.h"
#include "types.h"

/**
 * @brief Updates the game state based on user input
 * @author Samuel Manzorro
 * @param game Pointer to the game structure
 * @param cmd Pointer to the command structure containing user input
 * @return OK if the update was successful, ERROR otherwise
 */
Status game_actions_update(Game *game, Command *cmd);

#endif
