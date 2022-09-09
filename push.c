#include "monty.h"

/**
 * push - add a new element to the end of a list
 *
 * @stack: a pointer to the head of the linked list
 * @line_number: the number to be added
 *
 * Return: None
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tail = *stack;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->next = NULL;

	while (*stack != NULL && tail->next != NULL)
		tail = tail->next;

	new->prev = tail;
	if (*stack == NULL)
		*stack = new;
	else
		tail->next = new;
}
