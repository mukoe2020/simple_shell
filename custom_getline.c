#include "shell.h"
/**
 * our_getline - Reads input from a file stream
 * @line_buf: Pointer to the buffer that stores the input
 * @buffer_size: Pointer to the size of the buffer
 * @input_stream: File stream to read input from
 * Return: Number of bytes read from the file stream
 */
ssize_t our_getline(char **line_buf, size_t *h, FILE *input_stream)
{
	static char buf[SIZE_B];
	ssize_t position_b = 0, buf_size = 0;
	char **new_line_buf;
	size_t read_c, new_s;
	char c;
	*h = SIZE_B;
	new_s = 0;
	read_c = 0;

	if (*line_buf == NULL || h == 0)
	{
		*line_buf = malloc(SIZE_B);
		if (*line_buf == NULL)
		{
			free(line_buf);
			return (-1);
		}
	}
	while (1)
	{
		if (position_b >= buf_size)
		{
			buf_size = read(fileno(input_stream), buf, SIZE_B);
			position_b = 0;
			if (buf_size == 0)
			{
				if (read_c == 0)
				{
					return (-1);
				}
				else
				{
					break;
				}
			}
		}
		c = buf[position_b++];
		(*line_buf)[read_c++] = c;
		if (c == '\n')
		{
			break;
		}
		if (read_c >= *h - 1)
		{
			*h += SIZE_B;
			new_s = *h + SIZE_B;
			new_line_buf = realloc(*line_buf, new_s);
			if (new_line_buf == NULL)
			{
				free(new_line_buf);
				return (-1);
			}
			*line_buf = *new_line_buf;
		}
	}
	(*line_buf)[read_c] = '\0';
	return (read_c);
}
