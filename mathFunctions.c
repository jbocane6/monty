#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @stack: head of the stack.
 * @line_number: Line number.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	if (!(*stack) || !(*stack)->next)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		stackQueueError[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp->next->n + temp->n;
	temp->next = temp2->next;
	if (temp2->next)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * _sub - Subtracts the top element of the stack from the 2nd top element.
 * @stack: Head of the stack.
 * @ln: Line number.
 */
void _sub(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if (!(*stack) || !(*stack)->next)
	{
		printf("L%d: can't sub, stack too short\n", ln);
		stackQueueError[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n - temp->n;
	temp->next = temp2->next;
	if (temp2->next)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * _div - Divides the second top element of the stack by the top element.
 * @stack: Head of the stack.
 * @ln: Line number.
 */
void _div(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if (!(*stack) || !(*stack)->next)
	{
		printf("L%d: can't div, stack too short\n", ln);
		stackQueueError[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		stackQueueError[2] = 1;
		return;
	}
	temp->n = (int)(temp2->n / temp->n);
	temp->next = temp2->next;
	if (temp2->next)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * _mul - Multiplies the 2nd top element of the stack with the top element.
 * @stack: Head of the stack.
 * @ln: Line number.
 */
void _mul(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if (!(*stack) || !(*stack)->next)
	{
		printf("L%d: can't mul, stack too short\n", ln);
		stackQueueError[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n * temp->n;
	temp->next = temp2->next;
	if (temp2->next)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * _mod - Computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * @stack: Head of the stack.
 * @ln: Line number.
 */
void _mod(stack_t **stack, unsigned int ln)
{
	stack_t *temp, *temp2;

	if (!(*stack) || !(*stack)->next)
	{
		printf("L%d: can't mod, stack too short\n", ln);
		stackQueueError[2] = 1;
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", ln);
		stackQueueError[2] = 1;
		return;
	}
	temp->n = temp2->n % temp->n;
	temp->next = temp2->next;
	if (temp2->next)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}
