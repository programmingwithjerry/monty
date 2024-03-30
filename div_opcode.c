#include "monty.h"

/**
 * divide_top_two_elements - Divides the second top element by
 * the top element in the stack.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
 */
void divide_top_two_elements(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int stack_length = 0, quotient;

	/*Set the current_node to point to the top of the stack*/
	current_node = *head;
	/*Count the number of nodes in the stack*/
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	/*Check if the stack contains less than two elements*/
	if (stack_length < 2)
	{
		/* Print error message and exit if stack is too short*/
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Reset current_node to point to the top of the stack*/
	current_node = *head;
	/* Check if the top element is zero*/
	if (current_node->n == 0)
	{
		/*Print error message and exit if division by zero*/
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Calculate the quotient of the top two elements*/
	quotient = current_node->next->n / current_node->n;
	/*Update the second top element with the quotient*/
	current_node->next->n = quotient;
	/* Move the head to the second top element*/
	*head = current_node->next;
	free(current_node);
}
