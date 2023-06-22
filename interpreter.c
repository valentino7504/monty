#include "monty.h"
FILE *file;
/**
 * main - this is the main monty interpreter function
 * @argc: the number of command line arguments
 * @argv: the command line arguments
 * Return: 0 if successful or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	unsigned int line_no = 1;
	char *opcode;
	stack_t *monty_stack;
	int n;
	char line[1024];

	monty_stack = NULL;
	if (argc != 2)
		generic_error("USAGE: monty file\n", monty_stack);
	file = fopen(argv[1], "r");
	if (file == NULL)
		file_error(argv[1]);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (line[0] == '\n')
			continue;
		n = strlen(line);
		if (n > 0 && line[n - 1] == '\n')
			line[n - 1] = '\0';
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		call_opcode(opcode, line_no, &monty_stack);
		line_no++;
	}
	free_stack(monty_stack);
	fclose(file);
	return (0);
}
