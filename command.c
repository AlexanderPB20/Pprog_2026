/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Samuel Manzorro
 * @version 0
 * @date 24-01-2026
 * @copyright GNU Public License
 */

#include "command.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}, {"l", "Left"}, {"r", "Right"}, {"t", "Take"}, {"d", "Drop"}, {"a", "Attack"}, {"c", "Chat"}};

struct _Command {
  CommandCode code; /*!< The name of the command */
  char arg[MAX_CMD_ARG][CMD_LENGTH]; /*!< Command argument */
  Status status;                     /*!< Command status */
};

Command* command_create() {
  Command* newCommand = NULL;

  newCommand = (Command*)calloc(1,sizeof(Command));
  if (newCommand == NULL)
  {
    return NULL;
  }

  newCommand->code = NO_CMD;
  newCommand->status = ERROR;

  return newCommand;
}

Status command_destroy(Command* command) {
  if (!command)
  {
    return ERROR;
  }

  free(command);
  command = NULL;

  return OK;
}

Status command_set_code(Command* command, CommandCode code) {
  if (!command)
  {
    return ERROR;
  }

  command->code=code;

  return OK;
}

CommandCode command_get_code(Command* command) {
  if (!command)
  {
    return NO_CMD;
  }

  return command->code;
}

Status command_set_arg(Command* command, char* arg, int n) {
  if (!command || !arg || n < 0 || n >= MAX_CMD_ARG)
  {
    return ERROR;
  }

  strcpy(command->arg[n], arg);

  return OK;
}

char* command_get_arg(Command *command, int n) {
  if (!command || n < 0 || n >= MAX_CMD_ARG)
  {
    return NULL;
  }

  return command->arg[n];
}

Status command_set_status(Command* command, Status status) {
  if (!command)
  {
    return ERROR;
  }

  command->status = status;

  return OK;
}

Status command_get_status(Command* command) {
  if (!command)
  {
    return ERROR;
  }

  return command->status;
}

Status command_get_user_input(Command* command) {
  char input[CMD_LENGTH] = "", *token = NULL, *arg = NULL;
  int i = UNKNOWN - NO_CMD + 1;
  CommandCode cmd;

  if (!command)
  {
    return ERROR;
  }

  if (fgets(input, CMD_LENGTH, stdin))
  {
    input[strcspn(input, "\n")] = '\0';
    token = strtok(input, " ");
    if (!token)
    {
      return command_set_code(command, UNKNOWN);
    }

    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL]))
      {
        cmd = i + NO_CMD;
      } else {
        i++;
      }
    }

    if (command_set_code(command, cmd) == ERROR)
    {
      return ERROR;
    }

    for (i = 0; i < MAX_CMD_ARG; i++)
    {
      arg = strtok(NULL, " ");
      if (!arg)
      {
        arg = "";
      }

      if (command_set_arg(command, arg, i) == ERROR)
      {
        return ERROR;
      }
    }

    return OK;
  }
  else {
    return command_set_code(command, EXIT);
  }
}
