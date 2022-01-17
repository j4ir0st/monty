#include "monty.h"

int val = 0;
bool c_arg = false;
bool st_q = false;
char *token[1024];
FILE *fp;

/**
 * main - Entry Point
 * @argc: number of arguments
 * @argv: string of arguments
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *line_buf = NULL;
	stack_t *stack = NULL;
	size_t line_buf_size = 0;
	int line_count = 1;
	char line = 0;

	get_file(argc, (argc == 2) ? argv[1] : NULL);
	while (line != EOF)
	{
		line = getline(&line_buf, &line_buf_size, fp);
		if (line == EOF)
			break;
		token[0] = strtok(line_buf, "\n "), token[1] = strtok(NULL, "\n ");
		if (!token[0])
		{
			line_count++;
			continue;
		}
		if (strncmp(token[0], "#", 1) == 0)
		{
			line_count++;
			continue;
		}
		exist_token(token[1]);
		if (match(&stack, token[0], line_count))
			c_arg = true;
		else
		{
			fprintf(stderr, "L%i: unknown instruction %s\n", line_count, token[0]);
			fclose(fp), _free(&stack), free(*token);
			return (EXIT_FAILURE);
		}
		line_count++;
	}
	fclose(fp), _free(&stack), free(*token);
	return (0);
}

/**
 * exist_token - Cheks if the token exists
 * @token: pointer of the token to check
 */

void exist_token(char *token)
{
	if (token)
	{
		if (check_isnumber(token))
		{
			c_arg = true, val = atoi(token);
		}
		else
		{
			c_arg = false;
		}
	}
	else
	{
		c_arg = false;
	}
}
