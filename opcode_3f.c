#include "monty.h"

/**
 * div_f - divides the second top element of the stack from the top element
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void div_f(stack_t **stack, uint line_number)
{
	int quotient;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = (*stack)->next->n / (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = quotient;
	free(temp);
}
/**
 * pchar_f - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void pchar_f(stack_t **stack, uint line_number)
{
	int c;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	c = (*stack)->n;

	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", c);
}
