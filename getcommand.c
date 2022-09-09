#include "monty.h"

/**
 * getcom - returns the function to carry out the appropraite command
 *
 * @arr: an array of the command and it's arguments
 * @n: the line number
 *
 * Return: on success it returns the function,
 * or exit with an eror message if command not found
 */

void (*getcom(char **arr, int n))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t opcode[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{NULL, NULL}
	};

	while (opcode[i].opcode != NULL)
	{
		if (strcmp(opcode[i].opcode, arr[0]) == 0)
		{
			return (opcode[i].f);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", n, arr[0]);
	exit(EXIT_FAILURE);

}
