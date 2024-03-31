#include "monty.h"

/**
*push_integer - Inserts a new node containing the
*specified integer onto the stack.
*@head: Pointer to the top of the stack.
*@counter: Line number at which the operation is invoked.
*Return: This function does not return any value.
*/

void push_integer(stack_t **head, unsigned int counter)
{
	int number, j = 0, flag = 0;

	/*Check if bus.arg is not NULL*/
	if (shared_info.arg)
	{
		if (shared_info.arg[0] == '-')
			j++;
		/*Check if the argument is a valid integer*/
		for (; shared_info.arg[j] != '\0'; j++)
		{
			if (shared_info.arg[j] > 57 || shared_info.arg[j] < 48)
				flag = 1;
		}
		/* Error if argument is not a valid integer*/
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(shared_info.file);
			free(shared_info.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*Error if no argument provided*/
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(shared_info.file);
		free(shared_info.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	number = atoi(shared_info.arg);
	/*Add node to the stack or queue based on bus.lifi*/
	if (shared_info.lifi == 0)
		add_node_to_stack(head, number);
	else
		add_queue(head, number);
}




/**
 * print_stack - Prints all elements in the stack.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called (unused).
 * unsigned int counter
 */
void print_stack(stack_t **head, unsigned int counter)
{
	stack_t *current;

	(void)counter; /*Unused parameter, simply to satisfy compiler*/

	current = *head;

	/* Check if the stack is empty*/
	if (current == NULL)
		return;

	/* Iterate through the stack and print each element*/
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

