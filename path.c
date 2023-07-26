#include "shell.h"
/**
 * commandExists - Check if the command exists in the PATH directories
 * @cmd: The command to check
 * Return: path of the executable if it exists
 */
char *commandExists(const char *cmd)
{
	char *path = getenv_alt("PATH");
	size_t cmd_size, path_size;
	char *path_clone, *tok;
	char fullpath[1024] = "";

	if (cmd[0] == '/' || cmd[0] == '.' || cmd[0] == '~')
	{
		if (access(cmd, F_OK) == 0) /*checks if cmd exists */
			return (strdup_func(cmd));
	}
	else
	{
		if (path == NULL)
			return (NULL);
		cmd_size = strlen_alt(cmd);
		path_clone = strdup_func(path);
		tok = alt_strtok(path_clone, ":");

		while (tok != NULL)
		{
			path_size = strlen_alt(tok);

			if (path_size + 1 + cmd_size >= sizeof(fullpath))
			{
				free(path_clone);
				return (NULL);
			}
			strcpy_alt(fullpath, tok);
			strcat_alt(fullpath, "/");
			strcat_alt(fullpath, cmd);
			if (access(fullpath, F_OK) == 0)
			{
				free(path_clone);
				return (strdup_func(fullpath));
			}
			tok = alt_strtok(NULL, ":");
		}
		free(path_clone);
	}
	return (NULL);
}
