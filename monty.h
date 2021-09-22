#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int stackQueueError[];

/* sizeOfArgc - Check if received the correct number of args. */
void sizeOfArgc(int argc);
/* checkIfOpen - Check if file is valid. */
void checkIfOpen(FILE *fp, char *filename);
/* checkIfEmpty - Checks if a string is empty */
int checkIfEmpty(const char *str);
/* tokenize - Tokenize command and any arguments */
int tokenize(char *str, char *tokens[]);
/* pushArgs - Verifies if opcode push and its value are entered. */
void pushArgs(char **tok_line, int nOfLine);
/* isFail - check if got a fail. */
void isFail(char *line, FILE *fp, stack_t *head);
/* stackOrQueue - Change type between stack or queue */
void stackOrQueue(char *strOpcode);
/* get_opt_function - Selects the right function to be pointer. */
void (*get_opt_function(char *str))(stack_t **stack, unsigned int line_number);
/* opcodeIsNull - Check if there is not function on get_opt_function */
void opcodeIsNull(void (*opcode)(), int nOfLine, char *strOpcode);
/* clearString - Reset strings in an array */
void clearString(char *tokens[]);
/* freeStack - frees the stack */
void freeStack(stack_t *head);
/* isCommented - Checks if line is comment and changes it accordingly */
int isCommented(char **token);
/* isNumber - Checks if a string contains only numbers. */
int isNumber(char *str);
/* _push - Pushes an element to the stack. */
void _push(stack_t **stack, unsigned int line_number);
/* _pall - Prints all the values on the stack, starting from the top. */
void _pall(stack_t **stack, unsigned int line_number);
/* _pint - print value at top of stack followed by new line */
void _pint(stack_t **stack, unsigned int line_number);
/* _pop - Removes the top element of the stack. */
void _pop(stack_t **stack, unsigned int line_number);
/* _swap - Swaps the top two elements of the stack. */
void _swap(stack_t **stack, unsigned int line_number);
/* _add - Adds the top two elements of the stack. */
void _add(stack_t **stack, unsigned int line_number);
/* _nop - Doesn’t do anything. */
void _nop(stack_t **stack, unsigned int line_number);
/* addStack - adds the node to the beginning of the stack */
int addStack(stack_t **head, int n);
/* addQueue - adds the nodes to the end of the queue */
int addQueue(stack_t **head, int n);
/* _sub - Subtracts the top element of the stack from the 2nd top element. */
void _sub(stack_t **stack, unsigned int line_number);
/* _div - Divides the second top element of the stack by the top element. */
void _div(stack_t **stack, unsigned int line_number);
/* _mul - Multiplies the 2nd top element of the stack with the top element. */
void _mul(stack_t **stack, unsigned int line_number);
/*
 * _mod - Computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 */
void _mod(stack_t **stack, unsigned int line_number);
/* _pchar - Prints the char at the top of the stack, followed by a new line. */
void _pchar(stack_t **stack, unsigned int line_number);
/* _pstr - prints the string starting at the top of the stack, */
void _pstr(stack_t **stack, unsigned int line_number);
/* isAscii - Validates if contains an ascii value. */
int isAscii(int c);
/* _rotl - Rotates the stack to the top. */
void _rotl(stack_t **stack, unsigned int line_number);
/* _rotr - Rotates the stack to the bottom. */
void _rotr(stack_t **stack, unsigned int line_number);
/* _stack - Sets the format of the data to a stack (LIFO) */
void _stack(stack_t **stack, unsigned int line_number);
/* _queue - Sets the format of the data to a queue (FIFO). */
void _queue(stack_t **stack, unsigned int line_number);

#endif
