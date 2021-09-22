#include "monty.h"

/**
 * _push - Pushes an element to the stack.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (stackQueueError[1] == 0)
		n = addStack(stack, stackQueueError[0]);
	else
		n = addQueue(stack, stackQueueError[0]);
	if (n < 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		stackQueueError[2] = 1;
		return;
	}
}

/**
 * _pall - Prints all the values on the stack, starting from the top.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	temp = (*stack);
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - print value at top of stack followed by new line
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

	new_stack = *stack;
	if (!new_stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		stackQueueError[2] = 1;
		return;
	}
	printf("%d\n", new_stack->n);
}

/**
 * _pop - Removes the top element of the stack.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		stackQueueError[2] = 1;
		return;
	}
	temp = (*stack);
	if (temp->next == NULL)
	{
		free(temp);
		(*stack) = NULL;
		return;
	}
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * _swap - Swaps the top two elements of the stack.
 * @stack: Head of the stack.
 * @line_number: Line number.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;
	int temp_value;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		stackQueueError[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp_value = temp->n;
	temp->n = temp2->n;
	temp2->n = temp_value;
}
