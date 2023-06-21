#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: the integer
 * @prev: points to the previous element in the stack
 * @next: points to the next element in the stack
 *
 * Description: doubly linked list data structure
 * for stacks, queues, LIFO and FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern stack_t *monty_stack;
char *_strdup(char *str);
void free_instruction(void);
void file_error(char *file_name);
void generic_error(char *message);
void call_opcode(char *opcode, unsigned int line_no);
instruction_t *process_instruction(char *opcode, stack_t *stack);
void free_line(void);
int _isdigit(char *argument);
void pall_op(stack_t **stack, unsigned int line_number);
void push_op(stack_t **stack, unsigned int line_number);
void push_error(unsigned int line_no);
void free_stack(void);
#endif
