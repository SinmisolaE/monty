#include "monty.h"

/**
 * st_pchar - prints the char of top elem in stack
 * @head: head of stack
 * @count: line number
 * Return: nain
 */
void st_pchar(stack_t **head, unsigned int count)
{
	stack_t *cur;

	cur = *head;

	if (!cur)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if (cur->n > 127 || cur->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", cur->n);
}
