#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - the main method
 * @argc: num arguments
 * @argv: monty file location
 * Return: 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	char *line;
	size_t size = 0;
	unsigned int count = 0;
	ssize_t reading = 1;

	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (reading > 0)
	{
		line = NULL;
		reading = getline(&line, &size, file);
		bus.line = line;
		count++;
		if (reading > 0)
			exec(line, &stack, count, file);
		free(line);
	}
	stack_free(stack);
	fclose(file);
	return (0);

}
