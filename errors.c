#include "monty.h"
/**
 * file_error - if file does not exist
 * @file_name: the name of the file
 */
void file_error(char *file_name)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}
/**
 * generic_error - generic error
 * @message: the error message
 * @stack: the monty stack
 */
void generic_error(char *message, stack_t *stack)
{
	free_instruction();
	free_line();
	free_stack(stack);
	fprintf(stderr, "%s", message);
	exit(EXIT_FAILURE);
}
/**
 * push_error - prints push error
 * @line_no: the line number
 * @stack: the monty stack
 */
void push_error(unsigned int line_no, stack_t *stack)
{
	free_instruction();
	free_stack(stack);
	free_line();
	fprintf(stderr, "L%u: usage: push integer\n", line_no);
	exit(EXIT_FAILURE);
}
