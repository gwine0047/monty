#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

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
*struct con - variables
*@file: monty file pointer.
*@str: string value.
*@data: data in file line.
*@change: stack flag change.
*Description: collects and stores values
*/

typedef struct con
{
        FILE *file;
        char *str;
        char *data;
        int change;
} collect;
extern collect collection;

int call(FILE *file, char *lineptr, unsigned int count, stack_t **stack);
void free_s(stack_t *stack);
void handle_error(FILE *file, char *lineptr, stack_t **stack);
void stack_pop(stack_t **stack, unsigned int count);
void stack_pall(stack_t **stack, unsigned int count);
void add_queue(stack_t **stack, int con_int);
void add_node(stack_t **stack, int con_int);
void stack_push(stack_t **stack, unsigned int count);

#endif