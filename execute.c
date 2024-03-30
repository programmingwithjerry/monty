#include "monty.h"


/**
 * execute - Executes an instruction based on the given content.
 * @content: The content containing the instruction to be executed.
 * @stack: Pointer to the top of the stack.
 * @line_num: Line number where the instruction is located.
 * @file: Pointer to the file being processed.
 * This function parses the content to extract the instruction and
 * its arguments
 * and executes the corresponding function from the instruction set.
 * Return: 0 on success, 1 on failure
 */
int execute(char *content, stack_t **stack, unsigned int line_num, FILE *file)
{
	instruction_t operations[] = {
		{"push", push_integer}, {"pall", print_stack},
		{"pint", print_top_stack}, {"pop", remove_top_element},
		{"swap", swap_top_elements}, {"add", add_top_two_elements},
		{"nop", perform_no_operation}, {"sub", subtract_top_two_elements},
		{"div", divide_top_two_elements}, {"mul", multiply_top_two_elements},
		{"mod", perform_multiplication}, {"pchar", print_char},
		{"pstr", print_top_char}, {"rotl", rotate_left},
		{"rotr", rotate_right}, {"queue", set_queue_mode},
		{"stack", set_stack_mode},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *operation;

	/*Extract the instruction from the content*/
	operation = strtok(content, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	shared_info.arg = strtok(NULL, " \n\t"); /*Extract the argument for the instruction*/
	/*Iterate through the instruction set to find a match*/
	while (operations[i].opcode && operation)
	{
		if (strcmp(operation, operations[i].opcode) == 0)
		{
			operations[i].f(stack, line_num); /*Execute*/
			return (0);
		}
		i++;
	}
	/*If the instruction is not found in the instruction set, handle error*/
	if (operation && operations[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, operation);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1); /*Return 1 if the instruction could not be executed*/
}
