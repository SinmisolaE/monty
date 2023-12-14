#include "monty.h"

/**
 * st_pstr - prints the string in a stack
 * @head: head of xtack
 * @count: line number-void
 * Return: nain
 */
void st_pstr(stack_t **head, unsigned int count)
{
	(void)count;
	stack_t *cur;

	cur = *head;

	while (cur)
	{
		if (cur->n > 127 || cur->n <= 0)
			break;
		printf("%c", cur->n);
		cur = cur->next;
	}
	printf("\n");
}
