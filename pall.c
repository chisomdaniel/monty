#include "monty.h"

/**
 * pall - prints all the value on the stack,
 * starting from the top of the stack.
 * If the stack is empty, nothing is printed
 *
 * @stack: a pointer to the head of the stack
 * @line_number: this is an unused argument
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *next;

	(void)line_number;
	tail = *stack;
	if (stack == NULL)
		return;
	while (tail != NULL)
	{
		if (tail->next == NULL)
			break;
		tail = tail->next;
	}

	next = tail;
	while (next != NULL)
	{
		printf("%d\n", next->n);
		next = next->prev;
	}
}
