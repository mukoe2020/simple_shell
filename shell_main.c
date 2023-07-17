#include "shell.h"

/**
  * loop_ourshell - Loops shell and implements functions
  * until ctrl + d is entered
  * Return: void
  */
void loop_ourshell(void)
{
	int condition = 1;
	char *linebuf = NULL;
	char **tokens_made;

	do {
		linebuf = read_command();
		if (linebuf == NULL)
		{
			free(linebuf);
			break;
		}
		tokens_made = token_maker(linebuf);
		condition = exec_args(tokens_made);

		free(linebuf);
		free(tokens_made);

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
	loop_ourshell();

	return (0);
}

