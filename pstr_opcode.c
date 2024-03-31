#include "monty.h"


/**
 * print_ascii_characters - Prints the string from the top of
 * the stack to the end, terminated by a new line.
 * @stack_head: Pointer to the head of the stack.
 * @line_number: The line number where the operation is called.
 * Return: No return value.
 */



void print_ascii_characters(stack_t **stack_head, unsigned int line_number)
{
	/* Declare variables */
	stack_t *current;
	/* Unused parameter (line_number) */
	(void)line_number;

	/* Set current_node to the head of the stack */
	current = *stack_head;

	/* Iterate through the stack and print ASCII characters */
	while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}

	/* If the stack is empty, print a newline and return */
	if (current == NULL)
	{
		printf("\n");
		return;
	}

	printf("\n");
}
