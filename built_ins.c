#include "shell.h"

/**
 * shell_exit - handles the exit command.
 *
 * Description: 'this function is responsible
 *for exiting the shell'
 *
 * Return: void
 *
 **/

void shell_exit(void)
{
	exit(0);
}

/**
 * shell_env - handles the env command.
 *
 * Description: This function prints the envronment
 * to the standard output
 *
 * Return:void
 */
void shell_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}






















/**
 * blt_matcher - a function that matches or checks for a builtin function
 * @tokens_made: pointer to user input tokenized for execution
 */
void blt_matcher(char **tokens_made)
{
	if (strcmp_alt(tokens_made[0], "exit") == 0)
	{
		shell_exit();
	}
	else if (strcmp_alt(tokens_made[0], "env") == 0)
	{
		shell_env();
	}
}
