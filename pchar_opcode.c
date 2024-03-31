#include "monty.h"


/**
 * print_char - Prints the character at the top of the stack.
 * @head: Pointer to the top of the stack.
 * @line_number: Line number where the operation is called.
 * This function prints the character at the top of the stack.
 * If the stack is empty or
 * the value is out of the ASCII range, it prints an error message
 * and exits the program.
 */
void print_char(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	/*Set the current pointer to point to the top of the stack*/
	current = *head;

	/*Check if the stack is empty*/
	if (!current)
	{
		/*Print error message and exit if stack is empty*/
		fprintf(stderr, "L%d: can't pchar, stack is empty\n", line_number);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*Check if the value is out of the ASCII range*/
	if (current->n > 127 || current->n < 0)
	{
		/*Print error message and exit if value is out of range*/
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*Print the character at the top of the stack*/
	printf("%c\n", current->n);
}
