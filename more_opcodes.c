#include "monty.h"
void stack_rotr(stack_t **stack, unsigned int count)
{
    stack_t *temp = NULL;
    (void) count;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    temp = *stack;

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    temp->next = *stack;
    temp->prev = NULL;
    (*stack)->prev = temp;
    *stack = temp;
}

void stack_rot1(stack_t **stack, unsigned int count)
{
    stack_t *temp = NULL, *temp1 = NULL;
    (void) count;

    if (*stack == NULL || (*stack)->next == NULL)
        return;
    temp = (*stack)->next;
    temp1 = *stack;

    while (temp1->next != NULL)
        temp1 = temp1->next;

    temp->prev = NULL;
    temp1->next = *stack;
    (*stack)->next = NULL;
    (*stack)->prev = temp1;
    *stack = temp;
}

void stack_sub(stack_t **stack, unsigned int count)
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
        fprintf(stderr, "L%d: can't sub, stack too short\n", count);
        free_s();
        exit(EXIT_FAILURE);       
    }
    temp = (*stack)->next;
    temp->n = temp->n - (*stack)->n;
    stack_pop(stack, count); 
}