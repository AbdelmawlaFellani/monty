#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

typedef unsigned int uint;

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
	void (*f)(stack_t **stack, uint line_number);
} instruction_t;

/**
 * struct global_s - global variables for Monty interpreter
 * @fp: file pointer to Monty bytecode file
 * @line: line buffer for getline
 * @len: line length for getline
 * @nread: number of characters read by getline
 * @line_number: current line number in Monty bytecode file
 * @stack: pointer to top of stack
 * @format: Format of the data (stack or queue)
 *
 * Description: global variables for Monty interpreter
 */
typedef struct global_s
{
	FILE *fp;
	char *line;
	size_t len;
	ssize_t nread;
	uint line_number;
	stack_t *stack;
} global_t;

extern global_t data;

instruction_t *get_opcodes(void);
void push_f(stack_t **stack, uint line_number);
void pall_f(stack_t **stack, uint line_number);
void pint_f(stack_t **stack, uint line_number);
void pop_f(stack_t **stack, uint line_number);
void add_f(stack_t **stack, uint line_number);
void swap_f(stack_t **stack, uint line_number);
void nop_f(stack_t **stack, uint line_number);

int is_number(char *str);
void (*get_op_func(char *opcode))(stack_t **stack, uint line_number);
stack_t *add_node(stack_t **head, const int n);
void free_stack(stack_t **head);
stack_t *add_node_end(stack_t **head, const int n);
void tokenize_line(void);
#endif /* MONTY_H */
