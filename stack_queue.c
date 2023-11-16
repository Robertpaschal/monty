#include "monty.h"
/**
 * stack - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the script
 */
void stack_operation(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	while ((*stack)->next)
	{
		*stack = (*stack)->next;
	}
}

/**
 * queue- Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the script
 */
void queue(stack_t **stack, unsigned int line_number)
{

	stack_t *temp;

	stack_t *prev;

	(void)line_number;

	temp = *stack;
	prev = NULL;

	if (!stack || !*stack || !(*stack)->next)
		return;

	while (temp->next)
	{
		prev = temp;
		temp = temp->next;
	}

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp->next;
	temp->prev = NULL;
	prev->next = NULL;
}
