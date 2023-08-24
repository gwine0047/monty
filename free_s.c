#include "monty.h"

void free_s(stack_t *stack)
{
    stack_t *temp;

    temp = stack;
    while(stack != NULL)
    {
        temp = stack->next;
        free_s(stack);
        stack = temp;
    }
}