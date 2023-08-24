#include "monty.h"

void stack_pop(stack_t **stack, unsigned int count)
{
    stack_t *temp;

    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", count);
        handle_error(collection.file, collection.data, &stack);
    else
    {
        temp = *stack;
        *stack = temp->next;
        free(temp);
    }
}