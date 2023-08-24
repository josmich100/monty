#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void swap(stack_t **st, unsigned int ln)
{
	int tmp;

	if (*st == NULL || (*st)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	tmp = (*st)->n;
	(*st)->n = (*st)->next->n;
	(*st)->next->n = tmp;
}

/**
 * add - Adds the top two elements of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void add(stack_t **st, unsigned int ln)
{
	if (*st == NULL || (*st)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	(*st)->next->n += (*st)->n;
	pop(st, ln);
}

/**
 * nop - Doesn't do anything.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void nop(stack_t **st, unsigned int ln)
{
	(void)st; /* Unused parameter */
	(void)ln; /* Unused parameter */
	/* This function intentionally does nothing. */
}

/**
 * sub - Subtracts the top element of the stack from the second top element.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void sub(stack_t **st, unsigned int ln)
{
	if (*st == NULL || (*st)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	(*st)->next->n -= (*st)->n;
	pop(st, ln);
}
