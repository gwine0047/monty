#include "monty.h"

int call(FILE *file, char *lineptr, unsigned int count, stack_t **stack)
{
    int idx = 0;
    char *token;
    instruction_t match[] = {
        {"push", stack_push}, {"pop", stack_pop}, {"pall", stack_pall},
        {"queue", stack_queue}, {NULL, NULL}
    };
    token = strtok(lineptr, " \n\t");
    if (token[0] == '#' && token)
        return (0);
    collection.str = strtok(NULL, " \n\t");
    while (match[idx].opcode && token)
    {
        if (strcmp(token, match[idx].opcode) == 0)
        {
            match[idx].f(stack, count);
            return (0);
        }
        idx++;
    }
    if (token && match[idx].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", count, token);
        handle_error(file, lineptr, stack);
    }
    return (1);
}