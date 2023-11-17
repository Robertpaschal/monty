#include "monty.h"
#define BUFFER_SIZE 12

int _getline(char **lineptr, size_t *n, FILE *stream);
/**
 * _getline - mimicks the standard libary getline function
 * @lineptr: where the buffer is stored
 * @n: size of buffer
 * @stream: standard input
 * Return: length of the input
 */

int _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buf = BUFFER_SIZE;
	size_t length = 0;
	int c;
	char *temp;
	size_t new_size;


	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(buf);
	if (*lineptr == NULL)
	{
		return (-1);
	}
	*n = buf;
	}

	while (1)
	{
		c = fgetc(stream);

		if (c == EOF || c == '\n')
		{
			break;
		}

		if (length == *n - 1)
		{
			new_size = *n *2;
			temp = (char *)malloc(new_size);
			if (temp == NULL)
			{
				free(*lineptr);
				return (-1);
			}

			memcpy(temp, *lineptr, length);
			free(*lineptr);
			*lineptr = temp;
			*n = new_size;
		}
		
		(*lineptr)[length] = (char)c;
		length++;
	}

	if (length == 0 && c == EOF)
	{
		free(*lineptr);
		return (-1);
	}

	(*lineptr)[length] = '\0';
	return (length);
}
