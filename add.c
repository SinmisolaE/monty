#include "monty.h"

/**
 * st_add - adds first 2 element of stack
 * @head: the head of stack
 * @count: line number
 * Return: nain
 */
void st_add(stack_t **head, unsigned int count)
{
	stack_t *cur;
	int save, len = 0;

	cur = *head;

	while (cur)
	{
		cur = cur->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	cur = *head;
	save = (cur->n) + (cur->next->n);
	cur->next->n = save;
	*head = cur->next;
	free(cur);
}
