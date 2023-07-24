#include "shell.h"
/**
 * alt_strtok - splits string into tokens with a delimiter
 * @string: string to be used
 * @del: delimiter
 * Return: tokenized string
 */
char *alt_strtok(char *string, const char *del)
{
	char *tok;
	static char *remainder;

	if (string != NULL)
	{
		remainder = string;
	}

	if (remainder == NULL || *remainder == '\0')
	{
		return (NULL);
	}

	while (*remainder != '\0' && strchr_alt(del, *remainder) != NULL)
	{
		remainder++;
	}

	if (*remainder == '\0')
	{
		return (NULL);
	}

	tok = remainder;
	while (*remainder != '\0' && strchr(del, *remainder) == NULL)
	{
		remainder++;
	}
	if (*remainder != '\0')
	{
		*remainder = '\0';
		remainder++;
	}
	return (tok);
}

