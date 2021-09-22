#include "monty.h"

/**
 * checkIfEmpty - Checks if a string is empty
 * @str: string to check
 * Return: 1 if empty, 0 otherwise
 */
int checkIfEmpty(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * tokenize - Tokenize command and any arguments
 * @str: line to parse
 * @tokens: buffer to fill
 * Return: 1 if success, 0 if failed
 */
int tokenize(char *str, char *tokens[])
{
	int i, status;
	char *token;

	token = strtok(str, " \t\n");
	status = isCommented(&token);
	if (status == 1)
		return (0);

	for (i = 0; token && i < 2; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n");
	}
	return (1);
}

/**
 * pushArgs - Verifies if opcode push and its value are entered.
 * @lineToken: line received.
 * @nOfLine: Number of line.
 */
void pushArgs(char *lineToken[], int nOfLine)
{
	if (lineToken[1] && lineToken[1][0] && isNumber(lineToken[1]))
		stackQueueError[0] = atoi(lineToken[1]);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", nOfLine);
		stackQueueError[2] = 1;
	}
}

/**
 * clearString - Reset strings in an array
 * @tokens: array of strings
 */
void clearString(char *tokens[])
{
	if (strcmp(tokens[0], "push") == 0)
		tokens[1][0] = '\0';
	tokens[0][0] = '\0';
}

/**
 * isCommented - Checks if line is comment and changes it accordingly
 * @token: pointer to token string
 * Return: 1 if comment, 0 if not a comment
 */
int isCommented(char **token)
{
	if (*token[0] == '#')
	{
		*token[0] = '\0';
		return (1);
	}
	return (0);
}
