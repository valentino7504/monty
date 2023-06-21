#include "monty.h"
globals global;
/**
 * main - this is the main monty interpreter function
 * @argc: the number of command line arguments
 * @argv: the command line arguments
 * Return: 0 if successful or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	stack_t *monty_stack;
	unsigned int line_no = 1;
	char *opcode;
	FILE *file;
	size_t n = 0;

	monty_stack = NULL;
	if (argc != 2)
		generic_error("USAGE: monty file\n", monty_stack);
	file = fopen(argv[1], "r");
	if (file == NULL)
		file_error(argv[1]);
	while ((getline(&global.line, &n, file)) != -1)
	{
		global.instruction = NULL;
		opcode = strtok(global.line, " \t\n");
		check_opcode(opcode, line_no, monty_stack);
		global.instruction = process_instruction(opcode, monty_stack);
		global.instruction->f(&monty_stack, line_no);
		line_no++;
		free_instruction();
	}
	free_stack(monty_stack);
	fclose(file);
	free_line();
	return (0);
}
