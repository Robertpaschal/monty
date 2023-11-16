#include "monty.h"
#include <ctype.h>
/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the script
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;
	current = *stack;

	while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
