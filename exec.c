#include "monty.h"

/**
 * exec - executes the opcode
 * @line: line countent
 * @stack: the stack
 * @count: line counter
 * @file: pointer to monty file
 * Return: 0 or 1
 */
int exec(char *line, stack_t **stack, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"push", st_push},
				{"pall", st_pall},
				{"pint", st_pint},
				{"pop", st_pop},
				{"swap", st_swap},
				{"add", st_add},
				{"nop", st_nop}
				};

	unsigned int i = 0;
	char *op;
	char *del = " \t\n";

	op = strtok(line, del);
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, del);
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(line);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
