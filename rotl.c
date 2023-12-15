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

	if (*head == NULL || (*head)->next == NULL)
		return;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = *head;
	(*head)->prev = cur;
	(*head)->next = NULL;
	*head = save;
}
