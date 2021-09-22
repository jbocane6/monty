#include "monty.h"

/**
 * sizeOfArgc - Check if received the correct number of args.
 * @argc: Argument counter.
 */
void sizeOfArgc(int argc)
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * checkIfOpen - Check if file is valid.
 * @fp: File received.
 * @filename: Name of the file.
 */
void checkIfOpen(FILE *fp, char *filename)
{
	if (!fp)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * isFail - check if got a fail.
 * @line: line to be free
 * @fp: file stream to get close
 * @head: head of the stack
 */
void isFail(char *line, FILE *fp, stack_t *head)
{
	if (stackQueueError[2] == 1)
	{
		free(line);
		fclose(fp);
		freeStack(head);
		exit(EXIT_FAILURE);
	}
}

/**
 * opcodeIsNull - Check if there is not function on get_opt_function
 * @opcode: opcode function pointer
 * @nOfLine: line number
 * @strOpcode: command given
 */
void opcodeIsNull(void (*opcode)(), int nOfLine, char *strOpcode)
{
	if (!opcode)
	{
		printf("L%d: unknown instruction %s\n", nOfLine, strOpcode);
		stackQueueError[2] = 1;
	}
}
