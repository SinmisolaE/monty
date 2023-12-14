#include "monty.h"

/**
 * st_mod - modulus of top two elem
 * @head: head of stack
 * count: line number
 * Return: nain
 */
void st_mod(stack_t **head, unsigned int count)
{
	stack_t *cur;
	int len = 0;
	int save;

	cur = *head;

	while (cur)
	{
		cur = cur->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	cur = *head;
	if (cur->n == 0)
	{
		fprintf(stderr, "L%d:  division by zero", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	save = cur->next->n % cur->n;
	cur->next->n = save;
	*head = cur->next;
	free(cur);
}
