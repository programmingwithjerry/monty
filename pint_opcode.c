#include "monty.h"
/**
 * my_pint_func - This is the entry point
 * @stack:This is the stack head
 * @line_num:This is The line_number
*/
void my_pint_func(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		my_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
