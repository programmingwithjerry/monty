#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/**
 * struct SharedInfo - Structure holding variables for command line arguments,
 *                     monty file pointer, and line content.
 * @arg: Value representing command line argument.
 * @file: Pointer to the monty file being processed.
 * @content: Line content from the Monty file.
 * @lifi: Flag indicating a change between stack and queue operations.
 * Description:
 * This structure carries values throughout the program to share information
 * across functions.
 */

typedef struct shared_info_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} shared_info_t;

/* Global variable for storing shared information across functions */
extern shared_info_t shared_info;


/*Prototypes of all my functions */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_integer(stack_t **head, unsigned int counter);
void print_stack(stack_t **head, unsigned int counter);
void print_top_stack(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int line_num, FILE *file);
void free_stack(stack_t *head);
void remove_top_element(stack_t **head, unsigned int counter);
void swap_top_elements(stack_t **head, unsigned int counter);
void add_top_two_elements(stack_t **head, unsigned int counter);
void perform_no_operation(stack_t **head, unsigned int counter);
void subtract_top_two_elements(stack_t **head, unsigned int counter);
void divide_top_two_elements(stack_t **head, unsigned int counter);
void multiply_top_two_elements(stack_t **head, unsigned int counter);
void perform_modulo_operation(stack_t **head, unsigned int line_number);
void print_char(stack_t **head, unsigned int line_number);
void print_ascii_characters(stack_t **stack_head, unsigned int line_number);
void rotate_left(stack_t **head, __attribute__((unused)) unsigned int counter);
void rotate_right(stack_t **head, __attribute__((unused)) unsigned int counter);
void add_node_to_stack(stack_t **head, int value);
void add_queue(stack_t **head, int n);
void set_queue_mode(stack_t **head, unsigned int counter);
void set_stack_mode(stack_t **head, unsigned int counter);

#endif
