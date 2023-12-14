#include "monty.h"

/**
 * st_push - push a stack
 * @head: head of stack
 * @count: line number
 * Return: nain
 */
void st_push(stack_t **head, unsigned int count)
{
	int n, x = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			x++;
		for (; bus.arg[x] != '\0'; x++)
		{
			if (bus.arg[x] > 57 || bus.arg[x] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.line);
			stack_free(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.line);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	if (bus.change == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}
