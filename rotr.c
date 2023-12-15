#include "monty.h"

/**
 * rotr - last elem of stack becomes top
 * @head: head of stack
 * @count: line number
 * Return: nain
 */
void rotr(stack_t **head, unsigned int count)
{
	stack_t *cur;

	(void)count;
	cur = *head;

	if (!(*head) || !((*head)->next))
		return;
	while (cur->next)
		cur = cur->next;
	cur->next = *head;
	cur->prev->next = NULL;
	cur->prev = NULL;
	(*head)->prev = cur;
	*head = cur;
}
