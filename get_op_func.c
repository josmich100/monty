#include "monty.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 * asked by the opcode.
 * @str: The opcode.
 *
 * Return: A pointer to the corresponding function, or NULL if not found.
 */
void (*get_op_func(char *str))(stack_t **st, unsigned int ln)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, str) == 0)
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}
