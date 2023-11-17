#include "monty.h"
/**
 * mul - Multiplies the second top elemnt of the stack with the top element
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the script
 */
void mul(stack_t ** stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

