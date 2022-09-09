#define _GNU_SOURCE
#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - the main funtion
 *
 * @argc: number of arguments entered
 * @argv: arguments entered
 *
 * Return: 0 on success, or EXIT_FAILURE on error
 */

int main(int argc, char **argv)
{
	char *buf = malloc(1), **opcode = NULL;
	size_t j;
	FILE *stream;
	int line = 0, n;
	void (*op)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;

	check_input(argc);
	stream = fopen(argv[1], "r");
	check_file(stream, argv[1]);

	while (1)
	{
		n = getline(&buf, &j, stream);
		if (n == -1)
			break;
		line++;
		/*opcode = array(buf);*/
		opcode = split_string(buf, " \n\t");
		if (opcode[0] == NULL)
		{
			freestr(opcode);
			continue;
		}
		op = getcom(opcode, line);

		if (isnum(opcode[1]))
			op(&stack, atoi(opcode[1]));
		else if (ifsingle(opcode[0]))
			op(&stack, 0);
		else
		{
			printf("L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	freestr(opcode);
	free(buf);
	fclose(stream);

	return (0);
}

/**
 * ifsingle - checks if the command doesn't need an argument,
 * like an integer
 *
 * @opcode: the command to check
 *
 * Return: 1 if found, or 0 if not a single command
 */
int ifsingle(char *opcode)
{
	char *singlecode[] = {"pall", "pint", "nop", NULL};
	int i = 0;

	if (opcode == NULL)
		return (0);
	while (singlecode[i] != NULL)
	{
		if (strcmp(opcode, singlecode[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * check_input - checks to ensure the program is run
 * with the correct number of command line input
 *
 * @argc: the number of input passed
 */

void check_input(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_file - checks to ensure no error
 * occured while opening the file
 *
 * @stream: the file stream, or NULL if error occured
 * @file: the name of the file
 */
void check_file(FILE *stream, char *file)
{
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
}
