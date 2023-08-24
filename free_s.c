#include "monty.h"

void free_s(stack_t *h)
{
    stack_t *temp;

    temp = h;
    while(h != NULL)
    {
        temp = h->next;
        free(h);
        h = temp;
    }
}