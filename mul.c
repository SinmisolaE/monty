#include "monty.h"

/**
 * st_mul - multiplies the two top elem
 * @head: head of stack
 * @count: line nuber
 * Return: nain
 */
void st_mul(stack_t **head, unsigned int count)
{
	stack_t *cur;
	int len = 0, save;

	cur = *head;

	while (cur)
	{
		cur = cur->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	cur = *head;
	save = cur->next->n * cur->n;
	cur->next->n = save;
	*head = cur->next;
	free(cur);
}
