#include "monty.h"

#undef TEST_MODE

/**
 * array - a function to split the string into an array of commands
 *
 * @line: the line, wuth is the string
 *
 * Didn't use this function in the main file eventually
 *
 * Return: a pointer to the array, this needs to be freed
 */

char **array(char *line)
{
	char **code;
	int count = 0, i = 0, j = 0, k;

	code = malloc(sizeof(char *) * 3);
	code[0] = code[1] = code[2] = NULL;

	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\n') /* count each word */
			count++;

		/*allocate storage for each word*/
		if ((line[i] == ' ' || line[i] == '\n') && count > 0)
		{
			if (j > 1) /* ensure the array is not greater than 2 */
				break;
			code[j] = malloc(sizeof(char) * count + 1);
			count = 0;
			j++;
		}
		i++;
	}

	/* fill in each word into the code array */
	for (i = 0, j = 0, k = 0; line[i] != '\0' && j <= 1; i++)
	{
		if (line[i] != ' ' && line[i] != '\n') /* for each word found */
		{
			code[j][k] = line[i];
			k++;
		}
		if (line[i] == ' ' && k > 0) /* after each word */
		{
			code[j][k] = '\0';
			j++;
			k = 0;
		}
	}

	return (code);
}

/**
 * freearr - a function that frees all the array in the above function
 *
 * @code: the string to be freed
 *
 * Return: nothing
 */
void freearr(char **code)
{
	int i = 0;

	while (code[i] != NULL)
	{
		free(code[i]);
		i++;
	}
	free(code);
}


#ifdef TEST_MODE

/**
 * main - a main function to test the above functions
 *
 * @argc: number of arguments entered
 * @argv: arguments entered
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char **buf;
	int i = 0;

	buf = array(argv[1]);
	while (buf[i] != NULL)
	{
		printf("%s\n", buf[i]);
		i++;
	}

	freearr(buf);
	return (0);
}

#endif
