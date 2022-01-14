#include "monty.h"

/**
 * fswap - Prints the enviroment
 * @stack: pointer to double linked list
 * @line_number: number line of command being executed
 */

void fswap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * fadd - Prints the enviroment
 * @stack: pointer to double linked list
 * @line_number: number line of command being executed
 */

void fadd(stack_t **stack, unsigned int line_number)
{
	int suma;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	suma = (*stack)->n + (*stack)->next->n;
	fpop(stack, line_number);
	(*stack)->n = suma;
}

/**
 * fnop - Prints the enviroment
 * @stack: pointer to double linked list
 * @line_number: number line of command being executed
 */

void fnop(stack_t **stack, unsigned int line_number)
{

}
