#include "monty.h"


/**
 * set_stack_mode - Sets the stack mode.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called. (Unused)
 * This function sets the mode of the stack to 'stack',
 * where elements are added and removed
 * from the top of the stack.
 */
void set_stack_mode(stack_t **head, unsigned int counter)
{
	/*Set the stack mode*/
	(void)head; /*Unused parameter*/
	(void)counter; /*Unused parameter*/
	shared_info.lifi = 0;
}



/**
 * set_queue_mode - Sets the queue mode.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called. (Unused)
 * This function sets the mode of the stack to
 * 'queue', where elements are added to
 * the end of the stack and removed from the top.
 */
void set_queue_mode(stack_t **head, unsigned int counter)
{
	/*Set the queue mode*/
	(void)head; /* Unused parameter*/
	(void)counter; /* Unused parameter*/
	shared_info.lifi = 1;
}




/**
 * add_queue - Adds a new node to the end of the stack.
 * @head: Pointer to the top of the stack.
 * @n: Value to be added to the new node.
 * This function adds a new node with the given value to
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *current;

	/*Assign the current head to the current pointer*/
	current = *head;

	/*Allocate memory for the new node*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}

	/*Assign the value to the new node*/
	new_node->n = n;
	new_node->next = NULL;

	/*If the stack is not empty, traverse to the end*/
	if (current)
	{
		while (current->next)
		{
			current = current->next;
		}
	}

	/*If the stack is empty, make the new node the head*/
	if (!current)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	/*If the stack is not empty, add the new node to the end*/
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}
