#include "monty.h"

/**
 * fpchar - Prints the top of linked list as char
 * @stack: double pointer of head of linked list
 * @line_number: number of the actual line
 */

void fpchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	if (!__isascii((*stack)->n))
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * fpstr - Prints the entire linked list as string
 * @stack: double pointer of head of linked list
 * @line_number: number of the actual line
 */

void fpstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		printf("\n");
	}
	while (tmp != NULL)
	{
		if (tmp->n == 0 || !__isascii(tmp->n))
		{
			break;
		}
		printf("%c\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * frotl - Throws the top value to the tail of the linked list
 * @stack: double pointer of head of linked list
 * @line_number: number of the actual line
 */

void frotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int tmp_v;
	(void)line_number;

	if (!(*stack))
	{
		return;
	}
	tmp = *stack;
	tmp_v = tmp->n;
	while (tmp->next)
	{
		tmp->n = tmp->next->n;
		tmp = tmp->next;
	}
	tmp->n = tmp_v;
}

/**
 * frotr - Gets the value of tail the top of the linked list
 * @stack: double pointer of head of linked list
 * @line_number: number of the actual line
 */

void frotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int tmp_v;
	(void)line_number;

	if (!(*stack))
	{
		return;
	}
	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp_v = tmp->n;
	tmp->n = tmp_v;
}
