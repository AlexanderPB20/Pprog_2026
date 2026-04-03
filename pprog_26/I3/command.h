/**
 * @brief It defines the command interpreter interface
 *
 * @file command.h
 * @author Samuel Manzorro
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define CMD_LENGTH 30 /*!< Maximum lenght of a command input */
#define MAX_CMD_ARG 3 /*!< Maximum arguments a command can have */
#define N_CMDT 2 /*!< Number of command types */
#define N_CMD 9 /*!< Total number of commands available */

typedef enum { CMDS, CMDL } CommandType; /*!< The command type */

typedef enum { NO_CMD = -1, UNKNOWN, EXIT, TAKE, DROP, ATTACK, CHAT, MOVE, INSPECT} CommandCode; /*!< The command code*/

typedef struct _Command Command;

/**
 * @brief It creates a new command, allocating memory and initializing its code
 * @author Samuel Manzorro
 *
 * @return a pointer to the new command, or NULL if there was an error
 */
Command* command_create();

/**
 * @brief It destroys a command, freeing the allocated memory
 * @author Samuel Manzorro
 *
 * @param command a pointer to the command that must be destroyed
 * @return OK if everything goes well, or ERROR if the command is NULL
 */
Status command_destroy(Command* command);

/**
 * @brief It sets the code of a given command
 * @author Samuel Manzorro
 *
 * @param command a pointer to the command
 * @param code the new CommandCode to be set
 * @return OK if the code was set, or ERROR if the command is NULL
 */
Status command_set_code(Command* command, CommandCode code);

/**
 * @brief It gets the code of a given command
 * @author Samuel Manzorro
 *
 * @param command a pointer to the command
 * @return the code of the command, or NO_CMD if the command is NULL
 */
CommandCode command_get_code(Command* command);

/**
 * @brief It sets the argument of a given command
 * @author Samuel Manzorro
 *
 * @param command a pointer to the command
 * @param arg the new argument to be set
 * @param n the position of the argument
 * @return OK if the code was set, or ERROR if the command is NULL
 */
Status command_set_arg(Command* command, char* arg, int n);

/**
 * @brief It gets the argument of a given command
 * @author Samuel Manzorro
 *
 * @param command a pointer to the command
 * @param n the position of the argument
 * @return the argument of the command, or NULL if the command is NULL
 */
char* command_get_arg(Command* command, int n);

/**
 * @brief It sets the status of a given command
 * @author Samuel Manzorro
 *
 * @param command a pointer to the command
 * @param status the status of the command
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status command_set_status(Command* command, Status status);

/**
 * @brief It gets the status of a given command
 * @author Samuel Manzorro
 *
 * @param command a pointer to the command
 * @return OK if the command was correctly executed, ERROR if there was some mistake
 */
Status command_get_status(Command* command);

/**
 * @brief It reads the user input and identifies the corresponding command code
 * @author Samuel Manzorro
 *
 * @param command a pointer to the command structure where the code will be stored
 * @return OK if the input was processed, or ERROR if the command is NULL
 */
Status command_get_user_input(Command* command);

#endif
