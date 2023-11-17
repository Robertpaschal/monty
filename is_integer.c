#include "monty.h"
#include <ctype.h>
/**
 * is_integer - Checks if a string is a valid intgere
 * @str: The string to check
 * Return: 1 if the string is a valid integr, 0 otherwise
 */
int is_integer(const char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (0);

	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}
