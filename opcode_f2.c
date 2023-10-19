/**
 * swap - swaps the top two elements of a stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void swap(stack_t **stack, uint line_number)
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
 * nop - does nothing
 * @stack: pointer to the head of the stack
 * @line_number: line number of the command being run
 */
void nop(stack_t **stack, uint line_number)
{
	(void)stack;
	(void)line_number;
}
