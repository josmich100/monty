#include "monty.h"

/**
 * _stack - Sets the format of the data to a stack (LIFO).
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void _stack(stack_t **st, unsigned int ln)
{
	(void)st; /* Unused parameter */
	(void)ln; /* Unused parameter */
	/* No action needed as stack is the default behavior. */
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void _queue(stack_t **st, unsigned int ln)
{
	stack_t *last;
	(void)ln; /* Unused parameter */

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