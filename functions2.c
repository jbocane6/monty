#include "monty.h"

/**
 * _nop - Doesn’t do anything.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * addStack - adds the node to the beginning of the stack
 * @head: head of the stack
 * @n: number value for the stack
 * Return: 1 if success and -1 if fail
 */
int addStack(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (1);
}

/**
 * addQueue - adds the nodes to the end of the queue
 * @head: head of the queue
 * @n: number value for the queue
 * Return: 1 if success and -1 if fail
 */
int addQueue(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	return (1);
}

/**
 * _pchar - Prints the char at the top of the stack, followed by a new line.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int c;
	stack_t *temp;

	temp = (*stack);
	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		stackQueueError[2] = 1;
		return;
	}
	c = temp->n;
	if (!(isAscii(c)))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		stackQueueError[2] = 1;
		return;
	}
	printf("%c\n", c);
}

/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int c;

	(void) line_number;
	temp = (*stack);
	while (temp && temp->n != 0 && isAscii(temp->n))
	{
		c = temp->n;
		printf("%c", c);
		temp = temp->next;
	}
	printf("\n");
}
