#include "monty.h"

/**
 * push - Pushes an element to the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 * @value_str: Value as a string to push onto the stack.
 */
void push(stack_t **st, unsigned int ln, char *value_str)
{
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (value_str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);
	if (value == 0 && value_str[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *st;

	if (*st)
		(*st)->prev = new_node;

	*st = new_node;
}

/**
 * pop - Removes the top element of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void pop(stack_t **st, unsigned int ln)
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
 * pall - Prints all the values on the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void pall(stack_t **st, unsigned int ln)
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
 * pint - Prints the value at the top of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void pint(stack_t **st, unsigned int ln)
{
	if (*st == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*st)->n);
}
