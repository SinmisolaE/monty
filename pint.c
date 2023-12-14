#include "monty.h"

/**
 * st_pint - prints the top
 * @head: the head of the stack
 * @count: line number
 * Return: nain
 */
void st_pint(stack_t **head, unsigned int count)
{
	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
