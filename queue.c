#include "monty.h"

/**
 * add_queue - add node to tail of stack
 * @head: the head of list
 * @n: the value
 * Return: nain
 */
void add_queue(stack_t **head, int n)
{
	stack_t *new;
	stack_t *cur;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (!(*head))
	{
		new->next = NULL;
		*head = new;
	}
	else
	{	
		cur = *head;
		while (cur->next)
			cur = cur->next;
		new->next = cur->next;
		cur->next = new;
		new->prev = cur;
	}
}

/**
 * f_queue - prints the top
 * @head: head of stack
 * @count: the count
 * Return: nain
 */
void f_queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.change = 1;
}
