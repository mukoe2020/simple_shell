#include "shell.h"

/**
  * exec_args - Uses execve and fork to create processes to execute commands
  * @tokens_made: double pointer to commands/tokens
  * Return: 0 if sucessful or bring out an error message for failure
  */
int exec_args(char **tokens_made)
{
  int condition;
  char *cmd;
  pid_t ourchild;

  ourchild = fork();

  if (tokens_made[0] == NULL)
  {
    return (1);
  }

  if (ourchild == -1)
  {
    write(STDERR_FILENO, "child process failed to be createdn", 35);
    return (1);
  }

  if (!ourchild)
  {
    cmd = tokens_made[0];
    if (commandExists(cmd)) /* Check if the command exists */
    {
      if (execve(cmd, tokens_made, environ) == -1)
      {
        perror("Error");
        return (0);
      }
    }
    else
    {
      char errorMessage[100];
      size_t len;

      /* Construct the error message */
      strcpy(errorMessage, "Command not found: ");
      strcat(errorMessage, cmd);
      strcat(errorMessage, "n");
      len = strlen(errorMessage);
      
      write(STDERR_FILENO, errorMessage, len);
      return (0);
    }
  }
  else
  {
    wait(&condition);
  }
  return (-1);
}

