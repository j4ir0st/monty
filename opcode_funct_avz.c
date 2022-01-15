#include "monty.h"

/**
 * fsub - Substacs the the top element from the second top element of the stack
 * @stack: double pointer of head of the linked list
 * @line_number: number of the actual line
 */

void fsub(stack_t **stack, unsigned int line_number)
{
	int resta;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	resta = (*stack)->next->n - (*stack)->n;
	fpop(stack, line_number);
	(*stack)->n = resta;
}

/**
 * fdiv - Divides the second top element by the top element of the linked list
 * @stack: double pointer of head of the linked list
 * @line_number: number of the actual line
 */

void fdiv(stack_t **stack, unsigned int line_number)
{
	int div;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->next->n / (*stack)->n;
	fpop(stack, line_number);
	(*stack)->n = div;
}

/**
 * fmul - multiplies the second top element with the top element of the stack
 * @stack: double pointer of head of the linked list
 * @line_number: number of the actual line
 */

void fmul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	mul = (*stack)->next->n * (*stack)->n;
	fpop(stack, line_number);
	(*stack)->n = mul;
}

/**
 * f1mod - Calculates the module of the second top by the top element of stack
 * @stack: double pointer of head of the linked list
 * @line_number: number of the actual line
 */

void f1mod(stack_t **stack, unsigned int line_number)
{
	int mod;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		_free(stack);
		free(*token);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	mod = (*stack)->next->n % (*stack)->n;
	fpop(stack, line_number);
	(*stack)->n = mod;
}
