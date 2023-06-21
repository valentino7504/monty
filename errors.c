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
 * @monty_stack: the stack
 */
void generic_error(char *message, stack_t *monty_stack)
{
	free_stack(monty_stack);
	fprintf(stderr, "%s", message);
	if (file)
		fclose(file);
	exit(EXIT_FAILURE);
}
/**
 * push_error - prints push error
 * @line_no: the line number
 * @monty_stack: the monty stack
 */
void push_error(unsigned int line_no, stack_t *monty_stack)
{
	free_stack(monty_stack);
	fprintf(stderr, "L%u: usage: push integer\n", line_no);
	fclose(file);
	exit(EXIT_FAILURE);
}
