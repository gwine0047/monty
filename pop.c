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