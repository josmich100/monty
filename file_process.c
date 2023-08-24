#include "monty.h"

/**
 * process_file - Process each line of the input file and execute instructions.
 *
 * @file: Pointer to the input file.
 *
 * Return: EXIT_SUCCESS if successful, otherwise EXIT_FAILURE.
 */
int process_file(FILE *file)
{
	stack_t st = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int ln = 0;
	char *opcode = NULL;
	void (*op_func)(stack_t **, unsigned int) = NULL;
	int result = EXIT_SUCCESS;

	while ((read = getline(&line, &len, file)) != -1)
	{
		ln++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		op_func = get_op_func(opcode);

		if (op_func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
			result = EXIT_FAILURE;
			break;
		}

		op_func(&stack, ln);
	}

	free(line);
	free_stack(&stack);
	return (result);
}
