#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * free_stack - Frees the memory occupied by the stack.
 * @stack: Pointer to the top of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
