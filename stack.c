#include "monty.h"

/**
 * stackOrQueue - Change type between stack or queue
 * @strOpcode: opcode received.
 */
void stackOrQueue(char *strOpcode)
{
	if (strcmp(strOpcode, "stack") == 0)
		stackQueueError[1] = 0;
	else if (strcmp(strOpcode, "queue") == 0)
		stackQueueError[1] = 1;
}

/**
 * freeStack - frees the stack
 * @head: head of the stack
 */
void freeStack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
