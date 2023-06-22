#include "monty.h"
/**
 * nop_op - prints the value at the top of the stack
 * @stack: the stack to be printed from
 * @line_number: the line number
 */
void nop_op(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * add_op - prints the value at the top of the stack
 * @stack: the stack to be printed from
 * @line_number: the line number
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->next;
	current->n += (*stack)->n;
	pop_op(stack, line_number);
}
/**
 * sub_op - subs the value at the top of the stack
 * @stack: the stack to be changed
 * @line_number: the line number
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->next;
	current->n -= (*stack)->n;
	pop_op(stack, line_number);
}
/**
 * div_op - divs the value at the top of the stack
 * @stack: the stack to be changed
 * @line_number: the line number
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->next;
	current->n /= (*stack)->n;
	pop_op(stack, line_number);
}
/**
 * mul_op - muls the value at the top of the stack
 * @stack: the stack to be changed
 * @line_number: the line number
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	current = (*stack)->next;
	current->n *= (*stack)->n;
	pop_op(stack, line_number);
}
