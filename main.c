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
	ssize_t read = 1;

	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: can't open %s file\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read > 0)
	{
		line = NULL;
		read = getline(&line, &size, file);
		bus.line = line;
		count++;
		if (read > 0)
			exec(line, &stack, count, file);
		free(line);
	}
	stack_free(stack);
	fclose(file);
	return (0);

}
