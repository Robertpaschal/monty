#include "monty.h"
/**
 * pall - prints all the list from top to bottom
 * @stack: the list
 * @line_number: the specific memebrs to print out (in this case all)
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
