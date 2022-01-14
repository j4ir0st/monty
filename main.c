#include "monty.h"

int val = 0;
bool c_arg = false;
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

	if (get_file(argc, (argc == 2) ? argv[1] : NULL) == -1)
		return (EXIT_FAILURE);
	while (line != EOF)
	{
		line = getline(&line_buf, &line_buf_size, fp);
		if (line == EOF)
			break;
		token[0] = strtok(line_buf, "\n "), token[1] = strtok(NULL, "\n ");
		if (!token[0] || strncmp(token[0], "#", 1) == 0)
			continue;
		if (token[1])
		{
			if (check_isnumber(token[1]))
			{
				c_arg = true, val = atoi(token[1]);
			}
			else
				c_arg = false;
		}
		else
			c_arg = false;
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
	printf("\n"), fclose(fp), _free(&stack), free(*token);
	return (0);
}
