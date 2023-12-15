#include "monty.h"

/**
 * rotl - rotates stack to top
 * @head: the head of stack
 * @count: line number
 * Return: nain
 */
void rotl(stack_t **head, unsigned int count)
{
	stack_t *cur;
	stack_t *save;

	(void)count;
	cur = *head;
	save = (*head)->next;
	save->prev = NULL;

	if (!(*head) || !((*head)->next))
		return;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = *head;
	cur->next->prev = cur;
	cur->cur->next = NULL;
	*head = save;
}
