#include "monty.h"
#include <stdlib.h>

/**
 * _div_op - Divides two numbers.
 *
 * @a: First operand.
 * @b: Second operand.
 * @ln: Line number in the file.
 * Return: The result of the division.
 */
int _div_op(int a, int b, unsigned int ln)
{
	if (b == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	return (a / b);
}

/**
 * _div - Divides the second top element by the top element of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void _div(stack_t **st, unsigned int ln)
{
	int a, b;

	if (*st == NULL || (*st)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	b = (*st)->n;
	_pop(st, ln);

	a = (*st)->n;
	(*st)->n = _div_op(a, b, ln);
}

/**
 * _mul - Multiplies the second top element by the top element of the stack.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void _mul(stack_t **st, unsigned int ln)
{
	if (*st == NULL || (*st)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	(*st)->next->n *= (*st)->n;
	_pop(st, ln);
}

/**
 * _mod - Computes the remainder of division.
 *
 * @st: Pointer to the stack.
 * @ln: Line number in the file.
 */
void _mod(stack_t **st, unsigned int ln)
{
	int a, b;

	if (*st == NULL || (*st)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	b = (*st)->n;
	_pop(st, ln);

	a = (*st)->n;
	if (b == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", ln);
		exit(EXIT_FAILURE);
	}

	(*st)->n = a % b;
}
