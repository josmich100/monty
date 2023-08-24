#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **st, unsigned int ln);
} instruction_t;


void (*get_op_func(char *str))(stack_t **st, unsigned int ln);
void _push(stack_t **st, unsigned int ln, char *val);
void _pop(stack_t **st, unsigned int ln);
void _pint(stack_t **st, unsigned int ln);
void _pall(stack_t **st, unsigned int ln);
void _swap(stack_t **st, unsigned int ln);
void _nop(stack_t **st, unsigned int ln);
void _pchar(stack_t **st, unsigned int ln);
void _pstr(stack_t **st, unsigned int ln);
void _rotl(stack_t **st, unsigned int ln);
void _rotr(stack_t **st, unsigned int ln);
void _stack(stack_t **st, unsigned int ln);
void _queue(stack_t **st, unsigned int ln);

/* calc funcs */
void _add(stack_t **st, unsigned int ln);
void _sub(stack_t **st, unsigned int ln);
void _mul(stack_t **st, unsigned int ln);
int _div_op(int a, int b, unsigned int ln);
void _div(stack_t **st, unsigned int ln);
void _mod(stack_t **st, unsigned int ln);

/* file handling */
int _process_file(FILE *file);
void free_stack(stack_t **stack);
int _atoi(char *s);

#endif /* MONTY_H */