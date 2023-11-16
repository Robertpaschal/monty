#include "monty.h"
/**
 * execute_command - executes the command after parsing
 * @line: the full path of the command
 * @line_number: the command to execute
 * @stack: the location in the stack of data
 * Return: nothing
 */
void execute_command(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode;

	opcode = strtok(line, " \t\n");

	if (!opcode)
		return;

	if (strcmp(opcode, "push") == 0)
		push(stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack,line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack,line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
