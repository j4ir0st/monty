#include "monty.h"

/**
 * add_node_end - Adds a new node at the end of a dlistint_t list.
 * @head: Double pointer to struct.
 * @new: the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */

void add_node_end(stack_t **stack, stack_t *new)
{
	stack_t *tmp = *stack;

	new->n = val;
	new->next = NULL;
	if (*stack == NULL)
	{
		new->prev = NULL;
		(*stack) = new;
		return;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->prev = tmp;
}

/**
 * add_node_beg - Adds a new node at the end of a dlistint_t list.
 * @head: Double pointer to struct.
 * @new: the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */

void add_node_beg(stack_t **stack, stack_t *new)
{
	if (*stack)
	{
		(*stack)->prev = new;
	}
	new->n = val;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}
