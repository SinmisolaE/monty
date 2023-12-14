#include "monty.h"

/**
 * st_div - divide the second top by top in stack
 * @head: head of stack
 * @count: line number
 * Return: nain
 */
void st_div(stack_t **head, unsigned int count)
{
	stack_t *cur;
	int len = 0;

	cur = *head;

	while (cur)
	{
		cur = cur->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	cur = *head;
	if (cur->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	cur->next->n = cur->next->n / cur->n;
	*head = cur->next;
	free(cur);
}
