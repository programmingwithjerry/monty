#include "monty.h"


/**
 * rotate_right - Rotates the stack to the right.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
 * This function rotates the stack to the right, with the
 * last element becoming the top element
 * and all other elements moving down one position.
 * If the stack is empty or contains only one element,
 * it does nothing.
 */
void rotate_right(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head, *last_element;

	/*Check if stack is empty or contains only one element*/
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/*Traverse to the last element in the stack*/
	while (current->next != NULL)
	{
		current = current->next;
	}

	/*Set last_element pointer to the last element in the stack*/
	last_element = current;

	/*Make the last element become the new top of the stack*/
	last_element->next = *head;
	last_element->prev->next = NULL;
	last_element->prev = NULL;
	(*head)->prev = last_element;
	(*head) = last_element;
}
