#include "monty.h"

/**
 * fstack - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void fstack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	st_q = false;
}

/**
 * fqueue - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_number: number of the line in the file
 */

void fqueue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	st_q = true;
}
