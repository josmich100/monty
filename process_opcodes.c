#include "monty.h"
#include <stdlib.h>

/**
 * process_opcodes - Process Monty opcodes from a file.
 *
 * @file: Pointer to the input file.
 * @st: Pointer to the stack data structure.
 *
 * This function reads opcodes and arguments from the provided file and
 * processes them according to the Monty specification.
 */
void process_opcodes(FILE *file, stack_t **st)
{
	char line[256], *opcode, *arg;
	unsigned int ln = 0;
	void (*op_func)(stack_t **, unsigned int);

	while (fgets(line, sizeof(line), file))
	{
		ln++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			_push(st, ln, arg);
		}
		else
		{
			op_func = get_op_func(opcode);
			if (op_func)
			{
				op_func(st, ln);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
}
