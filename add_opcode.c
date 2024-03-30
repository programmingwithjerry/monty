#include "monty.h"

/**
 * add_top_two_elements - Adds the values of the top two elements in the stack.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
 * Return: Nothing
 */

void add_top_two_elements(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int stack_length = 0, sum;

	current_node = *head;

	/*Count the number of nodes in the stack*/
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}

	/*Check if there are at least two elements in the stack*/
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Reset the current_node to the head of the stack*/
	current_node = *head;
	/*Calculate the sum of the top two elements*/
	sum = current_node->n + current_node->next->n;

	/*Update the second element with the sum*/
	current_node->next->n = sum;

	/* Move the head to the next element*/
	*head = current_node->next;

	/* Free the memory of the removed top node*/
	free(current_node);
}
