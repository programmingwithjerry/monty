#include "monty.h"


/**
 * print_top_stack - Prints the value at the top of the stack.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
 */
void print_top_stack(stack_t **head, unsigned int counter)
{
	/*Check if the stack is empty */
	if (*head == NULL)
	{
		/*Print error message and exit if the stack is empty */
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*Print the value of the top element in the stack */
	printf("%d\n", (*head)->n);
}
