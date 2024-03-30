#include "monty.h"

/**
 * add_node_to_stack - Adds a new node to the top of the stack.
 * @head: Pointer to the pointer to the top of the stack.
 * @value: Value to be added to the new node.
 * This function creates a new node, assigns the given value to it,
 * and adds it to the top of the stack.
 */
void add_node_to_stack(stack_t **head, int value)
{
	stack_t *new_node, *auxiliary;

	auxiliary = *head;

	/*Allocate memory for the new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	/*Update the previous pointer of the existing top node if it exists*/
	if (auxiliary)
		auxiliary->prev = new_node;

	/*Assign the value and update pointers of the new node*/
	new_node->n = value;
	new_node->next = *head;
	new_node->prev = NULL;
	/*Update the head pointer to point to the new node*/
	*head = new_node;
}
