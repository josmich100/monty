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
	stack_t *new_node = malloc(sizeof(stack_t));

	if (val == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		exit(1);
	}

	value = _atoi(val);
	if (value == 0 && val[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		exit(1);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(1);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *st;

	if (*st)
		(*st)->prev = new_node;

	*st = new_node;
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
		exit(1);
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
		exit(1);
	}

	printf("%d\n", (*st)->n);
}
