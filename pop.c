#include "monty.h"

void stack_pop(stack_t **stack, unsigned int count)
{
    stack_t *temp;

    if (!(*stack) || !(stack))
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", count);
        free_s();
        exit(EXIT_FAILURE);
    }
    else
    {
        temp = *stack;
        *stack = temp->next;
        free(temp);
    }
}

void stack_swap(stack_t **stack, unsigned int count)
{
    stack_t *temp = NULL;
    int idx = 0;

    temp = *stack;
    while (temp != NULL)
    {
        temp = temp->next;
        idx++;
    }
    if (idx < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", count);
        free_s();
        exit(EXIT_FAILURE);       
    }
    temp = *stack;
    *stack = (*stack)->next;
    temp->next = (*stack)->next;
    temp->prev = *stack;
    (*stack)->next = temp;
    (*stack)->prev = NULL;
}

void stack_add(stack_t **stack, unsigned int count)
{
    stack_t *temp = NULL;
    int idx = 0;

    temp = *stack;
    while (temp != NULL)
    {
        temp = temp->next;
        idx++;
    }
    if (idx < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", count);
        free_s();
        exit(EXIT_FAILURE);       
    }
    temp = (*stack)->next;
    temp->n = temp->n + (*stack)->n;
    stack_pop(stack, count);
}