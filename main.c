#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"

global_t data = {0};
/**
 * main - entry point for Monty interpreter
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	data.fp = fopen(argv[1], "r");
	if (data.fp == NULL)
	{
		fprintf(stderr,	"Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((data.nread = getline(&data.line, &data.len, data.fp)) != -1)
	{
		data.line_number++;
		tokenize_line();
	}
	free(data.line);
	fclose(data.fp);
	free_stack(&data.stack);
	return (0);
}
