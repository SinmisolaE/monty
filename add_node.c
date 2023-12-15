#include "monty.h"
#include <stdio.h>

/**
 * add_node - adds node to stack
 * @head: the head of stck
 * @n: the node value
 * Return: nain
 */
void add_node(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	if (!(*head))
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
}

/**
 * st_pall - prints node
 * @head: head of stack
 * @count: the line number
 */
void st_pall(stack_t **head, unsigned int count)
{
	stack_t *cur;
	(void)count;

	cur = *head;

	if (!cur)
		return;

	while (cur)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}
