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
	if (globals.mode == 1)
	{
		while (current_element->prev)
			current_element = current_element->prev;
	}
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
	if (argument == NULL)
		push_error(line_no, *stack);
	if (_isdigit(argument) != 0)
		push_error(line_no, *stack);
	n = atoi(argument);
	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
		generic_error("Error: malloc failed\n", *stack);
	new_element->n = n;
	if (globals.mode == 0)
	{
		if (*stack != NULL)
			(*stack)->prev = new_element;
		new_element->next = *stack;
		new_element->prev = NULL;
		*stack = new_element;
		return;
	}
	else
	{
		if (*stack != NULL)
			(*stack)->next = new_element;
		new_element->prev = *stack;
		new_element->next = NULL;
		*stack = new_element;
		return;
	}
}
/**
 * pint_op - prints the value at the top of the stack
 * @stack: the stack to be printed from
 * @line_number: the line number
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_element = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	if (globals.mode == 1)
	{
		while (current_element->prev)
			current_element = current_element->prev;
	}
	printf("%d\n", (current_element)->n);
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
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if ((current->next == NULL && globals.mode == 0) ||
	(current->prev == NULL && globals.mode == 1))
	{
		free(current);
		*stack = NULL;
		return;
	}
	else if (globals.mode == 0)
	{
		*stack = current->next;
		(*stack)->prev = NULL;
		free(current);
		return;
	}
	else
	{
		while (current->prev)
			current = current->prev;
		current->next->prev = NULL;
		free(current);
		return;
	}
}
/**
 * swap_op - prints the value at the top of the stack
 * @stack: the stack to be printed from
 * @line_number: the line number
 */
void swap_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *swap;
	int temp;

	if (*stack == NULL || (((*stack)->next == NULL && globals.mode == 0)
	|| (((*stack)->prev == NULL) && globals.mode == 1)))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		fclose(globals.file);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	if (globals.mode == 0)
		swap = current->next;
	else
	{
		while (current->prev->prev)
			current = current->prev;
		swap = current->prev;
	}
	temp = current->n;
	current->n = swap->n;
	swap->n = temp;
}
