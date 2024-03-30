#include "monty.h"


/**
 * rotate_left - Rotates the stack to the left.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
 * This function rotates the stack to the left, with the
 * top element becoming the last element
 * and all other elements moving up one position. If the
 * stack is empty or contains only one element,
 * it does nothing.
 */
void rotate_left(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current = *head, *second_element;

	/*Check if stack is empty or contains only one element*/
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/*Set second_element pointer to the second element in the stack*/
	second_element = (*head)->next;
	second_element->prev = NULL;

	/*Traverse to the last element in the stack*/
	while (current->next != NULL)
	{
		current = current->next;
	}

	/*Make the last element point to the old top of the stack*/
	current->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current;

	/*Update head to point to the second element*/
	(*head) = second_element;
}
