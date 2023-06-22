#include "monty.h"
/**
 * _isdigit - checks if an argument is a digit
 * @argument: the argument to be checked
 * Return: 0 if it is a digit or 0 if not
 */
int _isdigit(char *argument)
{
	int i = 0;

	if (argument[0] == '-')
		i = 1;
	while (argument[i])
	{
		if (argument[i] < 48 || argument[i] > 57)
			return (1);
		i++;
	}
	return (0);
}
/**
 * call_opcode - checks if an opcode is valid
 * @opcode: the opcode to check
 * @line_no: the line number
 * @monty_stack: the stack to be freed
 */
void call_opcode(char *opcode, unsigned int line_no, stack_t **monty_stack)
{
	instruction_t instructions[] = {{"push", push_op}, {"pall", pall_op},
	{"div", div_op}, {"pint", pint_op}, {"pop", pop_op}, {"nop", nop_op},
	{"swap", swap_op}, {"mul", mul_op}, {"add", add_op}, {"sub", sub_op},
	{NULL, NULL}};
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(monty_stack, line_no);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_no, opcode);
	free_stack(*monty_stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
