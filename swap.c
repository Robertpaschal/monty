#include "monty.h"
/**
 * swap - Swaps the top two elemnts of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the script
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
