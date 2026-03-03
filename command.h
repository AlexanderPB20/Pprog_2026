/**
 * @brief It defines the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2
#define N_CMD 7

typedef enum { CMDS, CMDL } CommandType;

typedef enum { NO_CMD = -1, UNKNOWN, EXIT, NEXT, BACK, TAKE, DROP } CommandCode;

typedef struct _Command Command;

/**
 * @brief It creates a new command, allocating memory and initializing its code
 * @author Profesores PPROG
 *
 * @return a pointer to the new command, or NULL if there was an error
 */
Command* command_create();

/**
 * @brief It destroys a command, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param command a pointer to the command that must be destroyed
 * @return OK if everything goes well, or ERROR if the command is NULL
 */
Status command_destroy(Command* command);

/**
 * @brief It sets the code of a given command
 * @author Profesores PPROG
 *
 * @param command a pointer to the command
 * @param code the new CommandCode to be set
 * @return OK if the code was set, or ERROR if the command is NULL
 */
Status command_set_code(Command* command, CommandCode code);

/**
 * @brief It gets the code of a given command
 * @author Profesores PPROG
 *
 * @param command a pointer to the command
 * @return the code of the command, or NO_CMD if the command is NULL
 */
CommandCode command_get_code(Command* command);

/**
 * @brief It reads the user input and identifies the corresponding command code
 * @author Profesores PPROG
 *
 * This function uses a string-to-code mapping to translate the user input
 * into a valid CommandCode (e.g., 'e' or 'exit' becomes EXIT).
 *
 * @param command a pointer to the command structure where the code will be stored
 * @return OK if the input was processed, or ERROR if the command is NULL
 */
Status command_get_user_input(Command* command);

#endif
