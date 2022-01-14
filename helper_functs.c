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

/**
 * check_isnumber - ckecks if the string represents an integer
 * @is_number: the string represents an integer
 * Return: length on success, 0 on failure
 */

int check_isnumber(char *is_number)
{
	int c = 0, i = 0;

	if (*is_number == '-')
		is_number++;
	for (i = 0; is_number != NULL && is_number[i]; i++)
	{
		if (!(is_number[i] >= '0' && is_number[i] <= '9'))
			c++;
	}
	if (c != 0)
		return (0);
	return (1);
}

/**
 * _free - Frees a dlistint_t list.
 * @stack: Double pointer to struct.
 */

void _free(stack_t **stack)
{
	if (*stack)
	{
		_free(&(*stack)->next);
	}
	free(*stack);
}

/**
 * print_error - prints type of error
 * @status: id of type of error
 * @file_name: name of file
 */

void print_error(int status, char *file_name)
{
	switch (status)
	{
	case -1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case -2:
		fprintf(stderr, "Error: Can't open file '%s'\n", file_name);
		break;
	default:
		break;
	}
}

/**
 * get_file - gets file
 * @argc: arguments
 * @file_name: file name
 * Return: 0 if success, -1 if error
 */

int get_file(int argc, char *file_name)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (-1);
	}
	fp = fopen(file_name, "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		return (-1);
	}
	return (0);
}
