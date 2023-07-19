#include "shell.h"

/**
 * commandExists - Check if the command exists in the PATH directories
 * @command: The command to check
 *
 * Return: 1 if command exists, 0 otherwise
 */
int commandExists(const char *command)
{
	char *path = getenv("PATH");

	if (path == NULL)
		return (0);
	size_t command_len = strlen(command);
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		size_t path_len = strlen(token);

		char *fullpath = malloc((path_len + 1 + command_len + 1) * sizeof(char));

		snprintf(fullpath, path_len + 1 + command_len + 1, "%s/%s", token, command);
		if (access(fullpath, F_OK) == 0)
		{
			free(path_copy);
			free(fullpath);
			return (1); /* Command exists in the current directory */
		}
		free(fullpath);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (0); /* Command not found in any directory */
}

