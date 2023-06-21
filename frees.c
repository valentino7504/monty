#include "monty.h"
/**
 * free_stack - frees up the monty stack
 * @stack: the stack to be freed up
 */
void free_stack(stack_t *stack)
{
	stack_t *current_element = stack, *next_element = NULL;

	if (stack == NULL)
		return;
	if (stack->next == NULL)
	{
		free(current_element);
		return;
	}
	next_element = current_element->next;
	while (next_element)
	{
		next_element = current_element->next;
		free(current_element);
		current_element = next_element;
	}
}
/**
 * free_instruction - frees up the instruction variable
 */
void free_instruction(void)
{
	if (global.instruction)
	{
		free(global.instruction->opcode);
		free(global.instruction);
	}
}
/**
 * free_line - frees up the line
 */
void free_line(void)
{
	if (global.line)
	{
		free(global.line);
	}
}
/**
 * _strdup - copies a string
 * @str: the string to copy
 * Return: NULL or a pointer to the string
 */
char *_strdup(char *str)
{
	int length;
	int i = 0;
	char *copy;

	if (str == NULL)
	{
		return (NULL);
	}
	length = strlen(str);
	copy = malloc((sizeof(char) * length) + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	for (i = 0; i <= length; i++)
	{
		copy[i] = str[i];
	}
	return (copy);
}
