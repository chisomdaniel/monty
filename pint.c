#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * or exit with EXIT_FALIURE if stack is empty
 *
 * @stack: a pointer to the head of the stack
 * @line_number: this is an unused argument
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack, *next;

	(void)line_number;

	if (stack == NULL)
		return;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tail != NULL)
	{
		if (tail->next == NULL)
			break;
		tail = tail->next;
	}

	next = tail;

	printf("%d\n", next->n);
}

/**
 * nop - does nothing
 *
 * @stack: not used
 * @line_number: not used
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
