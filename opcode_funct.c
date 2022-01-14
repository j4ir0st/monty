#include "monty.h"

/**
 * fpush - Creates a new element of the stack
 * @stack: pointer of structure
 * @line_number: number line of command being executed
 */

void fpush(stack_t **stack, unsigned int line_number)
{
	stack_t *new_st = NULL;

	if (c_arg == false)
	{
		fprintf(stderr, "L%i: usage: push integer\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	new_st = malloc(sizeof(stack_t));
	if (!new_st)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		(*stack)->prev = new_st;
	}
	new_st->n = val;
	new_st->next = *stack;
	new_st->prev = NULL;
	*stack = new_st;
}

/**
 * fpall - Prints all the stack
 * @stack: pointer to double linked list
 * @line_number: number line of command being executed
 */

void fpall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * fpint - Prints the top the stack
 * @stack: pointer to double linked list
 * @line_number: number line of command being executed
 */

void fpint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

/**
 * fpop - Prints the enviroment
 * @stack: pointer to double linked list
 * @line_number: number line of command being executed
 */

void fpop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
