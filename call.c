#include "monty.h"

void(*call(char *token))(stack_t **stack, unsigned int line_number)
{
    int idx = 0;
    instruction_t match[] = {
        {"push", stack_push}, {"pop", stack_pop}, {"pall", stack_pall},
        {"queue", stack_queue}, {"pint", stack_pint},{"rotr", stack_rotr},
        {"rot1", stack_rot1}, {"swap", stack_swap}, {"add", stack_add},
        {NULL, NULL}
    };

    while (match[idx].opcode)
    {
        if (strcmp(match[idx].opcode, token) == 0)
            break;
        idx++;
    }
    return (match[idx].f);
}