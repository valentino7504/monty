#include "monty.h"
/**
 * pall_op - prints all values in the stack
 * @stack: the monty stack
 * @line_no: the line number
 */
void pall_op(stack_t **stack, unsigned int line_no)
{
	stack_t *current_element = *stack;

	if (*stack == NULL)
		return;
	while (current_element)
	{
		printf("%d\n", current_element->n);
		current_element = current_element->next;
	}
	(void) line_no;
}
/**
 * push_op - pushes to the monty stack
 * @stack: the monty stack
 * @line_no: the line number
 */
void push_op(stack_t **stack, unsigned int line_no)
{
	stack_t *new_element;
	char *argument;
	int n;

	argument = strtok(NULL, " \t\n");
	if (_isdigit(argument) != 0 || argument == NULL)
		push_error(line_no, *stack);
	n = atoi(argument);
	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
		generic_error("Error: malloc failed\n", *stack);
	new_element->n = n;
	if (*stack != NULL)
		(*stack)->prev = new_element;
	new_element->next = *stack;
	new_element->prev = NULL;
	*stack = new_element;
}
/**
 * pint_op - prints the value at the top of the stack
 * @stack: the stack to be printed from
 * @line_number: the line number
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop_op - pops the value at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (current->next == NULL)
	{
		free(current);
		*stack = NULL;
	}
	else
	{
		*stack = current->next;
		(*stack)->prev = NULL;
		free(current);
	}
}
/**
 * swap_op - prints the value at the top of the stack
 * @stack: the stack to be printed from
 * @line_number: the line number
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *next;
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	next = current->next;
	temp = current->n;
	current->n = next->n;
	next->n = temp;
}
