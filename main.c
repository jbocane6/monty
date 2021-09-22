#include "monty.h"

int stackQueueError[3] = {0, 0, 0};
/**
 * main - Interpreter for Monty ByteCodes files.
 * @argc: Argument counter.
 * @argv: Argument vector.
 * Return: 0 if succeed.
 */
int main(int argc, char *argv[])
{
	char *path, *line, *lineToken[2];
	FILE *fp;
	void (*fptr)(stack_t **stack, unsigned int ln);
	stack_t *head;
	size_t len, nOfLine, status;
	ssize_t nread;

	head = NULL;
	line = NULL;
	sizeOfArgc(argc);
	path = argv[1];

	fp = fopen(path, "r");
	checkIfOpen(fp, path);
	for (nOfLine = 1; (nread = getline(&line, &len, fp)) != -1; nOfLine++)
	{
		if (checkIfEmpty(line))
			continue;
		status = tokenize(line, lineToken);
		if (status == 0)
			continue;
		if (strcmp(lineToken[0], "push") == 0)
			pushArgs(lineToken, nOfLine, line, fp, head);
		isFail(line, fp, head);
		stackOrQueue(lineToken[0]);
		fptr = get_opt_function(lineToken[0]);
		opcodeIsNull(fptr, nOfLine, lineToken[0]);
		isFail(line, fp, head);
		(*fptr)(&head, nOfLine);
		isFail(line, fp, head);
		clearString(lineToken);
	}
	free(line);
	fclose(fp);
	freeStack(head);

	return (0);
}
