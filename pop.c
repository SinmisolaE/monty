#include "monty.h"

/**
 * st_pop - removes first elemnt in stack
 * @head: the head of stack
 * @count: line number
 * Return: nain
 */
void st_pop(stack_t **head, unsigned int count)
{
	stack_t *cur;

	if (!(*head))
	{
		fprintf(stderr, "L%d: can't pop an empty stack", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	cur = *head;
	*head = cur->next;
	(*head)->prev = NULL;
	free(cur);
}
