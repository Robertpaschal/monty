#include "monty.h"
/**
 * rotl - Rotates the stack to the top
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the script
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	last = *stack;

	while (last->next)
		last = last->next;

	*stack = temp->next;
	temp->next = NULL;
	last->next = temp;
	temp->prev = last;

	if (*stack)
		(*stack)->prev = NULL;
}
