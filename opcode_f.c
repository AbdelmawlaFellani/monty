#include "monty.h"

/**
 * push_f - pushes an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 * Return: void
 */
void push_f(stack_t **stack, uint line_number)
{
	int val;
	char *arg;

	arg = strtok(NULL, " \n\t");
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = atoi(arg);
	add_node(stack, val);

}
/**
 * pall_f - prints all the values on stack, starting from the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 * Return: void
 */
void pall_f(stack_t **stack, uint line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint_f - prints the value at the top of stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 * Return: void
 */
void pint_f(stack_t **stack, uint line_number)
{
	
	if (!*stack)
	{
		fprintf(stderr,"L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
        
	printf("%d\n", (*stack)->n);
}
/**
 * pop_f - removes the top element of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 * Return: void
 */
void pop_f(stack_t **stack, uint line_number)
{
	stack_t *temp;

        if (!*stack)
        {
                fprintf(stderr,"L%d: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
/**
 * add_f - adds the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void add_f(stack_t **stack, uint line_number)
{
	int sum;
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n = sum;

	free(temp);
}
