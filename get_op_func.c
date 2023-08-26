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
		{"pop", _pop},
		{"pall", _pall},
		{"pint", _pint},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"nop", _nop},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
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
