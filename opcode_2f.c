#include "monty.h"

/**
 * swap_f - swaps the top two elements of a stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void swap_f(stack_t **stack, uint line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * nop_f - does nothing
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void nop_f(stack_t **stack, uint line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub_f - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: pointer to the head of the stack
 * @line_number: line number of the connand being run
 */
void sub_f(stack_t **stack, uint line_number)
{
	int diff;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }

	diff = (*stack)->next->n - (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = diff;

	free(temp);
}
/**
 * mul_f - multiplies the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void mul_f(stack_t **stack, uint line_number)
{
	int product;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	product = (*stack)->next->n * (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = product;
	free(temp);
}

