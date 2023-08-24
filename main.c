#include "monty.h"

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
	int result;
	FILE *file = fopen(argv[1], "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (1);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (1);
	}

	result = _process_file(file);

	fclose(file);
	return (result);
}