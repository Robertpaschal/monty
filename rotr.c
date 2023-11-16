#include "monty.h"
/**
 * rotr - Rotates the stack to the bottom
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the script
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	last = *stack;

	while (last->next)
		last = last->next;

	temp = last->prev;
	temp->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
