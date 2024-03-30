#include "monty.h"

/**
 * perform_no_operation - Does nothing.
 * @head: Pointer to the top of the stack.
 * @counter: Line number where the operation is called.
 * This function does nothing and is used as a placeholder for
 * the "nop" opcode.
 * It takes two parameters: `head`, a pointer to the top of the stack, and
 * `counter`, the line number where the operation is called.
 */
void perform_no_operation(stack_t **head, unsigned int counter)
{
	/* Do nothing*/
	(void)head;
	(void)counter;
}
