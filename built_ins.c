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
