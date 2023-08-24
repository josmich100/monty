#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * _process_file - Process each line of the input file and execute instructions.
 *
 * @file: Pointer to the input file.
 *
 * Return: 0 if successful, otherwise 1.
 */
int _process_file(FILE *file)
{
	stack_t *st = NULL;
	char *line = NULL;
	char *val;
	size_t len = 0;
	ssize_t read;
	unsigned int ln = 0;
	char *opcode = NULL;
	void (*op_func)(stack_t **, unsigned int) = NULL;
	int result = 0;

	while (fgets(line, len, file) != NULL)
	{
		ln++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		op_func = get_op_func(opcode);

		if (op_func == NULL)
		{
			if (strcmp(opcode, "push") == 0)
			{
				val = strtok(NULL, " \t\n");
				_push(&st, ln, val);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
				result = 1;
				break;
			}
		}
		else
		{
			op_func(&st, ln);
		}
	}

	free(line);
	free_stack(&st);
	return (result);
}