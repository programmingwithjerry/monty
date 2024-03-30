#include "monty.h"

/**
 * perform_multiplication - Multiplies the top two elements in the stack.
 * @head: Pointer to the top of the stack.
 * @line_number: Line number where the operation is called.
 */
void perform_multiplication(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	int length = 0, product;

	/*Set the current pointer to point to the top of the stack*/
	current = *head;

	/* Count the number of nodes in the stack*/
	while (current)
	{
		current = current->next;
		length++;
	}
	/*Check if the stack contains less than two elements*/
	if (length < 2)
	{
		/* Print error message and exit if stack is too short*/
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Reset current pointer to point to the top of the stack*/
	current = *head;
	/* Calculate the product of the top two elements*/
	product = current->next->n * current->n;

	/*Update the second top element with the product*/
	current->next->n = product;

	/*Move the head to the second top element*/
	*head = current->next;

	/*Free the memory of the removed top element*/
	free(current);
}
