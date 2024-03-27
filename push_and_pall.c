#include "monty.h"

/**
 * my_push_func - Function to push an integer onto a stack
 * @stack: Pointer to the stack
 * @line_num: The line number in the input file
 */


void my_push_func(stack_t **stack, unsigned int line_num)
{
	int integer_to_push;
	int i = 0;
	int flag = 0;

	if (!bus.arg)
	{
		flag = 1; /*Treat missing argument as invalid*/
	}
	else
	{
		for (; bus.arg[i] != '\0'; i++)
		{
			if (!isdigit(bus.arg[i]))
			{
				flag = 1; /*Non-digit character found*/
				break;
			}
		}
	}

	if (flag)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		if (bus.arg)
			free(bus.arg);
		if (bus.file)
			fclose(bus.file);
		if (bus.content)
			free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	integer_to_push = atoi(bus.arg);
	if (bus.life_cycle == 0)
		addnode(stack, integer_to_push);
	else
		addqueue(stack, integer_to_push);
}
