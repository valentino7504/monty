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
	size_t n;
	char line[1024];

	monty_stack = NULL;
	if (argc != 2)
		generic_error("USAGE: monty file\n", monty_stack);
	file = fopen(argv[1], "r");
	if (file == NULL)
		file_error(argv[1]);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		n = strlen(line);
		if (n > 0 && line[n - 1] == '\n')
			line[n - 1] = '\0';
		global.line = _strdup(line);
		global.instruction = NULL;
		opcode = strtok(global.line, " \t\n");
		check_opcode(opcode, line_no, monty_stack);
		global.instruction = process_instruction(opcode, monty_stack);
		global.instruction->f(&monty_stack, line_no);
		line_no++;
		free_line();
		free_instruction();
	}
	free_stack(monty_stack);
	fclose(file);
	return (0);
}
