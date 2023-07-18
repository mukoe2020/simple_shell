#include "shell.h"
/**
  * token_maker - Uses strtok to create individual tokens from user input
  * @linebuf: pointer to user's input string
  * Return: tokens generated
  */
char **token_maker(char *linebuf)
{
	size_t buf_s = CMD_LEN, station = 0;
	char **individual_tok_space = malloc(buf_s * sizeof(char *));
	char *tok;
	char *linebuf_clone = strdup_func(linebuf);

	if (linebuf == NULL || individual_tok_space == NULL || linebuf_clone ==
			NULL)
	{
		perror("No space allocated");
		exit(EXIT_FAILURE);
	}

	tok = strtok(linebuf_clone, TOK_DEL);

	while (tok != NULL)
	{
		individual_tok_space[station] = strdup_func(tok);
		if (individual_tok_space[station] == NULL)
		{
			perror("No space allocated");
			exit(EXIT_FAILURE);
		}
		station++;
		if (station >= buf_s)
		{
			buf_s += CMD_LEN;
			individual_tok_space = custom_realloc(
individual_tok_space, buf_s * sizeof(char *), buf_s * sizeof(char *));
			if (individual_tok_space == NULL)
			{
				perror("No space allocated");
				exit(EXIT_FAILURE);
			}
		}
		tok = strtok(NULL, TOK_DEL);
	}
	individual_tok_space[station] = NULL;
	free(linebuf_clone);
	return (individual_tok_space);
}


/**
  * custom_realloc -  Responsible for reallocating memory
  * @ptr: pointer to new block of memory
  * @old_s: old size
  * @new_s: new size
  * Return: pointer to new memory block if sucessful
  */
void *custom_realloc(void *ptr, unsigned int old_s, size_t new_s)
{
	char *relo, *clone;
	unsigned int m;

	if (ptr != NULL)
		clone = ptr;
	else
	{ return (malloc(new_s)); }
	if (new_s == old_s)
		return (ptr);
	if (new_s == 0 && ptr != NULL)
	{ free(ptr);
		return (0); }
	relo = malloc(new_s);
	if (relo == NULL)
		return (NULL);
	for (m = 0; m < old_s && m < new_s; m++)
	{
		*(relo + m) = clone[m];
	}
	free(ptr);
	return (relo);
}
