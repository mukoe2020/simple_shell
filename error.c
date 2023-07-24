#include "shell.h"
/**
 * print_error - uses write system call to print error message when cmd is not
 * found
 * @name: name of the shell program
 * @cmd_count: number of command
 * @command: command
 * @error_msg: error message to be printed out
 */
void print_error(const char *name, int cmd_count, const char *command,
		const char *error_msg)
{
	char command_num[2];
	char newl = '\n';

	print_string(STDERR_FILENO, name);
	print_string(STDERR_FILENO, ": ");
	convert_string(cmd_count, command_num);

	print_string(STDERR_FILENO, command_num);
	print_string(STDERR_FILENO, ": ");
	print_string(STDERR_FILENO, command);
	print_string(STDERR_FILENO, ": ");
	print_string(STDERR_FILENO, error_msg);
	write(STDERR_FILENO, &newl, 1);
}

/**
 * print_string - prints a string to a specified file stream using write
 * @descriptor: stream
 * @string: string
 */
void print_string(int descriptor, const char *string)
{
	write(descriptor, string, strlen(string));
}

/**
 * convert_string - converts a string to an integer
 * @num: number
 * @string: string to be converted
 * Return: converted string
 */
void convert_string(int num, char *string)
{
	int h = 0;
	int length = 0;
	int fornow = num;

	while (fornow > 0)
	{
		fornow /= 10;
		length++;
	}

	for (h = length - 1; h >= 0; h--)
	{
		string[h] = '0' + (num % 10);
		num /= 10;
	}
	string[length] = '\0';
}
