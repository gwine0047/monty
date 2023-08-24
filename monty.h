#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

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
        char *store;
        int structure;
        unsigned int line;
        stack_t *point;
} colt;
extern colt collect;

void initialize(FILE *file);
void(*call(char *token))(stack_t **stack, unsigned int line_number);
void stack_push(stack_t **stack, unsigned int count);
void stack_queue(stack_t **stack, unsigned int count);
void stack_pall(stack_t **stack, unsigned int count);
void stack_pint(stack_t **stack, unsigned int count);
void stack_pop(stack_t **stack, unsigned int count);
void free_s(void);
void free_list(stack_t *stack);
stack_t *add_node(stack_t **stack, int con_int);
stack_t *add_node_at_end(stack_t **stack, int con_int);
void stack_add(stack_t **stack, unsigned int count);
void stack_swap(stack_t **stack, unsigned int count);
void stack_rotl(stack_t **stack, unsigned int count);
void stack_rotr(stack_t **stack, unsigned int count);
void stack_div(stack_t **stack, unsigned int count);
void _stack(stack_t **stack, unsigned int count);
void stack_mod(stack_t **stack, unsigned int count);
void stack_mul(stack_t **stack, unsigned int count);
void stack_pchar(stack_t **stack, unsigned int count);
void stack_pstr(stack_t **stack, unsigned int count);
void stack_sub(stack_t **stack, unsigned int count);
void stack_nop(stack_t **stack, unsigned int count);
#endif
