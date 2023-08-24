#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>

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
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

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


void (*get_op_func(char *str))(stack_t **st, unsigned int ln);
void push(stack_t **st, unsigned int ln, const char *val);
void pop(stack_t **st, unsigned int ln);
void pint(stack_t **st, unsigned int ln);
void pall(stack_t **st, unsigned int ln);
void swap(stack_t **st, unsigned int ln);
void nop(stack_t **st, unsigned int ln);
void pchar(stack_t **st, unsigned int ln);
void pstr(stack_t **st, unsigned int ln);
void rotl(stack_t **st, unsigned int ln);
void rotr(stack_t **st, unsigned int ln);
void stack(stack_t **st, unsigned int ln);
void queue(stack_t **st, unsigned int ln);

/* calc funcs */
void add(stack_t **st, unsigned int ln);
void sub(stack_t **st, unsigned int ln);
void mul(stack_t **st, unsigned int ln);
int div_op(int a, int b, unsigned int line_number);
void div(stack_t **st, unsigned int ln);
void mod(stack_t **st, unsigned int ln);

/* file handling */
int process_file(FILE *file);

#endif /* MONTY_H */