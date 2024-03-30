#include "monty.h"


/**
 * remove_top_element - Removes the top element from the stack.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
 */
void remove_top_element(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	/*Check if the stack is empty */
	if (*head == NULL)
	/*Print error message and exit if the stack is empty */
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*Set the current_node to point to the top element */
	current_node = *head;

	/*Move the head pointer to the next element */
	*head = current_node->next;
	/*Free the memory of the removed top node */
	free(current_node);
}
