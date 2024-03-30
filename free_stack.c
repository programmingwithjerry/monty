#include "monty.h"

/**
 * my_free_stack - Function to free memory allocated for a stack
 * @head: Pointer to the head of the stack
 */


void free_stack(stack_t *head)
{
	stack_t *current; /*Pointer to traverse the stack*/

	current = head; /*Initialize current pointer to the head of the stack*/
	while (head)
	{
		current = head->next; /*Store the next pointer of the current node*/
		free(head); /*Free memory allocated for the current node*/
		head = current; /*Move the head pointer to the next node*/
	}
}
