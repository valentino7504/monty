#include "monty.h"
/**
 * mod_op - mods the value at the top of the stack
 * @stack: the stack to be changed
 * @line_number: the line number
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL || (((*stack)->next == NULL && globals.mode == 0)
	|| (((*stack)->prev == NULL) && globals.mode == 1)))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	if (globals.mode == 1)
	{
		while (current->prev)
			current = current->prev;
	}
	if ((current)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	if (globals.mode == 0)
	{
		current = (*stack)->next;
		current->n %= (*stack)->n;
	}
	else
	{
		current = current->next;
		current->n %= current->prev->n;
	}
	pop_op(stack, line_number);
}
/**
 * pchar_op - prints the value at the top of the stack
 * @stack: the stack to be printed from
 * @line_number: the line number
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	if (globals.mode == 1)
	{
		while (current->prev)
			current = current->prev;
	}
	if ((current)->n < 0 || (current)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (current)->n);
}
/**
 * pstr_op - prints the stack as a string
 * @stack: the stack to be printed from
 * @line_number: the line number
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_element = *stack;

	(void) line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	if (globals.mode == 1)
	{
		while (current_element->prev)
			current_element = current_element->prev;
	}
	while (current_element != NULL)
	{
		if (current_element->n <= 0 || current_element->n > 127)
			break;
		printf("%c", current_element->n);
		current_element = current_element->next;
	}
	printf("\n");
}
/**
 * rotl_op - rotates stack to the top
 * @stack: the stack
 * @line_number: the line number
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_element = *stack;
	int temp;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = (*stack)->n;
	while (current_element->next != NULL)
	{
		current_element->n = current_element->next->n;
		current_element = current_element->next;
	}
	current_element->n = temp;
}
/**
 * rotr_op - rotates stack to the bottom
 * @stack: the stack
 * @line_number: the line number
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_element = *stack;
	int temp;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current_element->next != NULL)
		current_element = current_element->next;
	temp = current_element->n;
	while (current_element->prev != NULL)
	{
		current_element->n = current_element->prev->n;
		current_element = current_element->prev;
	}
	(*stack)->n = temp;
}
