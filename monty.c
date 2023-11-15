#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "monty.h"

stack_t *stack = NULL;

/**
 * main - the main file for the opcodes
 * @argc: argument counter
 * @argv: argument variable
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	int read;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	       exit(EXIT_FAILURE);
	}

	while ((read = _getline(&line, &len, file)) != -1)
	{
		line_number++;
		execute_command(line, line_number, &stack);
	}

	fclose(file);
	free(line);

	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}

	return (0);
}
