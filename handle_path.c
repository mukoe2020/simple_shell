#include "shell.h"

/**
 * commandExists - Check if the command exists in the PATH directories
 * @command: The command to check
 *
 * Return: Path as a string if command exists, or an empty string if not found
 */
char *commandExists(const char *command)
{
       	char *path = getenv("PATH");
	size_t command_len, path_len;
	char *path_copy, *token;
	char fullpath[4096] = "";
	
	if (path == NULL)
		return strdup("");
	command_len = strlen(command);
	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	
	while (token != NULL)
	{
		path_len = strlen(token);
		
		if (path_len + 1 + command_len >= sizeof(fullpath))
		{
			free(path_copy);
			return strdup("");
		}
		
		strcpy(fullpath, token);
		strcat(fullpath, "/");
		strcat(fullpath, command);
		
		if (access(fullpath, F_OK) == 0)
		{
			free(path_copy);
			return strdup(fullpath);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return strdup("");
}

