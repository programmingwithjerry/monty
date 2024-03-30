#include "monty.h"

/**
 * subtract_top_two_elements - Subtracts the top element
 * from the second top element in the stack.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
*/

void subtract_top_two_elements(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int nodes, difference;

	/*Set the current_node to point to the top of the stack*/
	current_node = *head;

	/*Count the number of nodes in the stack*/
	for (nodes = 0; current_node != NULL; nodes++)
		current_node = current_node->next;

	/* Check if the stack contains less than two elements*/
	if (nodes < 2)
	{
		/*Print error message and exit if stack is too short*/
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*Reset current_node to point to the top of the stack*/
	current_node = *head;

	/*Calculate the difference of the top two elements*/
	difference = current_node->next->n - current_node->n;

	/*Update the second top element with the difference*/
	current_node->next->n = difference;

	/*Move the head to the second top element*/
	*head = current_node->next;

	/*Free the memory of the removed top element*/
	free(current_node);
}
