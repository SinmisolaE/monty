#ifndef MONTY_H
#define MONTY_H
#include <fcntl.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables- arg, file, line
 * @arg: value
 * @file: pointer to monty file
 * @line: line contwnt
 * @change: flag change stack/queue
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *line;
	int change;
} bus_t;
extern bus_t bus;

void st_push(stack_t **head, unsigned int count);
void st_pall(stack_t **head, unsigned int count);
void add_node(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int count);
void add_queue(stack_t **head, int n);
int exec(char *line, stack_t **stack, unsigned int count, FILE *file);
void stack_free(stack_t *head);
void st_swap(stack_t **head, unsigned int count);
void st_add(stack_t **head, unsigned int count);
void st_nop(stack_t **head, unsigned int count);
void st_pop(stack_t **head, unsigned int count);
void st_pint(stack_t **head, unsigned int count);
void st_sub(stack_t **head, unsigned int count);
void st_div(stack_t **head, unsigned int count);
void st_mul(stack_t **head, unsigned int count);
void st_mod(stack_t **head, unsigned int count);
void st_pchar(stack_t **head, unsigned int count);
void st_pstr(stack_t **head, unsigned int count);
#endif
