#include "monty.h"

/**
 * stack_free - frees stack
 * @head: head of stack
 * Return: nain
 */
void stack_free(stack_t *head)
{
	stack_t *cur;

	cur = head;

	while (head)
	{
		cur = head->next;
		free(head);
		head = cur;
	}
}
