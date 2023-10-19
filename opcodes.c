#include "monty.h"

/**
 * get_opcodes - Get the list of supported opcodes and their functions
 * Return: A pointer to the array of opcode structures.
 */
instruction_t *get_opcodes(void)
{
	static instruction_t opcodes[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		/**
		 * {"pop", pop_f},
		 * {"add", add_f},
		 * {"sub", sub_f},
		 * {"mul", mul_f},
		 * {"div", div_f},
		 * {"swap", swap_f},
		 * {"mod", mod_f},
		 */
		{NULL, NULL}
	};
	return (opcodes);
}
/**
 * get_opcode_func - pointer to the function of the given opcode
 * @opcode: opcode string
 * Return: pointer to the corresponding function
 * or NULL if not found
 */
void (*get_opcode_func(char *opcode))(stack_t **stack, uint line_number)
{
	int i;
	instruction_t *opcodes = get_opcodes();

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			return (opcodes[i].f);
		}
	}
	return (NULL);
}
/**
 * tokenize_line - tokenizes the line provide on the monty file
 * Return: void
 */
void tokenize_line(void)
{
	char *opcode;
	void (*opcode_func)(stack_t **stack, uint line_number);

	opcode = strtok(data.line, " \n\t");
	if (opcode == NULL || opcode[0] == '#')
		return;

	opcode_func = get_opcode_func(opcode);
	if (opcode_func == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				data.line_number, opcode);
		exit(EXIT_FAILURE);
	}
	opcode_func(&data.stack, data.line_number);
}
