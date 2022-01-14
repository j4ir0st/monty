#include "monty.h"

/**
 * fpchar - Prints the enviroment
 * @: pointer of structure
 */

void fpchar(stack_t **stack, unsigned int line_number)
{
	if(*stack == NULL)
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
 * fpstr - Prints the enviroment
 * @: pointer of structure
 */

void fpstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
        
        if(*stack == NULL)
        {
                printf("\n");
        }
        while (tmp != NULL)
	{
		if(tmp->n == 0 || !__isascii(tmp->n))
                {
                        break;
                }
                printf("%c\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * frotl - Prints the enviroment
 * @: pointer of structure
 */

void frotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
        int tmp_v;
        
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
 * frotr - Prints the enviroment
 * @: pointer of structure
 */

void frotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
        int tmp_v;
        
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
