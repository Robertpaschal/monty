#include "monty.h"
/**
 * push - adds to the top of the stack
 * @stack: the whole list to which a new one is added
 * @line_number: the part from hwere the new one is added
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument;
	int value;
	stack_t *new_node;

	argument = strtok(NULL, " \t\n");

	if (!argument || !is_integer(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(argument);

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
