#include "shell.h"
/**
  * read_command - Uses getline to read input of user and handles EOF condition
  * Return: the string inputted
  */

char *read_command()
{
	char *linebuf = NULL;
	size_t m = 0;
	ssize_t getline_read;

	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "~$ ", 3);
	}

	getline_read = getline(&linebuf, &m, stdin);

	if (getline_read == -1)
	{
		free(linebuf);
		write(STDERR_FILENO, "Exiting our shell...\n", 25);
		return (NULL);
	}
	/* print prompt on newline if user taps on only enter */
	if (linebuf[0] == '\n')
	{
		free(linebuf);
		return (read_command()); /*calling function recursively*/
	}

	if (linebuf[strlen(linebuf) - 1] != '\n')
	{
		m += 2;
		linebuf = (char *) realloc(linebuf, m);
		linebuf[strlen(linebuf) - 1] = '\0';
	}

	return (linebuf);
}
