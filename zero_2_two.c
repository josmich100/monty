#include "monty.h"
#include <stdlib.h>

/**
 * _push - Pushes an element to the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 * @val: Value as a string to push onto the stack.
 */
void _push(stack_t **st, unsigned int ln, char *val)
{
	int value;
	stack_t *new_node;

	if (val == NULL || !is_integer(val))
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}

	value = _atoi(val);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;

	if (*st == NULL)
	{
		*st = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = *st;
		(*st)->prev = new_node;
		*st = new_node;
	}
}

/**
 * _pop - Removes the top element of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void _pop(stack_t **st, unsigned int ln)
{
	stack_t *temp = *st;

	if (*st == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	temp = *st;
	*st = (*st)->next;

	if (*st)
		(*st)->prev = NULL;

	free(temp);
}

/**
 * _pall - Prints all the values on the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void _pall(stack_t **st, unsigned int ln)
{
	stack_t *current = *st;
	(void) ln;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - Prints the value at the top of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void _pint(stack_t **st, unsigned int ln)
{
	if (*st == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*st)->n);
}

/**
 * is_integer - checks whether it is an integer
 *
 * @str: input to check for an integer
 *
 * Return: 0 if true and 1 if false
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	/* Skip leading signs before checking digits */
	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return 0;
		str++;
	}

	return (1);
}
