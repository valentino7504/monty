#include "monty.h"
/**
 * queue_op - changes the stack to a queue
 * @stack: the stack
 * @line_number: the line_number
 */
void queue_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_element = *stack;

	(void) line_number;
	if (globals.mode == 1)
		return;
	globals.mode = 1;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current_element->next != NULL)
		current_element = current_element->next;
	*stack = current_element;
}
/**
 * stack_op - changes the queue to a stack
 * @stack: the stack
 * @line_number: the line_number
 */
void stack_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_element = *stack;

	(void) line_number;
	if (globals.mode == 0)
		return;
	globals.mode = 0;
	if (*stack == NULL || (*stack)->prev == NULL)
		return;
	while (current_element->prev != NULL)
		current_element = current_element->prev;
	*stack = current_element;
}
