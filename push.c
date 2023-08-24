#include "monty.h"

void stack_push(stack_t **stack, unsigned int count)
{
    int idx = 0, flag = 0, con_int;

    if (collection.str)
    {
        if(collection.str[0] == '-')
            idx++;
        while(collection.str[idx])
        {
            if (collection.str[idx] > 57 || collection.str[idx] < 48)
                flag = 1;
            idx++;
        }
        if (flag == 1)
        {
            printf("I was led here\n");
            fprintf(stderr, "L%d: usage: push integer\n", count);
            fclose(collection.file);
            free(collection.data);
            free_s(*stack);
            exit(EXIT_FAILURE);
        }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", count);
        handle_error(collection.file, collection.data, stack);
    }
    con_int = atoi(collection.str);
    if (collection.change == 0)
        add_node(stack, con_int);
    add_queue(stack, con_int);
    }
}

void stack_queue(stack_t **stack, unsigned int count)
{
    (void) stack;
    collection.change = 1;
    (void) count;
}

void stack_pall(stack_t **stack, unsigned int count)
{
    stack_t *temp;
    (void) count;

    temp = *stack;
    if (!temp)
        return;

    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}