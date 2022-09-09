#include "monty.h"

/**
 * isnum - checks if the argument string is an int or a char
 *
 * @str: the string to be checked
 *
 * Return: 1 if it is all int, or 0 if it contains a char
 */

int isnum(char *str)
{
	int i = 0;

	if (str == NULL || str[0] == '\0')
		return (0);

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			continue;
		}
		return (0);
		i++;
	}
	return (1);
}
