#include "monty.h"


/**
 * swap_top_elements - Swaps the values of the top two elements in the stack.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
 */
void swap_top_elements(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int stack_length = 0, temp;

	/*Set the current_node to point to the top of the stack */
	current_node = *head;
	/*Count the number of nodes in the stack */
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	/*Check if the stack contains less than two elements */
	if (stack_length < 2)
	{
		/*Print error message and exit if stack is too short */
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Reset current_node to point to the top of the stack */
	current_node = *head;
	/*Swap the values of the top two elements */
	temp = current_node->n;
	current_node->n = current_node->next->n;
	current_node->next->n = temp;
}
