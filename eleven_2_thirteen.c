#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void pchar(stack_t **st, unsigned int ln)
{
	int value;

	if (*st == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	value = (*st)->n;

	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');
}

/**
 * pstr - Prints the string starting from the top of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void pstr(stack_t **st, unsigned int ln)
{
	(void)ln; /* Unused variable */
	stack_t *current = *st;

	while (current != NULL && current->n != 0
			&& (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * rotl - Rotates the stack to the top.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void rotl(stack_t **st, unsigned int ln)
{
	(void)ln; /* Unused variable */
	stack_t *last;

	if (*st == NULL || (*st)->next == NULL)
		return;

	last = *st;
	while (last->next != NULL)
		last = last->next;

	last->next = *st;
	(*st)->prev = last;

	*st = (*st)->next;
	(*st)->prev = NULL;

	last->next->next = NULL;
}

/**
 * rotr - Rotates the stack to the bottom.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void rotr(stack_t **st, unsigned int ln)
{
	(void)ln; /* Unused variable */
	stack_t *last;

	if (*st == NULL || (*st)->next == NULL)
		return;

	last = *st;
	while (last->next != NULL)
		last = last->next;

	last->next = *st;
	(*st)->prev = last;

	*st = last;
	last->prev->next = NULL;
	last->prev = NULL;
}

