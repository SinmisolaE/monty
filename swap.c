#include "monty.h"

/**
 * st_swap - swap first two elements in stack
 * @head: the head of stack
 * @count: line number
 * Return: nain
 */
void st_swap(stack_t **head, unsigned int count)
{
	stack_t *cur;
	int length = 0, save;

	cur = *head;

	while (cur)
	{
		cur = cur->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	cur = *head;
	save = cur->n;
	cur->n = cur->next->n;
	cur->next->n = save;
}
