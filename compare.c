#include "monty.h"

/**
 * isNumber - Checks if a string contains only numbers.
 * @str: string received.
 * Return: 1 if there are only numbers, 0 if not.
 */
int isNumber(char *str)
{
	int i;

	if (str && *str == '-')
		str++;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}

/**
 * isAscii - Validates if contains an ascii value.
 * @c: Char received.
 * Return: 1 if it's an ascii value, 0 if it fails.
 */
int isAscii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
