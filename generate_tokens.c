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
	char *linebuf_clone; /*a copy of input string to be tokenized */

	if (linebuf == NULL || individual_tok_space == NULL)
	{
		perror("No space allocated");
		exit(EXIT_FAILURE);
	}
	linebuf_clone = malloc(strlen(linebuf) + 1);
	if (linebuf_clone == NULL)
	{
		perror("No space allocated");
		exit(EXIT_FAILURE);
	}
	strcpy(linebuf_clone, linebuf);
	tok = strtok(linebuf_clone, TOK_DEL);

	while (tok != NULL)
	{
		individual_tok_space[station] = tok;
		station++;

		if (station >= buf_s)
		{
			buf_s += CMD_LEN;
			individual_tok_space = realloc(individual_tok_space,
					buf_s * sizeof(char *));
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
