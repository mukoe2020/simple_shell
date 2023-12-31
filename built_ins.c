#include "shell.h"

/**
 * shell_exit - handles the exit command.
 *
 * Description: 'this function is responsible
 *for exiting the shell'
 *@status:represents integer value to specicify the exit status
 * Return:void
 *
 **/

void shell_exit(int status)
{
	exit(status);
}



/**
 * blt_matcher - a function that matches or checks for a builtin function
 * @tokens_made: pointer to user input tokenized for execution
 */
void blt_matcher(char **tokens_made)
{
	if (strcmp_alt(tokens_made[0], "exit") == 0)
	{
		int status = 0;

		if (tokens_made[1] != NULL)

		{
			status = atoi_alt(tokens_made[1]);
		}

		shell_exit(status);
	}

	else if (strcmp_alt(tokens_made[0], "env") == 0)
	{
		/* shell_env();*/

		return;
	}
}
