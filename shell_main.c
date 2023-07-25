#include "shell.h"

/**
  * loop_ourshell - Loops shell and implements functions
  * until ctrl + d is entered
  * @ac: number of command line arguments.
  * @argv: array of command lie arguments.
  * Return: void
  */
void loop_ourshell(int ac, char **argv)
{
	int condition = 1;
	char *linebuf = NULL;
	char **tokens_made;

	do {
		linebuf = read_command(ac, argv);
		if (linebuf == NULL)
		{
			free(linebuf);
			break;
		}
		tokens_made = token_maker(linebuf);
		condition = exec_args(tokens_made);

		free(linebuf);
		_release(tokens_made);

	} while (condition);
}

/**
  * main - runs a simple unix command line interpreter
  * @ac: number of command line arguments
  * @argv: an array of command line arguments
  * Return: the value of the last executed command
  */
int main(int ac __attribute__((unused)), char **argv __attribute__((unused)))
{
	loop_ourshell(ac, argv);

	return (0);
}

/**
  * _release - frees memory allocated for each token generated
  * @tokens_made: double pointer to array of tokens
  */

void _release(char **tokens_made)
{
	int h;

	if (tokens_made == NULL)
	{
		return;
	}

	for (h = 0; tokens_made[h] != NULL; h++)
	{
		free(tokens_made[h]);
	}
	free(tokens_made);
}
