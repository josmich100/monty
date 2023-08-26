#include "monty.h"
#include <stdlib.h>

/**
 * main - Entry point of the Monty program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 or 1.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *st = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_opcodes(file, &st);
	fclose(file);

	exit(EXIT_SUCCESS);
}
