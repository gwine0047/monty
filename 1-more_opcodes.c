#include "monty.h"
void _stack(stack_t **stack, unsigned int count)
{
    (void) stack;
    (void) count;

    collect.line = 0;
}

void stack_div(stack_t **stack, unsigned int count)
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
        fprintf(stderr, "L%d: can't div, stack too short\n", count);
        free_s();
        exit(EXIT_FAILURE);       
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", count);
        free_s();
        exit(EXIT_FAILURE);
    }
    temp = (*stack)->next;
    temp->n = temp->n / (*stack)->n;
    stack_pop(stack, count);
}

void stack_mul(stack_t **stack, unsigned int count)
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
        fprintf(stderr, "L%d: can't mul, stack too short\n", count);
        free_s();
        exit(EXIT_FAILURE);       
    }
    temp = (*stack)->next;
    temp->n = temp->n * (*stack)->n;
    stack_pop(stack, count);
}

void stack_mod(stack_t **stack, unsigned int count)
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
        fprintf(stderr, "L%d: can't mod, stack too short\n", count);
        free_s();
        exit(EXIT_FAILURE);       
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", count);
        free_s();
        exit(EXIT_FAILURE);
    }
    temp = (*stack)->next;
    temp->n = temp->n % (*stack)->n;
    stack_pop(stack, count);
}