#include "monty.h"

/**
 * get_opt_function - Selects the right function to be pointer.
 * @str: String with name of opcode.
 * Return: NULL if didn't find the function.
 */
void (*get_opt_function(char *str))(stack_t **stack, unsigned int ln)
{

	int i;
	instruction_t opcod[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotr", _rotr},
		{"rotl", _rotl},
		{"queue", _queue},
		{"stack", _stack},
		{NULL, NULL}
	};

	i = 0;
	while (i < 17)
	{
		if (strcmp(str, (opcod[i]).opcode) == 0)
		{
			return (*(opcod[i]).f);
		}
		i++;
	}
	return (NULL);
}
