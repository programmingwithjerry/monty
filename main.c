#define _POSIX_C_SOURCE 200809L

#include "monty.h"

/*Initialize global bus variable with NULL pointers and 0 value for lifi*/

shared_info_t shared_info = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	char *content;	/*Pointer to store each line read from the file*/
	FILE *file;	/*Pointer to the input file*/
	size_t size = 0;	/*Size of the content buffer*/
	ssize_t read_line = 1;
	stack_t *stack = NULL;	/*Pointer to the stack data structure*/
	unsigned int counter = 0;/*Counter to keep track of the line number*/

	/*Check if the correct number of command-line arguments is provided*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*Open the file specified in the command-line argument for reading*/
	file = fopen(argv[1], "r");
	shared_info.file = file;/*Update bus.file with the opened file pointer*/

	/*Check if the file was successfully opened*/
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/*Read each line from the file until the end*/
	while (read_line > 0)
	{
		content = NULL;/*Reset content pointer*/
		/* Read a line from the file into content*/
		read_line = getline(&content, &size, file);
		shared_info.content = content;/*Update bus.content with the read line*/
		counter++;/*ncrement the line counter*/

		/*If a line is successfully read, execute the instruction*/
		if (read_line > 0)
		{
			/* Execute the instruction*/
			execute(content, &stack, counter, file);
		}

		free(content);/*Free dynamically allocated memory for content*/
	}

	free_stack(stack);/*Free dynamically allocated memory for the stack*/
	fclose(file);/* Close the file*/
	return (0);/*Return from the main function*/
}
