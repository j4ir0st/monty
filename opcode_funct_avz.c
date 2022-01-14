#include "monty.h"

/**
 * fsub - Prints the enviroment
 * @: pointer of structure
 */

void fsub(stack_t **stack, unsigned int line_number)
{
	int resta;

        if((*stack)->next == NULL)
        {
                fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
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
 * fdiv - Prints the enviroment
 * @: pointer of structure
 */

void fdiv(stack_t **stack, unsigned int line_number)
{
	int div;

        if((*stack)->next == NULL)
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
 * fmul - Prints the enviroment
 * @: pointer of structure
 */

void fmul(stack_t **stack, unsigned int line_number)
{
	int mul;

        if((*stack)->next == NULL)
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
 * f1mod - Prints the enviroment
 * @: pointer of structure
 */

void f1mod(stack_t **stack, unsigned int line_number)
{
	int mod;

        if((*stack)->next == NULL)
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
