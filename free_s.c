#include "monty.h"

void free_s(void)
{
    free_list(collect.point);
    free(collect.store);
    fclose(collect.file);
}

void free_list(stack_t *stack)
{
    stack_t *temp;

    while ((temp = stack) != NULL)
    {
        stack = stack->next;
        free(temp);
    }
}