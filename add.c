#include "monty.h"

void add_node(stack_t **stack, int con_int)
{
    stack_t *new, *temp;

    temp = *stack;
    new = malloc(sizeof(stack_t));
    if (!new)
    {
        printf("Error\n");
        exit(0);
    }
    if (temp)
        temp->prev = new;
    new->n = con_int;
    new->next = *stack;
    new->prev = NULL;
    *stack = new;
}

void add_queue(stack_t **stack, int con_int)
{
    stack_t *new, *temp;

    temp = *stack;
    new = malloc(sizeof(stack_t));
    if (!new)
    {
        printf("Error\n");
        exit(0);
    }
    new->n = con_int;
    new->next = NULL;

    if(temp)
    {
        *stack = new;
        new->prev = NULL;
    }
    temp->next = new;
    new->prev = temp;
}