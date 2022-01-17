#include "monty.h"

/**
 * match - Matches the input with the stored string
 * @stack: double linked list - stack
 * @tok_0: pointer to structure
 * @line_count: line of command being executed
 * Return: the result of the functions called or -1 on failure
 */

int match(stack_t **stack, char *tok_0, unsigned int line_count)
{
	int pos = 0, s_c = 0;

	instruction_t match_store[] = {
		{"push", fpush},
		{"pall", fpall},
		{"pint", fpint},
		{"pop", fpop},
		{"swap", fswap},
		{"add", fadd},
		{"nop", fnop},
		{"sub", fsub},
		{"div", fdiv},
		{"mul", fmul},
		{"mod", f1mod},
		{"pchar", fpchar},
		{"pstr", fpstr},
		{"rotl", frotl},
		{"rotr", frotr},
		{"stack", fstack},
		{"queue", fqueue},
		{NULL, NULL}};
	while (match_store[pos].opcode)
	{
		s_c = strcmp(tok_0, match_store[pos].opcode);
		if (s_c == 0)
		{
			match_store[pos].f(stack, line_count);
			return (1);
		}
		pos++;
	}
	return (0);
}
