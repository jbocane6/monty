#include "monty.h"

/**
 * _rotl - Rotates the stack to the top.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	(void) line_number;
	temp = (*stack);
	if (!temp)
		return;
	temp2 = temp;

	if (temp->next)
	{
		(*stack) = (*stack)->next;
		while (temp2->next)
			temp2 = temp2->next;
		temp2->next = temp;
		temp->prev = temp2;
		temp->next->prev = NULL;
		temp->next = NULL;
	}
}

/**
 * _rotr - Rotates the stack to the bottom.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	(void) line_number;
	temp = (*stack);
	if (!temp)
		return;
	temp2 = temp;
	if (temp->next)
	{
		while (temp2->next)
			temp2 = temp2->next;
		temp2->prev->next = NULL;
		temp2->prev = NULL;
		temp2->next = temp;
		temp->prev = temp2;
		(*stack) = temp2;
	}
}

/**
 * _stack - Sets the format of the data to a stack (LIFO)
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * _queue - Sets the format of the data to a queue (FIFO).
 * @stack: Head of the stack.
 * @line_number: Line number. of the opcode
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
