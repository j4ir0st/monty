#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>

#define _GNU_SOURCE

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
 
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int match(stack_t **tok, char *tok_0, unsigned int line_count);
void fpush(stack_t **stack, unsigned int line_number);
void fpall(stack_t **stack, unsigned int line_number);
void fpint(stack_t **stack, unsigned int line_number);
void fpop(stack_t **stack, unsigned int line_number);
void fswap(stack_t **stack, unsigned int line_number);
void fadd(stack_t **stack, unsigned int line_number);
void fnop(stack_t **stack, unsigned int line_number);
void fsub(stack_t **stack, unsigned int line_number);
void fdiv(stack_t **stack, unsigned int line_number);
void fmul(stack_t **stack, unsigned int line_number);
void f1mod(stack_t **stack, unsigned int line_number);
void fpchar(stack_t **stack, unsigned int line_number);
void fpstr(stack_t **stack, unsigned int line_number);
void frotl(stack_t **stack, unsigned int line_number);
void frotr(stack_t **stack, unsigned int line_number);
int check_isnumber(char *is_number);
void _free(stack_t **stack);

extern int val;
extern bool c_arg;
extern char *token[];
extern FILE *fp;

#endif
