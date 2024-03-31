#include "monty.h"

/**
 * perform_modulo_operation - Computes modulo of top two elements in the stack.
 * @head: Pointer to the top of the stack.
 * @line_number: Line number where the operation is called.
 */


void perform_modulo_operation(stack_t **head, unsigned int line_number)
{
	stack_t *current_top;
	int stack_length = 0, result;

	/* Count the number of nodes in the stack */
	current_top = *head;
	while (current_top)
	{
		current_top = current_top->next;
		stack_length++;
	}
	/* Check if the stack contains at least two elements */
	if (stack_length < 2)
	{
		/* Print error message and exit if stack is too short */
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* Reset current pointer to the top of the stack */
	current_top = *head;
	/* Check if division by zero would occur */
	if (current_top->n == 0)
	{
		/* Print error message and exit if division by zero */
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* Perform modulo operation on the top two elements */
	result = current_top->next->n % current_top->n;
	current_top->next->n = result;
	/* Move the head to the second top element */
	*head = current_top->next;
	/* Free the memory of the removed top element */
	free(current_top);
}
