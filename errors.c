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
 */
void generic_error(char *message)
{
	free_stack();
	fprintf(stderr, "%s", message);
	exit(EXIT_FAILURE);
}
/**
 * push_error - prints push error
 * @line_no: the line number
 */
void push_error(unsigned int line_no)
{
	free_stack();
	fprintf(stderr, "L%u: usage: push integer\n", line_no);
	exit(EXIT_FAILURE);
}
