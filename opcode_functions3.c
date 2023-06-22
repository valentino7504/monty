#include "monty.h"
/**
 * mod_op - mods the value at the top of the stack
 * @stack: the stack to be changed
 * @line_number: the line number
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->next;
	current->n %= (*stack)->n;
	pop_op(stack, line_number);
}
