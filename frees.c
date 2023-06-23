#include "monty.h"
/**
 * free_stack - frees up the monty stack
 * @monty_stack: stack to be freed
 */
void free_stack(stack_t *monty_stack)
{
	stack_t *current_element = monty_stack, *next_element = NULL;

	if (current_element == NULL)
		return;
	if ((current_element->next == NULL && globals.mode == 0) ||
	(current_element->prev == NULL && globals.mode == 1))
	{
		free(current_element);
		return;
	}
	if (globals.mode == 1)
	{
		while (current_element->prev)
			current_element = current_element->prev;
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
