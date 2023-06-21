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
 * check_opcode - checks if an opcode is valid
 * @opcode: the opcode to check
 * @line_no: the line number
 * @stack: the monty stack
 */
void check_opcode(char *opcode, unsigned int line_no, stack_t *stack)
{
	char *opcodes[] = {"push", "pall", "pint", "pop",
	"swap", "add", "nop", NULL};
	int i = 0;

	for (i = 0; opcodes[i] != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i]) == 0)
			return;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_no, opcode);
	free_stack(stack);
	free_instruction();
	free_line();
	exit(EXIT_FAILURE);
}
/**
 * process_instruction - returns an instruction pointer
 * @opcode: this is the operation
 * @stack: the monty stack
 * Return: the pointer to the required function
 */
instruction_t *process_instruction(char *opcode, stack_t *stack)
{
	instruction_t *new_instruction;

	new_instruction = malloc(sizeof(instruction_t));
	if (new_instruction == NULL)
		generic_error("Error: malloc failed\n", stack);
	new_instruction->opcode = strdup(opcode);
	if (new_instruction->opcode == NULL)
		generic_error("Error: malloc failed\n", stack);
	if (strcmp(opcode, "push") == 0)
		new_instruction->f = &push_op;
	else if (strcmp(opcode, "pall") == 0)
		new_instruction->f = &pall_op;
	else if (strcmp(opcode, "pint") == 0)
		exit(1);
	else if (strcmp(opcode, "pop") == 0)
		exit(1);
	else if (strcmp(opcode, "swap") == 0)
		exit(1);
	else if (strcmp(opcode, "add") == 0)
		exit(1);
	else if (strcmp(opcode, "nop") == 0)
		exit(1);
	return (new_instruction);
}
